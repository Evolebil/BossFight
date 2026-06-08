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

    // Вертикальная физика — передаём флаг провала
    applyGravityAndCollisions(deltaTime, platformDropTimer > 0.0f);

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

    // BFS-движение (прыжок, провал, ходьба по пути)
    updateMovement(dt, playerX, playerY);

    // Применяем горизонтальное движение + коллизии
    x += velocityX * dt;
    applyCollisionsX();

    const float distX = std::abs(playerX - x);

    // ── АНИМАЦИЯ ─────────────────────────────────────────────
    if (currentState == ArcherState::SWORD_ATTACK) {
        auto it = animations.find(ArcherState::SWORD_ATTACK);
        if (it != animations.end() && it->second.isFinished())
            setState(ArcherState::IDLE);
        return;
    }

    if (platformDropTimer > 0.0f) return;

    // ── БЛИЖНЯЯ АТАКА ────────────────────────────────────────
    if (distX <= MELEE_RANGE && swordTimer <= 0.0f && isGrounded) {
        meleeHitDealt = false;
        velocityX     = 0.0f;
        forceState(ArcherState::SWORD_ATTACK);
        swordTimer = swordCooldown;
        return;
    }

    // ── АНИМАЦИЯ ДВИЖЕНИЯ ────────────────────────────────────
    if (isGrounded) {
        if (velocityX != 0.0f)
            setState(ArcherState::WALK);
        else if (currentState == ArcherState::WALK)
            setState(ArcherState::IDLE);
    }
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

// ============================================================
// BFS — ВСПОМОГАТЕЛЬНЫЕ
// ============================================================

bool BossArcher::isSolidTile(int col, int row) const {
    if (!g_currentLevel) return false;
    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);
    int px = ox + col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
    int py = oy + row * BFS_TILE_SIZE + BFS_TILE_SIZE - 1; // низ тайла
    return g_currentLevel->isSolid(px, py) ||
           g_currentLevel->isPlatform(px, py);
}


bool BossArcher::isFreeTile(int col, int row) const {
    if (!g_currentLevel) return true;
    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);
    int px = ox + col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
    int py = oy + row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
    return !g_currentLevel->isSolid(px, py);
}

bool BossArcher::canJumpTo(int col, int row, int& landRow) const {
    if (!g_currentLevel) return false;

    for (int r = row - 1; r >= row - 4; r--) {
        if (r < 0) break;
        if (isSolidTile(col, r)) {
            if (r + 1 < row && isFreeTile(col, r + 1)) {
                landRow = r + 1;
                std::cout << "[JUMP FOUND] from=(" << col << "," << row
                          << ") landRow=" << landRow << "\n";  // ← ДОБАВЬ
                return true;
            }
        }
    }
    return false;
}
int BossArcher::findPlatformBelow(int col, int row) const {
    if (!g_currentLevel) return -1;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);
    const int maxRows = g_currentLevel->getMapHeight() / BFS_TILE_SIZE;

    // Идём вниз пока не найдём твёрдый тайл
    for (int r = row + 1; r < maxRows; r++) {
        if (isSolidTile(col, r)) {
            return r - 1;  // стоим на тайле над платформой
        }
    }
    return -1;
}

// ============================================================
// BFS — ПОИСК ПУТИ
// ============================================================

