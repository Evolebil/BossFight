/**
 * @file boss_archer.cpp
 * @brief Реализация BossArcher
 * @author evol
 * @date 2026-06-08
 *
 * АРХИТЕКТУРА UPDATE():
 *  1. spawnDelay → только физика
 *  2. Смерть → анимация + физика
 *  3. Регулярный кадр:
 *     - Таймеры
 *     - Проверка фазы 2 (50% HP)
 *     - Спавн/обновление клонов
 *     - Обновление стрел
 *     - updateAI() → прыжки/ходьба через BFS
 *     - Физика (гравитация)
 *     - Анимация
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
    // Кулдауны зависят от множителя скорости
    swordCooldown = BASE_SWORD_COOLDOWN / attackSpeedMult;
    shootCooldown = BASE_SHOOT_COOLDOWN / attackSpeedMult;

    loadAnimations();
}

// ============================================================
// ЗАГРУЗКА АНИМАЦИЙ
// ============================================================

void BossArcher::loadAnimations() {
    // Таблица: состояние → путь к PNG → кол-во кадров → скорость анимации → зацикленность
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

    // Загрузить стрелы отдельно
    arrowTexture = TextureManager::getTexture("assets/Samurai_Archer/Arrow.png");

    // Загрузить все анимации
    for (const auto& info : ANIMS) {
        SDL_Texture* tex = TextureManager::getTexture(info.path);
        if (!tex) {
            std::cerr << "[BossArcher::loadAnimations] ОШИБКА: Не загружена "
                      << info.path << "\n";
            continue;
        }

        // Создать анимацию: все кадры в одной строке (слева направо)
        Animation anim(info.loop);
        for (int i = 0; i < info.frames; i++) {
            anim.addFrame(
                i * FRAME_W,  // srcX = кадр * ширина кадра
                0,            // srcY = всегда верхняя строка
                FRAME_W,
                FRAME_H,
                info.speed
                );
        }

        textures[info.state]   = tex;
        animations[info.state] = anim;
    }
}

// ============================================================
// ГЛАВНЫЙ UPDATE (ПОРЯДОК КРИТИЧЕН!)
// ============================================================

void BossArcher::update(float deltaTime, float playerX, float playerY,
                        bool /*playerFacingRight*/) {
    // 1. ЗАПОМНИТЬ ПОЗИЦИЮ ИГРОКА
    lastPlayerX = playerX;
    lastPlayerY = playerY;

    // 2. ЗАДЕРЖКА СПАВНА
    if (spawnDelay > 0.0f) {
        spawnDelay -= deltaTime;
        applyGravityAndCollisions(deltaTime);
        return;  // ← Выходим, остального нет
    }

    // 3. СМЕРТЬ (ОТДЕЛЬНАЯ ВЕТКА)
    if (hp <= 0) {
        // Первый раз в DEATH?
        if (currentState != ArcherState::DEATH) {
            phase     = ArcherPhase::DYING;
            velocityX = 0.0f;

            // Отключить клонов и стрелы
            for (auto& clone : clones)
                clone.active = false;
            for (auto& arrow : arrows)
                arrow.active = false;

            forceState(ArcherState::DEATH);
        }

        // Продолжить падение (физика)
        applyGravityAndCollisions(deltaTime);

        // Обновить анимацию смерти
        auto it = animations.find(ArcherState::DEATH);
        if (it != animations.end()) {
            it->second.update(deltaTime);
        }
        return;  // ← Выходим
    }

    // 4. РЕГУЛЯРНЫЙ КАДР
    stateTimer += deltaTime;

    if (swordTimer > 0.0f)
        swordTimer -= deltaTime;
    if (shootTimer > 0.0f)
        shootTimer -= deltaTime;

    // 5. ПРОВЕРКА ПЕРЕХОД В ФАЗУ 2 (при 50% HP)
    checkPhaseTransition();

    // 6. ПЕРВЫЙ СПАВН КЛОНОВ
    if (!clonesSpawned) {
        spawnClones();
        clonesSpawned = true;
    }

    // 7. ОБНОВЛЕНИЕ КЛОНОВ (ПОЗИЦИИ + СТРЕЛЬБА)
    updateClones(deltaTime, playerX, playerY);

    // 8. ОБНОВЛЕНИЕ СТРЕЛ (ДВИЖЕНИЕ + ОЧИСТКА НЕАКТИВНЫХ)
    for (auto& arrow : arrows) {
        if (!arrow.active)
            continue;

        // Двигаем стрелу
        arrow.x += arrow.velX * deltaTime;
        arrow.y += arrow.velY * deltaTime;

        // Проверка: вышла ли стрела за пределы разумного расстояния?
        const float dx = arrow.x - x;
        const float dy = arrow.y - y;
        const float distSq = dx * dx + dy * dy;
        const float maxDistSq = ArcherArrow::SPEED * ArcherArrow::SPEED * 16.0f;

        if (distSq > maxDistSq) {
            arrow.active = false;
        }
    }

    // Удалить неактивные стрелы (очистка)
    arrows.erase(
        std::remove_if(arrows.begin(), arrows.end(),
                       [](const ArcherArrow& a) { return !a.active; }),
        arrows.end()
        );

    // 9. AI (ДВИЖЕНИЕ ПО ПУТИ BFS + БЛИЖНИЙ БОЙ)
    updateAI(deltaTime, playerX, playerY);

    // 10. ФИЗИКА (ГРАВИТАЦИЯ + КОЛЛИЗИИ)
    // Передаём флаг: если проваливаемся, то пропустить обычные коллизии по Y
    applyGravityAndCollisions(deltaTime, platformDropTimer > 0.0f);

    // 11. АНИМАЦИЯ (ОБНОВИТЬ ТЕКУЩЕЕ СОСТОЯНИЕ)
    auto it = animations.find(currentState);
    if (it != animations.end()) {
        it->second.update(deltaTime);
    }
}

