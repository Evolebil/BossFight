/**
 * @file boss_archer.cpp
 * @brief Реализация босса-лучника
 * @author evol
 * @date 2026-06-03
 *
 * ПОРЯДОК ВЫЗОВОВ В update():
 *   1. Сохранить позицию игрока
 *   2. Тикнуть spawnDelay — пока идёт, только физика
 *   3. Проверить смерть → отдельный путь (только анимация + физика)
 *   4. Тикнуть stateTimer, таймеры кулдаунов
 *   5. checkPhaseTransition() — переход в PHASE_2 при 50% HP
 *   6. Спавн клонов если ещё не заспавнены
 *   7. updateClones() — позиции клонов + стрельба
 *   8. Обновить стрелы (движение + удаление вышедших за карту)
 *   9. updateAI() — движение и ближний бой лучника
 *  10. applyGravityAndCollisions() — вертикальная физика
 *  11. Обновить текущую анимацию
 */
#include "boss_archer.h"
#include "../levels/ilevel.h"

extern ILevel* g_currentLevel;

// ============================================================
// КОНСТРУКТОР
// ============================================================

BossArcher::BossArcher(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
{
    swordCooldown = BASE_SWORD_COOLDOWN / attackSpeedMult;
    shootCooldown = BASE_SHOOT_COOLDOWN / attackSpeedMult;
    swordTimer    = 0.0f;
    shootTimer    = 0.0f;
    loadAnimations();
}

// ============================================================
// ЗАГРУЗКА АНИМАЦИЙ
// ============================================================

void BossArcher::loadAnimations() {
    struct AnimInfo {
        ArcherState state;
        const char* path;
        int         frames;
        float       speed;
        bool        loop;
    };

    static const AnimInfo ANIMS[] = {
                                      { ArcherState::IDLE,         "assets/Samurai_Archer/Idle.png",     FRAMES_IDLE,         ANIM_SPD_IDLE,         true  },
                                      { ArcherState::WALK,         "assets/Samurai_Archer/Run.png",      FRAMES_WALK,         ANIM_SPD_WALK,         true  },
                                      { ArcherState::SWORD_ATTACK, "assets/Samurai_Archer/Attack_1.png", FRAMES_SWORD_ATTACK, ANIM_SPD_SWORD_ATTACK, false },
                                      { ArcherState::SHOOT,        "assets/Samurai_Archer/Shot.png",     FRAMES_SHOOT,        ANIM_SPD_SHOOT,        false },
                                      { ArcherState::CLONE_VOLLEY, "assets/Samurai_Archer/Attack_2.png", FRAMES_CLONE_VOLLEY, ANIM_SPD_CLONE_VOLLEY, false },
                                      { ArcherState::DEATH,        "assets/Samurai_Archer/Dead.png",     FRAMES_DEATH,        ANIM_SPD_DEATH,        false },
                                      };

    arrowTexture = TextureManager::getTexture("assets/Samurai_Archer/Arrow.png");

    for (const auto& info : ANIMS) {
        SDL_Texture* tex = TextureManager::getTexture(info.path);
        if (!tex) {
            std::cout << "[BossArcher] Не загружена текстура: " << info.path << "\n";
            continue;
        }
        Animation anim(info.loop);
        for (int i = 0; i < info.frames; i++)
            anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, info.speed);
        textures[info.state]   = tex;
        animations[info.state] = anim;
    }
}

// ============================================================
// ГЛАВНЫЙ UPDATE
// ============================================================

