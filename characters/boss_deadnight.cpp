/**
 * @file boss_deadnight.cpp
 * @brief Реализация босса "Смерть Ночи"
 * @author evol
 * @date 2026-09-03
 */
#include "boss_deadnight.h"
#include "../levels/ilevel.h"
#include "../config/config.h"
#include "../levels/level3.h"
extern ILevel* g_currentLevel;

BossDeadNight::BossDeadNight(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
{
    topY = spawnY;
    fireballTimer = FIREBALL_COOLDOWN;

    int minCol = LEVEL3_MINION_SPAWNS[0].col;
    int maxCol = LEVEL3_MINION_SPAWNS[0].col;
    for (int i = 1; i < Level3::MINION_COUNT; i++) {
        minCol = std::min(minCol, LEVEL3_MINION_SPAWNS[i].col);
        maxCol = std::max(maxCol, LEVEL3_MINION_SPAWNS[i].col);
    }
    flyMinCol = minCol - FLY_RANGE_MARGIN_TILES;
    flyMaxCol = maxCol + FLY_RANGE_MARGIN_TILES;

    loadAnimations();
}

// ============================================================
// ЗАГРУЗКА АНИМАЦИЙ
// ============================================================

void BossDeadNight::loadAnimations() {
    texAttacking  = TextureManager::getTexture("assets/boss_3/attacking.png");
    texDeath      = TextureManager::getTexture("assets/boss_3/death.png");
    texIdleFly    = TextureManager::getTexture("assets/boss_3/idle.png");
    texIdleGround = TextureManager::getTexture("assets/boss_3/idle2.png");
    texSkill1     = TextureManager::getTexture("assets/boss_3/skill1.png");
    texProjectile = TextureManager::getTexture("assets/boss_3/projectile.png");
    texExplosion  = TextureManager::getTexture("assets/bomb/Explosion_bomb.png");

    for (int row = 0; row < ATTACKING_FRAMES_Y; row++)
        for (int col = 0; col < ATTACKING_FRAMES_X; col++)
            attackingAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, ATTACKING_FRAME_DUR);

    for (int row = 0; row < DEATH_FRAMES_Y; row++)
        for (int col = 0; col < DEATH_FRAMES_X; col++)
            deathAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, DEATH_FRAME_DUR);

    for (int row = 0; row < IDLE_FLY_FRAMES_Y; row++)
        for (int col = 0; col < IDLE_FLY_FRAMES_X; col++)
            idleFlyAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, IDLE_FLY_FRAME_DUR);

    for (int row = 0; row < IDLE_GROUND_FRAMES_Y; row++)
        for (int col = 0; col < IDLE_GROUND_FRAMES_X; col++)
            idleGroundAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, IDLE_GROUND_FRAME_DUR);

    for (int row = 0; row < SKILL1_FRAMES_Y; row++)
        for (int col = 0; col < SKILL1_FRAMES_X; col++)
            skill1Anim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, SKILL1_BASE_FRAME_DUR);
}

void BossDeadNight::initExplodeAnim(Animation& anim) {
    for (int row = 0; row < EXPLODE_FRAMES_Y; row++)
        for (int col = 0; col < EXPLODE_FRAMES_X; col++)
            anim.addFrame(col * EXPLODE_FRAME_SIZE, row * EXPLODE_FRAME_SIZE,
                          EXPLODE_FRAME_SIZE, EXPLODE_FRAME_SIZE, EXPLODE_FRAME_DUR);
}

// ============================================================
// УПРАВЛЕНИЕ СОСТОЯНИЯМИ
// ============================================================

void BossDeadNight::setState(DeadNightState newState) {
    if (currentState == newState) return;
    if (!canChangeState()) return;
    previousState        = currentState;
    currentState         = newState;
    lastStateChangeTime  = stateTimer;
}

void BossDeadNight::forceState(DeadNightState newState) {
    previousState        = currentState;
    currentState         = newState;
    lastStateChangeTime  = stateTimer;
}

bool BossDeadNight::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

