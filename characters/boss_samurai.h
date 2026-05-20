/**
 * @file boss_samurai.h
 * @brief Босс-самурай — дуэлянт средней дистанции
 * @author evol
 * @date 2026-05-20
 */
#pragma once
#include "boss.h"

class BossSamurai : public Boss {
private:
    // ============================================================
    // КОНСТАНТЫ
    // ============================================================

    static constexpr float HITBOX_W     = 50.0f;
    static constexpr float HITBOX_H     = 60.0f;
    static constexpr float BASE_HP      = 800.0f;

public:
    BossSamurai(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossSamurai() override = default;

    void update(float deltaTime, float playerX, float playerY) override;
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;

    [[nodiscard]] SDL_Rect getHitbox() const override {
        return { (int)(x - width/2), (int)(y - height/2), (int)width, (int)height };
    }
};