/**
 * @file boss_golem.cpp
 * @brief Реализация босса-голема
 * @author evol
 * @date 2026-02-20
 */
#include "boss_golem.h"
#include "../config/config.h"
#include "../utils/texture_manager.h"
#include "../levels/level1_assets.h"

BossGolem::BossGolem(float spawnX, float spawnY, float attackSpeedMult)
    : Character(spawnX, spawnY, 100, 100, 1000),
    currentState(BossState::IDLE),
    previousState(BossState::IDLE),
    defense(0.0f),
    moveSpeed(0),
    cellSize(32),
    attackCooldown(3.0f / attackSpeedMult),
    attackTimer(0),
    blockCooldown(20.0f),
    blockTimer(0),
    blockDuration(3.0f),
    blockActiveTimer(0),
    stateTimer(0),
    lastStateChangeTime(0.0f),
    meleeHitDealt(false),
    meleeHitTime(0.5f),
    attackSpawned(false),
    projectileQueue(0),
    projectileQueueTimer(0.0f),
    lastPlayerX(spawnX),
    lastPlayerY(spawnY),
    attackSpeedMult(attackSpeedMult),
    armTexture(nullptr),
    laserTexture(nullptr),
    laser({false, 0, 0, true, DAMAGE_LASER_SEC}),
    rng(std::random_device{}()) {

    cellSize  = Config::getWindowWidth() / 40;
    moveSpeed = 2.0f * cellSize;

    loadAnimations();
    loadAttackTextures();
}

bool BossGolem::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

void BossGolem::loadAnimations() {
    // Пробуем только правильный путь по структуре проекта, потом запасной
    spritesheet = TextureManager::getTexture("assets/boss1/Character.png");
    if (!spritesheet)
        spritesheet = TextureManager::getTexture("Character.png");
    if (!spritesheet) return;

    animations[BossState::IDLE] = Animation(true, false);
    for (int i = 0; i < 4; i++)
        animations[BossState::IDLE].addFrame(25 + i*100, 22, 75, 49, 0.2f);

    animations[BossState::WALK] = Animation(true, false);
    for (int i = 0; i < 10; i++)
        animations[BossState::WALK].addFrame(25 + i*100, 624, 75, 50, 0.08f);

    animations[BossState::ATTACK_MELEE] = Animation(false, false);
    for (int i = 0; i < 8; i++)
        animations[BossState::ATTACK_MELEE].addFrame(25 + i*100, 422, 75, 57, 0.1f);

    animations[BossState::ATTACK_RANGE] = Animation(false, false);
    for (int i = 0; i < 7; i++)
        animations[BossState::ATTACK_RANGE].addFrame(25 + i*100, 224, 75, 48, 0.09f);

    animations[BossState::LASER] = Animation(false, false);
    for (int i = 0; i < 7; i++)
        animations[BossState::LASER].addFrame(25 + i*100, 524, 75, 51, 0.13f);

    animations[BossState::BLOCK] = Animation(false, true);
    for (int i = 0; i < 8; i++)
        animations[BossState::BLOCK].addFrame(25 + i*100, 322, 75, 53, 0.1f);

    animations[BossState::HURT] = Animation(false, false);
    for (int i = 0; i < 8; i++)
        animations[BossState::HURT].addFrame(25 + i*100, 122, 75, 53, 0.07f);

    animations[BossState::DEATH] = Animation(false, false);
    for (int i = 0; i < 10; i++)
        animations[BossState::DEATH].addFrame(25 + i*100, 721, 75, 73, 0.1f);
    for (int i = 0; i < 4; i++)
        animations[BossState::DEATH].addFrame(25 + i*100, 834, 75, 61, 0.15f);
}

void BossGolem::loadAttackTextures() {
    armTexture = TextureManager::getTexture("assets/boss1/arm.png");
    if (!armTexture) armTexture = TextureManager::getTexture("arm.png");

    laserTexture = TextureManager::getTexture("assets/boss1/Laser.png");
    if (!laserTexture) laserTexture = TextureManager::getTexture("Laser.png");
}

// ============================================================
// UPDATE
// ============================================================

