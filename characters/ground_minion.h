/**
 * @file ground_minion.h
 * @brief Наземный миньон третьего босса — идёт к двери, с фазы 2 атакует.
 * @author evol
 * @date 2026-09-03
 *
 * ЗАГЛУШКА ГРАФИКИ: фиолетовый прямоугольник.
 *
 * ПУТЬ К ДВЕРИ (Level3): спавнится на верхней площадке рядом с боссом,
 * падает на неё через обычную гравитацию, идёт влево, доходит до лестницы
 * (col 25..32) — там Y берётся из ILevel::getStairGroundY() (тот же
 * slope-коллайдер, что у игрока), спускается на пол (row27), идёт до
 * двери (col3).
 */
#pragma once
#include "character.h"

struct GroundMinionPhaseParams {
    float speed;
    float attackDamage;
    float attackCooldown;
    bool  canAttack;
};

class GroundMinion : public Character {
private:
    static constexpr float WIDTH  = 50.0f;  // ТЗ: 50×50
    static constexpr float HEIGHT = 50.0f;
    static constexpr float BASE_HP = 50.0f; // 2 удара базовой атакой игрока (25×2)
    static constexpr int   HP_BAR_W      = 40;
    static constexpr int   HP_BAR_H      = 5;
    static constexpr int   HP_BAR_OFFSET = 10; // отступ над головой

    // TODO: точные числа не зафиксированы в ТЗ — временные, требуют подтверждения/подбора
    static constexpr GroundMinionPhaseParams PHASE_PARAMS[4] = {
        {80.0f,  0.0f,  0.0f, false}, // Фаза 1 — не атакует
        {110.0f, 10.0f, 1.5f, true},  // Фаза 2
        {140.0f, 15.0f, 1.2f, true},  // Фаза 3
        {170.0f, 20.0f, 1.0f, true},  // Фаза 4 — максимум
    };

    int   phaseIndex = 0; // 0..3
    float doorX       = 0.0f;
    float attackTimer  = 0.0f;
    bool  doorReached  = false;
    bool  killEventConsumed = false;

public:
    GroundMinion(float spawnX, float spawnY, float doorTargetX, int phase /*1..4*/);
    ~GroundMinion() override = default;

    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;

    [[nodiscard]] SDL_Rect getHitbox() const override {
        return { (int)(x - width / 2), (int)(y - height / 2), (int)width, (int)height };
    }

    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox);

    [[nodiscard]] bool isDead()       const { return hp <= 0.0f; }
    [[nodiscard]] bool reachedDoor()  const { return doorReached; }
    [[nodiscard]] bool shouldRemove() const { return isDead() || doorReached; }

    /// true РОВНО ОДИН РАЗ — когда смерть засчитывается как убийство (не через дверь)
    bool consumeKillEvent();
};