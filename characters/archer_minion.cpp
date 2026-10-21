/**
 * @file archer_minion.cpp
 * @brief Реализация стационарного лучника
 * @author evol
 * @date 2026-09-03
 */
#include "archer_minion.h"
#include "../utils/camera.h"
#include "../utils/texture_manager.h"
#include "../levels/level1_assets.h" // TILE_SIZE
#include <cmath>

ArcherMinion::ArcherMinion(float spawnX, float spawnY, int phase)
    : Character(spawnX, spawnY, WIDTH, HEIGHT, 1.0f) // HP не используется — неуязвим
{
    setPhase(phase);
    // Точка спавна — на 1 клетку выше платформы (см. Level3::getMinionSpawn),
    // значит платформа ровно на пол-тайла ниже центра точки спавна
    platformTopY = spawnY + TILE_SIZE / 2.0f;
    loadAnimations();
}

void ArcherMinion::loadAnimations() {
    texIdle   = TextureManager::getTexture("assets/kobold/idle.png");
    texAttack = TextureManager::getTexture("assets/kobold/attack.png");
    texArrow  = TextureManager::getTexture("assets/Samurai_Archer/Arrow.png");

    for (int i = 0; i < IDLE_FRAMES; i++)
        idleAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, IDLE_FRAME_DUR);
    for (int i = 0; i < ATTACK_FRAMES; i++)
        attackAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, ATTACK_FRAME_DUR);
}
void ArcherMinion::update(float deltaTime, float playerX, float playerY) {
    // Очередь стрел текущего залпа — стреляем ПОСЛЕДОВАТЕЛЬНО, не одновременно
    if (arrowsQueued > 0) {
        arrowStaggerTimer -= deltaTime;
        if (arrowStaggerTimer <= 0.0f) {
            float dx = playerX - x;
            float dy = playerY - y;
            float len = std::sqrt(dx * dx + dy * dy);
            if (len < 1.0f) len = 1.0f;

            MinionArrow a;
            a.x = x; a.y = y;
            a.velX = (dx / len) * MinionArrow::SPEED;
            a.velY = (dy / len) * MinionArrow::SPEED;
            a.active = true;
            arrows.push_back(a);

            arrowsQueued--;
            arrowStaggerTimer = ARROW_STAGGER;
        }
    } else {
        volleyTimer -= deltaTime;
        if (volleyTimer <= 0.0f) {
            arrowsQueued      = arrowsPerVolley();
            arrowStaggerTimer = 0.0f;
            volleyTimer       = VOLLEY_COOLDOWN;
            // Один взмах на весь залп: перезапуск на каждую стрелу (раз в 0.15 с)
            // обрывал бы анимацию на середине
            attacking = true;
            attackAnim.reset();
        }
    }

    // Смотрит на игрока; во время взмаха разворот заблокирован, чтобы он не дёргался
    if (!attacking) facingRight = (playerX > x);

    if (attacking) {
        attackAnim.update(deltaTime);
        if (attackAnim.isFinished()) attacking = false;
    } else {
        idleAnim.update(deltaTime);
    }

    // Полёт стрел + очистка вышедших за разумную дистанцию
    for (auto& a : arrows) {
        if (!a.active) continue;
        a.x += a.velX * deltaTime;
        a.y += a.velY * deltaTime;

        const float dx = a.x - x;
        const float dy = a.y - y;
        if (dx * dx + dy * dy > (MinionArrow::SPEED * MinionArrow::SPEED * 16.0f))
            a.active = false;
    }
    arrows.erase(std::remove_if(arrows.begin(), arrows.end(),
                                [](const MinionArrow& a) { return !a.active; }),
                 arrows.end());

    // Своё приземление вместо applyGravityAndCollisions(): общий
    // CollisionSystem::resolveY ловит платформу только в узком окне ~8px
    // за кадр — свободное падение с точки спавна легко его проскакивает
    // (см. collision_system.cpp, landingFromAbove). Целевая платформа
    // заранее известна (platformTopY), поэтому считаем приземление сами —
    // без риска проскока, но с настоящей гравитацией/скоростью.
    if (!isGrounded) {
        velocityY += GRAVITY * deltaTime;
        if (velocityY > MAX_FALL_SPEED) velocityY = MAX_FALL_SPEED;
        y += velocityY * deltaTime;

        const float landY = platformTopY - height / 2.0f;
        if (y >= landY) {
            y = landY;
            velocityY  = 0.0f;
            isGrounded = true;
        }
    }
}

float ArcherMinion::checkPlayerDamage(SDL_Rect playerBox) {
    float total = 0.0f;
    for (auto& a : arrows) {
        if (!a.active) continue;
        SDL_Rect box = {
            (int)(a.x - ARROW_HITBOX_W / 2), (int)(a.y - ARROW_HITBOX_H / 2),
            ARROW_HITBOX_W, ARROW_HITBOX_H
        };
        if (rectsOverlap(playerBox, box)) {
            a.active = false;
            total += MinionArrow::DAMAGE;
        }
    }
    return total;
}

void ArcherMinion::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_Texture* tex = attacking ? texAttack : texIdle;
    if (tex) {
        const SDL_Rect src = attacking ? attackAnim.getCurrentFrame() : idleAnim.getCurrentFrame();
        // Кадр шире тела и тело в нём не по центру: при отражении точка
        // привязки (центр тела) зеркалится внутри кадра
        const int anchorX = facingRight ? BODY_CENTER_X : FRAME_W - BODY_CENTER_X;
        const SDL_Rect dst = {
            (int)x - anchorX - cx,
            (int)(y + height / 2) - FEET_Y - cy,
            FRAME_W, FRAME_H
        };
        const SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, tex, &src, &dst, 0, nullptr, flip);
    } else {
        SDL_SetRenderDrawColor(renderer, 30, 200, 60, 255); // зелёный — заглушка, если спрайт не найден
        SDL_Rect rect = {
            (int)(x - width / 2) - cx, (int)(y - height / 2) - cy,
            (int)width, (int)height
        };
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_SetRenderDrawColor(renderer, 200, 200, 60, 255);
    for (const auto& a : arrows) {
        if (!a.active) continue;
        if (texArrow) {
            const double angleDeg = std::atan2(a.velY, a.velX) * 180.0 / M_PI;
            SDL_Rect dst = {
                (int)(a.x - ARROW_SPRITE_SIZE / 2) - cx, (int)(a.y - ARROW_SPRITE_SIZE / 2) - cy,
                ARROW_SPRITE_SIZE, ARROW_SPRITE_SIZE
            };
            SDL_RenderCopyEx(renderer, texArrow, nullptr, &dst, angleDeg, nullptr, SDL_FLIP_NONE);
        } else {
            SDL_Rect box = {
                (int)(a.x - ARROW_HITBOX_W / 2) - cx, (int)(a.y - ARROW_HITBOX_H / 2) - cy,
                ARROW_HITBOX_W, ARROW_HITBOX_H
            };
            SDL_RenderFillRect(renderer, &box);
        }
    }
}