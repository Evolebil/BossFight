/**
 * @file boss_golem.cpp
 * @brief Реализация босса-голема — две фазы
 * @author evol
 * @date 2026-02-20
 */
#include "boss_golem.h"
#include "../config/config.h"
#include "../utils/texture_manager.h"
#include "../levels/level1_assets.h"

// ============================================================
// КОНСТРУКТОР
// ============================================================

BossGolem::BossGolem(float spawnX, float spawnY, float attackSpeedMult)
    : Character(spawnX, spawnY, 100, 100, 1000),
    currentState(BossState::IDLE),
    previousState(BossState::IDLE),
    phase(BossPhase::PHASE_1),
    phaseTimer(0.0f),
    phase2Triggered(false),
    currentMeleePattern(MeleePattern::NONE),
    meleePatternStep(0),
    meleePatternTimer(0.0f),
    meleeTeleportDone(false),
    meleeAttackDirX(1.0f),
    patternFacingRight(true),
    isTeleporting(false),
    teleportTargetX(0.0f),
    teleportTargetY(0.0f),
    reviveAnim(false, false),
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
    meleeSecondHitDealt(false),
    meleeHitTime(0.5f),
    attackSpawned(false),
    projectileQueue(0),
    projectileQueueTimer(0.0f),
    lastPlayerX(spawnX),
    lastPlayerY(spawnY),
    attackSpeedMult(attackSpeedMult),
    armTexture(nullptr),
    laserTexture(nullptr),
    laser({false, 0, 0, true, DAMAGE_LASER_SEC, 20.0f}),
    rng(std::random_device{}()) {

    cellSize  = Config::getWindowWidth() / 40;
    moveSpeed = 2.0f * cellSize;

    loadAnimations();
    loadAttackTextures();
}

// ============================================================
// ЗАГРУЗКА АНИМАЦИЙ
// ============================================================