// ============================================================
// ГЛАВНЫЙ UPDATE
// ============================================================

void BossDeadNight::update(float deltaTime, float playerX, float playerY, bool /*playerFacingRight*/) {
    stateTimer += deltaTime;

    if (currentState == DeadNightState::DEATH) {
        deathAnim.update(deltaTime);
        return;
    }

    if (hp <= 0.0f && currentState != DeadNightState::DEATH) {
        forceState(DeadNightState::DEATH);
        deathAnim.reset();
        fireballs.clear();
        return;
    }

    updateFireballs(deltaTime);

    // Анимация файрбола (skill1) — играет поверх idle, пока не закончится
    if (!skill1Anim.isFinished()) {
        skill1Anim.update(deltaTime * attackSpeedMult);
    }

    switch (currentState) {
    case DeadNightState::FLYING_TOP:
        updateFlyingTop(deltaTime, playerX, playerY);
        idleFlyAnim.update(deltaTime);
        break;
    case DeadNightState::DESCENDING:
        updateDescending(deltaTime);
        idleFlyAnim.update(deltaTime);
        break;
    case DeadNightState::ASCENDING:
        updateAscending(deltaTime);
        idleFlyAnim.update(deltaTime);
        break;
    case DeadNightState::DASHING:
        updateArena(deltaTime, playerX, playerY);
        attackingAnim.update(deltaTime);
        break;
    case DeadNightState::ARENA_IDLE:
    case DeadNightState::MELEE_ATTACK:
    case DeadNightState::RETREATING:
        updateArena(deltaTime, playerX, playerY);
        idleGroundAnim.update(deltaTime);
        break;
    default:
        break;
    }
}

// ============================================================
// ВЕРХНЯЯ СТАДИЯ
// ============================================================

void BossDeadNight::updateFlyingTop(float deltaTime, float playerX, float playerY) {
    x += flyDirX * FLY_SPEED * deltaTime;

    if (g_currentLevel) {
        int ox, oy;
        g_currentLevel->getMapOffset(ox, oy);
        const float minX = ox + flyMinCol * TILE_SIZE;
        const float maxX = ox + flyMaxCol * TILE_SIZE;
        if (x < minX) { x = minX; flyDirX = 1.0f; }
        if (x > maxX) { x = maxX; flyDirX = -1.0f; }
    }
    y = getPhaseTopY();

    if (!survivalPassed) {
        survivalTimer += deltaTime;
        if (survivalTimer >= SURVIVAL_TIME) survivalPassed = true;
    }

    fireballTimer -= deltaTime;
    if (fireballTimer <= 0.0f) {
        spawnFireball(playerX, playerY);
        fireballTimer = FIREBALL_COOLDOWN;
    }
}

// ============================================================
// СПУСК / ПОДЪЁМ
// ============================================================

void BossDeadNight::updateDescending(float deltaTime) {
    applyGravityAndCollisions(deltaTime);
    if (isGrounded) {
        dashesDoneInCycle = 0;
        forceState(DeadNightState::ARENA_IDLE);
    }
}

void BossDeadNight::updateAscending(float deltaTime) {
    const float targetY = getPhaseTopY();
    const float dy = targetY - y;
    const float step = ASCEND_SPEED * deltaTime;
    if (std::abs(dy) <= step) {
        y = targetY;
        resetForNextPhaseTop();
        forceState(DeadNightState::FLYING_TOP);
    } else {
        y += (dy > 0 ? 1.0f : -1.0f) * step;
    }
}

void BossDeadNight::resetForNextPhaseTop() {
    survivalTimer   = 0.0f;
    survivalPassed  = false;
    minionsKilled   = 0;
    fireballTimer   = FIREBALL_COOLDOWN;
}

float BossDeadNight::getPhaseTopY() const {
    return topY - (int)phase * TILE_SIZE;
}

// ============================================================
// АРЕНА
// ============================================================

