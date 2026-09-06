/**
 * @file archer_minion.cpp
 * @brief Реализация стационарного лучника
 * @author evol
 * @date 2026-09-03
 */
#include "archer_minion.h"
#include "../utils/camera.h"
#include "../levels/level1_assets.h" // TILE_SIZE
#include <cmath>

ArcherMinion::ArcherMinion(float spawnX, float spawnY, int phase)
    : Character(spawnX, spawnY, WIDTH, HEIGHT, 1.0f) // HP не используется — неуязвим
{
    setPhase(phase);
    // Точка спавна — на 1 клетку выше платформы (см. Level3::getMinionSpawn),
    // значит платформа ровно на пол-тайла ниже центра точки спавна
    platformTopY = spawnY + TILE_SIZE / 2.0f;
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
        }
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

    SDL_SetRenderDrawColor(renderer, 30, 200, 60, 255); // зелёный — заглушка
    SDL_Rect rect = {
        (int)(x - width / 2) - cx, (int)(y - height / 2) - cy,
        (int)width, (int)height
    };
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 200, 200, 60, 255);
    for (const auto& a : arrows) {
        if (!a.active) continue;
        SDL_Rect box = {
            (int)(a.x - ARROW_HITBOX_W / 2) - cx, (int)(a.y - ARROW_HITBOX_H / 2) - cy,
            ARROW_HITBOX_W, ARROW_HITBOX_H
        };
        SDL_RenderFillRect(renderer, &box);
    }
}