void BossArcher::update(float deltaTime, float playerX, float playerY,
                        bool /*playerFacingRight*/) {
    lastPlayerX = playerX;
    lastPlayerY = playerY;

    // Задержка после спавна
    if (spawnDelay > 0.0f) {
        spawnDelay -= deltaTime;
        applyGravityAndCollisions(deltaTime);
        return;
    }

    // ── СМЕРТЬ ──────────────────────────────────────────────
    if (hp <= 0) {
        if (currentState != ArcherState::DEATH) {
            phase     = ArcherPhase::DYING;
            velocityX = 0.0f;
            for (auto& clone : clones) clone.active = false;
            for (auto& arrow : arrows) arrow.active = false;
            forceState(ArcherState::DEATH);
        }
        // Физика оставлена намеренно — тело падает на пол после смерти
        applyGravityAndCollisions(deltaTime);
        auto it = animations.find(ArcherState::DEATH);
        if (it != animations.end()) it->second.update(deltaTime);
        return;
    }

    // ── НОРМАЛЬНЫЙ КАД ──────────────────────────────────────

    stateTimer += deltaTime;
    if (swordTimer > 0.0f) swordTimer -= deltaTime;
    if (shootTimer > 0.0f) shootTimer -= deltaTime;

    // Переход в фазу 2 при 50% HP
    checkPhaseTransition();

    // Первый спавн клонов
    if (!clonesSpawned) {
        spawnClones();
        clonesSpawned = true;
    }

    // Обновляем клонов (позиции + стрельба)
    updateClones(deltaTime, playerX, playerY);

    // Обновляем стрелы
    for (auto& arrow : arrows) {
        if (!arrow.active) continue;
        arrow.x += arrow.velX * deltaTime;
        arrow.y += arrow.velY * deltaTime;

        // Убираем стрелы вышедшие за пределы карты
        const float dx = arrow.x - x;
        const float dy = arrow.y - y;
        if (dx*dx + dy*dy > ArcherArrow::SPEED * ArcherArrow::SPEED * 16.0f)
            arrow.active = false;
    }
    arrows.erase(
        std::remove_if(arrows.begin(), arrows.end(),
                       [](const ArcherArrow& a){ return !a.active; }),
        arrows.end());

    // AI — движение и ближний бой
    updateAI(deltaTime, playerX, playerY);

    applyGravityAndCollisions(deltaTime);

    // Анимация текущего состояния
    // SWORD_ATTACK обновляется здесь — updateAI только проверяет isFinished()
    auto it = animations.find(currentState);
    if (it != animations.end()) it->second.update(deltaTime);
}

// ============================================================
// СПАВН КЛОНОВ
// ============================================================

void BossArcher::spawnClones() {
    clones.clear();

    const int total = (phase == ArcherPhase::PHASE_1)
                          ? CLONE_COUNT
                          : CLONE_COUNT_P2;

    for (int i = 0; i < total; i++) {
        const float offset = (i - (total - 1) / 2.0f) * CLONE_SPACING;

        ArcherClone clone;
        clone.x              = x;
        clone.y              = y + offset;
        clone.verticalOffset = offset;  // сохраняем раз и навсегда
        clone.offsetX        = 0.0f;
        clone.active         = true;
        clone.isCenter       = (i == total / 2);

        if (clone.isCenter) {
            clone.dirX = 0.0f;  // пересчитывается в updateClones()
            clone.dirY = 0.0f;
        } else {
            clone.dirX = facingRight ? 1.0f : -1.0f;
            clone.dirY = 0.0f;
        }

        clones.push_back(clone);
    }
}

// ============================================================
// ОБНОВЛЕНИЕ КЛОНОВ
// ============================================================