void BossDeadNight::updateArena(float deltaTime, float playerX, float playerY) {
    facingRight = (playerX > x);

    if (currentState == DeadNightState::ARENA_IDLE ||
        currentState == DeadNightState::DASHING     ||
        currentState == DeadNightState::MELEE_ATTACK ||
        currentState == DeadNightState::RETREATING) {
        updateDashCycle(deltaTime, playerX, playerY);
    }

    applyGravityAndCollisions(deltaTime);
}

void BossDeadNight::updateDashCycle(float deltaTime, float playerX, float playerY) {
    const int phaseIdx = (int)phase;

    switch (currentState) {
    case DeadNightState::ARENA_IDLE: {
        dashTimer -= deltaTime;
        if (dashTimer > 0.0f) return;

        if (dashesDoneInCycle >= DASH_COUNT_PER_CYCLE) {
            dashDirX = (playerX > x) ? -1.0f : 1.0f;
            forceState(DeadNightState::RETREATING);
            dashTimer = RETREAT_DURATION;
            return;
        }

        const float distX = std::abs(playerX - x);
        if (distX <= HITBOX_W) {
            meleeHitDealt = false;
            forceState(DeadNightState::MELEE_ATTACK);
            dashTimer = 0.4f;
        } else {
            dashDirX = (playerX > x) ? 1.0f : -1.0f;
            dashHitDealt = false;
            forceState(DeadNightState::DASHING);
            attackingAnim.reset(); // рывок стартует — анимация с начала
            dashTimer = DASH_DURATION;
        }
        break;
    }

    case DeadNightState::DASHING: {
        x += dashDirX * DASH_SPEED * deltaTime;
        applyCollisionsX();
        dashTimer -= deltaTime;
        if (dashTimer <= 0.0f) {
            dashesDoneInCycle++;
            forceState(DeadNightState::ARENA_IDLE);
            dashTimer = DASH_BETWEEN_COOLDOWN;
        }
        break;
    }

    case DeadNightState::MELEE_ATTACK: {
        dashTimer -= deltaTime;
        if (dashTimer <= 0.0f) {
            forceState(DeadNightState::ARENA_IDLE);
            dashTimer = DASH_BETWEEN_COOLDOWN;
        }
        break;
    }

    case DeadNightState::RETREATING: {
        x += dashDirX * RETREAT_SPEED * deltaTime;
        applyCollisionsX();
        dashTimer -= deltaTime;
        if (dashTimer <= 0.0f) {
            dashesDoneInCycle = 0;
            forceState(DeadNightState::ARENA_IDLE);
            dashTimer = RETREAT_WAIT_BY_PHASE[phaseIdx];
        }
        break;
    }

    default:
        break;
    }
}

// ============================================================
// ФАЙРБОЛЫ
// ============================================================

void BossDeadNight::spawnFireball(float playerX, float playerY) {
    skill1Anim.reset(); // анимация каста запускается заново при каждом броске

    Fireball fb;
    fb.x = x;
    fb.y = y;

    float dx = playerX - x;
    float dy = playerY - y;
    float len = std::sqrt(dx * dx + dy * dy);
    if (len < 1.0f) len = 1.0f;

    const float speed = FIREBALL_SPEED * attackSpeedMult;
    fb.velX = (dx / len) * speed;
    fb.velY = (dy / len) * speed;

    fb.active   = true;
    fb.exploded = false;
    fireballs.push_back(fb);
    initExplodeAnim(fireballs.back().explodeAnim);
}

void BossDeadNight::updateFireballs(float deltaTime) {
    if (!g_currentLevel) return;

    for (auto& fb : fireballs) {
        if (!fb.active) continue;

        if (!fb.exploded) {
            fb.x += fb.velX * deltaTime;
            fb.y += fb.velY * deltaTime;

            if (g_currentLevel->isSolid((int)fb.x, (int)fb.y)) {
                fb.exploded     = true;
                fb.explodeTimer = FIREBALL_EXPLODE_LIFETIME;
                fb.explodeAnim.reset();
            }
        } else {
            fb.explodeAnim.update(deltaTime);
            fb.explodeTimer -= deltaTime;
            if (fb.explodeTimer <= 0.0f) fb.active = false;
        }
    }

    fireballs.erase(
        std::remove_if(fireballs.begin(), fireballs.end(),
                       [](const Fireball& f) { return !f.active; }),
        fireballs.end());
}

