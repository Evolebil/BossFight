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

void Player::render(SDL_Renderer* renderer) {
    if (!spritesheet) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = {(int)(x - width / 2), (int)(y - height / 2), (int)width, (int)height};
        SDL_RenderFillRect(renderer, &rect);
        return;
    }

    // Получаем ТЕКУЩИЙ фрейм анимации
    SDL_Rect src = {0, 0, 0, 0};
    if (animations.count(currentState)) {
        src = animations[currentState].getCurrentFrame();
    }

    // ВЫЧИСЛЯЕМ размеры спрайта НА ОСНОВЕ ТЕКУЩЕГО ФРЕЙМА
    int dstW = RENDER_W;
    int dstH = RENDER_H;
    int dstX = (int)(x - dstW / 2);
    int dstY = (int)(y - dstH / 2);

    SDL_Rect dst = {dstX, dstY, dstW, dstH};
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer, spritesheet, &src, &dst, 0, nullptr, flip);

    // DEBUG: Рисуем границы ДИНАМИЧЕСКИ из текущего фрейма
    if (showHitboxes) {
        // Спрайт вычисляется из размеров ТЕКУЩЕЙ отрисовки
        renderDebugBounds(renderer,
                          static_cast<float>(dstW),
                          static_cast<float>(dstH));
    }
}