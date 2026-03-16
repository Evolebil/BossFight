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
    rng(std::random_device{}())
{
    cellSize  = Config::getWindowWidth() / 40;
    moveSpeed = 2.0f * cellSize;

    loadAnimations();
    loadAttackTextures();
}

bool BossGolem::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

void BossGolem::loadAnimations() {
    const char* paths[] = {
        "SDL/assets/boss1/Character.png",
        "./SDL/assets/boss1/Character.png",
        "assets/boss1/Character.png",
        "Character.png"
    };
    for (const char* path : paths) {
        spritesheet = TextureManager::getTexture(path);
        if (spritesheet) break;
    }
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
    const char* armPaths[] = {
        "assets/boss1/arm.png",
        "SDL/assets/boss1/arm.png",
        "arm.png"
    };
    for (const char* p : armPaths) {
        armTexture = TextureManager::getTexture(p);
        if (armTexture) break;
    }

    const char* laserPaths[] = {
        "assets/boss1/Laser.png",
        "SDL/assets/boss1/Laser.png",
        "Laser.png"
    };
    for (const char* p : laserPaths) {
        laserTexture = TextureManager::getTexture(p);
        if (laserTexture) break;
    }
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

    laser.x = x + (facingRight ? width/2 : -width/2);
    laser.y = y;
    laser.facingRight = facingRight;

    if (currentState == BossState::BLOCK) {
        blockActiveTimer += deltaTime;
        hp += 50.0f * deltaTime;
        if (hp > maxHP) hp = maxHP;

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

    for (auto& proj : projectiles) {
        if (!proj.active) continue;

        if (proj.trackingTime > 0.0f) {
            proj.trackingTime -= deltaTime;
            proj.targetX = playerX;
            proj.targetY = playerY;

            float dx = proj.targetX - proj.x;
            float dy = proj.targetY - proj.y;
            float len = std::sqrt(dx*dx + dy*dy);
            if (len > 1.0f) {
                proj.velX = (dx / len) * PROJECTILE_SPEED;
                proj.velY = (dy / len) * PROJECTILE_SPEED;
            }
        }

        proj.x += proj.velX * deltaTime;
        proj.y += proj.velY * deltaTime;

        int W = Config::getWindowWidth();
        int H = Config::getWindowHeight();
        if (proj.x < -100 || proj.x > W + 100 || proj.y > H + 100)
            proj.active = false;
    }

    if (projectileQueue > 0) {
        projectileQueueTimer -= deltaTime;
        if (projectileQueueTimer <= 0.0f) {
            spawnProjectile(lastPlayerX, lastPlayerY);
            projectileQueue--;
            projectileQueueTimer = 0.35f;
        }
    }

    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(),
                       [](const Projectile& p){ return !p.active; }),
        projectiles.end()
        );

    auto it = animations.find(currentState);
    if (it != animations.end()) it->second.update(deltaTime);

    if (!attackSpawned) {
        if (currentState == BossState::ATTACK_RANGE) {
            auto& anim = animations[BossState::ATTACK_RANGE];
            if (anim.getCurrentFrameIndex() >= 3) {
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
            auto& anim = animations[BossState::LASER];
            if (anim.getCurrentFrameIndex() >= 2) {
                spawnLaser();
                attackSpawned = true;
            }
        }
    }

    if ((currentState == BossState::ATTACK_MELEE ||
         currentState == BossState::ATTACK_RANGE ||
         currentState == BossState::LASER) &&
        animations.count(currentState) &&
        animations[currentState].isFinished())
    {
        if (currentState == BossState::LASER) laser.active = false;
        setState(BossState::IDLE);
    }
}

// ============================================================
// AI
// ============================================================