void BossGolem::loadAnimations() {
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

    // Воскрешение — HURT кадры задом наперёд
    for (int i = 7; i >= 0; i--)
        reviveAnim.addFrame(25 + i*100, 122, 75, 53, 0.07f);
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
    // Запоминаем позицию игрока всегда — даже если он мёртв
    // Это предотвращает пропадание босса при смерти игрока
    lastPlayerX = playerX;
    lastPlayerY = playerY;

    // --- Переход фаза1 → фаза2 (смерть → пауза → воскрешение) ---
    if (phase == BossPhase::DYING ||
        phase == BossPhase::PAUSING ||
        phase == BossPhase::TRANSITIONING) {
        updatePhaseTransition(deltaTime);
        applyGravityAndCollisions(deltaTime);
        return;
    }

    // --- Смерть в фазе 1 → запускаем переход ---
    if (hp <= 0 && !phase2Triggered && phase == BossPhase::PHASE_1) {
        phase2Triggered = true;
        phase           = BossPhase::DYING;
        phaseTimer      = 0.0f;
        laser.active    = false;
        projectiles.clear();
        // Принудительно запускаем анимацию смерти
        currentState = BossState::DEATH;
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].reset();
        applyGravityAndCollisions(deltaTime);
        return;
    }

    // --- Настоящая смерть (фаза 2) ---
    if (hp <= 0 && phase == BossPhase::PHASE_2) {
        if (currentState != BossState::DEATH) {
            currentState = BossState::DEATH;
            if (animations.count(BossState::DEATH))
                animations[BossState::DEATH].reset();
        }
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].update(deltaTime);
        applyGravityAndCollisions(deltaTime);
        return;
    }

    attackTimer += deltaTime;
    blockTimer  += deltaTime;
    stateTimer  += deltaTime;

    laser.x          = x + (facingRight ? width/2 : -width/2);
    laser.y          = y;
    laser.facingRight = facingRight;

    // --- Блок (только фаза 1, только HP > 70%) ---
    if (phase == BossPhase::PHASE_1 && currentState == BossState::BLOCK) {
        blockActiveTimer += deltaTime;
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

    // --- Телепорт: показываем IDLE пока скользим ---
    if (isTeleporting) {
        updateTeleport(deltaTime);
        // Обновляем анимацию IDLE во время телепорта чтобы не пропадать
        if (animations.count(BossState::IDLE))
            animations[BossState::IDLE].update(deltaTime);
    }

    // --- AI ---
    updateAI(deltaTime, playerX, playerY);
    applyGravityAndCollisions(deltaTime);

    // --- Снаряды ---
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

    if (projectileQueue > 0) {
        projectileQueueTimer -= deltaTime;
        if (projectileQueueTimer <= 0.0f) {
            bool pred = (phase == BossPhase::PHASE_2 && projectileQueue % 2 == 0);
            spawnProjectile(lastPlayerX, lastPlayerY, pred);
            projectileQueue--;
            projectileQueueTimer = 0.35f;
        }
    }

    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(),
                       [](const Projectile& p){ return !p.active; }),
        projectiles.end());

    // --- Анимации (только если не телепортируем — там выше обновляется IDLE) ---
    if (!isTeleporting) {
        auto it = animations.find(currentState);
        if (it != animations.end()) it->second.update(deltaTime);
    }

    // --- Спавн снаряда/лазера ---
    if (!attackSpawned) {
        if (currentState == BossState::ATTACK_RANGE &&
            animations[BossState::ATTACK_RANGE].getCurrentFrameIndex() >= 3) {
            spawnProjectile(playerX, playerY, false);
            if (phase == BossPhase::PHASE_2) {
                projectileQueue      = 1;
                projectileQueueTimer = 0.3f;
            } else if (attackSpeedMult > 1.0f) {
                projectileQueue      = 2;
                projectileQueueTimer = 0.35f;
            }
            attackSpawned = true;
        }
        // Лазер только в фазе 1
        if (phase == BossPhase::PHASE_1 &&
            currentState == BossState::LASER &&
            animations[BossState::LASER].getCurrentFrameIndex() >= 2) {
            spawnLaser(false);
            attackSpawned = true;
        }
    }

    // --- Возврат в IDLE после атаки ---
    const bool patternActive = (phase == BossPhase::PHASE_2 &&
                                currentMeleePattern != MeleePattern::NONE);
    if (!patternActive && !isTeleporting &&
        (currentState == BossState::ATTACK_MELEE ||
         currentState == BossState::ATTACK_RANGE ||
         currentState == BossState::LASER) &&
        animations.count(currentState) &&
        animations[currentState].isFinished()) {
        if (currentState == BossState::LASER) laser.active = false;
        setState(BossState::IDLE);
    }
}

// ============================================================
// ПЕРЕХОД ФАЗА 1 → ФАЗА 2
// ============================================================

void BossGolem::updatePhaseTransition(float deltaTime) {
    phaseTimer += deltaTime;

    // ШАГ 1: DYING — проигрываем анимацию смерти до конца
    if (phase == BossPhase::DYING) {
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].update(deltaTime);

        if (animations[BossState::DEATH].isFinished()) {
            // Смерть доиграла — начинаем паузу
            phase      = BossPhase::PAUSING;
            phaseTimer = 0.0f;
        }
        return;
    }

    // ШАГ 2: PAUSING — стоим на последнем кадре смерти, ждём
    if (phase == BossPhase::PAUSING) {
        // Ничего не делаем — игрок радуется
        if (phaseTimer >= PHASE2_PAUSE_DURATION) {
            // Пауза закончилась — начинаем воскрешение
            phase      = BossPhase::TRANSITIONING;
            phaseTimer = 0.0f;
            hp         = maxHP * 0.75f;
            projectiles.clear();
            reviveAnim.reset();
        }
        return;
    }

    // ШАГ 3: TRANSITIONING — анимация воскрешения
    if (phase == BossPhase::TRANSITIONING) {
        reviveAnim.update(deltaTime);

        if (reviveAnim.isFinished()) {
            // Воскрешение завершено — начинаем фазу 2
            phase               = BossPhase::PHASE_2;
            currentState        = BossState::IDLE;
            lastStateChangeTime = stateTimer;
            if (animations.count(BossState::IDLE))
                animations[BossState::IDLE].reset();
            attackTimer = 0.0f;
            blockTimer  = 0.0f;
        }
        return;
    }
}

// ============================================================
// AI
// ============================================================

