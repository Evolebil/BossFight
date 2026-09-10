/**
 * @file ground_minion.h
 * @brief Наземный миньон третьего босса — идёт к двери, с фазы 2 атакует.
 * @author evol
 * @date 2026-09-03
 */
#pragma once
#include "character.h"
#include "../utils/animation.h"
#include "../utils/texture_manager.h"

struct GroundMinionPhaseParams {
    float speed;
    float attackDamage;
    float attackCooldown;
    bool  canAttack;
};

class GroundMinion : public Character {
private:
    static constexpr float WIDTH  = 50.0f;
    static constexpr float HEIGHT = 50.0f;
    static constexpr float BASE_HP = 50.0f; // 2 удара базовой атакой игрока (25×2)

    // TODO: точные числа не зафиксированы в ТЗ — временные, требуют подтверждения/подбора
    static constexpr GroundMinionPhaseParams PHASE_PARAMS[4] = {
        {80.0f,  0.0f,  0.0f, false}, // Фаза 1 — не атакует
        {110.0f, 10.0f, 1.5f, true},  // Фаза 2
        {140.0f, 15.0f, 1.2f, true},  // Фаза 3
        {170.0f, 20.0f, 1.0f, true},  // Фаза 4 — максимум
    };

    static constexpr int   HP_BAR_W      = 40;
    static constexpr int   HP_BAR_H      = 5;
    static constexpr int   HP_BAR_OFFSET = 10; // отступ над головой

    // ============================================================
    // АНИМАЦИИ — размер кадра 50×50, совпадает с хитбоксом
    // ============================================================
    static constexpr int FRAME_SIZE = 50;

    // summonAppear.png 150×100 → 3×2 = 6 кадров, one-shot
    static constexpr int APPEAR_FRAMES_X = 3;
    static constexpr int APPEAR_FRAMES_Y = 2;
    static constexpr float APPEAR_FRAME_DUR = 0.08f; // TODO: подобрать

    // summonIdle.png 200×50 → 4×1 = 4 кадра, loop
    static constexpr int WALK_FRAMES_X = 4;
    static constexpr int WALK_FRAMES_Y = 1;
    static constexpr float WALK_FRAME_DUR = 0.1f; // TODO: подобрать

    // summonDeath.png 150×100 → 3×2 = 6 кадров, one-shot
    static constexpr int DEATH_FRAMES_X = 3;
    static constexpr int DEATH_FRAMES_Y = 2;
    static constexpr float DEATH_FRAME_DUR = 0.08f; // TODO: подобрать

    int   phaseIndex = 0; // 0..3
    float doorX       = 0.0f;
    float attackTimer  = 0.0f;
    bool  doorReached  = false;
    bool  killEventConsumed = false;

    // --- Жизненный цикл анимаций ---
    bool appearing   = true;  // проигрывает summonAppear, движение заморожено
    bool dying       = false; // умер или дошёл до двери — играет summonDeath
    bool deathAnimDone = false; // true когда summonDeath доигран — можно удалять объект

    SDL_Texture* texAppear = nullptr;
    SDL_Texture* texWalk   = nullptr;
    SDL_Texture* texDeath  = nullptr;

    Animation appearAnim{false};
    Animation walkAnim{true};
    Animation deathAnim{false};

    void loadAnimations();
    void startDying(); // общий переход в "умирает/исчезает"

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
    // Объект убирается из мира только ПОСЛЕ того как доиграна анимация исчезновения
    [[nodiscard]] bool shouldRemove() const { return deathAnimDone; }

    /// true РОВНО ОДИН РАЗ — когда смерть засчитывается как убийство (не через дверь)
    bool consumeKillEvent();
};