void BossGolem::updateAI(float deltaTime, float playerX, float playerY) {
    if (currentState == BossState::DEATH) return;
    if (currentState == BossState::BLOCK) return;
    if (currentState == BossState::ATTACK_MELEE ||
        currentState == BossState::ATTACK_RANGE ||
        currentState == BossState::LASER) return;

    float dx = playerX - x;
    float dy = playerY - y;
    float distance = std::sqrt(dx*dx + dy*dy);
    float distCells = distance / cellSize;

    facingRight = (dx > 0);

    if (blockTimer >= blockCooldown && canChangeState()) {
        setState(BossState::BLOCK);
        defense          = 0.5f;
        blockActiveTimer = 0;
        return;
    }

    if (attackTimer >= attackCooldown && canChangeState()) {
        attackTimer   = 0;
        attackSpawned = false;
        meleeHitDealt = false;

        if (distCells <= RANGE_MELEE) {
            setState(BossState::ATTACK_MELEE);
            return;
        }

        // Игрок выше босса → снаряды arm, на уровне → лазер
        bool playerAbove = (dy < -cellSize);

        if (distCells <= RANGE_RANGED) {
            setState(playerAbove ? BossState::ATTACK_RANGE : BossState::LASER);
            return;
        }
        if (distCells <= RANGE_LASER) {
            setState(playerAbove ? BossState::ATTACK_RANGE : BossState::LASER);
            return;
        }
    }

    if (distCells > RANGE_MELEE + 0.5f) {
        if (currentState != BossState::WALK && canChangeState())
            setState(BossState::WALK);
        velocityX = (dx > 0) ? moveSpeed : -moveSpeed;
        x += velocityX * deltaTime;
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

    float dx = playerX - startX;
    float dy = playerY - startY;
    float len = std::sqrt(dx*dx + dy*dy);
    if (len < 1.0f) len = 1.0f;

    Projectile proj;
    proj.x            = startX;
    proj.y            = startY;
    proj.velX         = (dx / len) * PROJECTILE_SPEED;
    proj.velY         = (dy / len) * PROJECTILE_SPEED;
    proj.damage       = DAMAGE_RANGE;
    proj.active       = true;
    proj.trackingTime = 0.5f;
    proj.targetX      = playerX;
    proj.targetY      = playerY;
    projectiles.push_back(proj);
}

void BossGolem::spawnLaser() {
    laser.active       = true;
    laser.x            = x + (facingRight ? width/2.0f : -width/2.0f);
    laser.y            = y - height * 0.1f;
    laser.facingRight  = facingRight;
    laser.damagePerSec = DAMAGE_LASER_SEC;
}

// ============================================================
// ПРОВЕРКА УРОНА
// ============================================================

float BossGolem::checkPlayerDamage(SDL_Rect playerBox, float deltaTime) {
    // Удар только в середине анимации (кадр 4 из 8) — не с первого кадра
    if (currentState == BossState::ATTACK_MELEE && !meleeHitDealt &&
        animations.count(BossState::ATTACK_MELEE) &&
        animations.at(BossState::ATTACK_MELEE).getCurrentFrameIndex() >= 4) {
        // Хитбокс атаки захватывает тело босса + область впереди.
        // Начинается на 30% ширины тела ПОЗАДИ края — исправляет баг
        // "вплотную = нет урона" (раньше хитбокс начинался с края тела).
        int meleeW = (int)(cellSize * 2.0f) + (int)(width * 0.3f);
        int meleeH = (int)height;
        int meleeX = facingRight
                         ? (int)(x + width/2 - width*0.3f)          // немного назад от края
                         : (int)(x - width/2 - meleeW + width*0.3f); // зеркально
        int meleeY = (int)(y - height/2);

        SDL_Rect meleeBox = { meleeX, meleeY, meleeW, meleeH };
        bool hit = playerBox.x < meleeBox.x + meleeBox.w &&
                   playerBox.x + playerBox.w > meleeBox.x &&
                   playerBox.y < meleeBox.y + meleeBox.h &&
                   playerBox.y + playerBox.h > meleeBox.y;

        if (hit) {
            meleeHitDealt = true;
            return DAMAGE_MELEE;
        }
    }

    for (auto& proj : projectiles) {
        if (!proj.active) continue;
        int projSize = 24;
        SDL_Rect projBox = {
            (int)(proj.x - projSize/2),
            (int)(proj.y - projSize/2),
            projSize, projSize
        };
        bool hit = playerBox.x < projBox.x + projBox.w &&
                   playerBox.x + playerBox.w > projBox.x &&
                   playerBox.y < projBox.y + projBox.h &&
                   playerBox.y + playerBox.h > projBox.y;

        if (hit) {
            proj.active = false;
            return proj.damage;
        }
    }

    if (laser.active) {
        int W = Config::getWindowWidth();
        int laserH = 20;
        int laserX = laser.facingRight ? (int)laser.x : 0;
        int laserW = laser.facingRight ? W - (int)laser.x : (int)laser.x;
        int laserY = (int)(laser.y - laserH/2);

        SDL_Rect laserBox = { laserX, laserY, laserW, laserH };
        bool hit = playerBox.x < laserBox.x + laserBox.w &&
                   playerBox.x + playerBox.w > laserBox.x &&
                   playerBox.y < laserBox.y + laserBox.h &&
                   playerBox.y + playerBox.h > laserBox.y;

        if (hit) return DAMAGE_LASER_SEC * deltaTime;
    }

    return 0.0f;
}

// ============================================================
// SETSTATE
// ============================================================

void BossGolem::setState(BossState newState) {
    if (currentState == newState) return;

    bool alwaysAllowed = (newState == BossState::IDLE ||
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

    float actualDamage = damage * (1.0f - defense);
    hp -= actualDamage;

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
        SDL_Rect rect = { (int)(x - width/2), (int)(y - height/2), (int)width, (int)height };
        SDL_RenderFillRect(renderer, &rect);
        return;
    }

    auto it = animations.find(currentState);
    if (it == animations.end()) return;

    SDL_Rect src = it->second.getCurrentFrame();
    int dstW = (int)(src.w * SPRITE_SCALE);
    int dstH = (int)(src.h * SPRITE_SCALE);
    int dstX = (int)(x - dstW / 2);
    int dstY = (int)(y + height/2 - dstH);

    SDL_Rect dst = { dstX, dstY, dstW, dstH };
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer, spritesheet, &src, &dst, 0, nullptr, flip);
}

