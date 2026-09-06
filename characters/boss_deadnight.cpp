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

    // Границы полёта — над крайними точками спавна лучников, с запасом
    int minCol = LEVEL3_MINION_SPAWNS[0].col;
    int maxCol = LEVEL3_MINION_SPAWNS[0].col;
    for (int i = 1; i < Level3::MINION_COUNT; i++) {
        minCol = std::min(minCol, LEVEL3_MINION_SPAWNS[i].col);
        maxCol = std::max(maxCol, LEVEL3_MINION_SPAWNS[i].col);
    }
    flyMinCol = minCol - FLY_RANGE_MARGIN_TILES;
    flyMaxCol = maxCol + FLY_RANGE_MARGIN_TILES;
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
        return; // TODO: анимация смерти + взрывы подключим позже
    }

    if (hp <= 0.0f && currentState != DeadNightState::DEATH) {
        forceState(DeadNightState::DEATH);
        fireballs.clear();
        return;
    }

    updateFireballs(deltaTime);

    switch (currentState) {
    case DeadNightState::FLYING_TOP:
        updateFlyingTop(deltaTime, playerX, playerY);
        break;
    case DeadNightState::DESCENDING:
        updateDescending(deltaTime);
        break;
    case DeadNightState::ASCENDING:
        updateAscending(deltaTime);
        break;
    case DeadNightState::ARENA_IDLE:
    case DeadNightState::DASHING:
    case DeadNightState::MELEE_ATTACK:
    case DeadNightState::RETREATING:
        updateArena(deltaTime, playerX, playerY);
        break;
    default:
        break;
    }
}

// ============================================================
// ВЕРХНЯЯ СТАДИЯ — неуязвим, летает, кидает файрболы
// ============================================================

void BossDeadNight::updateFlyingTop(float deltaTime, float playerX, float playerY) {
    // Полёт влево-вправо, отскок от краёв карты
    x += flyDirX * FLY_SPEED * deltaTime;

    if (g_currentLevel) {
        int ox, oy;
        g_currentLevel->getMapOffset(ox, oy);
        const float minX = ox + flyMinCol * TILE_SIZE;
        const float maxX = ox + flyMaxCol * TILE_SIZE;
        if (x < minX) { x = minX; flyDirX = 1.0f; }
        if (x > maxX) { x = maxX; flyDirX = -1.0f; }
    }
    y = getPhaseTopY(); // держим высоту фиксированной — растёт с фазой

    // Таймер выживания (30 сек) — после него внешняя система может начать спавнить миньонов
    if (!survivalPassed) {
        survivalTimer += deltaTime;
        if (survivalTimer >= SURVIVAL_TIME) survivalPassed = true;
    }

    // Файрболы вниз, независимо от таймера выживания
    fireballTimer -= deltaTime;
    if (fireballTimer <= 0.0f) {
        spawnFireball(playerX, playerY);
        fireballTimer = FIREBALL_COOLDOWN;
    }
}

// ============================================================
// СПУСК / ПОДЪЁМ — реюзаем гравитацию Character для спуска,
// ручной полёт для подъёма (симметрично FLYING_TOP)
// ============================================================

void BossDeadNight::updateDescending(float deltaTime) {
    applyGravityAndCollisions(deltaTime);
    if (isGrounded) {
        dashesDoneInCycle = 0;
        forceState(DeadNightState::ARENA_IDLE);
    }
}

void BossDeadNight::updateAscending(float deltaTime) {
    // phase к этому моменту уже увеличена (см. onPhaseHpThresholdReached) —
    // летим на высоту НОВОЙ фазы
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
    // topY — высота фазы 1 (запомнена при спавне), каждая следующая фаза — на 1 тайл выше
    return topY - (int)phase * TILE_SIZE;
}

