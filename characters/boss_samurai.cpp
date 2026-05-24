/**
 * @file boss_samurai.cpp
 * @brief Реализация босса-самурая
 * @author evol
 * @date 2026-05-20
 *
 * ПОРЯДОК ВЫЗОВОВ В update():
 *   1. Сохранить позицию игрока
 *   2. Проверить смерть → отдельный путь (только анимация + физика)
 *   3. Тикнуть stateTimer и jumpCooldown
 *   4. updateMovement() — физика и движение
 *   5. updateAI()       — выбор атаки (тикает кулдауны телепорта/бомб)
 *   6. swordTimer тикает независимо
 *   7. updateStance()   — таймаут стойки → автостан
 *   8. updateBombs()    — физика бомб + взрывы (БЫЛО ПРОПУЩЕНО — добавлено)
 *   9. updateSmoke()    — частицы дыма
 *  10. applyGravityAndCollisions() — физика вертикальная
 *  11. Обновить текущую анимацию
 */
#include "boss_samurai.h"

// ============================================================
// КОНСТРУКТОР
// ============================================================

BossSamurai::BossSamurai(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
{
    loadAnimations();
}

// ============================================================
// ЗАГРУЗКА АНИМАЦИЙ
// ============================================================

void BossSamurai::loadAnimations() {
    // Таблица — состояние, путь к PNG, количество кадров, скорость, зациклена ли
    struct AnimInfo {
        SamuraiState state;
        const char*  path;
        int          frames;
        float        speed;
        bool         loop;
    };

    static const AnimInfo ANIMS[] = {
                                      { SamuraiState::IDLE,         "assets/Samurai/Idle.png",       FRAMES_IDLE,         ANIM_SPD_IDLE,         true  },
                                      { SamuraiState::WALK,         "assets/Samurai/Run.png",        FRAMES_WALK,         ANIM_SPD_WALK,         true  },
                                      { SamuraiState::JUMP,         "assets/Samurai/Jump.png",       FRAMES_JUMP,         ANIM_SPD_JUMP,         false },
                                      { SamuraiState::TELEPORT,     "assets/Samurai/Run.png",        FRAMES_WALK,         ANIM_SPD_WALK,         true  },
                                      { SamuraiState::SWORD_ATTACK, "assets/Samurai/Attack_1.png",   FRAMES_SWORD_ATTACK, ANIM_SPD_SWORD_ATTACK, false },
                                      { SamuraiState::THROW_BOMBS,  "assets/Samurai/Attack_2.png",   FRAMES_THROW_BOMBS,  ANIM_SPD_THROW_BOMBS,  false },
                                      { SamuraiState::POWER_ATTACK, "assets/Samurai/Attack_3.png",   FRAMES_POWER_ATTACK, ANIM_SPD_POWER_ATTACK, false },
                                      { SamuraiState::STANCE,       "assets/Samurai/Protection.png", FRAMES_STANCE,       ANIM_SPD_STANCE,       true  },
                                      { SamuraiState::STUNNED,      "assets/Samurai/Hurt.png",       FRAMES_STUNNED,      ANIM_SPD_STUNNED,      false },
                                      { SamuraiState::DEATH,        "assets/Samurai/Dead.png",       FRAMES_DEATH,        ANIM_SPD_DEATH,        false },
                                      };

    // Загружаем текстуры и анимации для каждого состояния
    for (const auto& info : ANIMS) {
        SDL_Texture* tex = TextureManager::getTexture(info.path);
        Animation    anim(info.loop);

        // Все кадры в одну строку горизонтально (стандартный формат спрайтшита)
        for (int i = 0; i < info.frames; i++)
            anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, info.speed);

        textures[info.state]   = tex;
        animations[info.state] = anim;
    }

    // Текстура и анимация летящей бомбы (один горизонтальный ряд)
    bombTexture = TextureManager::getTexture("assets/bomb/bomb.png");
    for (int i = 0; i < BOMB_FRAMES; i++)
        bombAnim.addFrame(i * BOMB_FRAME_W, 0, BOMB_FRAME_W, BOMB_FRAME_H, BOMB_ANIM_SPEED);

    // Текстура и анимация взрыва (сетка EXPLODE_COLS × EXPLODE_COLS)
    explodeTexture = TextureManager::getTexture("assets/bomb/Explosion_bomb.png");
    for (int row = 0; row < EXPLODE_COLS; row++)
        for (int col = 0; col < EXPLODE_COLS; col++)
            explodeAnim.addFrame(
                col * EXPLODE_FRAME_W, row * EXPLODE_FRAME_H,
                EXPLODE_FRAME_W, EXPLODE_FRAME_H,
                EXPLODE_ANIM_SPEED);
}