void BossGolem::renderProjectiles(SDL_Renderer* renderer) {
    for (const auto& proj : projectiles) {
        if (!proj.active) continue;

        if (armTexture) {
            SDL_Rect src = { 0, 0, 102, 154 };
            int size = 32;
            SDL_Rect dst = { (int)(proj.x - size/2), (int)(proj.y - size/2), size, size };
            SDL_RenderCopy(renderer, armTexture, &src, &dst);
        } else {
            SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
            SDL_Rect r = { (int)(proj.x - 12), (int)(proj.y - 12), 24, 24 };
            SDL_RenderFillRect(renderer, &r);
        }
    }
}

void BossGolem::renderLaser(SDL_Renderer* renderer) {
    if (!laser.active) return;

    int W = Config::getWindowWidth();
    int laserH = 20;
    int laserX = laser.facingRight ? (int)laser.x : 0;
    int laserW = laser.facingRight ? W - (int)laser.x : (int)laser.x;
    int laserY = (int)(laser.y - laserH/2);

    if (laserTexture) {
        SDL_Rect src = { 0, 800, 308, 100 };
        SDL_Rect dst = { laserX, laserY, laserW, laserH };
        SDL_RendererFlip flip = laser.facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, laserTexture, &src, &dst, 0, nullptr, flip);
    } else {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 50, 150, 255, 200);
        SDL_Rect laserRect = { laserX, laserY, laserW, laserH };
        SDL_RenderFillRect(renderer, &laserRect);
        SDL_SetRenderDrawColor(renderer, 150, 220, 255, 255);
        SDL_RenderDrawRect(renderer, &laserRect);
    }
}