void BossGolem::updateAI(float deltaTime, float playerX, float playerY) {
    if (currentState == BossState::DEATH) return;
    if (isTeleporting) return;

    if (phase == BossPhase::PHASE_1)
        updateAI_Phase1(deltaTime, playerX, playerY);
    else if (phase == BossPhase::PHASE_2)
        updateAI_Phase2(deltaTime, playerX, playerY);
}

void BossGolem::updateAI_Phase1(float deltaTime, float playerX, float playerY) {
    if (currentState == BossState::BLOCK ||
        currentState == BossState::ATTACK_MELEE ||
        currentState == BossState::ATTACK_RANGE ||
        currentState == BossState::LASER) return;

    float dx        = playerX - x;
    float dy        = playerY - y;
    float distCells = std::sqrt(dx*dx + dy*dy) / cellSize;
    facingRight     = (dx > 0);

    const float hpPct = hp / maxHP;
    if (blockTimer >= blockCooldown && canChangeState() && hpPct >= BLOCK_HP_THRESHOLD) {
        setState(BossState::BLOCK);
        defense          = 0.5f;
        blockActiveTimer = 0;
        return;
    }

    if (attackTimer >= attackCooldown && canChangeState()) {
        attackTimer   = 0;
        attackSpawned = false;
        meleeHitDealt = false;

        if (distCells <= RANGE_MELEE) { setState(BossState::ATTACK_MELEE); return; }

        // Лазер только если игрок НЕ выше босса и далеко
        const bool playerAbove = (dy < -cellSize);
        if (distCells <= RANGE_RANGED) { setState(BossState::ATTACK_RANGE); return; }
        if (distCells <= RANGE_LASER && !playerAbove) {
            setState(BossState::LASER);
            return;
        }
        if (distCells <= RANGE_LASER && playerAbove) {
            setState(BossState::ATTACK_RANGE);
            return;
        }
    }

    if (distCells > RANGE_MELEE + 0.5f) {
        if (currentState != BossState::WALK && canChangeState())
            setState(BossState::WALK);
        velocityX = (dx > 0) ? moveSpeed : -moveSpeed;
        x += velocityX * deltaTime;
        applyCollisionsX();
    } else {
        if (currentState == BossState::WALK) {
            setState(BossState::IDLE);
            velocityX = 0;
        }
    }
}