void BossGolem::update(float deltaTime, float playerX, float playerY) {
    if (hp <= 0) {
        if (currentState != BossState::DEATH) setState(BossState::DEATH);
        auto it = animations.find(currentState);
        if (it != animations.end()) it->second.update(deltaTime);
        applyGravityAndCollisions(deltaTime);
        return;
    }

    attackTimer += deltaTime;
    blockTimer  += deltaTime;
    stateTimer  += deltaTime;

    laser.x           = x + (facingRight ? width/2 : -width/2);
    laser.y           = y;
    laser.facingRight  = facingRight;

    if (currentState == BossState::BLOCK) {
        blockActiveTimer += deltaTime;
        // Медленное восстановление HP во время блока
        hp = std::min(hp + 50.0f * deltaTime, maxHP);

        auto& blockAnim = animations[BossState::BLOCK];
        if (!blockAnim.isFinished()) {
            if (blockActiveTimer >= blockDuration && blockAnim.isGoingForward())
                blockAnim.playReverse();
        } else {
            setState(BossState::IDLE);
            blockTimer       = 0;
            blockActiveTimer = 0;
            defense          = 0.0f;
        }
    }

    updateAI(deltaTime, playerX, playerY);
    applyGravityAndCollisions(deltaTime);

    // Обновляем снаряды
    for (auto& proj : projectiles) {
        if (!proj.active) continue;

        if (proj.trackingTime > 0.0f) {
            proj.trackingTime -= deltaTime;
            proj.targetX = playerX;
            proj.targetY = playerY;

            float dx  = proj.targetX - proj.x;
            float dy  = proj.targetY - proj.y;
            float len = std::sqrt(dx*dx + dy*dy);
            if (len > 1.0f) {
                proj.velX = (dx / len) * PROJECTILE_SPEED;
                proj.velY = (dy / len) * PROJECTILE_SPEED;
            }
        }

        proj.x += proj.velX * deltaTime;
        proj.y += proj.velY * deltaTime;

        const int W = Config::getWindowWidth();
        const int H = Config::getWindowHeight();
        if (proj.x < -100 || proj.x > W + 100 || proj.y > H + 100)
            proj.active = false;
    }

    // Очередь снарядов (тройной залп на высоких сложностях)
    if (projectileQueue > 0) {
        projectileQueueTimer -= deltaTime;
        if (projectileQueueTimer <= 0.0f) {
            spawnProjectile(lastPlayerX, lastPlayerY);
            projectileQueue--;
            projectileQueueTimer = 0.35f;
        }
    }

    // Удаляем неактивные снаряды
    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(),
                       [](const Projectile& p){ return !p.active; }),
        projectiles.end());

    auto it = animations.find(currentState);
    if (it != animations.end()) it->second.update(deltaTime);

    // Спавн снаряда/лазера в нужный кадр анимации
    if (!attackSpawned) {
        if (currentState == BossState::ATTACK_RANGE) {
            if (animations[BossState::ATTACK_RANGE].getCurrentFrameIndex() >= 3) {
                lastPlayerX = playerX;
                lastPlayerY = playerY;
                spawnProjectile(lastPlayerX, lastPlayerY);
                if (attackSpeedMult > 1.0f) {
                    projectileQueue      = 2;
                    projectileQueueTimer = 0.35f;
                }
                attackSpawned = true;
            }
        }
        if (currentState == BossState::LASER) {
            if (animations[BossState::LASER].getCurrentFrameIndex() >= 2) {
                spawnLaser();
                attackSpawned = true;
            }
        }
    }

    // Возврат в IDLE после завершения атаки
    if ((currentState == BossState::ATTACK_MELEE ||
         currentState == BossState::ATTACK_RANGE ||
         currentState == BossState::LASER) &&
        animations.count(currentState) &&
        animations[currentState].isFinished()) {
        if (currentState == BossState::LASER) laser.active = false;
        setState(BossState::IDLE);
    }
}

// ============================================================
// AI
// ============================================================

