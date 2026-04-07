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
    isJumping(false),
    jumpVelocityY(0.0f),
    jumpLanded(false),
    isTeleporting(false),
    teleportTargetX(0.0f),
    teleportTargetY(0.0f),
    reviveAnim(false, false),
    defense(0.0f),
    moveSpeed(0),
    cellSize(32),
    attackCooldown(2.2f / attackSpeedMult),
    attackTimer(0),
    blockCooldown(BLOCK_COOLDOWN_P1),
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
    laser({false, 0, 0, true, DAMAGE_LASER_SEC, 80.0f}),
    laserFullyCharged(false),
    rng(std::random_device{}()) {

    cellSize  = Config::getWindowWidth() / 40;
    moveSpeed = 1.3f * cellSize;

    loadAnimations();
    loadAttackTextures();
}

// ============================================================
// ЗАГРУЗКА АНИМАЦИЙ - ИСПРАВЛЕННЫЕ РАЗМЕРЫ И ОТСТУПЫ
// ============================================================

void BossGolem::loadAnimations() {
    spritesheet = TextureManager::getTexture("assets/boss1/Character.png");
    if (!spritesheet)
        spritesheet = TextureManager::getTexture("Character.png");
    if (!spritesheet) return;

    animations[BossState::IDLE] = Animation(true, false);
    for (int i = 0; i < 4; i++)
        animations[BossState::IDLE].addFrame(i*100, 0, 100, 100, 0.2f);

    animations[BossState::WALK] = Animation(true, false);
    for (int i = 0; i < 10; i++)
        animations[BossState::WALK].addFrame(i*100, 600, 100, 100, 0.08f);

    animations[BossState::ATTACK_MELEE] = Animation(false, false);
    for (int i = 0; i < 8; i++)
        animations[BossState::ATTACK_MELEE].addFrame(i*100, 400, 100, 100, 0.1f);

    animations[BossState::ATTACK_RANGE] = Animation(false, false);
    for (int i = 0; i < 7; i++)
        animations[BossState::ATTACK_RANGE].addFrame(i*100, 200, 100, 100, 0.09f);

    animations[BossState::LASER] = Animation(false, false);
    for (int i = 0; i < 7; i++)
        animations[BossState::LASER].addFrame(i*100, 500, 100, 100, 0.13f);

    animations[BossState::BLOCK] = Animation(false, true);
    for (int i = 0; i < 8; i++)
        animations[BossState::BLOCK].addFrame(i*100, 300, 100, 100, 0.1f);

    animations[BossState::HURT] = Animation(false, false);
    for (int i = 0; i < 8; i++)
        animations[BossState::HURT].addFrame(i*100, 100, 100, 100, 0.07f);

    animations[BossState::DEATH] = Animation(false, false);
    for (int i = 0; i < 10; i++)
        animations[BossState::DEATH].addFrame(i*100, 700, 100, 100, 0.1f);
    for (int i = 0; i < 4; i++)
        animations[BossState::DEATH].addFrame(i*100, 800, 100, 100, 0.15f);

    for (int i = 3; i >= 0; i--)
        reviveAnim.addFrame(i*100, 800, 100, 100, 0.12f);
    for (int i = 9; i >= 0; i--)
        reviveAnim.addFrame(i*100, 700, 100, 100, 0.08f);
}

void BossGolem::loadAttackTextures() {
    armTexture = TextureManager::getTexture("assets/boss1/arm.png");
    if (!armTexture) armTexture = TextureManager::getTexture("arm.png");

    laserTexture = TextureManager::getTexture("assets/boss1/Laser.png");
    if (!laserTexture) laserTexture = TextureManager::getTexture("Laser.png");

    projectileAnim = Animation(true, false);
    for (int row = 0; row < 2; row++)
        for (int col = 0; col < 3; col++)
            projectileAnim.addFrame(col * 102, row * 102, 102, 102, 0.18f);

    laserChargeAnim = Animation(false, false);
    for (int i = 0; i < 8; i++)
        laserChargeAnim.addFrame(0, i * 108, 308, 108, 0.07f);

    laserBeamAnim = Animation(true, false);
    for (int i = 0; i < 6; i++)
        laserBeamAnim.addFrame(0, (8 + i) * 108, 308, 108, 0.08f);

    laserFullyCharged = false;
}