// ============================================================
// ГЛАВНЫЙ UPDATE
// ============================================================

void BossSamurai::update(float deltaTime, float playerX, float playerY) {
    // Сохраняем позицию игрока — нужна для атак (телепорт, бомбы)
    lastPlayerX = playerX;
    lastPlayerY = playerY;

    // ── СМЕРТЬ ──────────────────────────────────────────────
    // HP кончились — запускаем анимацию смерти, AI выключаем
    if (hp <= 0 && phase == SamuraiPhase::PHASE_1) {
        if (currentState != SamuraiState::DEATH) {
            phase        = SamuraiPhase::DYING;
            velocityX    = 0.0f;
            stanceActive = false;
            smokeParticles.clear();
            forceState(SamuraiState::DEATH);
            animations[SamuraiState::DEATH].reset();
        }
        // Продолжаем физику и анимацию (тело падает на пол)
        applyGravityAndCollisions(deltaTime);
        auto it = animations.find(SamuraiState::DEATH);
        if (it != animations.end())
            it->second.update(deltaTime);
        return;
    }

    // ── НОРМАЛЬНЫЙ КАД ──────────────────────────────────────

    // Глобальный таймер — используется для cooldown смены состояний
    stateTimer += deltaTime;

    // Кулдаун прыжка
    if (jumpCooldown > 0.0f) jumpCooldown -= deltaTime;

    // Движение (горизонталь, прыжок, провал через платформу)
    updateMovement(deltaTime, playerX, playerY);

    // AI — выбор атаки по дистанции (тикает кулдауны телепорта/бомб)
    updateAI(deltaTime, playerX, playerY);

    // Кулдаун удара меча тикает независимо от AI
    if (swordTimer > 0.0f) swordTimer -= deltaTime;

    // Стойка — отслеживаем таймаут
    updateStance(deltaTime);

    // Бомбы — физика полёта и взрывы
    // ИСПРАВЛЕНО: метод был описан в .h но не вызывался —
    //             бомбы летели вечно и никогда не взрывались
    updateBombs(deltaTime);

    // Частицы дыма — движение и угасание
    updateSmoke(deltaTime);

    // Вертикальная физика + коллизии
    // platformDropTimer > 0 → отключаем коллизии с платформами (провал вниз)
    applyGravityAndCollisions(deltaTime, platformDropTimer > 0.0f);

    // Анимация текущего состояния
    // Исключение: SWORD_ATTACK обновляется в updateMeleeFallback()
    // чтобы синхронизировать с проверкой isFinished()
    auto it = animations.find(currentState);
    if (it != animations.end())
        it->second.update(deltaTime);
}

// ============================================================
// ДВИЖЕНИЕ
// ============================================================