// ============================================================
// УРОН ПО ИГРОКУ
// ============================================================

float BossDeadNight::checkPlayerDamage(SDL_Rect playerBox, float /*deltaTime*/) {
    float total = 0.0f;

    for (auto& fb : fireballs) {
        if (!fb.active) continue;

        if (!fb.exploded) {
            SDL_Rect fbBox = {
                (int)(fb.x - FIREBALL_HIT_SIZE / 2), (int)(fb.y - FIREBALL_HIT_SIZE / 2),
                (int)FIREBALL_HIT_SIZE, (int)FIREBALL_HIT_SIZE
            };
            if (rectsOverlap(playerBox, fbBox)) {
                fb.exploded     = true;
                fb.explodeTimer = FIREBALL_EXPLODE_LIFETIME;
                fb.explodeAnim.reset();
                total += FIREBALL_DAMAGE;
            }
        } else if (!fb.damageDealt) {
            const float px = playerBox.x + playerBox.w / 2.0f;
            const float py = playerBox.y + playerBox.h / 2.0f;
            const float dx = px - fb.x;
            const float dy = py - fb.y;
            if (dx * dx + dy * dy <= FIREBALL_EXPLODE_RADIUS * FIREBALL_EXPLODE_RADIUS) {
                total += FIREBALL_DAMAGE;
                fb.damageDealt = true;
            }
        }
    }

    if (currentState == DeadNightState::MELEE_ATTACK && !meleeHitDealt) {
        const int hx = facingRight
                           ? (int)(x + width / 2)
                           : (int)(x - width / 2 - MELEE_HIT_W);
        const int hy = (int)(y - MELEE_HIT_H / 2);
        SDL_Rect meleeBox = {hx, hy, (int)MELEE_HIT_W, (int)MELEE_HIT_H};
        if (rectsOverlap(playerBox, meleeBox)) total += DAMAGE_MELEE;
        meleeHitDealt = true;
    }

    if (currentState == DeadNightState::DASHING && !dashHitDealt) {
        if (rectsOverlap(playerBox, getHitbox())) {
            total += DAMAGE_DASH;
            dashHitDealt = true;
        }
    }

    return total;
}

// ============================================================
// TAKE DAMAGE
// ============================================================

void BossDeadNight::takeDamage(float damage) {
    if (!isVulnerable()) return;

    hp -= damage;
    if (hp < 0.0f) hp = 0.0f;

    onPhaseHpThresholdReached();
}

void BossDeadNight::onPhaseHpThresholdReached() {
    const int phaseIdx = (int)phase;
    const float threshold = maxHP * PHASE_HP_THRESHOLD[phaseIdx];

    if (hp > threshold) return;

    if (phase == DeadNightPhase::PHASE_4) return;

    phase = (DeadNightPhase)((int)phase + 1);
    fireballs.clear();
    forceState(DeadNightState::ASCENDING);
}

// ============================================================
// РЕГИСТРАЦИЯ МИНЬОНОВ
// ============================================================

void BossDeadNight::registerMinionKilled() {
    if (currentState != DeadNightState::FLYING_TOP) return;
    if (minionsKilled >= MINIONS_REQUIRED) return;

    minionsKilled++;
    if (minionsKilled >= MINIONS_REQUIRED) {
        forceState(DeadNightState::DESCENDING);
    }
}

void BossDeadNight::registerMinionReachedDoor() {}

// ============================================================
// RENDER
// ============================================================