void BossArcher::recalcPath(float playerX, float playerY) {
    path.clear();
    pathIndex = 0;

    if (!g_currentLevel) return;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);
    const int mapCols = g_currentLevel->getMapWidth()  / BFS_TILE_SIZE;
    const int mapRows = g_currentLevel->getMapHeight() / BFS_TILE_SIZE;

    // Переводим позиции в тайлы
    const int startCol = (int)((x       - ox) / BFS_TILE_SIZE);
    const int startRow = (int)((y + HITBOX_H / 2 - oy) / BFS_TILE_SIZE) - 1;
    int goalCol  = (int)((playerX - ox) / BFS_TILE_SIZE);
    int goalRow  = (int)((playerY - oy) / BFS_TILE_SIZE);

    // После вычисления startCol/startRow в recalcPath():
    std::cout << "[BFS] archer x=" << x << " y=" << y << "\n";
    std::cout << "[BFS] floor tile=" << isSolidTile(startCol, startRow + 1) << "\n";
    std::cout << "[BFS] isSolid floor=" << (g_currentLevel ? g_currentLevel->isSolid(
                                                                 ox + startCol * BFS_TILE_SIZE + BFS_TILE_SIZE/2,
                                                                 oy + (startRow+1) * BFS_TILE_SIZE + BFS_TILE_SIZE/2) : -1) << "\n";
    std::cout << "[BFS] isPlatform floor=" << (g_currentLevel ? g_currentLevel->isPlatform(
                                                                    ox + startCol * BFS_TILE_SIZE + BFS_TILE_SIZE/2,
                                                                    oy + (startRow+1) * BFS_TILE_SIZE + BFS_TILE_SIZE/2) : -1) << "\n";

    // Сдвигаем цель вверх пока не найдём свободный тайл
    // (игрок стоит на платформе — его Y-тайл может быть твёрдым)
    while (goalRow > 0 && !isFreeTile(goalCol, goalRow))
        goalRow--;

    // Проверяем границы
    if (startCol < 0 || startCol >= mapCols ||
        startRow < 0 || startRow >= mapRows ||
        goalCol  < 0 || goalCol  >= mapCols ||
        goalRow  < 0 || goalRow  >= mapRows) return;

    // ── СТРУКТУРА УЗЛА BFS ────────────────────────────────────
    struct BFSNode {
        int        col    = 0;
        int        row    = 0;
        int        parent = -1;  ///< Индекс родителя в visited[]
        PathAction action = PathAction::WALK_RIGHT;
    };

    // visited[row * mapCols + col] = индекс в nodes[]  (-1 = не посещён)
    std::vector<int> visited(mapCols * mapRows, -1);
    std::vector<BFSNode> nodes;
    nodes.reserve(512);

    std::queue<int> queue;  // индексы в nodes[]

    // Стартовый узел
    BFSNode start;
    start.col    = startCol;
    start.row    = startRow;
    start.parent = -1;
    nodes.push_back(start);
    visited[startRow * mapCols + startCol] = 0;
    queue.push(0);

    int goalIdx = -1;

    // ── ВОЛНА BFS ─────────────────────────────────────────────
    while (!queue.empty() && (int)nodes.size() < BFS_MAX_TILES) {
        const int idx = queue.front();
        queue.pop();

        const BFSNode& cur = nodes[idx];

        // Достигли цели?
        if (cur.col == goalCol && cur.row == goalRow) {
            goalIdx = idx;
            break;
        }

        // ── СОСЕДИ ───────────────────────────────────────────

        // Лямбда добавляет соседа если он свободен и не посещён
        auto tryAdd = [&](int nc, int nr, PathAction act) {
            if (nc < 0 || nc >= mapCols || nr < 0 || nr >= mapRows) return;
            if (!isFreeTile(nc, nr)) return;
            if (visited[nr * mapCols + nc] != -1) return;

            BFSNode next;
            next.col    = nc;
            next.row    = nr;
            next.parent = idx;
            next.action = act;

            const int newIdx = (int)nodes.size();
            visited[nr * mapCols + nc] = newIdx;
            nodes.push_back(next);
            queue.push(newIdx);
        };

        // 1. Шаг влево/вправо — тайл свободен И под ним есть пол (не висим в воздухе)
        auto canWalk = [&](int nc, int nr) {
            return isFreeTile(nc, nr) && isSolidTile(nc, nr + 1);
        };
        if (canWalk(cur.col - 1, cur.row))
            tryAdd(cur.col - 1, cur.row, PathAction::WALK_LEFT);
        if (canWalk(cur.col + 1, cur.row))
            tryAdd(cur.col + 1, cur.row, PathAction::WALK_RIGHT);

        // 2. Прыжок — проверяем свободное пространство и платформу выше
        {
            int landRow = -1;
            if (canJumpTo(cur.col, cur.row, landRow)) {
                tryAdd(cur.col, landRow, PathAction::JUMP);
            }
        }

        // 3. Провал — ищем ближайшую платформу ниже
        {
            // Провалиться можно только если стоим на платформе
            if (isSolidTile(cur.col, cur.row + 1)) {
                int dropRow = findPlatformBelow(cur.col, cur.row);
                if (dropRow != -1 && dropRow != cur.row) {
                    tryAdd(cur.col, dropRow, PathAction::DROP);
                }
            }
        }
    }

    std::cout << "[BFS] start=(" << startCol << "," << startRow << ")"
              << " goal=(" << goalCol << "," << goalRow << ")"
              << " startFree=" << isFreeTile(startCol, startRow)
              << " startHasFloor=" << isSolidTile(startCol, startRow + 1)
              << " goalFree=" << isFreeTile(goalCol, goalRow)
              << "\n";
    // Цель не найдена
    if (goalIdx == -1) return;

    // ── ВОССТАНАВЛИВАЕМ ПУТЬ (от цели к старту, потом разворачиваем) ──
    std::vector<PathNode> reversed;
    int cur = goalIdx;
    while (cur != -1) {
        const BFSNode& n = nodes[cur];
        PathNode pn;
        pn.col    = n.col;
        pn.row    = n.row;
        pn.action = n.action;
        reversed.push_back(pn);
        cur = n.parent;
    }

    // Разворачиваем — путь идёт от старта к цели
    std::reverse(reversed.begin(), reversed.end());

    // path[0] = старт (сам лучник), path[1] = первый шаг
    path      = reversed;
    pathIndex = 1;  // начинаем с первого шага, не со старта

    std::cout << "[BFS RESULT] start=(" << startCol << "," << startRow
              << ") goal=(" << goalCol << "," << goalRow
              << ") size=" << path.size() << "\n";  // ← ДОБАВЬ
}