void BossGolem::updateAI_Phase2(float deltaTime, float playerX, float playerY) {
    // Активный паттерн — обновляем его, ничего другого не делаем
    if (currentMeleePattern != MeleePattern::NONE) {
        updateMeleePattern(deltaTime);
        return;
    }

    if (currentState == BossState::ATTACK_MELEE ||
        currentState == BossState::ATTACK_RANGE) return;

    float dx        = playerX - x;
    float dy        = playerY - y;
    float distCells = std::sqrt(dx*dx + dy*dy) / cellSize;
    facingRight     = (dx > 0);

    if (attackTimer >= attackCooldown && canChangeState()) {
        attackTimer         = 0;
        attackSpawned       = false;
        meleeHitDealt       = false;
        meleeSecondHitDealt = false;

        if (distCells <= RANGE_MELEE)  { startMeleePattern(playerX, playerY); return; }
        if (distCells <= RANGE_LASER)  { setState(BossState::ATTACK_RANGE); return; }
    }

    if (distCells > RANGE_MELEE + 0.5f) {
        if (currentState != BossState::WALK && canChangeState())
            setState(BossState::WALK);
        velocityX = (dx > 0) ? moveSpeed : -moveSpeed;
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
// ПАТТЕРНЫ БЛИЖНЕЙ АТАКИ
// ============================================================

void BossGolem::startMeleePattern(float /*playerX*/, float /*playerY*/) {
    std::uniform_int_distribution<int> dist(0, 2);
    int roll = dist(rng);

    meleePatternStep    = 0;
    meleePatternTimer   = 0.0f;
    meleeTeleportDone   = false;
    meleeAttackDirX     = facingRight ? 1.0f : -1.0f;
    patternFacingRight  = facingRight;
    meleeHitDealt       = false;
    meleeSecondHitDealt = false;

    if      (roll == 0) currentMeleePattern = MeleePattern::DOUBLE_STRIKE;
    else if (roll == 1) currentMeleePattern = MeleePattern::DOUBLE_DIRECTION;
    else                currentMeleePattern = MeleePattern::STRIKE_TELEPORT_RANGE;

    attackSpawned = false;
    facingRight   = patternFacingRight;
    forceState(BossState::ATTACK_MELEE);
}

void BossGolem::updateMeleePattern(float deltaTime) {
    meleePatternTimer -= deltaTime;

    // Во время всего паттерна — не поворачиваемся к игроку
    facingRight = patternFacingRight;

    // Ждём завершения текущей анимации
    if (currentState == BossState::ATTACK_MELEE &&
        !animations[BossState::ATTACK_MELEE].isFinished()) return;
    if (currentState == BossState::ATTACK_RANGE &&
        !animations[BossState::ATTACK_RANGE].isFinished()) return;
    if (isTeleporting) return;

    // ----------------------------------------------------------------
    // ПАТТЕРН 1: DOUBLE_STRIKE
    // Удар → 0.2 сек → удар (то же направление)
    // ----------------------------------------------------------------
    if (currentMeleePattern == MeleePattern::DOUBLE_STRIKE) {
        if (meleePatternStep == 0) {
            meleePatternStep  = 1;
            meleePatternTimer = 0.2f;
        } else if (meleePatternStep == 1 && meleePatternTimer <= 0.0f) {
            meleeHitDealt = false;
            attackSpawned = false;
            facingRight   = patternFacingRight;
            forceState(BossState::ATTACK_MELEE);
            meleePatternStep = 2;
        } else if (meleePatternStep == 2) {
            currentMeleePattern = MeleePattern::NONE;
            setState(BossState::IDLE);
        }
    }

    // ----------------------------------------------------------------
    // ПАТТЕРН 2: DOUBLE_DIRECTION
    // Удар → мгновенный разворот → удар в другую сторону
    // ----------------------------------------------------------------
    else if (currentMeleePattern == MeleePattern::DOUBLE_DIRECTION) {
        if (meleePatternStep == 0) {
            patternFacingRight = !patternFacingRight;
            facingRight        = patternFacingRight;
            meleeHitDealt      = false;
            attackSpawned      = false;
            forceState(BossState::ATTACK_MELEE);
            meleePatternStep = 1;
        } else if (meleePatternStep == 1) {
            currentMeleePattern = MeleePattern::NONE;
            setState(BossState::IDLE);
        }
    }

    // ----------------------------------------------------------------
    // ПАТТЕРН 3: STRIKE_TELEPORT_RANGE
    // Удар → телепорт НАЗАД от своей позиции → снаряды
    // ----------------------------------------------------------------
    else if (currentMeleePattern == MeleePattern::STRIKE_TELEPORT_RANGE) {
        if (meleePatternStep == 0) {
            // Удар завершился — телепорт назад (от своей позиции, не от игрока!)
            meleePatternStep = 1;
            // Отскакиваем назад на 5 клеток от текущей позиции
            float targetX = x + (-meleeAttackDirX) * cellSize * 5.0f;
            startTeleport(targetX, y);
        } else if (meleePatternStep == 1 && !isTeleporting) {
            // Телепорт завершён — ждём 0.5 сек
            meleePatternStep  = 2;
            meleePatternTimer = 0.5f;
            // Смотрим в сторону первого удара
            facingRight        = (meleeAttackDirX > 0);
            patternFacingRight = facingRight;
            forceState(BossState::IDLE);
        } else if (meleePatternStep == 2 && meleePatternTimer <= 0.0f) {
            // Стреляем снарядами в сторону первого удара
            attackSpawned = false;
            facingRight   = (meleeAttackDirX > 0);
            patternFacingRight = facingRight;
            // Спавним 2 снаряда: обычный + предсказывающий
            spawnProjectile(lastPlayerX, lastPlayerY, false);
            projectileQueue      = 1;
            projectileQueueTimer = 0.3f;
            forceState(BossState::ATTACK_RANGE);
            meleePatternStep = 3;
        } else if (meleePatternStep == 3) {
            // Атака дальнего боя завершилась
            currentMeleePattern = MeleePattern::NONE;
            setState(BossState::IDLE);
        }
    }
}

// ============================================================
// ТЕЛЕПОРТ
// ============================================================

void BossGolem::startTeleport(float targetX, float targetY) {
    isTeleporting   = true;
    teleportTargetY = targetY;

    // Зажимаем в границы карты
    int ox, oy;
    getMapOffset(ox, oy);
    teleportTargetX = std::clamp(targetX,
                                 (float)(ox + cellSize * 2),
                                 (float)(ox + LEVEL1_WIDTH * TILE_SIZE - cellSize * 2));

    // Переключаем на IDLE чтобы не пропадать во время скольжения
    forceState(BossState::IDLE);
}

void BossGolem::updateTeleport(float deltaTime) {
    float dx  = teleportTargetX - x;
    float len = std::abs(dx);

    if (len < 5.0f) {
        x             = teleportTargetX;
        isTeleporting = false;
    } else {
        x += (dx > 0 ? 1.0f : -1.0f) * TELEPORT_SPEED * deltaTime;
    }
}

// ============================================================
// СПАВН АТАК
// ============================================================

void BossGolem::spawnProjectile(float playerX, float playerY, bool predictive) {
    float startX = x + (facingRight ? width/2.0f : -width/2.0f);
    float startY = y;

    float dx  = playerX - startX;
    float dy  = playerY - startY;
    float len = std::sqrt(dx*dx + dy*dy);
    if (len < 1.0f) len = 1.0f;

    Projectile proj;
    proj.x            = startX;
    proj.y            = startY;
    proj.velX         = (dx / len) * PROJECTILE_SPEED;
    proj.velY         = (dy / len) * PROJECTILE_SPEED;
    proj.damage       = (phase == BossPhase::PHASE_2) ? DAMAGE_RANGE_P2 : DAMAGE_RANGE;
    proj.active       = true;
    proj.predictive   = predictive;
    proj.targetX      = playerX;
    proj.targetY      = playerY;
    proj.trackingTime = predictive ? 1.0f : 0.6f;

    projectiles.push_back(proj);
}

void BossGolem::spawnLaser(bool p2) {
    laser.active       = true;
    laser.x            = x + (facingRight ? width/2.0f : -width/2.0f);
    laser.y            = y + height * 0.3f;
    laser.facingRight  = facingRight;
    laser.damagePerSec = DAMAGE_LASER_SEC;
    laser.height       = 20.0f;
    (void)p2; // лазер одинаковый в обеих фазах
}

// ============================================================
// ПРИНУДИТЕЛЬНАЯ СМЕНА СОСТОЯНИЯ
// ============================================================

void BossGolem::forceState(BossState newState) {
    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
    attackSpawned       = false;
    meleeHitDealt       = false;

    if (newState != BossState::LASER) laser.active = false;
    if (animations.count(newState)) animations[newState].reset();
}

// ============================================================
// ПРОВЕРКА УРОНА ПО ИГРОКУ
// ============================================================

float BossGolem::checkPlayerDamage(SDL_Rect playerBox, float deltaTime) {
    // Во время перехода — не наносим урон
    if (phase == BossPhase::DYING ||
        phase == BossPhase::PAUSING ||
        phase == BossPhase::TRANSITIONING) return 0.0f;

    float meleeDmg = (phase == BossPhase::PHASE_2) ? DAMAGE_MELEE_P2 : DAMAGE_MELEE;

    if (currentState == BossState::ATTACK_MELEE && !meleeHitDealt &&
        animations.count(BossState::ATTACK_MELEE) &&
        animations.at(BossState::ATTACK_MELEE).getCurrentFrameIndex() >= 6) {

        int meleeW = (int)(cellSize * 1.0f);
        int meleeH = (int)(height * 0.85f);
        int meleeX = facingRight
                         ? (int)(x + width * 0.1f)
                         : (int)(x - width * 0.1f - meleeW);
        int meleeY = (int)(y - meleeH / 2);

        SDL_Rect meleeBox = {meleeX, meleeY, meleeW, meleeH};
        meleeHitDealt = true;

        if (rectsOverlap(playerBox, meleeBox)) return meleeDmg;
        return 0.0f;
    }

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

    if (laser.active) {
        const int W = Config::getWindowWidth();
        int laserH  = (int)laser.height;
        int laserX  = laser.facingRight ? (int)laser.x : 0;
        int laserW  = laser.facingRight ? W - (int)laser.x : (int)laser.x;
        int laserY  = (int)(laser.y - laserH / 2);

        SDL_Rect laserBox = {laserX, laserY, laserW, laserH};
        if (rectsOverlap(playerBox, laserBox))
            return laser.damagePerSec * deltaTime;
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

bool BossGolem::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

// ============================================================
// TAKEDAMAGE
// ============================================================

void BossGolem::takeDamage(float damage) {
    // Во время перехода — неуязвим
    if (phase == BossPhase::DYING ||
        phase == BossPhase::PAUSING ||
        phase == BossPhase::TRANSITIONING) return;
    if (currentState == BossState::DEATH) return;

    hp -= damage * (1.0f - defense);
    if (hp < 0) hp = 0;

    if (hp <= 0 && phase == BossPhase::PHASE_2) {
        laser.active = false;
        projectiles.clear();
        currentState = BossState::DEATH;
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].reset();
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

    SDL_Rect src = {0, 0, 0, 0};

    if (phase == BossPhase::TRANSITIONING) {
        src = reviveAnim.getCurrentFrame();
    } else if (phase == BossPhase::PAUSING) {
        // Стоим на последнем кадре анимации смерти
        auto it = animations.find(BossState::DEATH);
        if (it == animations.end()) return;
        src = it->second.getCurrentFrame();
    } else if (isTeleporting) {
        // Во время телепорта — IDLE анимация
        auto it = animations.find(BossState::IDLE);
        if (it == animations.end()) return;
        src = it->second.getCurrentFrame();
    } else {
        auto it = animations.find(currentState);
        if (it == animations.end()) return;
        src = it->second.getCurrentFrame();
    }

    int dstW = (int)(src.w * SPRITE_SCALE);
    int dstH = (int)(src.h * SPRITE_SCALE);
    int dstX = (int)(x - dstW / 2);
    int dstY = (int)(y + height/2 - dstH);

    SDL_Rect dst = {dstX, dstY, dstW, dstH};
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    if (phase == BossPhase::PHASE_2)
        SDL_SetTextureColorMod(spritesheet, 255, 150, 150);
    else
        SDL_SetTextureColorMod(spritesheet, 255, 255, 255);

    SDL_RenderCopyEx(renderer, spritesheet, &src, &dst, 0, nullptr, flip);
    SDL_SetTextureColorMod(spritesheet, 255, 255, 255);
}

void BossGolem::renderProjectiles(SDL_Renderer* renderer) {
    for (const auto& proj : projectiles) {
        if (!proj.active) continue;

        if (armTexture) {
            SDL_Rect src = {0, 0, 102, 154};
            constexpr int SIZE = 32;
            SDL_Rect dst = {(int)(proj.x - SIZE/2), (int)(proj.y - SIZE/2), SIZE, SIZE};
            if (proj.predictive)
                SDL_SetTextureColorMod(armTexture, 255, 180, 80);
            else
                SDL_SetTextureColorMod(armTexture, 255, 255, 255);
            SDL_RenderCopy(renderer, armTexture, &src, &dst);
            SDL_SetTextureColorMod(armTexture, 255, 255, 255);
        } else {
            if (proj.predictive)
                SDL_SetRenderDrawColor(renderer, 255, 180, 80, 255);
            else
                SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
            SDL_Rect r = {(int)(proj.x - 12), (int)(proj.y - 12), 24, 24};
            SDL_RenderFillRect(renderer, &r);
        }
    }
}

void BossGolem::renderLaser(SDL_Renderer* renderer) {
    if (!laser.active) return;

    const int W = Config::getWindowWidth();
    int laserH  = (int)laser.height;
    int laserX  = laser.facingRight ? (int)laser.x : 0;
    int laserW  = laser.facingRight ? W - (int)laser.x : (int)laser.x;
    int laserY  = (int)(laser.y - laserH / 2);

    SDL_Rect laserRect = {laserX, laserY, laserW, laserH};

    if (laserTexture) {
        SDL_Rect src = {0, 800, 308, 100};
        SDL_SetTextureColorMod(laserTexture, 255, 255, 255);
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