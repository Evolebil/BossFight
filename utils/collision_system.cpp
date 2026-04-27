/**
 * @file collision_system.cpp
 * @brief Реализация системы коллизий
 * @author evol
 * @date 2026-02-20
 */

#include "collision_system.h"
#include "../levels/ilevel.h"
#include "../levels/level1_assets.h"  // для TILE_SIZE
// Объявлен в ilevel.cpp
extern ILevel* g_currentLevel;

// ============================================================
// resolveX — коллизии по горизонтали
// ============================================================

void CollisionSystem::resolveX(float& x, float y, float& velocityX, float width, float height) {
    if (!g_currentLevel) return;

    const float hw = width  / 2.0f;
    const float hh = height / 2.0f;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);

    const int checkTop    = (int)(y - hh + 4);
    const int checkBottom = (int)(y + hh - 4);

    if (velocityX < 0) {
        int leftX = (int)(x - hw);
        if (g_currentLevel->isSolid(leftX, checkTop) ||
            g_currentLevel->isSolid(leftX, checkBottom)) {
            int col = (leftX - ox) / TILE_SIZE;
            x = static_cast<float>(ox + (col + 1) * TILE_SIZE) + hw;
            velocityX = 0;
        }
    }

    if (velocityX > 0) {
        int rightX = (int)(x + hw);
        if (g_currentLevel->isSolid(rightX, checkTop) ||
            g_currentLevel->isSolid(rightX, checkBottom)) {
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
                               float width, float height, bool& isGrounded,
                               bool ignorePlatforms) {
    if (!g_currentLevel) return;

    const float hw = width  / 2.0f;
    const float hh = height / 2.0f;

    int ox, oy;
    g_currentLevel->getMapOffset(ox, oy);

    isGrounded = false;

    const int checkLeft  = (int)(x - hw + 4);
    const int checkRight = (int)(x + hw - 4);

    if (velocityY >= 0) {
        int bottomY = (int)(y + hh);

        if (g_currentLevel->isSolid(checkLeft, bottomY) ||
            g_currentLevel->isSolid(checkRight, bottomY)) {
            int row = (bottomY - oy) / TILE_SIZE;
            y = static_cast<float>(oy + row * TILE_SIZE) - hh;
            velocityY  = 0;
            isGrounded = true;
        }

        if (!isGrounded && !ignorePlatforms) {
            bool platLeft  = g_currentLevel->isPlatform(checkLeft,  bottomY);
            bool platRight = g_currentLevel->isPlatform(checkRight, bottomY);

            if (platLeft || platRight) {
                int platRow  = (bottomY - oy) / TILE_SIZE;
                int platTopY = oy + platRow * TILE_SIZE;

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

    if (velocityY < 0) {
        int topY = (int)(y - hh);
        if (g_currentLevel->isSolid(checkLeft, topY) ||
            g_currentLevel->isSolid(checkRight, topY)) {
            int row = (topY - oy) / TILE_SIZE;
            y = static_cast<float>(oy + (row + 1) * TILE_SIZE) + hh;
            velocityY = 0;
        }
    }
}