void BossArcher::updateClones(float dt, float playerX, float playerY) {
    if (clones.empty()) return;

    // Находим центральный клон
    ArcherClone* center = nullptr;
    for (auto& clone : clones) {
        if (clone.isCenter) { center = &clone; break; }
    }
    if (!center) return;

    // Центральный следует за лучником по X
    center->x = x;
    center->y = y + center->verticalOffset;

    // Центральный пересчитывает направление к игроку каждый кадр
    const float cdx = playerX - center->x;
    const float cdy = playerY - center->y;
    const float len = std::sqrt(cdx * cdx + cdy * cdy);
    if (len > 1.0f) {
        center->dirX = cdx / len;
        center->dirY = cdy / len;
    }

    // Боковые клоны — следуют за лучником, сохраняют вертикальное смещение
    for (auto& clone : clones) {
        if (clone.isCenter) continue;

        clone.x = center->x + clone.offsetX;
        clone.y = y + clone.verticalOffset;

        if (phase == ArcherPhase::PHASE_2) {
            // Вертикальный клон (над лучником) — пересчитывает направление к игроку
            if (clone.verticalOffset <= -VERTICAL_CLONE_OFFSET) {
                const float dx   = playerX - clone.x;
                const float dy   = playerY - clone.y;
                const float vlen = std::sqrt(dx * dx + dy * dy);
                if (vlen > 1.0f) {
                    clone.dirX = dx / vlen;
                    clone.dirY = dy / vlen;
                }
            }
            // Диагональный клон — зеркалится по facingRight
            else if (clone.dirY > 0.5f && std::abs(clone.dirX) > 0.5f) {
                clone.dirX = facingRight ? 0.707f : -0.707f;
                clone.dirY = 0.707f;
            }
            // Горизонтальные боковые
            else {
                clone.dirX = facingRight ? 1.0f : -1.0f;
                clone.dirY = 0.0f;
            }
        } else {
            clone.dirX = facingRight ? 1.0f : -1.0f;
            clone.dirY = 0.0f;
        }
    }

    // Стрельба — общий таймер
    cloneShootTimer -= dt;
    if (cloneShootTimer > 0.0f) return;
    cloneShootTimer = CLONE_SHOOT_INTERVAL / attackSpeedMult;

    for (const auto& clone : clones) {
        if (!clone.active) continue;
        if (clone.isCenter && len <= 1.0f) continue;

        ArcherArrow arrow;
        arrow.x      = clone.x;
        arrow.y      = clone.y;
        arrow.velX   = clone.dirX * ArcherArrow::SPEED;
        arrow.velY   = clone.dirY * ArcherArrow::SPEED;
        arrow.active = true;
        arrows.push_back(arrow);
    }
}

// ============================================================
// ПЕРЕХОД В ФАЗУ 2
// ============================================================

void BossArcher::checkPhaseTransition() {
    if (phase != ArcherPhase::PHASE_1) return;
    if (hp > maxHP * 0.5f) return;

    phase = ArcherPhase::PHASE_2;

    // Пересоздаём клонов с новым количеством CLONE_COUNT_P2
    spawnClones();

    // Диагональный клон — 45° вниз, зеркалится по facingRight
    ArcherClone diag;
    diag.x              = x;
    diag.y              = y;
    diag.verticalOffset = 0.0f;
    diag.offsetX        = 0.0f;
    diag.dirX           = facingRight ?  0.707f : -0.707f;
    diag.dirY           = 0.707f;
    diag.active         = true;
    diag.isCenter       = false;
    clones.push_back(diag);

    // Вертикальный клон — над лучником, пересчитывает направление к игроку
    ArcherClone vert;
    vert.x              = x;
    vert.y              = y - VERTICAL_CLONE_OFFSET;
    vert.verticalOffset = -VERTICAL_CLONE_OFFSET;
    vert.offsetX        = 0.0f;
    vert.dirX           = 0.0f;
    vert.dirY           = 1.0f;  // начальное приближение, updateClones обновит
    vert.active         = true;
    vert.isCenter       = false;
    clones.push_back(vert);

    // Сбрасываем таймеры — не мгновенная атака после перехода
    swordTimer      = swordCooldown;
    shootTimer      = shootCooldown;
    cloneShootTimer = CLONE_SHOOT_INTERVAL;
}

// ============================================================
// AI — ДВИЖЕНИЕ И БЛИЖНИЙ БОЙ
// ============================================================

void BossArcher::updateAI(float dt, float playerX, float playerY) {
    if (currentState == ArcherState::DEATH) return;

    const float dx    = playerX - x;
    const float distX = std::abs(dx);
    facingRight = (dx > 0);

    // ── ИДЁТ АНИМАЦИЯ УДАРА — ждём конца ─────────────────────
    if (currentState == ArcherState::SWORD_ATTACK) {
        auto it = animations.find(ArcherState::SWORD_ATTACK);
        if (it != animations.end() && it->second.isFinished())
            setState(ArcherState::WALK);
        return;  // во время атаки не двигаемся
    }

    // ── БЛИЖНЯЯ ДИСТАНЦИЯ — начать атаку ─────────────────────
    if (distX <= MELEE_RANGE && swordTimer <= 0.0f) {
        meleeHitDealt = false;
        velocityX     = 0.0f;
        forceState(ArcherState::SWORD_ATTACK);
        swordTimer = swordCooldown;
        return;
    }

    // ── ПРЕСЛЕДОВАНИЕ ────────────────────────────────────────
    velocityX = (dx > 0) ? MOVE_SPEED : -MOVE_SPEED;
    setState(ArcherState::WALK);

    x += velocityX * dt;
    applyCollisionsX();
}