void BossGolem::updateAI(float deltaTime, float playerX, float playerY) {
    if (currentState == BossState::DEATH ||
        currentState == BossState::BLOCK ||
        currentState == BossState::ATTACK_MELEE ||
        currentState == BossState::ATTACK_RANGE ||
        currentState == BossState::LASER) return;

    float dx       = playerX - x;
    float dy       = playerY - y;
    float distCells = std::sqrt(dx*dx + dy*dy) / cellSize;

    facingRight = (dx > 0);

    // Блок с кулдауном
    if (blockTimer >= blockCooldown && canChangeState()) {
        setState(BossState::BLOCK);
        defense          = 0.5f;
        blockActiveTimer = 0;
        return;
    }

    // Атака с кулдауном
    if (attackTimer >= attackCooldown && canChangeState()) {
        attackTimer   = 0;
        attackSpawned = false;
        meleeHitDealt = false;

        if (distCells <= RANGE_MELEE) {
            setState(BossState::ATTACK_MELEE);
            return;
        }

        // Игрок выше — снаряды (arm), на уровне — лазер
        const bool playerAbove = (dy < -cellSize);

        // Близкая дальняя атака
        if (distCells <= RANGE_RANGED) {
            setState(BossState::ATTACK_RANGE);
            return;
        }
        // Далёкая дальняя атака — лазер (если игрок не выше)
        if (distCells <= RANGE_LASER) {
            setState(playerAbove ? BossState::ATTACK_RANGE : BossState::LASER);
            return;
        }
    }

    // Движение к игроку
    if (distCells > RANGE_MELEE + 0.5f) {
        if (currentState != BossState::WALK && canChangeState())
            setState(BossState::WALK);
        // ВАЖНО: применяем coллизии через applyCollisionsX, а не напрямую x +=
        velocityX  = (dx > 0) ? moveSpeed : -moveSpeed;
        x += velocityX * deltaTime;
        applyCollisionsX();
    } else {
        if (currentState == BossState::WALK) {
            setState(BossState::IDLE);
            velocityX = 0;
        }
    }
}

// ============================================================
// СПАВН АТАК
// ============================================================

void BossGolem::spawnProjectile(float playerX, float playerY) {
    float startX = x + (facingRight ? width/2.0f : -width/2.0f);
    float startY = y;

    float dx  = playerX - startX;
    float dy  = playerY - startY;
    float len = std::sqrt(dx*dx + dy*dy);
    if (len < 1.0f) len = 1.0f;

    Projectile proj;
    proj.x           = startX;
    proj.y           = startY;
    proj.velX        = (dx / len) * PROJECTILE_SPEED;
    proj.velY        = (dy / len) * PROJECTILE_SPEED;
    proj.damage      = DAMAGE_RANGE;
    proj.active      = true;
    proj.trackingTime = 0.5f;
    proj.targetX     = playerX;
    proj.targetY     = playerY;
    projectiles.push_back(proj);
}

void BossGolem::spawnLaser() {
    laser.active       = true;
    laser.x            = x + (facingRight ? width/2.0f : -width/2.0f);

    // БАГ 4 FIX: спавним лазер ниже — совпадает со смещением в checkPlayerDamage
    laser.y            = y + height * 0.3f;

    laser.facingRight  = facingRight;
    laser.damagePerSec = DAMAGE_LASER_SEC;
}

// ============================================================
// ПРОВЕРКА УРОНА ПО ИГРОКУ
// ============================================================

float BossGolem::checkPlayerDamage(SDL_Rect playerBox, float deltaTime) {

    // ШАГ 1: MELEE — удар наносится на кадре 5 из 8 (было 4, теперь позже)
    // БАГ 1 FIX: кадр 5 вместо 4 — даёт время увернуться пока босс замахивается
    if (currentState == BossState::ATTACK_MELEE && !meleeHitDealt &&
        animations.count(BossState::ATTACK_MELEE) &&
        animations.at(BossState::ATTACK_MELEE).getCurrentFrameIndex() >= 6) {

        // БАГ 2+3 FIX: хитбокс короче (было 2.0f клетки, стало 1.4f)
        // и смещён дальше от центра босса (отступ width*0.5f вместо width*0.3f)
        int meleeW = (int)(cellSize * 1.0f);
        int meleeH = (int)(height * 0.85f);

        // БАГ 3 FIX: хитбокс начинается дальше от тела босса
        int meleeX = facingRight
                         ? (int)(x + width * 0.1f)
                         : (int)(x - width * 0.1f - meleeW);          // левая атака: зеркально

        int meleeY = (int)(y - meleeH / 2);

        SDL_Rect meleeBox = {meleeX, meleeY, meleeW, meleeH};

        // БАГ 2 FIX: проверяем попадание ПЕРЕД нанесением урона
        if (rectsOverlap(playerBox, meleeBox)) {
            meleeHitDealt = true;
            return DAMAGE_MELEE;
        } else {
            // Игрок вне зоны — помечаем что удар уже был, урон не наносим
            meleeHitDealt = true;
            return 0.0f;
        }
    }

    // ШАГ 2: Снаряды — без изменений
    for (auto& proj : projectiles) {
        if (!proj.active) continue;
        constexpr int PROJ_SIZE = 24;
        SDL_Rect projBox = {
            (int)(proj.x - PROJ_SIZE/2),
            (int)(proj.y - PROJ_SIZE/2),
            PROJ_SIZE, PROJ_SIZE
        };
        if (rectsOverlap(playerBox, projBox)) {
            proj.active = false;
            return proj.damage;
        }
    }

    // ШАГ 3: Лазер
    // БАГ 4 FIX: лазер смещён ниже — y + height*0.3f вместо центра
    if (laser.active) {
        const int W = Config::getWindowWidth();
        constexpr int LASER_H = 20;

        int laserX = laser.facingRight ? (int)laser.x : 0;
        int laserW = laser.facingRight ? W - (int)laser.x : (int)laser.x;

        // БАГ 4 FIX: хитбокс лазера опускаем на 30% высоты босса вниз
        int laserY = (int)(laser.y + height * 0.3f - LASER_H / 2);

        SDL_Rect laserBox = {laserX, laserY, laserW, LASER_H};
        if (rectsOverlap(playerBox, laserBox))
            return DAMAGE_LASER_SEC * deltaTime;
    }

    return 0.0f;
}