// ============================================================
// АРЕНА — ближний бой, циклы рывков
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
    const int phaseIdx = (int)phase; // 0..3

    switch (currentState) {
    case DeadNightState::ARENA_IDLE: {
        dashTimer -= deltaTime;
        if (dashTimer > 0.0f) return;

        if (dashesDoneInCycle >= DASH_COUNT_PER_CYCLE) {
            // Цикл из 3 рывков завершён — отступление
            dashDirX = (playerX > x) ? -1.0f : 1.0f; // отходим ОТ игрока
            forceState(DeadNightState::RETREATING);
            dashTimer = RETREAT_DURATION;
            return;
        }

        // Ближняя дистанция — бьём мечом, иначе рывок к игроку
        const float distX = std::abs(playerX - x);
        if (distX <= HITBOX_W) {
            meleeHitDealt = false;
            forceState(DeadNightState::MELEE_ATTACK);
            dashTimer = 0.4f; // TODO: длительность замаха, подобрать
        } else {
            dashDirX = (playerX > x) ? 1.0f : -1.0f;
            dashHitDealt = false;
            forceState(DeadNightState::DASHING);
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
    Fireball fb;
    fb.x = x;
    fb.y = y;

    // Вектор точно на игрока в момент броска (не самонаводится, как снаряды голема)
    float dx = playerX - x;
    float dy = playerY - y;
    float len = std::sqrt(dx * dx + dy * dy);
    if (len < 1.0f) len = 1.0f;

    // Базовая скорость × сложность (attackSpeedMult, как у остальных боссов)
    // × множитель текущей фазы (ТЗ: ×1.5 за фазу, кумулятивно)
    const float speed = FIREBALL_SPEED * attackSpeedMult * PHASE_FIREBALL_SPEED_MULT[(int)phase];

    fb.velX = (dx / len) * speed;
    fb.velY = (dy / len) * speed;

    fb.active   = true;
    fb.exploded = false;
    fireballs.push_back(fb);
    fireballs.push_back(fb);
}

void BossDeadNight::updateFireballs(float deltaTime) {
    if (!g_currentLevel) return;

    for (auto& fb : fireballs) {
        if (!fb.active) continue;

        if (!fb.exploded) {
            fb.x += fb.velX * deltaTime;
            fb.y += fb.velY * deltaTime;

            // Попадание в пол — взрыв (используем isSolid уровня, как и коллизии игрока)
            if (g_currentLevel->isSolid((int)fb.x, (int)fb.y)) {
                fb.exploded     = true;
                fb.explodeTimer = FIREBALL_EXPLODE_LIFETIME;
            }
        } else {
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

    // --- Файрболы: прямое попадание в полёте ИЛИ радиус взрыва ---
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

    // --- Ближняя атака ---
    if (currentState == DeadNightState::MELEE_ATTACK && !meleeHitDealt) {
        const int hx = facingRight
                           ? (int)(x + width / 2)
                           : (int)(x - width / 2 - MELEE_HIT_W);
        const int hy = (int)(y - MELEE_HIT_H / 2);
        SDL_Rect meleeBox = {hx, hy, (int)MELEE_HIT_W, (int)MELEE_HIT_H};
        if (rectsOverlap(playerBox, meleeBox)) total += DAMAGE_MELEE;
        meleeHitDealt = true;
    }

    // --- Рывок (контакт телом) ---
    if (currentState == DeadNightState::DASHING && !dashHitDealt) {
        if (rectsOverlap(playerBox, getHitbox())) {
            total += DAMAGE_DASH;
            dashHitDealt = true;
        }
    }

    return total;
}

// ============================================================
// TAKE DAMAGE — блокируем урон пока не уязвим, следим за порогами фаз
// ============================================================

void BossDeadNight::takeDamage(float damage) {
    if (!isVulnerable()) return; // наверху / в полёте — неуязвим

    hp -= damage;
    if (hp < 0.0f) hp = 0.0f;

    onPhaseHpThresholdReached();
}

void BossDeadNight::onPhaseHpThresholdReached() {
    const int phaseIdx = (int)phase; // 0..3
    const float threshold = maxHP * PHASE_HP_THRESHOLD[phaseIdx];

    if (hp > threshold) return; // порог ещё не достигнут

    if (phase == DeadNightPhase::PHASE_4) {
        // 0% HP в последней фазе — смерть обрабатывается в update() по hp<=0
        return;
    }

    // Переход в следующую фазу: улетаем наверх
    phase = (DeadNightPhase)((int)phase + 1);
    fireballs.clear();
    forceState(DeadNightState::ASCENDING);
}

// ============================================================
// РЕГИСТРАЦИЯ МИНЬОНОВ (вызывается извне, когда появится система миньонов)
// ============================================================

void BossDeadNight::registerMinionKilled() {
    if (currentState != DeadNightState::FLYING_TOP) return;
    if (minionsKilled >= MINIONS_REQUIRED) return;

    minionsKilled++;
    if (minionsKilled >= MINIONS_REQUIRED) {
        forceState(DeadNightState::DESCENDING);
    }
}

void BossDeadNight::registerMinionReachedDoor() {
    // Миньон просто исчезает, счётчик не трогаем — по ТЗ п.9
}

// ============================================================
// RENDER
// ============================================================

void BossDeadNight::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    renderFireballs(renderer, cx, cy);

    // ЗАГЛУШКА: красный прямоугольник вместо тела
    SDL_SetRenderDrawColor(renderer, 200, 30, 30, 255);
    SDL_Rect rect = {
        (int)(x - width / 2) - cx,
        (int)(y - height / 2) - cy,
        (int)width, (int)height
    };
    SDL_RenderFillRect(renderer, &rect);

    // Полупрозрачная рамка, когда неуязвим — визуальная подсказка
    if (!isVulnerable()) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 150);
        SDL_RenderDrawRect(renderer, &rect);
    }

    if (showHitboxes) renderHitboxes(renderer, cx, cy);
}

void BossDeadNight::renderFireballs(SDL_Renderer* renderer, int camX, int camY) {
    for (const auto& fb : fireballs) {
        if (!fb.active) continue;

        if (!fb.exploded) {
            SDL_SetRenderDrawColor(renderer, 255, 120, 0, 255);
            SDL_Rect r = {
                (int)(fb.x - FIREBALL_HIT_SIZE / 2) - camX,
                (int)(fb.y - FIREBALL_HIT_SIZE / 2) - camY,
                (int)FIREBALL_HIT_SIZE, (int)FIREBALL_HIT_SIZE
            };
            SDL_RenderFillRect(renderer, &r);
        } else {
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(renderer, 255, 80, 0, 160);
            SDL_Rect r = {
                (int)(fb.x - FIREBALL_EXPLODE_RADIUS) - camX,
                (int)(fb.y - FIREBALL_EXPLODE_RADIUS) - camY,
                (int)(FIREBALL_EXPLODE_RADIUS * 2), (int)(FIREBALL_EXPLODE_RADIUS * 2)
            };
            SDL_RenderFillRect(renderer, &r);
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