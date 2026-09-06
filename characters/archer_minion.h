/**
 * @file archer_minion.h
 * @brief Стационарный лучник третьего босса — 4 шт., на платформах.
 *        Стреляет N стрел ПОСЛЕДОВАТЕЛЬНО (не одним залпом) по фазе.
 *        Неуязвим — просто спавнер стрел.
 * @author evol
 * @date 2026-09-03
 */
#pragma once
#include "character.h"

struct MinionArrow {
    float x = 0.0f, y = 0.0f;
    float velX = 0.0f, velY = 0.0f;
    bool  active = false;

    // Значения взяты из существующего ArcherArrow (boss_archer.h) — не придумывались заново
    static constexpr float SPEED  = 500.0f;
    static constexpr float DAMAGE = 15.0f;
};

class ArcherMinion : public Character {
private:
    static constexpr float WIDTH  = 50.0f; // ТЗ: 50×60
    static constexpr float HEIGHT = 60.0f;

    static constexpr float VOLLEY_COOLDOWN = 3.0f;  // TODO: подобрать
    static constexpr float ARROW_STAGGER   = 0.15f; // TODO: пауза между стрелами в очереди

    static constexpr int ARROW_HITBOX_W = 20;
    static constexpr int ARROW_HITBOX_H = 8;

    int   phaseIndex        = 0; // 0..3 → 1..4 стрелы
    float volleyTimer       = VOLLEY_COOLDOWN;
    int   arrowsQueued      = 0;
    float arrowStaggerTimer = 0.0f;
    float platformTopY      = 0.0f; // известная Y платформы (спавн — на 1 клетку выше)

    std::vector<MinionArrow> arrows;

    [[nodiscard]] int arrowsPerVolley() const { return phaseIndex + 1; }

public:
    ArcherMinion(float spawnX, float spawnY, int phase /*1..4*/);
    ~ArcherMinion() override = default;

    void update(float deltaTime) override { (void)deltaTime; } // заглушка Character — используем версию ниже
    void update(float deltaTime, float playerX, float playerY);
    void render(SDL_Renderer* renderer) override;

    void takeDamage(float /*damage*/) override {} // неуязвим

    void setPhase(int phase) { phaseIndex = std::clamp(phase - 1, 0, 3); }

    [[nodiscard]] SDL_Rect getHitbox() const override {
        return { (int)(x - width / 2), (int)(y - height / 2), (int)width, (int)height };
    }

    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox);
};