/**
 * @file boss_archer.cpp
 * @brief Реализация BossArcher
 * @author evol
 * @date 2026-06-08
 */

#include "boss_archer.h"
#include "../levels/ilevel.h"

extern ILevel* g_currentLevel;

// ============================================================
// КОНСТРУКТОР
// ============================================================

BossArcher::BossArcher(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
    , lastRecalcPlayerX(spawnX)
    , lastRecalcPlayerY(spawnY)
{
    swordCooldown = BASE_SWORD_COOLDOWN / attackSpeedMult;
    shootCooldown = BASE_SHOOT_COOLDOWN / attackSpeedMult;
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
                                      { ArcherState::ATTACK_1,     "assets/Samurai_Archer/Attack_1.png", FRAMES_ATTACK_1,     ANIM_SPD_ATTACK_1,     false },
                                      { ArcherState::ATTACK_2,     "assets/Samurai_Archer/Attack_2.png", FRAMES_ATTACK_2,     ANIM_SPD_ATTACK_2,     false },
                                      { ArcherState::ATTACK_3,     "assets/Samurai_Archer/Attack_3.png", FRAMES_ATTACK_3,     ANIM_SPD_ATTACK_3,     false },
                                      { ArcherState::HURT,         "assets/Samurai_Archer/Hurt.png",     FRAMES_HURT,         ANIM_SPD_HURT,         false },
                                      { ArcherState::SHOOT,        "assets/Samurai_Archer/Shot.png",     FRAMES_SHOOT,        ANIM_SPD_SHOOT,        false },
                                      { ArcherState::CLONE_VOLLEY, "assets/Samurai_Archer/Attack_2.png", FRAMES_CLONE_VOLLEY, ANIM_SPD_CLONE_VOLLEY, false },
                                      { ArcherState::DEATH,        "assets/Samurai_Archer/Dead.png",     FRAMES_DEATH,        ANIM_SPD_DEATH,        false },
                                      };

    arrowTexture = TextureManager::getTexture("assets/Samurai_Archer/Arrow.png");

    for (const auto& info : ANIMS) {
        SDL_Texture* tex = TextureManager::getTexture(info.path);
        if (!tex) {
            std::cerr << "[BossArcher] ОШИБКА: не загружена " << info.path << "\n";
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

    // 1. ЗАДЕРЖКА СПАВНА
    if (spawnDelay > 0.0f) {
        spawnDelay -= deltaTime;
        applyGravityAndCollisions(deltaTime);
        return;
    }

    // 2. СМЕРТЬ
    if (hp <= 0) {
        if (currentState != ArcherState::DEATH) {
            phase     = ArcherPhase::DYING;
            velocityX = 0.0f;
            for (auto& c : clones) c.active = false;
            for (auto& a : arrows) a.active = false;
            forceState(ArcherState::DEATH);
        }
        applyGravityAndCollisions(deltaTime);
        auto it = animations.find(ArcherState::DEATH);
        if (it != animations.end()) it->second.update(deltaTime);
        return;
    }

    // 3. РЕГУЛЯРНЫЙ КАДР
    stateTimer += deltaTime;

    // Визуализация BFS
    if (showHitboxes && bfsVisualStep < (int)bfsAllNodes.size()) {
        bfsVisualTimer += deltaTime;
        while (bfsVisualTimer >= BFS_VIS_STEP_INTERVAL &&
               bfsVisualStep < (int)bfsAllNodes.size()) {
            bfsVisualTimer -= BFS_VIS_STEP_INTERVAL;
            bfsVisualStep++;
        }
    }

    if (swordTimer    > 0.0f) swordTimer    -= deltaTime;
    if (shootTimer    > 0.0f) shootTimer    -= deltaTime;
    if (teleportCooldown > 0.0f) teleportCooldown -= deltaTime;

    // 4. АНИМАЦИЯ HURT ПЕРЕД ТЕЛЕПОРТОМ
    // Если играет — ждём конца, потом телепортируемся
    if (playingPreTeleportHurt) {
        auto it = animations.find(ArcherState::HURT);
        if (it != animations.end()) it->second.update(deltaTime);

        if (it == animations.end() || it->second.isFinished()) {
            playingPreTeleportHurt = false;
            // Теперь сам телепорт
            teleportNearPlayer(playerX, playerY);
        }
        // Физика продолжается даже во время hurt
        applyGravityAndCollisions(deltaTime);
        return;
    }

    checkPhaseTransition();

    if (!clonesSpawned) {
        spawnClones();
        clonesSpawned = true;
    }

    updateClones(deltaTime, playerX, playerY);

    // Обновление стрел
    for (auto& arrow : arrows) {
        if (!arrow.active) continue;
        arrow.x += arrow.velX * deltaTime;
        arrow.y += arrow.velY * deltaTime;
        const float dx = arrow.x - x;
        const float dy = arrow.y - y;
        if (dx*dx + dy*dy > ArcherArrow::SPEED * ArcherArrow::SPEED * 16.0f)
            arrow.active = false;
    }
    arrows.erase(
        std::remove_if(arrows.begin(), arrows.end(),
                       [](const ArcherArrow& a){ return !a.active; }),
        arrows.end());

    updateAI(deltaTime, playerX, playerY);

    applyGravityAndCollisions(deltaTime, platformDropTimer > 0.0f);
    if (platformDropTimer > 0.0f) platformDropTimer -= deltaTime;

    // Обновляем анимацию текущего состояния
    // (HURT обновляется отдельно выше — здесь не трогаем)
    auto it = animations.find(currentState);
    if (it != animations.end()) it->second.update(deltaTime);
}

// ============================================================
// СПАВН КЛОНОВ
// ============================================================

void BossArcher::spawnClones() {
    clones.clear();
    const int count = (phase == ArcherPhase::PHASE_1) ? CLONE_COUNT : CLONE_COUNT_P2;

    for (int i = 0; i < count; i++) {
        const float offset = (i - (count - 1) / 2.0f) * CLONE_SPACING;
        ArcherClone clone;
        clone.x              = x;
        clone.y              = y + offset;
        clone.verticalOffset = offset;
        clone.offsetX        = 0.0f;
        clone.active         = true;
        clone.isCenter       = (i == count / 2);
        clone.dirX           = clone.isCenter ? 0.0f : (facingRight ? 1.0f : -1.0f);
        clone.dirY           = 0.0f;
        clones.push_back(clone);
    }
}

// ============================================================
// ОБНОВЛЕНИЕ КЛОНОВ
// ============================================================

void BossArcher::updateClones(float dt, float playerX, float playerY) {
    if (clones.empty()) return;

    ArcherClone* center = nullptr;
    for (auto& clone : clones)
        if (clone.isCenter) { center = &clone; break; }
    if (!center) return;

    center->x = x;
    center->y = y + center->verticalOffset;

    const float cdx  = playerX - center->x;
    const float cdy  = playerY - center->y;
    const float clen = std::sqrt(cdx*cdx + cdy*cdy);
    if (clen > 1.0f) {
        center->dirX = cdx / clen;
        center->dirY = cdy / clen;
    }

    for (auto& clone : clones) {
        if (clone.isCenter) continue;
        clone.x = center->x + clone.offsetX;
        clone.y = y + clone.verticalOffset;

        if (phase == ArcherPhase::PHASE_2) {
            if (clone.verticalOffset <= -VERTICAL_CLONE_OFFSET) {
                const float dx  = playerX - clone.x;
                const float dy  = playerY - clone.y;
                const float len = std::sqrt(dx*dx + dy*dy);
                if (len > 1.0f) { clone.dirX = dx/len; clone.dirY = dy/len; }
            } else if (clone.dirY > 0.5f && std::abs(clone.dirX) > 0.5f) {
                clone.dirX = facingRight ? 0.707f : -0.707f;
                clone.dirY = 0.707f;
            } else {
                clone.dirX = facingRight ? 1.0f : -1.0f;
                clone.dirY = 0.0f;
            }
        } else {
            clone.dirX = facingRight ? 1.0f : -1.0f;
            clone.dirY = 0.0f;
        }
    }

    cloneShootTimer -= dt;
    if (cloneShootTimer > 0.0f) return;
    cloneShootTimer = CLONE_SHOOT_INTERVAL / attackSpeedMult;

    const float centerDist = std::sqrt(cdx*cdx + cdy*cdy);
    for (const auto& clone : clones) {
        if (!clone.active) continue;
        if (clone.isCenter && centerDist <= 1.0f) continue;
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
    spawnClones();

    // Диагональный клон
    ArcherClone diag;
    diag.x = x; diag.y = y; diag.verticalOffset = 0.0f; diag.offsetX = 0.0f;
    diag.dirX = facingRight ? 0.707f : -0.707f; diag.dirY = 0.707f;
    diag.active = true; diag.isCenter = false;
    clones.push_back(diag);

    // Вертикальный клон
    ArcherClone vert;
    vert.x = x; vert.y = y - VERTICAL_CLONE_OFFSET;
    vert.verticalOffset = -VERTICAL_CLONE_OFFSET; vert.offsetX = 0.0f;
    vert.dirX = 0.0f; vert.dirY = 1.0f;
    vert.active = true; vert.isCenter = false;
    clones.push_back(vert);

    swordTimer      = swordCooldown;
    shootTimer      = shootCooldown;
    cloneShootTimer = CLONE_SHOOT_INTERVAL;
}

// ============================================================
// AI
// ============================================================

void BossArcher::updateAI(float dt, float playerX, float playerY) {
    if (currentState == ArcherState::DEATH) return;

    updateMovement(dt, playerX, playerY);
    x += velocityX * dt;
    applyCollisionsX();

    // Атака идёт — ждём конца, движение НЕ останавливаем
    const bool isAttacking = (currentState == ArcherState::ATTACK_1 ||
                              currentState == ArcherState::ATTACK_2 ||
                              currentState == ArcherState::ATTACK_3);
    if (isAttacking) {
        auto it = animations.find(currentState);
        if (it != animations.end() && it->second.isFinished())
            setState(ArcherState::IDLE);
        return;
    }

    if (platformDropTimer > 0.0f) return;

    const float distX = std::abs(playerX - x);
    const float distY = std::abs(playerY - y);

    // Телепорт если игрок слишком далеко и кулдаун прошёл
    if (distX > TELEPORT_TRIGGER_DIST && teleportCooldown <= 0.0f) {
        // Сначала — анимация Hurt (без урона)
        playingPreTeleportHurt = true;
        auto it = animations.find(ArcherState::HURT);
        if (it != animations.end()) it->second.reset();
        forceState(ArcherState::HURT);
        return;
    }

    // Ближний бой — случайная из трёх анимаций, движение не останавливаем
    if (distX <= MELEE_RANGE && distY <= HITBOX_H &&
        swordTimer <= 0.0f && isGrounded) {
        meleeHitDealt = false;

        std::uniform_int_distribution<int> roll(0, 2);
        currentAttack = roll(rng);

        ArcherState attackState = ArcherState::ATTACK_1;
        if (currentAttack == 1) attackState = ArcherState::ATTACK_2;
        if (currentAttack == 2) attackState = ArcherState::ATTACK_3;

        forceState(attackState);
        swordTimer = swordCooldown;
        return;
    }

    // Анимация движения
    if (isGrounded) {
        if (std::abs(velocityX) > 10.0f)
            setState(ArcherState::WALK);
        else if (currentState == ArcherState::WALK)
            setState(ArcherState::IDLE);
    }
}

// ============================================================
// ТЕЛЕПОРТ В СЛУЧАЙНУЮ ТОЧКУ РЯДОМ С ИГРОКОМ
// ============================================================

void BossArcher::teleportNearPlayer(float playerX, float playerY) {
    if (!g_currentLevel) return;

    int ox, oy;
    getCurrentMapOffset(ox, oy);

    std::uniform_real_distribution<float> angleDist(0.0f, 2.0f * static_cast<float>(M_PI));
    std::uniform_real_distribution<float> distDist(TELEPORT_MIN_DIST, TELEPORT_MAX_DIST);

    for (int attempt = 0; attempt < 12; ++attempt) {
        const float angle   = angleDist(rng);
        const float dist    = distDist(rng);
        const float targetX = playerX + std::cos(angle) * dist;
        const float targetY = playerY + std::sin(angle) * dist;

        const int col = static_cast<int>((targetX - ox) / BFS_TILE_SIZE);
        const int row = static_cast<int>((targetY - oy) / BFS_TILE_SIZE);

        if (isWalkable(col, row) && hasSupport(col, row)) {
            x = ox + col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;
            y = oy + row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;
            teleportCooldown = TELEPORT_COOLDOWN;
            facingRight      = (playerX > x);
            path.clear();
            pathIndex = 0;
            return;
        }
    }
    // 12 попыток не нашли валидную позицию — ставим половину кулдауна
    teleportCooldown = TELEPORT_COOLDOWN * 0.5f;
}

// ============================================================
// ПРОВЕРКА УРОНА ПО ИГРОКУ
// ============================================================

float BossArcher::checkPlayerDamage(SDL_Rect playerBox, float /*deltaTime*/) {
    if (phase == ArcherPhase::DYING) return 0.0f;

    float totalDamage = 0.0f;

    // Меч — любая из трёх атак
    const bool isAttackingNow = (currentState == ArcherState::ATTACK_1 ||
                                 currentState == ArcherState::ATTACK_2 ||
                                 currentState == ArcherState::ATTACK_3);
    if (isAttackingNow && !meleeHitDealt) {
        auto it = animations.find(currentState);
        if (it != animations.end() &&
            it->second.getCurrentFrameIndex() >= SWORD_HIT_FRAME) {
            const int hx = facingRight
                               ? (int)(x + width / 2)
                               : (int)(x - width / 2 - SWORD_HIT_W);
            const int hy = (int)(y - SWORD_HIT_H / 2);
            SDL_Rect meleeBox = {hx, hy, (int)SWORD_HIT_W, (int)SWORD_HIT_H};
            if (rectsOverlap(playerBox, meleeBox))
                totalDamage += SWORD_DAMAGE;
            meleeHitDealt = true;
        }
    }

    // Стрелы
    for (auto& arrow : arrows) {
        if (!arrow.active) continue;
        SDL_Rect arrowBox = {
            (int)(arrow.x - ARROW_HITBOX_W / 2),
            (int)(arrow.y - ARROW_HITBOX_H / 2),
            ARROW_HITBOX_W, ARROW_HITBOX_H
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
    if (!renderer) return;

    const int camOffsetX = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int camOffsetY = g_camera ? (int)g_camera->getOffsetY() : 0;
    const int dstW = (int)(FRAME_W * SPRITE_SCALE);
    const int dstH = (int)(FRAME_H * SPRITE_SCALE);

    // 1. КЛОНЫ
    {
        auto idleTexIt  = textures.find(ArcherState::IDLE);
        auto idleAnimIt = animations.find(ArcherState::IDLE);
        if (idleTexIt != textures.end() && idleTexIt->second &&
            idleAnimIt != animations.end()) {
            SDL_SetTextureAlphaMod(idleTexIt->second, 120);
            for (const auto& clone : clones) {
                if (!clone.active) continue;
                SDL_Rect src = idleAnimIt->second.getCurrentFrame();
                SDL_Rect dst = {
                    (int)(clone.x - dstW / 2) - camOffsetX,
                    (int)(clone.y + HITBOX_H / 2) - dstH - camOffsetY,
                    dstW, dstH
                };
                SDL_RendererFlip flip = (clone.dirX >= 0) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
                SDL_RenderCopyEx(renderer, idleTexIt->second, &src, &dst, 0, nullptr, flip);
            }
            SDL_SetTextureAlphaMod(idleTexIt->second, 255);
        }
    }

    // 2. СТРЕЛЫ
    for (const auto& arrow : arrows) {
        if (!arrow.active) continue;
        const double angleDeg = std::atan2(arrow.velY, arrow.velX) * 180.0 / M_PI;
        SDL_Rect dst = {
            (int)(arrow.x - ARROW_W / 2) - camOffsetX,
            (int)(arrow.y - ARROW_H / 2) - camOffsetY,
            ARROW_W, ARROW_H
        };
        if (arrowTexture)
            SDL_RenderCopyEx(renderer, arrowTexture, nullptr, &dst, angleDeg, nullptr, SDL_FLIP_NONE);
        else {
            SDL_SetRenderDrawColor(renderer, 200, 160, 80, 255);
            SDL_RenderFillRect(renderer, &dst);
        }
    }

    // 3. БОСС
    {
        // Во время playingPreTeleportHurt рисуем Hurt текстуру
        ArcherState renderState = playingPreTeleportHurt ? ArcherState::HURT : currentState;

        auto texIt  = textures.find(renderState);
        auto animIt = animations.find(renderState);

        if (texIt == textures.end() || !texIt->second || animIt == animations.end()) {
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
            SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(renderer, texIt->second, &src, &dst, 0, nullptr, flip);
        }
    }

    if (showHitboxes) renderHitboxes(renderer);
}

// ============================================================
// ХИТБОКСЫ (ОТЛАДКА)
// ============================================================

void BossArcher::renderHitboxes(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    int ox = 0, oy = 0;
    if (g_currentLevel) g_currentLevel->getMapOffset(ox, oy);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // СИНИЙ — хитбокс босса
    SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
    SDL_Rect hb = getHitbox();
    SDL_Rect bossHb = {hb.x - cx, hb.y - cy, hb.w, hb.h};
    SDL_RenderDrawRect(renderer, &bossHb);

    // КРАСНЫЙ — хитбокс меча
    const bool isAttackingDbg = (currentState == ArcherState::ATTACK_1 ||
                                 currentState == ArcherState::ATTACK_2 ||
                                 currentState == ArcherState::ATTACK_3);
    if (isAttackingDbg) {
        const int hx = facingRight
                           ? (int)(x + width / 2)
                           : (int)(x - width / 2 - SWORD_HIT_W);
        const int hy = (int)(y - SWORD_HIT_H / 2);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect swordHb = {hx - cx, hy - cy, (int)SWORD_HIT_W, (int)SWORD_HIT_H};
        SDL_RenderDrawRect(renderer, &swordHb);
    }

    // ЖЁЛТЫЙ — стрелы
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (const auto& arrow : arrows) {
        if (!arrow.active) continue;
        SDL_Rect arrowHb = {
            (int)(arrow.x - ARROW_HITBOX_W / 2) - cx,
            (int)(arrow.y - ARROW_HITBOX_H / 2) - cy,
            ARROW_HITBOX_W, ARROW_HITBOX_H
        };
        SDL_RenderDrawRect(renderer, &arrowHb);
    }

    // ЗЕЛЁНЫЙ — клоны
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (const auto& clone : clones) {
        if (!clone.active) continue;
        SDL_Rect cloneHb = {
            (int)(clone.x - HITBOX_W / 2) - cx,
            (int)(clone.y - HITBOX_H / 2) - cy,
            (int)HITBOX_W, (int)HITBOX_H
        };
        SDL_RenderDrawRect(renderer, &cloneHb);
    }

    // Белая точка — центр
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, (int)x - cx, (int)y - cy);

    // BFS визуализация
    if (!bfsAllNodes.empty()) {
        std::set<std::pair<int,int>> pathSet;
        for (const auto& pn : path) pathSet.insert({pn.col, pn.row});

        const int limit = std::min(bfsVisualStep, (int)bfsAllNodes.size());
        for (int i = 0; i < limit; i++) {
            const auto& n = bfsAllNodes[i];
            bool onPath = pathSet.count({n.col, n.row}) > 0;
            if (onPath)
                SDL_SetRenderDrawColor(renderer, 0, 255, 80, 160);
            else
                SDL_SetRenderDrawColor(renderer, 120, 120, 120, 80);
            SDL_Rect cell = {
                ox + n.col * BFS_TILE_SIZE + 4 - cx,
                oy + n.row * BFS_TILE_SIZE + 4 - cy,
                BFS_TILE_SIZE - 8, BFS_TILE_SIZE - 8
            };
            SDL_RenderFillRect(renderer, &cell);
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
    for (int i = pathIndex; i + 1 < (int)path.size(); i++) {
        SDL_RenderDrawLine(renderer,
                           ox + path[i].col   * BFS_TILE_SIZE + BFS_TILE_SIZE/2 - cx,
                           oy + path[i].row   * BFS_TILE_SIZE + BFS_TILE_SIZE/2 - cy,
                           ox + path[i+1].col * BFS_TILE_SIZE + BFS_TILE_SIZE/2 - cx,
                           oy + path[i+1].row * BFS_TILE_SIZE + BFS_TILE_SIZE/2 - cy);
    }

    if (pathIndex < (int)path.size()) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_Rect bfsRect = {
            ox + path[pathIndex].col * BFS_TILE_SIZE - cx,
            oy + path[pathIndex].row * BFS_TILE_SIZE - cy,
            BFS_TILE_SIZE, BFS_TILE_SIZE
        };
        SDL_RenderDrawRect(renderer, &bfsRect);
    }
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ
// ============================================================

SDL_Rect BossArcher::getHitbox() const {
    return {
        (int)(x - width / 2), (int)(y - height / 2),
        (int)width, (int)height
    };
}

bool BossArcher::isDeathAnimFinished() const {
    auto it = animations.find(ArcherState::DEATH);
    if (it == animations.end()) return true;
    return it->second.isFinished();
}

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

void BossArcher::getCurrentMapOffset(int& ox, int& oy) const {
    ox = 0; oy = 0;
    if (g_currentLevel) g_currentLevel->getMapOffset(ox, oy);
}

bool BossArcher::hasSupport(int col, int row) const {
    if (!g_currentLevel) return false;
    int ox, oy; getCurrentMapOffset(ox, oy);
    return g_currentLevel->isSolid(ox + col*BFS_TILE_SIZE + BFS_TILE_SIZE/2,
                                   oy + (row+1)*BFS_TILE_SIZE - 1) ||
           g_currentLevel->isPlatform(ox + col*BFS_TILE_SIZE + BFS_TILE_SIZE/2,
                                      oy + (row+1)*BFS_TILE_SIZE - 1);
}

bool BossArcher::isWalkable(int col, int row) const {
    if (!g_currentLevel) return false;
    int ox, oy; getCurrentMapOffset(ox, oy);
    return !g_currentLevel->isSolid(ox + col*BFS_TILE_SIZE + BFS_TILE_SIZE/2,
                                    oy + row*BFS_TILE_SIZE + BFS_TILE_SIZE/2);
}

bool BossArcher::isSolidTile(int col, int row) const {
    if (!g_currentLevel) return false;
    int ox, oy; g_currentLevel->getMapOffset(ox, oy);
    int px = ox + col*BFS_TILE_SIZE + BFS_TILE_SIZE/2;
    int py = oy + row*BFS_TILE_SIZE + BFS_TILE_SIZE - 1;
    return g_currentLevel->isSolid(px, py) || g_currentLevel->isPlatform(px, py);
}

bool BossArcher::isFreeTile(int col, int row) const {
    if (!g_currentLevel) return true;
    int ox, oy; g_currentLevel->getMapOffset(ox, oy);
    return !g_currentLevel->isSolid(ox + col*BFS_TILE_SIZE + BFS_TILE_SIZE/2,
                                    oy + row*BFS_TILE_SIZE + BFS_TILE_SIZE/2);
}

bool BossArcher::canJumpTo(int col, int row, int& outLandRow) const {
    if (!g_currentLevel) return false;
    for (int r = row - 1; r >= row - BFS_JUMP_REACH_H; r--) {
        if (r < 0) break;
        if (isFreeTile(col, r) && isSolidTile(col, r + 1)) {
            outLandRow = r;
            return true;
        }
    }
    return false;
}

int BossArcher::findPlatformBelow(int col, int row) const {
    if (!g_currentLevel) return -1;
    int ox, oy; getCurrentMapOffset(ox, oy);
    const int maxRows = g_currentLevel->getMapHeight() / BFS_TILE_SIZE;
    for (int r = row + 1; r < maxRows; ++r) {
        int px = ox + col*BFS_TILE_SIZE + BFS_TILE_SIZE/2;
        int py = oy + r*BFS_TILE_SIZE + BFS_TILE_SIZE/2;
        if (!isWalkable(col, r)) {
            if (!g_currentLevel->isPlatform(px, py)) return -1;
            continue;
        }
        if (hasSupport(col, r)) return r;
    }
    return -1;
}

// ============================================================
// BFS
// ============================================================

void BossArcher::recalcPath(float playerX, float playerY) {
    path.clear();
    pathIndex = 0;
    bfsAllNodes.clear();
    if (!g_currentLevel) return;

    int ox, oy;
    getCurrentMapOffset(ox, oy);
    const int mapCols = g_currentLevel->getMapWidth()  / BFS_TILE_SIZE;
    const int mapRows = g_currentLevel->getMapHeight() / BFS_TILE_SIZE;
    if (mapCols <= 0 || mapRows <= 0) return;

    int startCol = static_cast<int>((x  - ox) / BFS_TILE_SIZE);
    int startRow = static_cast<int>((y + HITBOX_H/2 - oy) / BFS_TILE_SIZE);

    if (!hasSupport(startCol, startRow)) {
        for (int r = startRow + 1; r < mapRows; ++r)
            if (isWalkable(startCol, r) && hasSupport(startCol, r)) { startRow = r; break; }
    }

    int goalCol = static_cast<int>((playerX - ox) / BFS_TILE_SIZE);
    int goalRow = static_cast<int>((playerY + HITBOX_H/2 - oy) / BFS_TILE_SIZE);

    if (!hasSupport(goalCol, goalRow)) {
        float bestDist = 1e9f;
        int bestC = goalCol, bestR = goalRow;
        for (int dc = -6; dc <= 6; ++dc) {
            for (int dr = -4; dr <= 8; ++dr) {
                int c = goalCol + dc, r = goalRow + dr;
                if (c < 0 || c >= mapCols || r < 0 || r >= mapRows) continue;
                if (!isWalkable(c, r) || !hasSupport(c, r)) continue;
                float d = std::hypot(playerX - (ox + c*BFS_TILE_SIZE + BFS_TILE_SIZE/2.0f),
                                     playerY - (oy + r*BFS_TILE_SIZE + BFS_TILE_SIZE/2.0f));
                if (d < bestDist) { bestDist = d; bestC = c; bestR = r; }
            }
        }
        goalCol = bestC; goalRow = bestR;
    }

    if (startCol == goalCol && startRow == goalRow) return;

    struct BFSNode { int col, row, parent; PathAction action; };
    std::vector<BFSNode> nodes;
    std::vector<int> visited(mapRows * mapCols, -1);
    std::queue<int> q;

    nodes.push_back({startCol, startRow, -1, PathAction::WALK_RIGHT});
    visited[startRow * mapCols + startCol] = 0;
    q.push(0);
    int goalIdx = -1;

    while (!q.empty() && nodes.size() < 6000) {
        int idx = q.front(); q.pop();
        const auto& cur = nodes[idx];

        if (cur.col == goalCol && cur.row == goalRow) { goalIdx = idx; break; }

        auto tryAdd = [&](int nc, int nr, PathAction act) {
            if (nc < 0 || nc >= mapCols || nr < 0 || nr >= mapRows) return;
            if (visited[nr * mapCols + nc] != -1) return;
            if (!isWalkable(nc, nr)) return;
            if ((act == PathAction::WALK_LEFT || act == PathAction::WALK_RIGHT) &&
                !hasSupport(nc, nr)) return;
            int ni = (int)nodes.size();
            nodes.push_back({nc, nr, idx, act});
            visited[nr * mapCols + nc] = ni;
            q.push(ni);
        };

        tryAdd(cur.col - 1, cur.row, PathAction::WALK_LEFT);
        tryAdd(cur.col + 1, cur.row, PathAction::WALK_RIGHT);

        // Прыжок — максимум BFS_JUMP_REACH_H тайлов вверх
        // Прыжок
        if (hasSupport(cur.col, cur.row)) {
            for (int dx = -BFS_JUMP_REACH_W; dx <= BFS_JUMP_REACH_W; ++dx) {
                if (dx == 0) continue;
                int nc = cur.col + dx;
                for (int dy = -BFS_MAX_JUMP_HEIGHT; dy <= -1; ++dy) {   // ← используем новую константу
                    int nr = cur.row + dy;
                    if (nr < 0) continue;
                    if (isWalkable(nc, nr) && hasSupport(nc, nr)) {
                        tryAdd(nc, nr, PathAction::JUMP);
                        break;   // нашли ближайшую платформу по вертикали
                    }
                }
            }
        }

        // Drop вниз
        if (hasSupport(cur.col, cur.row)) {
            int dropRow = findPlatformBelow(cur.col, cur.row);
            if (dropRow != -1 && dropRow > cur.row)
                tryAdd(cur.col, dropRow, PathAction::DROP);
        }
    }

    for (const auto& n : nodes)
        bfsAllNodes.push_back({n.col, n.row, 0});

    if (goalIdx == -1) {
        velocityX   = (playerX > x) ? MOVE_SPEED : -MOVE_SPEED;
        facingRight = (playerX > x);
        return;
    }

    std::vector<PathNode> newPath;
    for (int i = goalIdx; i != -1; i = nodes[i].parent)
        newPath.push_back({nodes[i].col, nodes[i].row, nodes[i].action});
    std::reverse(newPath.begin(), newPath.end());
    path = std::move(newPath);
    pathIndex = path.empty() ? 0 : 1;
}

// ============================================================
// ДВИЖЕНИЕ
// ============================================================

void BossArcher::updateMovement(float dt, float playerX, float playerY) {
    if (currentState == ArcherState::DEATH) return;

    if (jumpCooldown > 0.0f) jumpCooldown -= dt;
    if (dropCooldown > 0.0f) dropCooldown -= dt;

    int ox = 0, oy = 0;
    getCurrentMapOffset(ox, oy);

    if (platformDropTimer > 0.0f) {
        y += 5.5f;
        velocityX = (playerX > x) ? MOVE_SPEED * 0.65f : -MOVE_SPEED * 0.65f;
        return;
    }

    const float playerDistSq =
        (playerX - lastRecalcPlayerX) * (playerX - lastRecalcPlayerX) +
        (playerY - lastRecalcPlayerY) * (playerY - lastRecalcPlayerY);

    if (path.empty() || bfsTimer <= 0.0f ||
        playerDistSq > RECALC_DISTANCE_THRESHOLD * RECALC_DISTANCE_THRESHOLD) {
        bfsTimer = 0.35f;
        lastRecalcPlayerX = playerX;
        lastRecalcPlayerY = playerY;
        recalcPath(playerX, playerY);
    } else {
        bfsTimer -= dt;
    }

    if (path.empty() || pathIndex >= (int)path.size()) {
        const float toX = std::abs(playerX - x);
        const float toY = std::abs(playerY - y);
        if (toX <= MELEE_RANGE && toY <= HITBOX_H * 2.0f)
            velocityX = 0.0f;
        else {
            velocityX   = (playerX > x) ? MOVE_SPEED * 0.9f : -MOVE_SPEED * 0.9f;
            facingRight = (playerX > x);
        }
        return;
    }

    const PathNode& target  = path[pathIndex];
    const float     targetX = ox + target.col * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;
    const float     targetY = oy + target.row * BFS_TILE_SIZE + BFS_TILE_SIZE / 2.0f;

    facingRight = (targetX > x);
    const float distX = std::abs(x - targetX);
    const float distY = std::abs(y - targetY);

    bool reached = false;
    switch (target.action) {
    case PathAction::JUMP:
    case PathAction::DROP:
        reached = (distY < BFS_TILE_SIZE * 1.5f && distX < 90.0f);
        break;
    default:
        reached = (distX < BFS_REACH_DIST);
        break;
    }
    if (reached) { pathIndex++; return; }

    switch (target.action) {
    case PathAction::WALK_LEFT:
    case PathAction::WALK_RIGHT:
        velocityX = (targetX > x) ? MOVE_SPEED : -MOVE_SPEED;
        break;
    case PathAction::JUMP:
        if (isGrounded && jumpCooldown <= 0.0f && distX < 120.0f) {
            velocityY    = JUMP_VELOCITY * 1.05f;
            isGrounded   = false;
            jumpCooldown = JUMP_COOLDOWN_MAX * 0.9f;
        } else if (!isGrounded) {
            velocityX = (targetX > x) ? MOVE_SPEED * 0.9f : -MOVE_SPEED * 0.9f;
        } else {
            velocityX = (targetX > x) ? MOVE_SPEED : -MOVE_SPEED;
        }
        break;
    case PathAction::DROP:
        if (isGrounded && dropCooldown <= 0.0f) {
            platformDropTimer = DROP_DURATION;
            dropCooldown      = DROP_COOLDOWN;
        } else if (!isGrounded) {
            velocityX = (targetX > x) ? MOVE_SPEED * 0.75f : -MOVE_SPEED * 0.75f;
        }
        break;
    }
}