// ============================================================
// СПАВН КЛОНОВ (ФАЗА 1 И 2)
// ============================================================

void BossArcher::spawnClones() {
    clones.clear();

    // Сколько клонов в текущей фазе?
    const int count = (phase == ArcherPhase::PHASE_1)
                          ? CLONE_COUNT
                          : CLONE_COUNT_P2;

    // Создать вертикальный ряд клонов
    // Они расположены выше и ниже лучника с равным интервалом
    for (int i = 0; i < count; i++) {
        // Смещение: центр = i = count/2
        //   если count=4: i=0,1,2,3 → offset=-1.5, -0.5, +0.5, +1.5
        const float offset = (i - (count - 1) / 2.0f) * CLONE_SPACING;

        ArcherClone clone;
        clone.x              = x;
        clone.y              = y + offset;
        clone.verticalOffset = offset;  // Запоминаем навсегда
        clone.offsetX        = 0.0f;    // Горизонтально не смещаем
        clone.active         = true;
        clone.isCenter       = (i == count / 2);  // Средний клон = центральный

        // Центральный клон следит за игроком (updateClones пересчитает direction)
        // Остальные смотрят в сторону, куда смотрит босс
        if (clone.isCenter) {
            clone.dirX = 0.0f;
            clone.dirY = 0.0f;
        } else {
            clone.dirX = facingRight ? 1.0f : -1.0f;
            clone.dirY = 0.0f;
        }

        clones.push_back(clone);
    }
}

// ============================================================
// ОБНОВЛЕНИЕ КЛОНОВ (КАЖДЫЙ КАДР)
// ============================================================

