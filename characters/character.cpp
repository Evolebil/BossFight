/**
 * @file character.cpp
 * @brief Реализация базового класса Character
 * @author evol
 * @date 2026-02-20
 */

#include "character.h"

Character::Character(float spawnX, float spawnY, float w, float h, float health)
    : x(spawnX), y(spawnY),
    velocityX(0), velocityY(0),
    width(w), height(h),
    hp(health), maxHP(health),
    isGrounded(false),
    facingRight(true),
    spritesheet(nullptr)
{}

void Character::takeDamage(float damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

void Character::heal(float amount) {
    hp += amount;
    if (hp > maxHP) hp = maxHP;
}

void Character::applyGravityAndCollisions(float deltaTime, bool ignorePlatforms) {
    // Гравитация — только если в воздухе
    if (!isGrounded) {
        velocityY += GRAVITY * deltaTime;
        if (velocityY > MAX_FALL_SPEED) velocityY = MAX_FALL_SPEED;
    }

    // Двигаем по Y → разрешаем коллизии
    y += velocityY * deltaTime;
    CollisionSystem::resolveY(x, y, velocityY, width, height, isGrounded, ignorePlatforms);
}

void Character::applyCollisionsX() {
    CollisionSystem::resolveX(x, y, velocityX, width, height);
}

void Character::renderDebugBounds(SDL_Renderer* renderer, float spriteW, float spriteH) const {
    // Вычисляем координаты хитбокса (x, y — центр)
    int left   = static_cast<int>(x - spriteW / 2.0f);
    int top    = static_cast<int>(y - spriteH / 2.0f);
    int right  = left + static_cast<int>(spriteW);
    int bottom = top + static_cast<int>(spriteH);

    // Прямоугольник хитбокса (ЗЕЛЁНЫЙ = физический хитбокс для коллизий)
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect hitbox = {left, top, static_cast<int>(spriteW), static_cast<int>(spriteH)};
    SDL_RenderDrawRect(renderer, &hitbox);

    // Центр (БЕЛАЯ ТОЧКА)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, static_cast<int>(x), static_cast<int>(y));

    // Направление взгляда (СИНЯЯ СТРЕЛКА)
    SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
    int arrowLen = static_cast<int>(spriteW / 4.0f);
    int arrowX = facingRight ? right : left;
    SDL_RenderDrawLine(renderer, static_cast<int>(x), static_cast<int>(y),
                       arrowX, static_cast<int>(y));

    // Статус заземления (ЖЁЛТАЯ ЛИНИЯ снизу если isGrounded)
    if (isGrounded) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderDrawLine(renderer, left, bottom, right, bottom);
    }
}