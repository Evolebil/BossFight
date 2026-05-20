/**
 * @file boss_samurai.cpp
 * @brief Реализация босса-самурая
 * @author evol
 * @date 2026-05-20
 */
#include "boss_samurai.h"

BossSamurai::BossSamurai(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
{}

void BossSamurai::update(float deltaTime, float playerX, float playerY) {
    lastPlayerX = playerX;
    lastPlayerY = playerY;
}

void BossSamurai::render(SDL_Renderer* renderer) {
    // Заглушка — красный прямоугольник
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;
    SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
    SDL_Rect rect = {
        (int)(x - width/2) - cx,
        (int)(y - height/2) - cy,
        (int)width, (int)height
    };
    SDL_RenderFillRect(renderer, &rect);
}