// ============================================================
// UPDATE
// ============================================================

void BossGolem::update(float deltaTime, float playerX, float playerY) {
    lastPlayerX = playerX;
    lastPlayerY = playerY;

    if (phase == BossPhase::DYING ||
        phase == BossPhase::PAUSING ||
        phase == BossPhase::TRANSITIONING) {
        updatePhaseTransition(deltaTime);
        applyGravityAndCollisions(deltaTime);
        return;
    }

    if (hp <= 0 && !phase2Triggered && phase == BossPhase::PHASE_1) {
        phase2Triggered = true;
        phase           = BossPhase::DYING;
        phaseTimer      = 0.0f;
        laser.active    = false;
        projectiles.clear();
        groundSpikes.clear();
        currentState = BossState::DEATH;
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].reset();
        applyGravityAndCollisions(deltaTime);
        return;
    }

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

    laser.x           = x + (facingRight ? width/2 : -width/2);
    laser.y           = y;
    laser.facingRight = facingRight;

    // --- Блок (фаза 1) ---
    if (phase == BossPhase::PHASE_1) {
        const float hpPct = hp / maxHP;

        if (currentState == BossState::BLOCK) {
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
        } else if (blockTimer >= BLOCK_COOLDOWN_P1 && hpPct < BLOCK_HP_THRESHOLD) {
            laser.active = false;
            forceState(BossState::BLOCK);
            defense          = 0.5f;
            blockActiveTimer = 0;
            blockTimer       = 0;
        }
    }

    if (isTeleporting) {
        updateTeleport(deltaTime);
        if (animations.count(BossState::IDLE))
            animations[BossState::IDLE].update(deltaTime);
    }

    if (isJumping) {
        updateJump(deltaTime);
    }

    updateSpikes(deltaTime);

    // AI — TELEPORT_LASER полностью замораживает AI (обрабатывается внутри updateAI_Phase2)
    updateAI(deltaTime, playerX, playerY);

    if (!isJumping) {
        applyGravityAndCollisions(deltaTime);
    }

    // Снаряды
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
            bool tracking = (phase == BossPhase::PHASE_1);
            spawnProjectile(lastPlayerX, lastPlayerY, tracking);
            projectileQueue--;
            projectileQueueTimer = 0.35f;
        }
    }

    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(),
                       [](const Projectile& p){ return !p.active; }),
        projectiles.end());

    projectileAnim.update(deltaTime);

    if (laser.active) {
        laserTimer -= deltaTime;

        if (laserTimer <= 0.0f) {
            laser.active = false;
        }

        if (!laserFullyCharged) {
            laserChargeAnim.update(deltaTime);
            if (laserChargeAnim.isFinished())
                laserFullyCharged = true;
        } else {
            laserBeamAnim.update(deltaTime);
        }
    }

    if (!isTeleporting && !isJumping) {
        auto it = animations.find(currentState);
        if (it != animations.end()) it->second.update(deltaTime);
    }

    if (!attackSpawned) {
        if (currentState == BossState::ATTACK_RANGE &&
            animations[BossState::ATTACK_RANGE].getCurrentFrameIndex() >= 3) {
            spawnTwoProjectiles(playerX, playerY,
                                phase == BossPhase::PHASE_1);
            attackSpawned = true;
        }
        if (phase == BossPhase::PHASE_1 &&
            currentState == BossState::LASER &&
            animations[BossState::LASER].getCurrentFrameIndex() >= 2) {
            spawnLaser(false);
            attackSpawned = true;
        }
    }

    const bool patternActive = (phase == BossPhase::PHASE_2 &&
                                currentMeleePattern != MeleePattern::NONE);
    if (!patternActive && !isTeleporting && !isJumping &&
        (currentState == BossState::ATTACK_MELEE ||
         currentState == BossState::ATTACK_RANGE ||
         currentState == BossState::LASER) &&
        animations.count(currentState) &&
        animations[currentState].isFinished()) {

        if (currentState == BossState::LASER) {
            if (!laser.active) {
                setState(BossState::IDLE);
            }
        } else {
            setState(BossState::IDLE);
        }
    }
}