void BossDeadNight::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    renderFireballs(renderer, cx, cy);

    // Выбор текущего кадра/текстуры под реальное состояние
    SDL_Texture* tex = texIdleFly;
    SDL_Rect src = idleFlyAnim.getCurrentFrame();

    if (currentState == DeadNightState::DEATH) {
        tex = texDeath;
        src = deathAnim.getCurrentFrame();
    } else if (!skill1Anim.isFinished() && currentState == DeadNightState::FLYING_TOP) {
        // Файрбол-каст перекрывает обычный полёт, пока анимация не доиграна
        tex = texSkill1;
        src = skill1Anim.getCurrentFrame();
    } else if (currentState == DeadNightState::DASHING) {
        tex = texAttacking;
        src = attackingAnim.getCurrentFrame();
    } else if (currentState == DeadNightState::ARENA_IDLE ||
               currentState == DeadNightState::MELEE_ATTACK ||
               currentState == DeadNightState::RETREATING) {
        tex = texIdleGround;
        src = idleGroundAnim.getCurrentFrame();
    } else {
        // FLYING_TOP (без каста), DESCENDING, ASCENDING — летит
        tex = texIdleFly;
        src = idleFlyAnim.getCurrentFrame();
    }

    SDL_Rect dst = {
        (int)(x - width / 2) - cx,
        (int)(y - height / 2) - cy,
        (int)width, (int)height
    };

    if (tex) {
        SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, tex, &src, &dst, 0, nullptr, flip);
    } else {
        SDL_SetRenderDrawColor(renderer, 200, 30, 30, 255);
        SDL_RenderFillRect(renderer, &dst);
    }

    if (!isVulnerable()) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 150);
        SDL_RenderDrawRect(renderer, &dst);
    }

    if (showHitboxes) renderHitboxes(renderer, cx, cy);
}

void BossDeadNight::renderFireballs(SDL_Renderer* renderer, int camX, int camY) {
    for (const auto& fb : fireballs) {
        if (!fb.active) continue;

        if (!fb.exploded) {
            if (texProjectile) {
                const double angle = std::atan2(fb.velY, fb.velX) * 180.0 / M_PI;
                SDL_Rect dst = {
                    (int)(fb.x - FIREBALL_SPRITE_W / 2) - camX,
                    (int)(fb.y - FIREBALL_SPRITE_H / 2) - camY,
                    (int)FIREBALL_SPRITE_W, (int)FIREBALL_SPRITE_H
                };
                SDL_RenderCopyEx(renderer, texProjectile, nullptr, &dst, angle, nullptr, SDL_FLIP_NONE);
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 120, 0, 255);
                SDL_Rect r = {
                    (int)(fb.x - FIREBALL_HIT_SIZE / 2) - camX,
                    (int)(fb.y - FIREBALL_HIT_SIZE / 2) - camY,
                    (int)FIREBALL_HIT_SIZE, (int)FIREBALL_HIT_SIZE
                };
                SDL_RenderFillRect(renderer, &r);
            }
        } else {
            SDL_Rect src = fb.explodeAnim.getCurrentFrame();
            SDL_Rect dst = {
                (int)(fb.x - EXPLODE_FRAME_SIZE / 2) - camX,
                (int)(fb.y - EXPLODE_FRAME_SIZE / 2) - camY,
                EXPLODE_FRAME_SIZE, EXPLODE_FRAME_SIZE
            };
            if (texExplosion) {
                SDL_RenderCopy(renderer, texExplosion, &src, &dst);
            } else {
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(renderer, 255, 80, 0, 160);
                SDL_RenderFillRect(renderer, &dst);
            }
        }
    }
}

void BossDeadNight::renderHitboxes(SDL_Renderer* renderer, int camX, int camY) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect hb = getHitbox();
    SDL_Rect hbScreen = {hb.x - camX, hb.y - camY, hb.w, hb.h};
    SDL_RenderDrawRect(renderer, &hbScreen);

    if (currentState == DeadNightState::MELEE_ATTACK) {
        const int hx = facingRight
                           ? (int)(x + width / 2)
                           : (int)(x - width / 2 - MELEE_HIT_W);
        const int hy = (int)(y - MELEE_HIT_H / 2);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect meleeBox = {hx - camX, hy - camY, (int)MELEE_HIT_W, (int)MELEE_HIT_H};
        SDL_RenderDrawRect(renderer, &meleeBox);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, (int)x - camX, (int)y - camY);
}