void BossArcher::updateClones(float dt, float playerX, float playerY) {
    if (clones.empty())
        return;

    // Найти центральный клон
    ArcherClone* center = nullptr;
    for (auto& clone : clones) {
        if (clone.isCenter) {
            center = &clone;
            break;
        }
    }
    if (!center)
        return;

    // ── ЦЕНТРАЛЬНЫЙ КЛОН ──
    // Позиция: следует за лучником по X
    center->x = x;
    center->y = y + center->verticalOffset;

    // Направление: каждый кадр пересчитываем к игроку
    const float cdx = playerX - center->x;
    const float cdy = playerY - center->y;
    const float clen = std::sqrt(cdx * cdx + cdy * cdy);

    if (clen > 1.0f) {
        center->dirX = cdx / clen;
        center->dirY = cdy / clen;
    }

    // ── БОКОВЫЕ КЛОНЫ ──
    for (auto& clone : clones) {
        if (clone.isCenter)
            continue;

        // Позиция: следуют за центром по X, но сохраняют вертикальное смещение
        clone.x = center->x + clone.offsetX;
        clone.y = y + clone.verticalOffset;

        // Направление зависит от фазы
        if (phase == ArcherPhase::PHASE_2) {
            // ФАЗА 2: дополнительные клоны могут менять направление

            // Вертикальный клон (высоко над лучником) — смотрит на игрока вниз
            if (clone.verticalOffset <= -VERTICAL_CLONE_OFFSET) {
                const float dx = playerX - clone.x;
                const float dy = playerY - clone.y;
                const float vlen = std::sqrt(dx * dx + dy * dy);

                if (vlen > 1.0f) {
                    clone.dirX = dx / vlen;
                    clone.dirY = dy / vlen;
                }
            }
            // Диагональный клон — фиксированный угол 45° вниз
            else if (clone.dirY > 0.5f && std::abs(clone.dirX) > 0.5f) {
                clone.dirX = facingRight ? 0.707f : -0.707f;
                clone.dirY = 0.707f;
            }
            // Остальные (горизонтальные) — смотрят в сторону босса
            else {
                clone.dirX = facingRight ? 1.0f : -1.0f;
                clone.dirY = 0.0f;
            }
        } else {
            // ФАЗА 1: все боковые смотрят горизонтально
            clone.dirX = facingRight ? 1.0f : -1.0f;
            clone.dirY = 0.0f;
        }
    }

    // ── СТРЕЛЬБА (ОБЩИЙ ТАЙМЕР ДЛЯ ВСЕХ КЛОНОВ) ──
    cloneShootTimer -= dt;

    if (cloneShootTimer > 0.0f)
        return;  // ← Ещё не время

    // Пересчитать таймер
    cloneShootTimer = CLONE_SHOOT_INTERVAL / attackSpeedMult;

    // Все клоны стреляют
    for (const auto& clone : clones) {
        if (!clone.active)
            continue;

        // Центральный клон не стреляет если игрок совсем рядом
        const float centerDist = std::sqrt(cdx * cdx + cdy * cdy);
        if (clone.isCenter && centerDist <= 1.0f)
            continue;

        // Создать стрелу
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
// ПРОВЕРКА ПЕРЕХОД В ФАЗУ 2 (50% HP)
// ============================================================

void BossArcher::checkPhaseTransition() {
    if (phase != ArcherPhase::PHASE_1)
        return;  // Уже в другой фазе

    if (hp > maxHP * 0.5f)
        return;  // HP ещё больше половины

    // ── ПЕРЕХОД ──
    phase = ArcherPhase::PHASE_2;

    // Пересоздать клонов (теперь CLONE_COUNT_P2 штук)
    spawnClones();

    // Добавить ДИАГОНАЛЬНЫЙ клон (45° вниз-в сторону)
    {
        ArcherClone diag;
        diag.x              = x;
        diag.y              = y;
        diag.verticalOffset = 0.0f;
        diag.offsetX        = 0.0f;
        diag.dirX           = facingRight ? 0.707f : -0.707f;
        diag.dirY           = 0.707f;
        diag.active         = true;
        diag.isCenter       = false;
        clones.push_back(diag);
    }

    // Добавить ВЕРТИКАЛЬНЫЙ клон (высоко над лучником)
    {
        ArcherClone vert;
        vert.x              = x;
        vert.y              = y - VERTICAL_CLONE_OFFSET;
        vert.verticalOffset = -VERTICAL_CLONE_OFFSET;
        vert.offsetX        = 0.0f;
        vert.dirX           = 0.0f;
        vert.dirY           = 1.0f;  // Начальное направление (вниз)
        vert.active         = true;
        vert.isCenter       = false;
        clones.push_back(vert);
    }

    // Сбросить таймеры атак
    swordTimer      = swordCooldown;
    shootTimer      = shootCooldown;
    cloneShootTimer = CLONE_SHOOT_INTERVAL;
}

// ============================================================
// AI — УПРАВЛЕНИЕ И АТАКИ
// ============================================================

void BossArcher::updateAI(float dt, float playerX, float playerY) {
    if (currentState == ArcherState::DEATH)
        return;

    // Движение по BFS пути
    updateMovement(dt, playerX, playerY);

    // Применить горизонтальное движение (velocityX уже установлен в updateMovement)
    x += velocityX * dt;
    applyCollisionsX();  // Коллизии со стенами

    // ── ПРОВЕРКА БЛИЖНЕГО БОЯ ──
    const float distX = std::abs(playerX - x);

    // Если мы ещё замахиваемся мечом — ждём
    if (currentState == ArcherState::SWORD_ATTACK) {
        auto it = animations.find(ArcherState::SWORD_ATTACK);
        if (it != animations.end() && it->second.isFinished()) {
            setState(ArcherState::IDLE);
        }
        return;  // ← Не делаем ничего пока замахиваемся
    }

    // Если проваливаемся через платформу — ничего не делаем
    if (platformDropTimer > 0.0f)
        return;

    // БЛИЖНИЙ БОЙ (если близко, на земле, и кулдаун прошёл)
    if (distX <= MELEE_RANGE && swordTimer <= 0.0f && isGrounded) {
        meleeHitDealt = false;  // Сброс флага: урон ещё не нанесён
        velocityX     = 0.0f;   // Стоп на месте
        forceState(ArcherState::SWORD_ATTACK);
        swordTimer = swordCooldown;
        return;  // ← Не обновляем анимацию движения
    }

    // ── АНИМАЦИЯ ДВИЖЕНИЯ ──
    if (isGrounded) {
        if (velocityX != 0.0f) {
            setState(ArcherState::WALK);
        } else if (currentState == ArcherState::WALK) {
            setState(ArcherState::IDLE);
        }
    }
}

// ============================================================
// ПРОВЕРКА УРОНА (МЕЧ + СТРЕЛЫ)
// ============================================================

float BossArcher::checkPlayerDamage(SDL_Rect playerBox, float /*deltaTime*/) {
    if (phase == ArcherPhase::DYING)
        return 0.0f;

    float totalDamage = 0.0f;

    // ── УДАР МЕЧОМ ──
    if (currentState == ArcherState::SWORD_ATTACK && !meleeHitDealt) {
        auto it = animations.find(ArcherState::SWORD_ATTACK);
        if (it != animations.end()) {
            // Проверить: достаточно ли кадров прошло?
            if (it->second.getCurrentFrameIndex() >= SWORD_HIT_FRAME) {
                // Создать хитбокс меча (зависит от направления)
                const int hx = facingRight
                                   ? (int)(x + width / 2)
                                   : (int)(x - width / 2 - SWORD_HIT_W);
                const int hy = (int)(y - SWORD_HIT_H / 2);

                SDL_Rect meleeBox = {hx, hy, (int)SWORD_HIT_W, (int)SWORD_HIT_H};

                if (rectsOverlap(playerBox, meleeBox)) {
                    totalDamage += SWORD_DAMAGE;
                }

                meleeHitDealt = true;  // ← Больше не наносим урон в этом замахе
            }
        }
    }

    // ── СТРЕЛЫ ──
    for (auto& arrow : arrows) {
        if (!arrow.active)
            continue;

        SDL_Rect arrowBox = {
            (int)(arrow.x - ARROW_HITBOX_W / 2),
            (int)(arrow.y - ARROW_HITBOX_H / 2),
            ARROW_HITBOX_W,
            ARROW_HITBOX_H
        };

        if (rectsOverlap(playerBox, arrowBox)) {
            arrow.active = false;
            totalDamage += ArcherArrow::DAMAGE;
        }
    }

    return totalDamage;
}

// ============================================================
// ОТРИСОВКА
// ============================================================

void BossArcher::render(SDL_Renderer* renderer) {
    if (!renderer)
        return;

    // Получить смещение камеры
    const int camOffsetX = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int camOffsetY = g_camera ? (int)g_camera->getOffsetY() : 0;

    // Размер спрайта на экране
    const int dstW = (int)(FRAME_W * SPRITE_SCALE);
    const int dstH = (int)(FRAME_H * SPRITE_SCALE);

    // ── 1. КЛОНЫ (ПОЛУПРОЗРАЧНЫЕ) ──
    {
        auto idleTexIt  = textures.find(ArcherState::IDLE);
        auto idleAnimIt = animations.find(ArcherState::IDLE);

        if (idleTexIt != textures.end() && idleTexIt->second &&
            idleAnimIt != animations.end()) {

            // Установить прозрачность
            SDL_SetTextureAlphaMod(idleTexIt->second, 120);

            for (const auto& clone : clones) {
                if (!clone.active)
                    continue;

                SDL_Rect src = idleAnimIt->second.getCurrentFrame();
                SDL_Rect dst = {
                    (int)(clone.x - dstW / 2) - camOffsetX,
                    (int)(clone.y + HITBOX_H / 2) - dstH - camOffsetY,
                    dstW, dstH
                };

                SDL_RendererFlip flip = (clone.dirX >= 0)
                                            ? SDL_FLIP_NONE
                                            : SDL_FLIP_HORIZONTAL;

                SDL_RenderCopyEx(renderer, idleTexIt->second,
                                 &src, &dst, 0, nullptr, flip);
            }

            // Восстановить прозрачность
            SDL_SetTextureAlphaMod(idleTexIt->second, 255);
        }
    }

    // ── 2. СТРЕЛЫ ──
    {
        for (const auto& arrow : arrows) {
            if (!arrow.active)
                continue;

            // Угол поворота (от направления движения)
            const double angleRad = std::atan2(arrow.velY, arrow.velX);
            const double angleDeg = angleRad * 180.0 / M_PI;

            SDL_Rect dst = {
                (int)(arrow.x - ARROW_W / 2) - camOffsetX,
                (int)(arrow.y - ARROW_H / 2) - camOffsetY,
                ARROW_W, ARROW_H
            };

            if (arrowTexture) {
                SDL_RenderCopyEx(renderer, arrowTexture,
                                 nullptr, &dst, angleDeg, nullptr, SDL_FLIP_NONE);
            } else {
                // Заглушка — жёлтый прямоугольник
                SDL_SetRenderDrawColor(renderer, 200, 160, 80, 255);
                SDL_RenderFillRect(renderer, &dst);
            }
        }
    }

    // ── 3. БОСС (СПРАЙТ) ──
    {
        auto texIt  = textures.find(currentState);
        auto animIt = animations.find(currentState);

        if (texIt == textures.end() || !texIt->second ||
            animIt == animations.end()) {
            // Заглушка — оранжевый прямоугольник
            SDL_SetRenderDrawColor(renderer, 200, 80, 0, 255);
            SDL_Rect rect = {
                (int)(x - width / 2) - camOffsetX,
                (int)(y - height / 2) - camOffsetY,
                (int)width, (int)height
            };
            SDL_RenderFillRect(renderer, &rect);
        } else {
            SDL_Rect src = animIt->second.getCurrentFrame();
            SDL_Rect dst = {
                (int)(x - dstW / 2) - camOffsetX,
                (int)(y + height / 2) - dstH - camOffsetY,
                dstW, dstH
            };

            SDL_RendererFlip flip = facingRight
                                        ? SDL_FLIP_NONE
                                        : SDL_FLIP_HORIZONTAL;

            SDL_RenderCopyEx(renderer, texIt->second,
                             &src, &dst, 0, nullptr, flip);
        }
    }

    // ── 4. ОТЛАДОЧНЫЕ ХИТБОКСЫ (если включены) ──
    if (showHitboxes) {
        renderHitboxes(renderer);
    }
}

// ============================================================
// ОТЛАДКА — ХИТБОКСЫ
// ============================================================

void BossArcher::renderHitboxes(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // СИНИЙ — физический хитбокс босса
    SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
    SDL_Rect hb = getHitbox();
    SDL_Rect hbScreen = {hb.x - cx, hb.y - cy, hb.w, hb.h};
    SDL_RenderDrawRect(renderer, &hbScreen);

    // КРАСНЫЙ — хитбокс меча (если замахиваемся)
    if (currentState == ArcherState::SWORD_ATTACK) {
        const int hx = facingRight
                           ? (int)(x + width / 2)
                           : (int)(x - width / 2 - SWORD_HIT_W);
        const int hy = (int)(y - SWORD_HIT_H / 2);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect swordBox = {hx - cx, hy - cy, (int)SWORD_HIT_W, (int)SWORD_HIT_H};
        SDL_RenderDrawRect(renderer, &swordBox);
    }

    // ЖЁЛТЫЙ — хитбоксы стрел
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (const auto& arrow : arrows) {
        if (!arrow.active)
            continue;

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
        if (!clone.active)
            continue;

        SDL_Rect cloneBox = {
            (int)(clone.x - HITBOX_W / 2) - cx,
            (int)(clone.y - HITBOX_H / 2) - cy,
            (int)HITBOX_W, (int)HITBOX_H
        };
        SDL_RenderDrawRect(renderer, &cloneBox);
    }

    // Белая точка — центр босса
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, (int)x - cx, (int)y - cy);
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ
// ============================================================

SDL_Rect BossArcher::getHitbox() const {
    return {
        (int)(x - width / 2),
        (int)(y - height / 2),
        (int)width,
        (int)height
    };
}

bool BossArcher::isDeathAnimFinished() const {
    auto it = animations.find(ArcherState::DEATH);
    if (it == animations.end())
        return true;
    return it->second.isFinished();
}

// ============================================================
// УПРАВЛЕНИЕ СОСТОЯНИЯМИ
// ============================================================

void BossArcher::setState(ArcherState newState) {
    if (currentState == newState)
        return;  // Уже в этом состоянии

    if (!canChangeState())
        return;  // Кулдаун смены состояний

    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
}

void BossArcher::forceState(ArcherState newState) {
    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;

    // Сбросить анимацию
    auto it = animations.find(newState);
    if (it != animations.end()) {
        it->second.reset();
    }
}

bool BossArcher::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

// ============================================================
// BFS — ПРОВЕРКА ТАЙЛОВ
// ============================================================

bool BossArcher::isSolidTile(int col, int row) const {
    if (!g_currentLevel)
        return false;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);

    // Позиция в мировых координатах (нижняя часть тайла)
    int px = ox + col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
    int py = oy + row * BFS_TILE_SIZE + BFS_TILE_SIZE - 1;

    // Платформа или стена?
    return g_currentLevel->isSolid(px, py) ||
           g_currentLevel->isPlatform(px, py);
}

bool BossArcher::isFreeTile(int col, int row) const {
    if (!g_currentLevel)
        return true;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);

    // Позиция в мировых координатах (центр тайла)
    int px = ox + col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
    int py = oy + row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;

    // Стена?
    return !g_currentLevel->isSolid(px, py);
}