void BossSamurai::updateMovement(float deltaTime, float playerX, float playerY) {

    // ── ОГЛУШЕНИЕ ────────────────────────────────────────────
    if (currentState == SamuraiState::STUNNED) {
        velocityX  = 0.0f;
        stunTimer -= deltaTime;
        if (stunTimer <= 0.0f)
            forceState(SamuraiState::IDLE);
        return;
    }

    // Вектор до игрока и дистанция
    const float dx   = playerX - x;
    const float dy   = playerY - y;
    const float dist = std::sqrt(dx*dx + dy*dy);

    // Самурай всегда смотрит на игрока
    facingRight = (dx > 0);

    // ── ПРЫЖОК ───────────────────────────────────────────────
    // Условие: игрок выше (dy < 0), самурай на земле, кулдаун прошёл
    // Порог: -JUMP_VELOCITY * 0.05f ≈ 29px — минимальная высота цели чтобы прыгать
    if (dy < -JUMP_VELOCITY * 0.05f && isGrounded && jumpCooldown <= 0.0f) {
        velocityY    = JUMP_VELOCITY;
        isGrounded   = false;
        jumpCooldown = JUMP_COOLDOWN_MAX;
        forceState(SamuraiState::JUMP);
    }

    // ── ПРОВАЛ ЧЕРЕЗ ПЛАТФОРМУ ───────────────────────────────
    // Активируется снаружи (когда игрок на нижней платформе)
    if (platformDropTimer > 0.0f) {
        platformDropTimer -= deltaTime;
        y += 2.0f;  // небольшой толчок вниз чтобы пройти сквозь платформу
    }

    // ── ГОРИЗОНТАЛЬНОЕ ДВИЖЕНИЕ ──────────────────────────────
    if (dist > PREFERRED_DISTANCE + DISTANCE_THRESHOLD) {
        // Слишком далеко → идём к игроку
        velocityX = (dx > 0) ? MOVE_SPEED : -MOVE_SPEED;
        if (isGrounded) setState(SamuraiState::WALK);

    } else if (dist < PREFERRED_DISTANCE - DISTANCE_THRESHOLD) {
        // Слишком близко → отступаем (60% скорости)
        velocityX = (dx > 0) ? -MOVE_SPEED * 0.6f : MOVE_SPEED * 0.6f;
        if (isGrounded) setState(SamuraiState::WALK);

    } else {
        // Комфортная дистанция → стоим
        velocityX = 0.0f;
        if (isGrounded && currentState == SamuraiState::WALK)
            setState(SamuraiState::IDLE);
    }

    // Приземлились → сбрасываем состояние прыжка
    if (isGrounded && currentState == SamuraiState::JUMP)
        setState(SamuraiState::IDLE);

    // Применяем горизонтальное движение + коллизии по X
    x += velocityX * deltaTime;
    applyCollisionsX();
}

// ============================================================
// AI — ВЫБОР АТАКИ
// ============================================================

void BossSamurai::updateAI(float deltaTime, float playerX, float playerY) {
    // Тикаем кулдауны (swordTimer тикает отдельно в update())
    if (teleportTimer > 0.0f) teleportTimer -= deltaTime;
    if (bombTimer     > 0.0f) bombTimer     -= deltaTime;

    // Не прерывать текущую атаку или спец-состояние
    if (currentState == SamuraiState::THROW_BOMBS  ||
        currentState == SamuraiState::SWORD_ATTACK  ||
        currentState == SamuraiState::TELEPORT      ||
        currentState == SamuraiState::STANCE        ||
        currentState == SamuraiState::STUNNED       ||
        currentState == SamuraiState::DEATH) return;

    // Если все специальные атаки на кулдауне → ближний бой
    const bool specialAttacksOnCooldown =
        (teleportTimer > 0.0f) &&
        (bombTimer     > 0.0f) &&
        (!stanceActive && currentState != SamuraiState::STANCE);

    if (specialAttacksOnCooldown) {
        updateMeleeFallback(deltaTime, playerX, playerY);
        return;
    }

    // ── ВЫБОР АТАКИ ПО ДИСТАНЦИИ ─────────────────────────────
    const float dx   = playerX - x;
    const float dist = std::abs(dx);

    if (dist >= DIST_FAR && teleportTimer <= 0.0f) {
        // Дальняя дистанция → телепорт за спину
        teleportBehindPlayer();

    } else if (dist >= DIST_CLOSE && dist < DIST_FAR && bombTimer <= 0.0f) {
        // Средняя дистанция → веер бомб
        throwBombsFan();

    } else if (dist < DIST_CLOSE && swordTimer <= 0.0f) {
        // Ближняя дистанция → стойка парирования
        stanceTimer  = 0.0f;
        stanceActive = true;
        spawnSmoke();  // дымный эффект при входе в стойку
        forceState(SamuraiState::STANCE);
    }
}

