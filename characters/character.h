/**
 * @file character.h
 * @brief Базовый класс для всех персонажей игры
 * @author evol
 * @date 2026-02-20
 *
 * От Character наследуются:
 *   - Player  (управление, прыжки, атака)
 *   - BossGolem, BossNinja, ... (AI, состояния)
 *
 * Character хранит всё общее: позицию, физику, HP, спрайтшит.
 * Дочерние классы добавляют свою логику.
 */

#pragma once
#include "../config/common.h"
#include "../utils/animation.h"
#include "../utils/collision_system.h"

/**
 * @class Character
 * @brief Абстрактный базовый класс персонажа.
 *
 * Содержит:
 * - Позицию и физику (x, y, velocityX, velocityY, гравитация)
 * - Здоровье (hp, maxHP)
 * - Хитбокс (width, height)
 * - Направление взгляда (facingRight)
 * - Спрайтшит (spritesheet)
 *
 * Дочерние классы ОБЯЗАНЫ реализовать:
 * - update(float deltaTime)  — своя логика обновления
 * - render(SDL_Renderer*)    — своя отрисовка
 */
class Character {
protected:
    // --- Позиция и физика ---
    float x, y;
    float velocityX, velocityY;
    float width, height;

    // --- Здоровье ---
    float hp, maxHP;

    // --- Состояние ---
    bool isGrounded;
    bool facingRight;

    // --- Графика ---
    SDL_Texture* spritesheet;

    // --- Физические константы ---
    // NOTE: дочерний класс может переопределить через свои constexpr
    static constexpr float GRAVITY        = 980.0f;
    static constexpr float MAX_FALL_SPEED = 600.0f;

public:
    /**
     * @brief Конструктор — инициализирует общие поля
     * @param spawnX  Начальная позиция X
     * @param spawnY  Начальная позиция Y
     * @param w       Ширина хитбокса
     * @param h       Высота хитбокса
     * @param health  Начальное и максимальное HP
     */
    Character(float spawnX, float spawnY, float w, float h, float health);

    // Виртуальный деструктор — ОБЯЗАТЕЛЕН для базового класса с virtual методами
    virtual ~Character() = default;

    // --- Основной цикл (чистые виртуальные — дочерний класс ОБЯЗАН реализовать) ---
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;

    // --- Геттеры (общие для всех персонажей) ---
    [[nodiscard]] float getX()     const { return x; }
    [[nodiscard]] float getY()     const { return y; }
    [[nodiscard]] float getHP()    const { return hp; }
    [[nodiscard]] float getMaxHP() const { return maxHP; }
    [[nodiscard]] bool  isAlive()  const { return hp > 0; }

    // --- Взаимодействие ---
    // NOTE: virtual — босс переопределяет (учитывает defense)
    virtual void takeDamage(float damage);
    void heal(float amount);
    void renderDebugBounds(SDL_Renderer* renderer, float spriteW, float spriteH) const;

protected:
    /**
     * @brief Применяет гравитацию и разрешает коллизии по Y.
     *
     * Вызывать каждый кадр в update() дочернего класса.
     * Обновляет y, velocityY, isGrounded.
     *
     * @param deltaTime Время кадра в секундах
     */
    void applyGravityAndCollisions(float deltaTime);

    /**
     * @brief Разрешает коллизии по X после движения.
     *
     * Вызывать ПОСЛЕ x += velocityX * deltaTime.
     * Обновляет x и velocityX при столкновении со стеной.
     */
    void applyCollisionsX();
};