// ============================================================
// BFS — ПРЫЖОК И ПАДЕНИЕ
// ============================================================

bool BossArcher::canJumpTo(int col, int row, int& outLandRow) const {
    if (!g_currentLevel)
        return false;

    // Ищем платформу выше текущей позиции (на 1-4 тайла выше)
    for (int r = row - 1; r >= row - 4; r--) {
        if (r < 0)
            break;

        // Найдена твёрдая платформа?
        if (isSolidTile(col, r)) {
            // Проверить что место для приземления свободно
            if (r < row && isFreeTile(col, r)) {
                outLandRow = r;  // ← Возвращаем эту строку
                return true;
            }
        }
    }

    return false;
}

int BossArcher::findPlatformBelow(int col, int row) const {
    if (!g_currentLevel)
        return -1;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);
    const int maxRows = g_currentLevel->getMapHeight() / BFS_TILE_SIZE;

    // Ищем вниз пока не найдём твёрдый тайл
    for (int r = row + 1; r < maxRows; r++) {
        if (isSolidTile(col, r)) {
            return r - 1;  // Приземляемся на тайл ДО платформы
        }
    }

    return -1;
}

/**
 * @brief BFS — поиск пути БЕЗ ОГРАНИЧЕНИЙ
 *        Работает даже если:
 *        - Игрок в воздухе
 *        - Игрок внутри стены
 *        - Игрок на платформе
 *        - Игрок где угодно
 *
 * ИДЕЯ: Ищем путь не из центра босса, а из БЛИЖАЙШЕЙ ВАЛИДНОЙ позиции
 */
