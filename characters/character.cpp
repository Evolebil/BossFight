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

void Character::applyGravityAndCollisions(float deltaTime) {
    // Гравитация — только если в воздухе
    if (!isGrounded) {
        velocityY += GRAVITY * deltaTime;
        if (velocityY > MAX_FALL_SPEED) velocityY = MAX_FALL_SPEED;
    }

    // Двигаем по Y → разрешаем коллизии
    y += velocityY * deltaTime;
    CollisionSystem::resolveY(x, y, velocityY, width, height, isGrounded);
}

void Character::applyCollisionsX() {
    CollisionSystem::resolveX(x, y, velocityX, width, height);
}