// ============================================================
// ПРОВЕРКА УРОНА ПО ИГРОКУ
// ============================================================

float BossArcher::checkPlayerDamage(SDL_Rect playerBox, float /*deltaTime*/) {
    if (phase == ArcherPhase::DYING) return 0.0f;

    float total = 0.0f;

    // ── УДАР МЕЧОМ ────────────────────────────────────────────
    if (currentState == ArcherState::SWORD_ATTACK && !meleeHitDealt) {
        auto it = animations.find(ArcherState::SWORD_ATTACK);
        if (it != animations.end() &&
            it->second.getCurrentFrameIndex() >= SWORD_HIT_FRAME) {

            const int hx = facingRight
                               ? (int)(x + width  / 2)
                               : (int)(x - width  / 2 - SWORD_HIT_W);
            const int hy = (int)(y - SWORD_HIT_H / 2);
            SDL_Rect meleeBox = {hx, hy, (int)SWORD_HIT_W, (int)SWORD_HIT_H};

            if (rectsOverlap(playerBox, meleeBox))
                total += SWORD_DAMAGE;

            meleeHitDealt = true;  // кадр обработан — не бить повторно
        }
    }

    // ── СТРЕЛЫ ОТ КЛОНОВ ─────────────────────────────────────
    for (auto& arrow : arrows) {
        if (!arrow.active) continue;

        SDL_Rect arrowBox = {
            (int)(arrow.x - ARROW_HITBOX_W / 2),
            (int)(arrow.y - ARROW_HITBOX_H / 2),
            ARROW_HITBOX_W,
            ARROW_HITBOX_H
        };

        if (rectsOverlap(playerBox, arrowBox)) {
            arrow.active = false;
            total += ArcherArrow::DAMAGE;
        }
    }

    return total;
}

// ============================================================
// ОТРИСОВКА
// ============================================================

void BossArcher::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    const int dstW = (int)(FRAME_W * SPRITE_SCALE);
    const int dstH = (int)(FRAME_H * SPRITE_SCALE);

    // ── КЛОНЫ (рисуем до лучника — под ним) ──────────────────
    auto idleTexIt  = textures.find(ArcherState::IDLE);
    auto idleAnimIt = animations.find(ArcherState::IDLE);

    if (idleTexIt != textures.end() && idleTexIt->second &&
        idleAnimIt != animations.end()) {

        SDL_SetTextureAlphaMod(idleTexIt->second, 120); // полупрозрачные

        for (const auto& clone : clones) {
            if (!clone.active) continue;

            SDL_Rect src = idleAnimIt->second.getCurrentFrame();
            SDL_Rect dst = {
                (int)(clone.x - dstW / 2) - cx,
                (int)(clone.y + HITBOX_H / 2) - dstH - cy,
                dstW, dstH
            };
            SDL_RendererFlip flip = (clone.dirX >= 0)
                                        ? SDL_FLIP_NONE
                                        : SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(renderer, idleTexIt->second,
                             &src, &dst, 0, nullptr, flip);
        }

        SDL_SetTextureAlphaMod(idleTexIt->second, 255); // восстанавливаем
    }

    // ── СТРЕЛЫ ───────────────────────────────────────────────
    for (const auto& arrow : arrows) {
        if (!arrow.active) continue;

        const double angle = std::atan2(arrow.velY, arrow.velX) * 180.0 / M_PI;
        SDL_Rect dst = {
            (int)(arrow.x - ARROW_W / 2) - cx,
            (int)(arrow.y - ARROW_H / 2) - cy,
            ARROW_W, ARROW_H
        };

        if (arrowTexture) {
            SDL_RenderCopyEx(renderer, arrowTexture,
                             nullptr, &dst, angle, nullptr, SDL_FLIP_NONE);
        } else {
            SDL_SetRenderDrawColor(renderer, 200, 160, 80, 255);
            SDL_RenderFillRect(renderer, &dst);
        }
    }

    // ── СПРАЙТ ЛУЧНИКА ───────────────────────────────────────
    auto texIt  = textures.find(currentState);
    auto animIt = animations.find(currentState);

    if (texIt == textures.end() || !texIt->second ||
        animIt == animations.end()) {
        // Заглушка — оранжевый прямоугольник
        SDL_SetRenderDrawColor(renderer, 200, 80, 0, 255);
        SDL_Rect rect = {
            (int)(x - width  / 2) - cx,
            (int)(y - height / 2) - cy,
            (int)width, (int)height
        };
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_Rect src = animIt->second.getCurrentFrame();
        SDL_Rect dst = {
            (int)(x - dstW / 2) - cx,
            (int)(y + height / 2) - dstH - cy,
            dstW, dstH
        };
        SDL_RendererFlip flip = facingRight
                                    ? SDL_FLIP_NONE
                                    : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, texIt->second,
                         &src, &dst, 0, nullptr, flip);
    }

    if (showHitboxes) renderHitboxes(renderer);
}