// ============================================================
// ДВИЖЕНИЕ — ПРЫЖОК И ПРОВАЛ
// ============================================================

void BossArcher::updateMovement(float dt, float playerX, float playerY) {
    // ── КУЛДАУНЫ ─────────────────────────────────────────────
    if (jumpCooldown > 0.0f) jumpCooldown -= dt;
    if (dropCooldown > 0.0f) dropCooldown -= dt;

    // ── АКТИВНЫЙ ПРОВАЛ — ждём пока не упадём ────────────────
    if (platformDropTimer > 0.0f) {
        platformDropTimer -= dt;
        y += 2.0f;
        // Горизонтально стоим на месте во время провала
        velocityX = 0.0f;
        return;
    }

    // ── ПЕРЕСЧЁТ ПУТИ ────────────────────────────────────────
    bfsTimer -= dt;
    if (bfsTimer <= 0.0f) {
        bfsTimer = BFS_INTERVAL;
        recalcPath(playerX, playerY);
    }

    // Нет пути — просто стоим
    if (path.empty() || pathIndex >= (int)path.size()) {
        velocityX = 0.0f;
        return;
    }

    // ── ТЕКУЩИЙ УЗЕЛ ЦЕЛИ ────────────────────────────────────
    const PathNode& target = path[pathIndex];

    if (!g_currentLevel) return;
    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);

    // Позиция цели в пикселях (центр тайла)
    const float targetX = ox + target.col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;
    const float targetY = oy + target.row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;

    const float distToTarget = std::abs(x - targetX);

    // Достигли текущего узла — переходим к следующему
    if (distToTarget < BFS_REACH_DIST &&
        std::abs(y - targetY) < BFS_TILE_SIZE * 1.5f) {
        pathIndex++;
        return;
    }

    // ── ВЫПОЛНЯЕМ ДЕЙСТВИЕ ───────────────────────────────────
    facingRight = (targetX > x);

    switch (target.action) {

    case PathAction::WALK_LEFT:
    case PathAction::WALK_RIGHT:
        // Просто идём горизонтально
        velocityX = (targetX > x) ? MOVE_SPEED : -MOVE_SPEED;
        break;

    case PathAction::JUMP:
        // Прыгаем только если стоим на земле и кулдаун прошёл
        if (isGrounded && jumpCooldown <= 0.0f) {
            velocityY    = JUMP_VELOCITY;
            isGrounded   = false;
            jumpCooldown = JUMP_COOLDOWN_MAX;
        }
        // Во время прыжка тоже двигаемся горизонтально к цели
        velocityX = (targetX > x) ? MOVE_SPEED : -MOVE_SPEED;
        break;

    case PathAction::DROP:
        // Провалиться через платформу
        if (isGrounded && dropCooldown <= 0.0f) {
            platformDropTimer = DROP_DURATION;
            dropCooldown      = DROP_COOLDOWN;
        }
        break;
    }
}