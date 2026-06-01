/**
 * @file boss.h
 * @brief Базовый класс для всех боссов игры
 * @author evol
 * @date 2026-05-20
 *
 * Иерархия: Boss → Character
 *
 * Boss добавляет поверх Character:
 *   - attackSpeedMult    — множитель скорости атак (настраивается сложностью)
 *   - lastPlayerX/Y      — последняя известная позиция игрока (нужна для атак)
 *   - mapW / mapH        — размер карты (ограничение движения)
 *   - defense            — снижение получаемого урона (0.0 = нет защиты, 1.0 = полный иммунитет)
 *   - rng                — генератор случайных чисел (паттерны атак, частицы)
 *   - showHitboxes       — отладочный флаг (клавиша H в игре)
 *
 * Каждый дочерний класс (BossGolem, BossSamurai, …) ОБЯЗАН реализовать:
 *   void update(float deltaTime, float playerX, float playerY)
 *   void render(SDL_Renderer* renderer)
 *   SDL_Rect getHitbox() const
 */
#pragma once
#include "character.h"
#include "../utils/animation.h"
#include "../utils/camera.h"
#include <random>

class Boss : public Character {
protected:
    // ---- Сложность ----
    float attackSpeedMult = 1.0f;   ///< Множитель скорости атак (1.0 = нормально)

    // ---- Позиция игрока ----
    float lastPlayerX = 0.0f;       ///< Последняя X игрока — обновляется каждый кадр в update()
    float lastPlayerY = 0.0f;       ///< Последняя Y игрока

    // ---- Карта ----
    int mapW = 0;                   ///< Ширина карты в пикселях
    int mapH = 0;                   ///< Высота карты в пикселях

    // ---- Защита ----
    float defense = 0.0f;           ///< Снижение урона [0.0 … 1.0]

    // ---- Случайные числа ----
    std::mt19937 rng{ std::random_device{}() };  ///< RNG — используется в атаках и частицах

public:
    bool showHitboxes = false;  ///< Включить/выключить отладочные хитбоксы (клавиша H)

    /**
     * @brief Конструктор босса.
     * @param spawnX          Начальная позиция X (центр хитбокса)
     * @param spawnY          Начальная позиция Y (центр хитбокса)
     * @param w               Ширина хитбокса
     * @param h               Высота хитбокса
     * @param health          Максимальное HP
     * @param attackSpeedMult Множитель скорости атак (сложность)
     */
    Boss(float spawnX, float spawnY, float w, float h, float health,
         float attackSpeedMult = 1.0f);

    ~Boss() override = default;

    // ---- Размер карты ----
    void setMapSize(int w, int h) { mapW = w; mapH = h; }

    // ---- Урон с учётом защиты ----
    void takeDamage(float damage) override;

    // ---- Основной update с позицией игрока — реализуют дочерние классы ----
    // Может быть с дополнительными параметрами (например, playerFacingRight для BossSamurai)
    virtual void update(float deltaTime, float playerX, float playerY, bool playerFacingRight = true) = 0;

    // Character::update() — заглушка, боссы используют версию выше
    void update(float deltaTime) override { (void)deltaTime; }

    // ---- Рендер — реализуют дочерние классы ----
    void render(SDL_Renderer* renderer) override = 0;

    // ---- Хитбокс — реализуют дочерние классы ----
    [[nodiscard]] virtual SDL_Rect getHitbox() const override = 0;
};