// ============================================================
// ХИТБОКСЫ (ОТЛАДКА)
// ============================================================

void BossArcher::renderHitboxes(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // СИНИЙ — физический хитбокс лучника
    SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
    SDL_Rect hb       = getHitbox();
    SDL_Rect hbScreen = {hb.x - cx, hb.y - cy, hb.w, hb.h};
    SDL_RenderDrawRect(renderer, &hbScreen);

    // КРАСНЫЙ — хитбокс меча
    if (currentState == ArcherState::SWORD_ATTACK) {
        const int hx = facingRight
                           ? (int)(x + width  / 2)
                           : (int)(x - width  / 2 - SWORD_HIT_W);
        const int hy = (int)(y - SWORD_HIT_H / 2);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect swordBox = {hx - cx, hy - cy, (int)SWORD_HIT_W, (int)SWORD_HIT_H};
        SDL_RenderDrawRect(renderer, &swordBox);
    }

    // ЖЁЛТЫЙ — хитбоксы стрел
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (const auto& arrow : arrows) {
        if (!arrow.active) continue;
        SDL_Rect arrowBox = {
            (int)(arrow.x - ARROW_HITBOX_W / 2) - cx,
            (int)(arrow.y - ARROW_HITBOX_H / 2) - cy,
            ARROW_HITBOX_W, ARROW_HITBOX_H
        };
        SDL_RenderDrawRect(renderer, &arrowBox);
    }

    // ЗЕЛЁНЫЙ — хитбоксы клонов
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (const auto& clone : clones) {
        if (!clone.active) continue;
        SDL_Rect cloneBox = {
            (int)(clone.x - HITBOX_W / 2) - cx,
            (int)(clone.y - HITBOX_H / 2) - cy,
            (int)HITBOX_W, (int)HITBOX_H
        };
        SDL_RenderDrawRect(renderer, &cloneBox);
    }

    // Белая точка — центр лучника
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, (int)x - cx, (int)y - cy);
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ
// ============================================================

SDL_Rect BossArcher::getHitbox() const {
    return {
        (int)(x - width  / 2),
        (int)(y - height / 2),
        (int)width,
        (int)height
    };
}

bool BossArcher::isDeathAnimFinished() const {
    auto it = animations.find(ArcherState::DEATH);
    if (it == animations.end()) return true;
    return it->second.isFinished();
}

// ============================================================
// УПРАВЛЕНИЕ СОСТОЯНИЯМИ
// ============================================================

void BossArcher::setState(ArcherState newState) {
    if (currentState == newState) return;
    if (!canChangeState()) return;
    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
}

void BossArcher::forceState(ArcherState newState) {
    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
    auto it = animations.find(newState);
    if (it != animations.end()) it->second.reset();
}

bool BossArcher::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}