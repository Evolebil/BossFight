/**
 * @file ground_minion.cpp
 * @brief Реализация наземного миньона
 * @author evol
 * @date 2026-09-03
 */
#include "ground_minion.h"
#include "../levels/ilevel.h"
#include "../utils/camera.h"

extern ILevel* g_currentLevel;

GroundMinion::GroundMinion(float spawnX, float spawnY, float doorTargetX, int phase)
    : Character(spawnX, spawnY, WIDTH, HEIGHT, BASE_HP)
{
    phaseIndex = std::clamp(phase - 1, 0, 3);
    doorX = doorTargetX;
}

void GroundMinion::update(float deltaTime) {
    if (isDead()) return; // GameScene удалит на следующем кадре

    const GroundMinionPhaseParams& p = PHASE_PARAMS[phaseIndex];

    velocityX = -p.speed; // дверь всегда левее точки спавна
    facingRight = false;

    float groundY = 0.0f;
    if (g_currentLevel && g_currentLevel->getStairGroundY(x, groundY)) {
        // На лестнице — идём точно по гипотенузе, гравитация не нужна
        y = groundY - height / 2.0f;
        velocityY = 0.0f;
        isGrounded = true;
        x += velocityX * deltaTime;
    } else {
        x += velocityX * deltaTime;
        applyCollisionsX();
        applyGravityAndCollisions(deltaTime);
    }

    if (attackTimer > 0.0f) attackTimer -= deltaTime;

    if (x <= doorX) doorReached = true;
}

void GroundMinion::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_SetRenderDrawColor(renderer, 150, 30, 200, 255); // фиолетовый — заглушка
    SDL_Rect rect = {
        (int)(x - width / 2) - cx,
        (int)(y - height / 2) - cy,
        (int)width, (int)height
    };
    SDL_RenderFillRect(renderer, &rect);

    // Полоска HP над головой
    const int barX = (int)(x - HP_BAR_W / 2) - cx;
    const int barY = (int)(y - height / 2) - cy - HP_BAR_OFFSET;
    const float pct = getHP() / getMaxHP();

    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
    SDL_Rect bg = {barX, barY, HP_BAR_W, HP_BAR_H};
    SDL_RenderFillRect(renderer, &bg);

    SDL_SetRenderDrawColor(renderer, 220, 50, 50, 255);
    SDL_Rect bar = {barX, barY, (int)(HP_BAR_W * pct), HP_BAR_H};
    SDL_RenderFillRect(renderer, &bar);

    SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
    SDL_RenderDrawRect(renderer, &bg);
}

float GroundMinion::checkPlayerDamage(SDL_Rect playerBox) {
    const GroundMinionPhaseParams& p = PHASE_PARAMS[phaseIndex];
    if (!p.canAttack || attackTimer > 0.0f || isDead()) return 0.0f;

    if (rectsOverlap(playerBox, getHitbox())) {
        attackTimer = p.attackCooldown;
        return p.attackDamage;
    }
    return 0.0f;
}

bool GroundMinion::consumeKillEvent() {
    if (isDead() && !doorReached && !killEventConsumed) {
        killEventConsumed = true;
        return true;
    }
    return false;
}