// ============================================================
// ТЕЛЕПОРТ
// ============================================================

void BossSamurai::teleportBehindPlayer() {
    // Определяем с какой стороны стоит самурай относительно игрока
    // и встаём с противоположной стороны (за спину)
    const float direction = (lastPlayerX > x) ? -1.0f : 1.0f;
    x = lastPlayerX + direction * TELEPORT_OFFSET;
    y = lastPlayerY;

    // После телепорта смотрим на игрока
    facingRight = (lastPlayerX > x);

    teleportTimer = TELEPORT_COOLDOWN;
    forceState(SamuraiState::TELEPORT);
}

// ============================================================
// ВЕЕР БОМБ
// ============================================================

void BossSamurai::throwBombsFan() {
    // Базовый угол зависит от направления взгляда:
    //   смотрим вправо → 45° (вниз-вперёд)
    //   смотрим влево  → 180° - 45° = 135°
    const float baseAngle  = facingRight ? BOMB_BASE_ANGLE : 180.0f - BOMB_BASE_ANGLE;
    const float halfSpread = (BOMB_COUNT - 1) * BOMB_SPREAD_ANGLE / 2.0f;

    for (int i = 0; i < BOMB_COUNT; i++) {
        const float angleDeg = baseAngle + (-halfSpread + i * BOMB_SPREAD_ANGLE);
        const float angleRad = angleDeg * static_cast<float>(M_PI) / 180.0f;

        Bomb bomb;
        bomb.x         = x;
        bomb.y         = y;
        bomb.velX      = std::cos(angleRad) * Bomb::SPEED;
        bomb.velY      = std::sin(angleRad) * Bomb::SPEED;
        bomb.fuseTimer = Bomb::FUSE_TIME;
        bomb.active    = true;
        bomb.exploded  = false;
        bombs.push_back(bomb);
    }

    bombTimer = BOMB_COOLDOWN;
    forceState(SamuraiState::THROW_BOMBS);
}

// ============================================================
// СТОЙКА
// ============================================================

void BossSamurai::updateStance(float deltaTime) {
    if (currentState != SamuraiState::STANCE) return;

    stanceTimer += deltaTime;

    // Игрок не атаковал за STANCE_DURATION секунд → самурай устал и получает стан
    if (stanceTimer >= STANCE_DURATION) {
        stanceActive = false;
        stanceTimer  = 0.0f;
        stunTimer    = STUN_DURATION;
        forceState(SamuraiState::STUNNED);
    }
}

// ============================================================
// ПАРИРОВАНИЕ
// ============================================================

bool BossSamurai::checkParry() {
    // Парирование возможно только пока стойка активна
    if (!stanceActive) return false;

    // Сбрасываем стойку
    stanceActive = false;
    stanceTimer  = 0.0f;

    // Ответный удар: телепорт за спину + веер бомб
    teleportBehindPlayer();
    throwBombsFan();

    // Возвращаем true → GameScene должна наложить стан на игрока
    return true;
}

// ============================================================
// БОМБЫ
// ============================================================

void BossSamurai::updateBombs(float deltaTime) {
    // ИСПРАВЛЕНО: эта функция не существовала в оригинале.
    // Без неё бомбы летели вечно и никогда не взрывались.

    for (auto& bomb : bombs) {
        if (!bomb.active) continue;

        if (!bomb.exploded) {
            // ── Бомба летит ──────────────────────────────────
            bomb.x         += bomb.velX * deltaTime;
            bomb.y         += bomb.velY * deltaTime;
            bomb.fuseTimer -= deltaTime;

            // Простая гравитация для дуги полёта
            bomb.velY += 400.0f * deltaTime;

            // Таймер истёк → взрыв
            if (bomb.fuseTimer <= 0.0f) {
                bomb.exploded = true;
                explodeAnim.reset();  // запускаем анимацию взрыва
            }
        } else {
            // ── Взрыв проигрывается ──────────────────────────
            explodeAnim.update(deltaTime);

            // Анимация взрыва закончилась → убираем бомбу
            if (explodeAnim.isFinished())
                bomb.active = false;
        }
    }

    // Удаляем неактивные бомбы из вектора
    bombs.erase(
        std::remove_if(bombs.begin(), bombs.end(),
                       [](const Bomb& b) { return !b.active; }),
        bombs.end());
}