void BossArcher::recalcPath(float playerX, float playerY) {
    path.clear();
    pathIndex = 0;

    if (!g_currentLevel)
        return;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);
    const int mapCols = g_currentLevel->getMapWidth() / BFS_TILE_SIZE;
    const int mapRows = g_currentLevel->getMapHeight() / BFS_TILE_SIZE;

    // ── ВСПОМОГАТЕЛЬНЫЕ ЛЯМБДЫ ──

    auto isPlatformTile = [this](int col, int row) -> bool {
        if (!g_currentLevel)
            return false;
        int ox, oy;
        g_currentLevel->getMapOffset(ox, oy);
        int px = ox + col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
        int py = oy + row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2;
        return g_currentLevel->isPlatform(px, py);
    };

    auto hasSupport = [this, isPlatformTile](int col, int row) -> bool {
        if (row + 1 < 0) return false;  // Граница карты
        return isSolidTile(col, row + 1) || isPlatformTile(col, row + 1);
    };

    auto isWalkable = [this](int col, int row) -> bool {
        return isFreeTile(col, row);
    };

    // ── КОНВЕРТИРОВАТЬ ПОЗИЦИИ В ТАЙЛЫ ──

    int startCol = (int)((x - ox) / BFS_TILE_SIZE);
    int startRow = (int)((y + HITBOX_H / 2 - oy) / BFS_TILE_SIZE) - 1;

    int goalCol = (int)((playerX - ox) / BFS_TILE_SIZE);
    int goalRow = (int)((playerY + HITBOX_H / 2 - oy) / BFS_TILE_SIZE) - 1;

    // ── ГЛАВНОЕ ОТЛИЧИЕ: Не требуем поддержку в стартовой позиции ──
    // (босс может быть где угодно, мы его спасаем)

    // Если уже на одном тайле — выходим
    if (startCol == goalCol && startRow == goalRow) {
        return;
    }

    // Проверить границы
    if (startCol < 0 || startCol >= mapCols ||
        startRow < 0 || startRow >= mapRows) {
        return;  // Босс за пределами карты — беда
    }

    // ── КЛЮЧЕВОЕ ОТЛИЧИЕ: Обработать цель которая может быть в стене/воздухе ──

    // Если цель в стене — сдвинуть вверх пока не будет свободна
    while (goalRow >= 0 && !isWalkable(goalCol, goalRow)) {
        goalRow--;
    }

    // Если даже сдвинув не нашли — выходим
    if (goalRow < 0 || goalCol < 0 || goalCol >= mapCols || goalRow >= mapRows) {
        return;
    }

    // ── BFS СТРУКТУРЫ ──

    struct BFSNode {
        int        col    = 0;
        int        row    = 0;
        int        parent = -1;
        PathAction action = PathAction::WALK_RIGHT;
    };

    std::vector<int> visited(mapRows * mapCols, -1);
    std::vector<BFSNode> nodes;
    nodes.reserve(512);

    std::queue<int> queue;

    // Добавить стартовый узел
    // ВАЖНО: Стартовый узел НЕ требует поддержки!
    {
        BFSNode start;
        start.col    = startCol;
        start.row    = startRow;
        start.parent = -1;
        start.action = PathAction::WALK_RIGHT;
        nodes.push_back(start);
        visited[startRow * mapCols + startCol] = 0;
        queue.push(0);
    }

    int goalIdx = -1;

    // ── ВОЛНА BFS ──

    while (!queue.empty() && (int)nodes.size() < BFS_MAX_TILES) {
        int idx = queue.front();
        queue.pop();

        const BFSNode& cur = nodes[idx];

        // Достигли цели?
        if (cur.col == goalCol && cur.row == goalRow) {
            goalIdx = idx;
            break;
        }

        // ── ПРОБОВАТЬ СОСЕДЕЙ ──

        auto tryAdd = [&](int nc, int nr, PathAction act) {
            // Границы?
            if (nc < 0 || nc >= mapCols || nr < 0 || nr >= mapRows)
                return;

            // Уже посетили?
            if (visited[nr * mapCols + nc] != -1)
                return;

            // Стена?
            if (!isWalkable(nc, nr))
                return;

            // ── КЛЮЧЕВОЕ ОТЛИЧИЕ: НЕ требуем поддержку для ВСЕХ узлов ──
            // Разрешаем быть в воздухе! Босс упадёт через гравитацию.
            // Но если это не первый шаг — проверяем поддержку
            if (idx != 0) {  // Если не стартовый узел
                if (!hasSupport(nc, nr))
                    return;
            }

            BFSNode next;
            next.col    = nc;
            next.row    = nr;
            next.parent = idx;
            next.action = act;

            int newIdx = (int)nodes.size();
            visited[nr * mapCols + nc] = newIdx;
            nodes.push_back(next);
            queue.push(newIdx);
        };

        // Ходьба влево/вправо
        tryAdd(cur.col - 1, cur.row, PathAction::WALK_LEFT);
        tryAdd(cur.col + 1, cur.row, PathAction::WALK_RIGHT);

        // Прыжок вверх — проверяем что есть место
        {
            int landRow = -1;
            if (canJumpTo(cur.col, cur.row, landRow)) {
                tryAdd(cur.col, landRow, PathAction::JUMP);
            }
        }

        // Провал вниз — проверяем что есть опора
        if (hasSupport(cur.col, cur.row)) {
            int dropRow = findPlatformBelow(cur.col, cur.row);
            if (dropRow != -1 && dropRow != cur.row) {
                tryAdd(cur.col, dropRow, PathAction::DROP);
            }
        }
    }

    // Путь не найден
    if (goalIdx == -1) {
        // Даже если путь не нашли — двигаемся просто к игроку горизонтально
        velocityX = (playerX > x) ? MOVE_SPEED : -MOVE_SPEED;
        facingRight = (playerX > x);
        return;
    }

    // ── ВОССТАНОВИТЬ ПУТЬ ──

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

    std::reverse(reversed.begin(), reversed.end());

    // Установить путь
    path      = reversed;
    pathIndex = (path.size() > 1) ? 1 : 0;
}