// ============================================================
// ПЕРЕХОД ФАЗА 1 -> ФАЗА 2
// ============================================================

void BossGolem::updatePhaseTransition(float deltaTime) {
    phaseTimer += deltaTime;

    if (phase == BossPhase::DYING) {
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].update(deltaTime);
        if (animations[BossState::DEATH].isFinished()) {
            phase      = BossPhase::PAUSING;
            phaseTimer = 0.0f;
        }
        return;
    }

    if (phase == BossPhase::PAUSING) {
        if (phaseTimer >= PHASE2_PAUSE_DURATION) {
            phase      = BossPhase::TRANSITIONING;
            phaseTimer = 0.0f;
            hp         = maxHP * 0.75f;
            projectiles.clear();
            groundSpikes.clear();
            reviveAnim.reset();
        }
        return;
    }

    if (phase == BossPhase::TRANSITIONING) {
        reviveAnim.update(deltaTime);
        if (reviveAnim.isFinished()) {
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
    if (isJumping) return;

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

    if (attackTimer >= attackCooldown && canChangeState()) {
        attackTimer   = 0;
        attackSpawned = false;
        meleeHitDealt = false;

        const bool playerAbove = (dy < -cellSize * 0.5f);

        if (playerAbove) {
            setState(BossState::ATTACK_RANGE);
            return;
        }

        if (distCells <= RANGE_MELEE) {
            setState(BossState::ATTACK_MELEE);
            return;
        }

        if (distCells <= RANGE_LASER && !playerAbove) {
            setState(BossState::LASER);
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
    // TELEPORT_LASER: AI полностью заморожен — ни движения, ни атак, ни решений
    if (currentMeleePattern == MeleePattern::TELEPORT_LASER) {
        updateMeleePattern(deltaTime);
        return;
    }

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

        if (distCells <= RANGE_MELEE) {
            startMeleePattern(playerX, playerY);
            return;
        }
        setState(BossState::ATTACK_RANGE);
        return;
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
// ПАТТЕРНЫ БЛИЖНЕЙ АТАКИ (ФАЗА 2)
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
    attackSpawned       = false;

    if      (roll == 0) currentMeleePattern = MeleePattern::DASH_STRIKE;
    else if (roll == 1) currentMeleePattern = MeleePattern::JUMP_SLAM;
    else                currentMeleePattern = MeleePattern::TELEPORT_LASER;

    facingRight = patternFacingRight;
    forceState(BossState::ATTACK_MELEE);
}

void BossGolem::updateMeleePattern(float deltaTime) {
    meleePatternTimer -= deltaTime;

    facingRight = patternFacingRight;

    if (currentMeleePattern != MeleePattern::JUMP_SLAM &&
        currentMeleePattern != MeleePattern::TELEPORT_LASER) {
        if (currentState == BossState::ATTACK_MELEE &&
            !animations[BossState::ATTACK_MELEE].isFinished()) return;
        if (currentState == BossState::ATTACK_RANGE &&
            !animations[BossState::ATTACK_RANGE].isFinished()) return;
    } else if (currentMeleePattern != MeleePattern::TELEPORT_LASER) {
        if (currentState == BossState::ATTACK_MELEE &&
            !animations[BossState::ATTACK_MELEE].isFinished()) return;
    }

    if (isTeleporting) return;

    // ----------------------------------------------------------------
    // ПАТТЕРН 1: DASH_STRIKE
    // ----------------------------------------------------------------
    if (currentMeleePattern == MeleePattern::DASH_STRIKE) {
        if (meleePatternStep == 0) {
            meleePatternTimer = 0.2f;
            meleePatternStep  = 1;
            animations[BossState::ATTACK_MELEE].reset();
            currentState = BossState::ATTACK_MELEE;

        } else if (meleePatternStep == 1) {
            if (meleePatternTimer > 0.0f) return;
            dashStrikeVelX     = DASH_STRIKE_SPEED;
            dashStrikeTimer    = DASH_STRIKE_DURATION;
            dashStrikeHitDealt = false;
            facingRight        = true;
            patternFacingRight = true;
            meleePatternStep   = 2;
            animations[BossState::ATTACK_MELEE].reset();
            currentState = BossState::ATTACK_MELEE;

        } else if (meleePatternStep == 2) {
            dashStrikeTimer -= deltaTime;
            x += dashStrikeVelX * deltaTime;
            applyCollisionsX();
            animations[BossState::ATTACK_MELEE].update(deltaTime);
            if (dashStrikeTimer > 0.0f) return;
            meleePatternTimer = 0.08f;
            meleePatternStep  = 3;

        } else if (meleePatternStep == 3) {
            if (meleePatternTimer > 0.0f) return;
            dashStrikeVelX     = -DASH_STRIKE_SPEED;
            dashStrikeTimer    = DASH_STRIKE_DURATION;
            dashStrikeHitDealt = false;
            facingRight        = false;
            patternFacingRight = false;
            meleePatternStep   = 4;
            animations[BossState::ATTACK_MELEE].reset();
            currentState = BossState::ATTACK_MELEE;

        } else if (meleePatternStep == 4) {
            dashStrikeTimer -= deltaTime;
            x += dashStrikeVelX * deltaTime;
            applyCollisionsX();
            animations[BossState::ATTACK_MELEE].update(deltaTime);
            if (dashStrikeTimer > 0.0f) return;
            currentMeleePattern = MeleePattern::NONE;
            setState(BossState::IDLE);
        }
    }

    // ----------------------------------------------------------------
    // ПАТТЕРН 2: JUMP_SLAM
    // ----------------------------------------------------------------
    else if (currentMeleePattern == MeleePattern::JUMP_SLAM) {
        if (meleePatternStep == 0) {
            meleeHitDealt = true;
            auto& anim = animations[BossState::HURT];
            anim.update(deltaTime);
            if (anim.getCurrentFrameIndex() >= 3) {
                meleePatternStep = 1;
                isJumping        = true;
                jumpLanded       = false;
                jumpVelocityY    = JUMP_VELOCITY;
                forceState(BossState::HURT);
                meleeHitDealt    = true;
            }
        } else if (meleePatternStep == 1) {
            if (jumpLanded) {
                meleePatternStep = 2;
                spawnSpikes();
                forceState(BossState::ATTACK_MELEE);
            }
        } else if (meleePatternStep == 2) {
            if (!animations[BossState::ATTACK_MELEE].isFinished()) {
                animations[BossState::ATTACK_MELEE].update(deltaTime);
                return;
            }
            currentMeleePattern = MeleePattern::NONE;
            setState(BossState::IDLE);
        }
    }

    // ----------------------------------------------------------------
    // ПАТТЕРН 3: TELEPORT_LASER
    // ----------------------------------------------------------------
    else if (currentMeleePattern == MeleePattern::TELEPORT_LASER) {
        if (meleePatternStep == 0) {
            // Ждём завершения анимации удара
            if (currentState == BossState::ATTACK_MELEE &&
                !animations[BossState::ATTACK_MELEE].isFinished()) {
                animations[BossState::ATTACK_MELEE].update(deltaTime);
                return;
            }
            meleePatternStep = 1;
            float targetX = x + (-meleeAttackDirX) * cellSize * TELEPORT_P2_CELLS;
            startTeleport(targetX, y);

        } else if (meleePatternStep == 1 && !isTeleporting) {
            // Телепорт завершён — стреляем лазером
            attackSpawned      = false;
            facingRight        = (meleeAttackDirX > 0);
            patternFacingRight = facingRight;
            spawnLaser(true);
            forceState(BossState::LASER);
            meleePatternStep = 2;

        } else if (meleePatternStep == 2) {
            // Ждём конца лазера — AI заморожен всё это время
            // Обновляем только анимацию персонажа
            if (animations.count(BossState::LASER))
                animations[BossState::LASER].update(deltaTime);

            if (!laser.active) {
                velocityX           = 0;          // сброс скорости
                currentMeleePattern = MeleePattern::NONE;
                setState(BossState::IDLE);
                // AI разморозится автоматически — паттерн NONE, TELEPORT_LASER больше не активен
            }
        }
    }
}

// ============================================================
// ПРЫЖОК (JUMP_SLAM)
// ============================================================

void BossGolem::updateJump(float deltaTime) {
    const float GRAVITY_JUMP = 1200.0f;

    jumpVelocityY += GRAVITY_JUMP * deltaTime;
    y += jumpVelocityY * deltaTime;

    int ox, oy;
    getMapOffset(ox, oy);
    const float hw = width / 2.0f;
    const float hh = height / 2.0f;

    int bottomY = (int)(y + hh);
    int checkL  = (int)(x - hw + 4);
    int checkR  = (int)(x + hw - 4);

    if (jumpVelocityY > 0 &&
        (isSolidAt(checkL, bottomY) || isSolidAt(checkR, bottomY))) {
        int row = (bottomY - oy) / TILE_SIZE;
        y = static_cast<float>(oy + row * TILE_SIZE) - hh;
        jumpVelocityY = 0;
        isJumping     = false;
        isGrounded    = true;
        jumpLanded    = true;
    }
}

// ============================================================
// ШИПЫ
// ============================================================

void BossGolem::spawnSpikes() {
    const float areaHalf = SPIKE_AREA_CELLS * TILE_SIZE;
    const int spikeH     = TILE_SIZE;
    const int spikeY     = (int)(y + height/2);

    GroundSpike spike;
    spike.rect = {
        (int)(x - areaHalf),
        spikeY - spikeH,
        (int)(areaHalf * 2),
        spikeH
    };
    spike.damage   = DAMAGE_SPIKE;
    spike.lifetime = SPIKE_LIFETIME;
    spike.active   = true;
    spike.hitDealt = false;

    groundSpikes.push_back(spike);
}

void BossGolem::updateSpikes(float deltaTime) {
    for (auto& s : groundSpikes) {
        if (!s.active) continue;
        s.lifetime -= deltaTime;
        if (s.lifetime <= 0.0f) s.active = false;
    }

    groundSpikes.erase(
        std::remove_if(groundSpikes.begin(), groundSpikes.end(),
                       [](const GroundSpike& s){ return !s.active; }),
        groundSpikes.end());
}

// ============================================================
// ТЕЛЕПОРТ
// ============================================================

void BossGolem::startTeleport(float targetX, float targetY) {
    isTeleporting   = true;
    teleportTargetY = targetY;

    int ox, oy;
    getMapOffset(ox, oy);
    teleportTargetX = std::clamp(targetX,
                                 (float)(ox + cellSize * 2),
                                 (float)(ox + LEVEL1_WIDTH * TILE_SIZE - cellSize * 2));

    forceState(BossState::IDLE);
}

void BossGolem::updateTeleport(float deltaTime) {
    float dx   = teleportTargetX - x;
    float step = TELEPORT_SPEED * deltaTime;

    if (std::abs(dx) <= step) {  // не перелетит за этот кадр
        x             = teleportTargetX;
        isTeleporting = false;
    } else {
        x += (dx > 0 ? 1.0f : -1.0f) * step;
    }
}

// ============================================================
// СПАВН АТАК
// ============================================================

void BossGolem::spawnTwoProjectiles(float playerX, float playerY, bool withTracking) {
    spawnProjectile(playerX, playerY, false);
    spawnProjectile(playerX, playerY, withTracking);
}

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
    proj.trackingTime = predictive ? 1.0f : 0.0f;

    projectiles.push_back(proj);
}

void BossGolem::spawnLaser(bool megaLaser) {
    laser.active       = true;
    laser.x            = x + (facingRight ? width/2.0f : -width/2.0f);
    laser.y            = y + height * 0.3f;
    laser.facingRight  = facingRight;
    laser.damagePerSec = megaLaser ? DAMAGE_MEGA_LASER_SEC : DAMAGE_LASER_SEC;
    laser.height       = megaLaser ? 120.0f : 80.0f;

    laserDuration = megaLaser ? 3.5f : 2.0f;
    laserTimer    = laserDuration;

    laserChargeAnim.reset();
    laserBeamAnim.reset();
    laserFullyCharged = false;
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
        constexpr int PROJ_SIZE = 36;
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

    if (laser.active && laserFullyCharged) {
        const int W = Config::getWindowWidth();
        int laserH  = (int)laser.height;
        int laserX  = laser.facingRight ? (int)laser.x : 0;
        int laserW  = laser.facingRight ? W - (int)laser.x : (int)laser.x;
        int laserY  = (int)(laser.y - laserH / 2);

        SDL_Rect laserBox = {laserX, laserY, laserW, laserH};
        if (rectsOverlap(playerBox, laserBox))
            return laser.damagePerSec * deltaTime;
    }

    for (auto& spike : groundSpikes) {
        if (!spike.active || spike.hitDealt) continue;
        if (rectsOverlap(playerBox, spike.rect)) {
            spike.hitDealt = true;
            return spike.damage;
        }
    }

    if (currentMeleePattern == MeleePattern::DASH_STRIKE &&
        (meleePatternStep == 2 || meleePatternStep == 4) &&
        !dashStrikeHitDealt) {

        constexpr int DASH_HIT_W = 80;
        constexpr int DASH_HIT_H = 80;
        int hx = facingRight ? (int)(x + width * 0.1f)
                             : (int)(x - width * 0.1f - DASH_HIT_W);
        int hy = (int)(y - DASH_HIT_H / 2);
        SDL_Rect dashBox = {hx, hy, DASH_HIT_W, DASH_HIT_H};

        if (rectsOverlap(playerBox, dashBox)) {
            dashStrikeHitDealt = true;
            return DAMAGE_MELEE_P2;
        }
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
    if (phase == BossPhase::DYING ||
        phase == BossPhase::PAUSING ||
        phase == BossPhase::TRANSITIONING) return;
    if (currentState == BossState::DEATH) return;

    hp -= damage * (1.0f - defense);
    if (hp < 0) hp = 0;

    if (hp <= 0 && phase == BossPhase::PHASE_2) {
        laser.active = false;
        projectiles.clear();
        groundSpikes.clear();
        currentState = BossState::DEATH;
        if (animations.count(BossState::DEATH))
            animations[BossState::DEATH].reset();
    }
}

// ============================================================
// RENDER
// ============================================================

void BossGolem::render(SDL_Renderer* renderer) {


    renderSpikes(renderer);
    renderProjectiles(renderer);
    renderLaser(renderer);

    if (!spritesheet) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = {(int)(x - width/2), (int)(y - height/2), (int)width, (int)height};
        SDL_RenderFillRect(renderer, &rect);
        // Для случая без спрайта используем упрощенную версию
        renderHitboxes(renderer, (int)(x - width/2), (int)(y - height/2), (int)width, (int)height);
        return;
    }

    // Получаем текущий кадр анимации
    SDL_Rect src = getCurrentFrame();
    if (src.w == 0 || src.h == 0) return;

    // ДИНАМИЧЕСКИЕ размеры спрайта на основе текущего кадра
    int dstW = (int)(src.w * SPRITE_SCALE);
    int dstH = (int)(src.h * SPRITE_SCALE);
    int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    int cy = g_camera ? (int)g_camera->getOffsetY() : 0;
    int dstX = (int)(x - dstW / 2) - cx;
    int dstY = (int)(y - dstH / 2) + SPRITE_OFFSET_Y - cy;

    SDL_Rect dst = {dstX, dstY, dstW, dstH};
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    if (phase == BossPhase::PHASE_2)
        SDL_SetTextureColorMod(spritesheet, 255, 150, 150);
    else
        SDL_SetTextureColorMod(spritesheet, 255, 255, 255);

    SDL_RenderCopyEx(renderer, spritesheet, &src, &dst, 0, nullptr, flip);
    SDL_SetTextureColorMod(spritesheet, 255, 255, 255);

    // ИСПРАВЛЕНО: передаем динамические размеры спрайта для отрисовки хитбоксов
    renderHitboxes(renderer, dstX, dstY, dstW, dstH);
}

void BossGolem::renderSpikes(SDL_Renderer* renderer) {
    if (groundSpikes.empty()) return;

    SDL_Texture* tileset = TextureManager::getTexture("assets/map1/map1.png");
    SDL_Rect src = {1 * TILE_SOURCE, 14 * TILE_SOURCE, TILE_SOURCE, TILE_SOURCE};

    for (const auto& spike : groundSpikes) {
        if (!spike.active) continue;

        const int tileW    = TILE_SIZE;
        int       numTiles = spike.rect.w / tileW + 1;

        for (int i = 0; i < numTiles; i++) {
            int dstX  = spike.rect.x + i * tileW;
            int drawW = std::min(tileW, spike.rect.x + spike.rect.w - dstX);
            if (drawW <= 0) break;

            SDL_Rect dst = {dstX, spike.rect.y, drawW, tileW};

            if (tileset) {
                if (spike.lifetime < 0.3f) {
                    Uint8 mod = (Uint8)(spike.lifetime / 0.3f * 255);
                    SDL_SetTextureColorMod(tileset, 255, mod, mod);
                } else {
                    SDL_SetTextureColorMod(tileset, 255, 255, 255);
                }
                SDL_RenderCopyEx(renderer, tileset, &src, &dst,
                                 0.0, nullptr, SDL_FLIP_NONE);
                SDL_SetTextureColorMod(tileset, 255, 255, 255);
            } else {
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(renderer, 200, 30, 30, 200);
                SDL_RenderFillRect(renderer, &dst);
            }
        }
    }
}

void BossGolem::renderProjectiles(SDL_Renderer* renderer) {
    if (!armTexture) return;

    SDL_Rect src       = projectileAnim.getCurrentFrame();
    constexpr int SIZE = 80;

    for (const auto& proj : projectiles) {
        if (!proj.active) continue;

        double angle = std::atan2(proj.velY, proj.velX) * 180.0 / M_PI;

        SDL_Rect dst = {
            (int)(proj.x - SIZE / 2),
            (int)(proj.y - SIZE / 2),
            SIZE, SIZE
        };

        if (proj.predictive)
            SDL_SetTextureColorMod(armTexture, 255, 180, 80);
        else
            SDL_SetTextureColorMod(armTexture, 255, 255, 255);

        SDL_RenderCopyEx(renderer, armTexture, &src, &dst,
                         angle, nullptr, SDL_FLIP_NONE);
    }

    SDL_SetTextureColorMod(armTexture, 255, 255, 255);
}

void BossGolem::renderLaser(SDL_Renderer* renderer) {
    if (!laser.active) return;

    const int W      = Config::getWindowWidth();
    const int laserH = (int)laser.height;
    const int laserX = laser.facingRight ? (int)laser.x : 0;
    const int laserW = laser.facingRight ? W - (int)laser.x : (int)laser.x;
    const int laserY = (int)(laser.y - laserH / 2);

    SDL_RendererFlip flip = laser.facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    if (laserTexture) {
        if (!laserFullyCharged) {
            SDL_Rect src = laserChargeAnim.getCurrentFrame();
            constexpr int CHARGE_SIZE = 96;
            SDL_Rect dst = {
                (int)laser.x - CHARGE_SIZE / 2,
                (int)laser.y - CHARGE_SIZE / 2,
                CHARGE_SIZE, CHARGE_SIZE
            };
            SDL_RenderCopyEx(renderer, laserTexture, &src, &dst,
                             0, nullptr, SDL_FLIP_NONE);
        } else {
            SDL_Rect src = laserBeamAnim.getCurrentFrame();
            SDL_Rect dst = {laserX, laserY, laserW, laserH};

            if (phase == BossPhase::PHASE_2)
                SDL_SetTextureColorMod(laserTexture, 255, 80, 80);
            else
                SDL_SetTextureColorMod(laserTexture, 255, 255, 255);

            SDL_RenderCopyEx(renderer, laserTexture, &src, &dst,
                             0, nullptr, flip);
            SDL_SetTextureColorMod(laserTexture, 255, 255, 255);
        }
    } else {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        if (phase == BossPhase::PHASE_2)
            SDL_SetRenderDrawColor(renderer, 255, 80, 80, 200);
        else
            SDL_SetRenderDrawColor(renderer, 50, 150, 255, 200);

        SDL_Rect dst = {laserX, laserY, laserW, laserH};
        SDL_RenderFillRect(renderer, &dst);
    }
}

// Вспомогательный метод для получения текущего кадра
SDL_Rect BossGolem::getCurrentFrame() const {
    if (phase == BossPhase::TRANSITIONING) {
        return reviveAnim.getCurrentFrame();
    } else if (phase == BossPhase::PAUSING) {
        auto it = animations.find(BossState::DEATH);
        if (it != animations.end()) return it->second.getCurrentFrame();
    } else if (isTeleporting) {
        auto it = animations.find(BossState::IDLE);
        if (it != animations.end()) return it->second.getCurrentFrame();
    } else if (currentMeleePattern == MeleePattern::JUMP_SLAM && meleePatternStep == 0) {
        auto it = animations.find(BossState::HURT);
        if (it != animations.end()) return it->second.getCurrentFrame();
    } else {
        auto it = animations.find(currentState);
        if (it != animations.end()) return it->second.getCurrentFrame();
    }
    return {0, 0, 0, 0};
}

// ============================================================
// RENDER HITBOXES - динамическая отрисовка
// ============================================================

void BossGolem::renderHitboxes(SDL_Renderer* renderer, int spriteX, int spriteY, int spriteW, int spriteH) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Границы СПРАЙТА (синий прямоугольник) - динамические
    SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
    SDL_Rect spriteBounds = {spriteX, spriteY, spriteW, spriteH};
    SDL_RenderDrawRect(renderer, &spriteBounds);

    // ХИТБОКС физический (зелёный прямоугольник) - постоянный
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect hitbox = getHitbox();
    SDL_RenderDrawRect(renderer, &hitbox);

    // Хитбокс ближней атаки (красный)
    if (currentState == BossState::ATTACK_MELEE && !meleeHitDealt) {
        int meleeW = (int)(cellSize * 1.0f);
        int meleeH = (int)(height * 0.85f);
        int meleeX = facingRight
                         ? (int)(x + width * 0.1f)
                         : (int)(x - width * 0.1f - meleeW);
        int meleeY = (int)(y - meleeH / 2);

        SDL_Rect meleeBox = {meleeX, meleeY, meleeW, meleeH};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &meleeBox);
    }

    // DASH_STRIKE хитбокс (оранжевый)
    if (currentMeleePattern == MeleePattern::DASH_STRIKE &&
        (meleePatternStep == 2 || meleePatternStep == 4) &&
        !dashStrikeHitDealt) {
        constexpr int DASH_HIT_W = 80;
        constexpr int DASH_HIT_H = 80;
        int hx = facingRight ? (int)(x + width * 0.1f)
                             : (int)(x - width * 0.1f - DASH_HIT_W);
        int hy = (int)(y - DASH_HIT_H / 2);
        SDL_Rect dashBox = {hx, hy, DASH_HIT_W, DASH_HIT_H};
        SDL_SetRenderDrawColor(renderer, 255, 150, 0, 255);
        SDL_RenderDrawRect(renderer, &dashBox);
    }

    // Лазер (жёлтый)
    if (laser.active && laserFullyCharged) {
        const int W = Config::getWindowWidth();
        int laserH  = (int)laser.height;
        int laserX  = laser.facingRight ? (int)laser.x : 0;
        int laserW  = laser.facingRight ? W - (int)laser.x : (int)laser.x;
        int laserY  = (int)(laser.y - laserH / 2);

        SDL_Rect laserBox = {laserX, laserY, laserW, laserH};
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &laserBox);
    }

    // Центр (белая точка)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, (int)x, (int)y);

    // Направление (фиолетовая линия)
    SDL_SetRenderDrawColor(renderer, 200, 0, 255, 255);
    int lineLen = 40;
    int endX = facingRight ? (int)(x + lineLen) : (int)(x - lineLen);
    SDL_RenderDrawLine(renderer, (int)x, (int)y, endX, (int)y);
}