// ============================================================
// ДЫМ
// ============================================================

void BossSamurai::spawnSmoke() {
    // Распределения для случайного разброса частиц
    std::uniform_real_distribution<float> randX   (-30.0f,  30.0f);
    std::uniform_real_distribution<float> randY   (-40.0f,  10.0f);
    std::uniform_real_distribution<float> randVel (-20.0f,  20.0f);
    std::uniform_real_distribution<float> randLife(  0.8f,   1.8f);

    for (int i = 0; i < 20; i++) {
        SmokeParticle p;
        p.x           = x + randX(rng);
        p.y           = y + randY(rng);
        p.velX        = randVel(rng);
        p.velY        = -30.0f + randVel(rng);  // дым поднимается вверх (velY отрицательный)
        p.maxLifetime = randLife(rng);
        p.lifetime    = p.maxLifetime;
        p.alpha       = 180;
        smokeParticles.push_back(p);
    }

    smokeTimer = SMOKE_COOLDOWN;
}

void BossSamurai::updateSmoke(float deltaTime) {
    // Периодически создаём новую порцию дыма
    if (smokeTimer > 0.0f)  smokeTimer -= deltaTime;
    if (smokeTimer <= 0.0f) spawnSmoke();

    // Двигаем и угасаем каждую частицу
    for (auto& p : smokeParticles) {
        p.x        += p.velX * deltaTime;
        p.y        += p.velY * deltaTime;
        p.lifetime -= deltaTime;

        // Альфа пропорциональна оставшемуся времени жизни
        p.alpha = static_cast<Uint8>(180.0f * (p.lifetime / p.maxLifetime));
    }

    // Удаляем мёртвые частицы
    smokeParticles.erase(
        std::remove_if(smokeParticles.begin(), smokeParticles.end(),
                       [](const SmokeParticle& p) { return p.lifetime <= 0.0f; }),
        smokeParticles.end());
}

// ============================================================
// БЛИЖНИЙ БОЙ (фоллбэк когда все спец-атаки на кулдауне)
// ============================================================

void BossSamurai::updateMeleeFallback(float deltaTime, float /*playerX*/, float /*playerY*/) {

    // ── ФАЗА ОТСКОКА после завершения серии ──────────────────
    if (isBreakingAway) {
        breakAwayTimer -= deltaTime;

        // Отскакиваем от игрока (направление противоположное facingRight)
        const float dir = facingRight ? -1.0f : 1.0f;
        velocityX = dir * SWORD_BREAK_SPEED;
        x += velocityX * deltaTime;
        applyCollisionsX();

        if (breakAwayTimer <= 0.0f) {
            // Отскок закончен — сбрасываем серию
            isBreakingAway  = false;
            swordComboCount = 0;
            velocityX       = 0.0f;
        }
        return;
    }

    // ── ЖДЁМ КОНЦА ТЕКУЩЕГО УДАРА ────────────────────────────
    if (currentState == SamuraiState::SWORD_ATTACK) {
        auto it = animations.find(SamuraiState::SWORD_ATTACK);

        // Анимация ещё идёт — ждём
        if (it != animations.end() && !it->second.isFinished()) return;

        swordComboCount++;

        if (swordComboCount >= SWORD_COMBO_MAX) {
            // Вся серия нанесена → отскок
            isBreakingAway = true;
            breakAwayTimer = BREAK_AWAY_DURATION;
            forceState(SamuraiState::WALK);
        } else {
            // Ещё есть удары в серии → следующий удар
            meleeHitDealt = false;
            animations[SamuraiState::SWORD_ATTACK].reset();
            forceState(SamuraiState::SWORD_ATTACK);
            swordTimer = SWORD_COOLDOWN;
        }
        return;
    }

    // ── НАЧАЛО ПЕРВОГО УДАРА в серии ─────────────────────────
    if (swordTimer <= 0.0f) {
        meleeHitDealt = false;
        animations[SamuraiState::SWORD_ATTACK].reset();
        forceState(SamuraiState::SWORD_ATTACK);
        swordTimer = SWORD_COOLDOWN;
    }
}

