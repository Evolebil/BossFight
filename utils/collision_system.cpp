/**
 * @file collision_system.cpp
 * @brief Реализация системы коллизий
 * @author evol
 * @date 2026-02-20
 */

#include "collision_system.h"
#include "../levels/level1_assets.h"

// ============================================================
// resolveX — коллизии по горизонтали
// ============================================================

void CollisionSystem::resolveX(float& x, float y, float& velocityX, float width, float height) {
    const float hw = width  / 2.0f;
    const float hh = height / 2.0f;

    int ox, oy;
    getMapOffset(ox, oy);

    // Проверяем два пикселя по вертикали — чуть внутрь чтобы не цеплять угол тайла
    const int checkTop    = (int)(y - hh + 4);
    const int checkBottom = (int)(y + hh - 4);

    // Левый край — только если движемся влево
    if (velocityX < 0) {
        int leftX = (int)(x - hw);
        if (isSolidAt(leftX, checkTop) || isSolidAt(leftX, checkBottom)) {
            // Ставим вплотную к правой стороне тайла слева
            int col = (leftX - ox) / TILE_SIZE;
            x = static_cast<float>(ox + (col + 1) * TILE_SIZE) + hw;
            velocityX = 0;
        }
    }

    // Правый край — только если движемся вправо
    if (velocityX > 0) {
        int rightX = (int)(x + hw);
        if (isSolidAt(rightX, checkTop) || isSolidAt(rightX, checkBottom)) {
            // Ставим вплотную к левой стороне тайла справа
            int col = (rightX - ox) / TILE_SIZE;
            x = static_cast<float>(ox + col * TILE_SIZE) - hw;
            velocityX = 0;
        }
    }
}

// ============================================================
// resolveY — коллизии по вертикали
// ============================================================

void CollisionSystem::resolveY(float x, float& y, float& velocityY,
                               float width, float height, bool& isGrounded) {
    const float hw = width  / 2.0f;
    const float hh = height / 2.0f;

    int ox, oy;
    getMapOffset(ox, oy);

    // Сбрасываем isGrounded — будет выставлен заново если стоим на чём-то
    isGrounded = false;

    // Проверяем два пикселя по горизонтали — чуть внутрь чтобы не цеплять угол тайла
    const int checkLeft  = (int)(x - hw + 4);
    const int checkRight = (int)(x + hw - 4);

    // ШАГ 1: НИЖНИЙ КРАЙ — падаем вниз или стоим
    if (velocityY >= 0) {
        int bottomY = (int)(y + hh);

        // Сплошной пол/стена снизу
        // ВАЖНО: проверяем bottomY, не bottomY+1 — иначе телепортация!
        if (isSolidAt(checkLeft, bottomY) || isSolidAt(checkRight, bottomY)) {
            int row = (bottomY - oy) / TILE_SIZE;
            // Ставим вплотную к верхней стороне тайла
            y = static_cast<float>(oy + row * TILE_SIZE) - hh;
            velocityY  = 0;
            isGrounded = true;
        }

        // Платформы — ТОЛЬКО если не попали на сплошной пол
        // Механика: платформа работает только при падении сверху вниз.
        // Если bottomY попал в верхнюю четверть тайла — приземляемся.
        // Если глубже — значит игрок прыгнул снизу — пропускаем.
        if (!isGrounded) {
            bool platLeft  = isPlatformAt(checkLeft,  bottomY);
            bool platRight = isPlatformAt(checkRight, bottomY);

            if (platLeft || platRight) {
                int platRow  = (bottomY - oy) / TILE_SIZE;
                int platTopY = oy + platRow * TILE_SIZE;

                // TILE_SIZE/4 — допуск приземления.
                // Слишком маленький — легко провалиться при лагах FPS.
                // Слишком большой — платформа "притягивает" слишком рано.
                bool landingFromAbove = (bottomY >= platTopY) &&
                                        (bottomY <= platTopY + TILE_SIZE / 4);

                if (landingFromAbove) {
                    y = static_cast<float>(platTopY) - hh;
                    velocityY  = 0;
                    isGrounded = true;
                }
            }
        }
    }

    // ШАГ 2: ВЕРХНИЙ КРАЙ — прыгаем вверх
    // Платформы сверху НЕ блокируют — можно прыгать сквозь них.
    if (velocityY < 0) {
        int topY = (int)(y - hh);
        if (isSolidAt(checkLeft, topY) || isSolidAt(checkRight, topY)) {
            int row = (topY - oy) / TILE_SIZE;
            // Ставим вплотную к нижней стороне тайла потолка
            y = static_cast<float>(oy + (row + 1) * TILE_SIZE) + hh;
            velocityY = 0;
        }
    }
}