// ============================================================
// ДВИЖЕНИЕ — ОБНОВЛЕНИЕ ПОЗИЦИИ И ДЕЙСТВИЙ
// ============================================================

void BossArcher::updateMovement(float dt, float playerX, float playerY) {
    // ── СПАД ТАЙМЕРОВ ──
    if (jumpCooldown > 0.0f)
        jumpCooldown -= dt;
    if (dropCooldown > 0.0f)
        dropCooldown -= dt;

    // ── АКТИВНЫЙ ПРОВАЛ (ЧЕРЕЗ ПЛАТФОРМУ) ──
    if (platformDropTimer > 0.0f) {
        platformDropTimer -= dt;
        y += 2.0f;  // Медленно спускаемся
        velocityX = 0.0f;
        return;
    }

    // ── ПЕРЕСЧЁТ ПУТИ ──
    bfsTimer -= dt;
    if (bfsTimer <= 0.0f) {
        bfsTimer = BFS_INTERVAL;
        recalcPath(playerX, playerY);
    }

    // Нет пути — стоим на месте
    if (path.empty() || pathIndex >= (int)path.size()) {
        velocityX = 0.0f;
        return;
    }

    // ── ТЕКУЩИЙ УЗЕЛ ПУТИ ──
    const PathNode& target = path[pathIndex];

    if (!g_currentLevel)
        return;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);

    // Позиция целевого тайла (центр)
    const float targetX = ox + target.col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;
    const float targetY = oy + target.row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;

    const float distToTarget = std::abs(x - targetX);

    // Достигли узла?
    if (distToTarget < BFS_REACH_DIST &&
        std::abs(y - targetY) < BFS_TILE_SIZE * 1.5f) {
        pathIndex++;
        return;
    }

    // ── НАПРАВЛЕНИЕ И ДЕЙСТВИЕ ──
    facingRight = (targetX > x);

    switch (target.action) {
    case PathAction::WALK_LEFT:
    case PathAction::WALK_RIGHT:
        // Просто идём к целевому тайлу
        velocityX = (targetX > x) ? MOVE_SPEED : -MOVE_SPEED;
        break;

    case PathAction::JUMP:
        // Прыгаем если на земле и кулдаун прошёл
        if (isGrounded && jumpCooldown <= 0.0f) {
            velocityY    = JUMP_VELOCITY;
            isGrounded   = false;
            jumpCooldown = JUMP_COOLDOWN_MAX;
        }
        // И продолжаем двигаться горизонтально
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