// ============================================================
// РЕНДЕР
// ============================================================

void BossSamurai::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    // Дымка рисуется ДО спрайта — самурай поверх дыма
    renderSmoke(renderer);

    // ── СПРАЙТ САМУРАЯ ────────────────────────────────────────
    auto texIt  = textures.find(currentState);
    auto animIt = animations.find(currentState);

    if (texIt == textures.end() || !texIt->second || animIt == animations.end()) {
        // Текстура не загружена — заглушка красный прямоугольник
        SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
        SDL_Rect rect = {
            (int)(x - width  / 2) - cx,
            (int)(y - height / 2) - cy,
            (int)width, (int)height
        };
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_Rect src = animIt->second.getCurrentFrame();

        // Размер спрайта с учётом масштаба
        const int dstW = (int)(FRAME_W * SPRITE_SCALE);
        const int dstH = (int)(FRAME_H * SPRITE_SCALE);

        // Выравниваем спрайт: центр X по x, низ спрайта по низу хитбокса
        SDL_Rect dst = {
            (int)(x - dstW / 2) - cx,
            (int)(y + height / 2) - dstH - cy,
            dstW, dstH
        };

        SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, texIt->second, &src, &dst, 0, nullptr, flip);
    }

    // ── БОМБЫ ─────────────────────────────────────────────────
    // Анимация бомбы тикает постоянно (независимо от количества бомб)
    bombAnim.update(1.0f / 60.0f);

    for (const auto& bomb : bombs) {
        if (!bomb.active) continue;

        const int bx = (int)(bomb.x - BOMB_FRAME_W  / 2) - cx;
        const int by = (int)(bomb.y - BOMB_FRAME_H  / 2) - cy;

        if (!bomb.exploded) {
            // Летящая бомба
            SDL_Rect src = bombAnim.getCurrentFrame();
            SDL_Rect dst = {bx, by, BOMB_FRAME_W, BOMB_FRAME_H};
            if (bombTexture)
                SDL_RenderCopy(renderer, bombTexture, &src, &dst);
            else {
                // Заглушка — синий квадрат
                SDL_SetRenderDrawColor(renderer, 50, 50, 200, 255);
                SDL_RenderFillRect(renderer, &dst);
            }
        } else {
            // Взрыв — рисуем вдвое больше кадра (взрыв расширяется)
            SDL_Rect src = explodeAnim.getCurrentFrame();
            SDL_Rect dst = {
                (int)(bomb.x - EXPLODE_FRAME_W) - cx,
                (int)(bomb.y - EXPLODE_FRAME_H) - cy,
                EXPLODE_FRAME_W * 2,
                EXPLODE_FRAME_H * 2
            };
            if (explodeTexture)
                SDL_RenderCopy(renderer, explodeTexture, &src, &dst);
        }
    }

    // ── ХИТБОКСЫ (только в режиме отладки) ───────────────────
    if (showHitboxes) renderHitboxes(renderer);
}

void BossSamurai::renderSmoke(SDL_Renderer* renderer) {
    if (smokeParticles.empty()) return;

    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    for (const auto& p : smokeParticles) {
        // Размер частицы растёт по мере угасания: 8px → 32px
        const float lifePct = p.lifetime / p.maxLifetime;
        const int   size    = (int)(8.0f + (1.0f - lifePct) * 24.0f);

        SDL_SetRenderDrawColor(renderer, 180, 180, 180, p.alpha);
        SDL_Rect rect = {
            (int)(p.x - size / 2) - cx,
            (int)(p.y - size / 2) - cy,
            size, size
        };
        SDL_RenderFillRect(renderer, &rect);
    }
}