// ============================================================
// SETSTATE
// ============================================================

void BossGolem::setState(BossState newState) {
    if (currentState == newState) return;

    const bool alwaysAllowed = (newState == BossState::IDLE ||
                                newState == BossState::HURT ||
                                newState == BossState::DEATH);
    if (!alwaysAllowed && !canChangeState()) return;

    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
    attackSpawned       = false;
    meleeHitDealt       = false;

    if (newState != BossState::LASER) laser.active = false;

    if (animations.find(newState) != animations.end())
        animations[newState].reset();
}

// ============================================================
// TAKEDAMAGE
// ============================================================

void BossGolem::takeDamage(float damage) {
    if (currentState == BossState::DEATH) return;

    hp -= damage * (1.0f - defense);

    if (hp <= 0) {
        hp = 0;
        laser.active = false;
        projectiles.clear();
        setState(BossState::DEATH);
    }
}

// ============================================================
// RENDER
// ============================================================

void BossGolem::render(SDL_Renderer* renderer) {
    renderProjectiles(renderer);
    renderLaser(renderer);

    if (!spritesheet) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = {(int)(x - width/2), (int)(y - height/2), (int)width, (int)height};
        SDL_RenderFillRect(renderer, &rect);
        return;
    }

    auto it = animations.find(currentState);
    if (it == animations.end()) return;

    SDL_Rect src  = it->second.getCurrentFrame();
    int dstW = (int)(src.w * SPRITE_SCALE);
    int dstH = (int)(src.h * SPRITE_SCALE);
    int dstX = (int)(x - dstW / 2);
    int dstY = (int)(y + height/2 - dstH);

    SDL_Rect dst = {dstX, dstY, dstW, dstH};
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer, spritesheet, &src, &dst, 0, nullptr, flip);
}

void BossGolem::renderProjectiles(SDL_Renderer* renderer) {
    for (const auto& proj : projectiles) {
        if (!proj.active) continue;

        if (armTexture) {
            SDL_Rect src = {0, 0, 102, 154};
            constexpr int SIZE = 32;
            SDL_Rect dst = {(int)(proj.x - SIZE/2), (int)(proj.y - SIZE/2), SIZE, SIZE};
            SDL_RenderCopy(renderer, armTexture, &src, &dst);
        } else {
            SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
            SDL_Rect r = {(int)(proj.x - 12), (int)(proj.y - 12), 24, 24};
            SDL_RenderFillRect(renderer, &r);
        }
    }
}

void BossGolem::renderLaser(SDL_Renderer* renderer) {
    if (!laser.active) return;

    const int W       = Config::getWindowWidth();
    constexpr int LASER_H = 20;
    int laserX = laser.facingRight ? (int)laser.x : 0;
    int laserW = laser.facingRight ? W - (int)laser.x : (int)laser.x;
    int laserY = (int)(laser.y - LASER_H / 2);

    SDL_Rect laserRect = {laserX, laserY, laserW, LASER_H};

    if (laserTexture) {
        SDL_Rect src  = {0, 800, 308, 100};
        SDL_RendererFlip flip = laser.facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, laserTexture, &src, &laserRect, 0, nullptr, flip);
    } else {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 50, 150, 255, 200);
        SDL_RenderFillRect(renderer, &laserRect);
        SDL_SetRenderDrawColor(renderer, 150, 220, 255, 255);
        SDL_RenderDrawRect(renderer, &laserRect);
    }
}