/**
 * @file boss_archer.cpp
 * @brief Реализация босса-лучника
 * @author evol
 * @date 2026-06-03
 */
#include "boss_archer.h"

BossArcher::BossArcher(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
{
}

void BossArcher::update(float deltaTime, float playerX, float playerY,
                        bool /*playerFacingRight*/) {
    stateTimer += deltaTime;
    lastPlayerX = playerX;
    lastPlayerY = playerY;
    applyGravityAndCollisions(deltaTime);
}

void BossArcher::render(SDL_Renderer* renderer) {
    // Заглушка — оранжевый прямоугольник
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;
    SDL_SetRenderDrawColor(renderer, 200, 80, 0, 255);
    SDL_Rect rect = {
        (int)(x - width  / 2) - cx,
        (int)(y - height / 2) - cy,
        (int)width, (int)height
    };
    SDL_RenderFillRect(renderer, &rect);
}

[[nodiscard]] SDL_Rect BossArcher::getHitbox() const {
    return {
        (int)(x - width  / 2),
        (int)(y - height / 2),
        (int)width,
        (int)height
    };
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
}

bool BossArcher::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}