void BossSamurai::renderHitboxes(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Хитбокс тела (зелёный)
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect hb       = getHitbox();
    SDL_Rect hbScreen = {hb.x - cx, hb.y - cy, hb.w, hb.h};
    SDL_RenderDrawRect(renderer, &hbScreen);

    // Хитбокс меча (красный) — только во время атаки
    if (currentState == SamuraiState::SWORD_ATTACK && !meleeHitDealt) {
        const int hx = facingRight
                           ? (int)(x + width / 2)
                           : (int)(x - width / 2 - SWORD_HIT_W);
        const int hy = (int)(y - SWORD_HIT_H / 2);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect swordBox = {hx - cx, hy - cy, SWORD_HIT_W, SWORD_HIT_H};
        SDL_RenderDrawRect(renderer, &swordBox);
    }

    // Центр тела (белая точка)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, (int)x - cx, (int)y - cy);

    // Радиусы взрыва бомб (синий прямоугольник — аппроксимация круга)
    SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
    for (const auto& bomb : bombs) {
        if (!bomb.active) continue;
        SDL_Rect bombBox = {
            (int)(bomb.x - Bomb::EXPLODE_RADIUS) - cx,
            (int)(bomb.y - Bomb::EXPLODE_RADIUS) - cy,
            (int)(Bomb::EXPLODE_RADIUS * 2),
            (int)(Bomb::EXPLODE_RADIUS * 2)
        };
        SDL_RenderDrawRect(renderer, &bombBox);
    }
}

// ============================================================
// ПРОВЕРКА УРОНА ПО ИГРОКУ
// ============================================================

float BossSamurai::checkPlayerDamage(SDL_Rect playerBox, float /*deltaTime*/) {
    float totalDamage = 0.0f;

    // ── УДАР МЕЧОМ ────────────────────────────────────────────
    // Засчитывается один раз за замах — на кадре SWORD_HIT_FRAME и позже
    if (currentState == SamuraiState::SWORD_ATTACK && !meleeHitDealt) {
        auto it = animations.find(SamuraiState::SWORD_ATTACK);
        if (it != animations.end() &&
            it->second.getCurrentFrameIndex() >= SWORD_HIT_FRAME) {

            const int hx = facingRight
                               ? (int)(x + width / 2)
                               : (int)(x - width / 2 - SWORD_HIT_W);
            const int hy = (int)(y - SWORD_HIT_H / 2);

            SDL_Rect meleeBox = {hx, hy, SWORD_HIT_W, SWORD_HIT_H};
            if (rectsOverlap(playerBox, meleeBox))
                totalDamage += DAMAGE_SWORD;

            // Флаг — чтобы не засчитать второй раз в этом замахе
            meleeHitDealt = true;
        }
    }

    // ── ВЗРЫВЫ БОМБ ───────────────────────────────────────────
    for (auto& bomb : bombs) {
        if (!bomb.active || !bomb.exploded) continue;

        SDL_Rect bombBox = {
            (int)(bomb.x - Bomb::EXPLODE_RADIUS),
            (int)(bomb.y - Bomb::EXPLODE_RADIUS),
            (int)(Bomb::EXPLODE_RADIUS * 2),
            (int)(Bomb::EXPLODE_RADIUS * 2)
        };

        if (rectsOverlap(playerBox, bombBox)) {
            totalDamage += DAMAGE_BOMB;
            bomb.active = false;  // взрыв засчитан — убираем бомбу
        }
    }

    return totalDamage;
}

// ============================================================
// УПРАВЛЕНИЕ СОСТОЯНИЯМИ
// ============================================================

void BossSamurai::setState(SamuraiState newState) {
    // Игнорируем если то же состояние или кулдаун не прошёл
    if (currentState == newState) return;
    if (!canChangeState()) return;

    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
}

void BossSamurai::forceState(SamuraiState newState) {
    // Принудительная смена — без проверки кулдауна
    // Используется для атак, смерти, стана
    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
}

bool BossSamurai::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ ПРОВЕРКИ
// ============================================================

bool BossSamurai::isDeathAnimFinished() const {
    auto it = animations.find(SamuraiState::DEATH);
    // Если анимация не найдена — считаем завершённой (безопасный дефолт)
    if (it == animations.end()) return true;
    return it->second.isFinished();
}