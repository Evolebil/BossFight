/**
 * @file boss.h
 * @brief Базовый класс для всех боссов игры
 * @author evol
 * @date 2026-05-20
 */
#pragma once
#include "character.h"
#include "../utils/animation.h"
#include "../utils/camera.h"

/**
 * @class Boss
 * @brief Промежуточный класс между Character и конкретными боссами.
 *
 * Содержит только то что гарантированно нужно ВСЕМ боссам:
 * - множитель скорости атак (сложность)
 * - последняя известная позиция игрока
 * - размер карты для ограничения движения
 * - флаг отладочных хитбоксов
 */
class Boss : public Character {
protected:
    float attackSpeedMult = 1.0f;

    float lastPlayerX = 0.0f;
    float lastPlayerY = 0.0f;

    int mapW = 0;
    int mapH = 0;
    float defense = 0.0f;

    std::mt19937 rng{ std::random_device{}() };

public:
    bool showHitboxes = false;

    Boss(float spawnX, float spawnY, float w, float h, float health,
         float attackSpeedMult = 1.0f);
    ~Boss() override = default;

    void setMapSize(int w, int h) { mapW = w; mapH = h; }
    void takeDamage(float damage) override;

    virtual void update(float deltaTime, float playerX, float playerY) = 0;

    void update(float deltaTime) override { (void)deltaTime; }

    virtual void render(SDL_Renderer* renderer) override = 0;

    [[nodiscard]] virtual SDL_Rect getHitbox() const override = 0;

};