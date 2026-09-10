/**
 * @file boss_deadnight.h
 * @brief Финальный босс "Смерть Ночи" — 4 фазы, летающая неуязвимая стадия
 *        над ареной + уязвимая ближнебойная стадия на земле.
 * @author evol
 * @date 2026-09-03
 */
#pragma once
#include "boss.h"
#include "../utils/texture_manager.h"

// ============================================================
// ФАЙРБОЛ
// ============================================================
struct Fireball {
    float x = 0.0f, y = 0.0f;
    float velX = 0.0f, velY = 0.0f;
    bool  active   = false;
    bool  exploded = false;
    float explodeTimer = 0.0f;  ///< сколько ещё показывать взрыв
    bool  damageDealt   = false;

    Animation explodeAnim{false}; // своя анимация взрыва у каждого файрбола
};

class BossDeadNight : public Boss {
private:
    // ============================================================
    // КОНСТАНТЫ — ХИТБОКС И HP
    // ============================================================
    static constexpr float HITBOX_W = 80.0f;
    static constexpr float HITBOX_H = 100.0f;
    static constexpr float BASE_HP  = 1200.0f;

    // ============================================================
    // КОНСТАНТЫ — БЛИЖНИЙ БОЙ
    // ============================================================
    static constexpr float DAMAGE_MELEE = 30.0f;
    static constexpr float MELEE_HIT_W = HITBOX_W * 2.0f;
    static constexpr float MELEE_HIT_H = HITBOX_H;
    static constexpr float DAMAGE_DASH = DAMAGE_MELEE;

    // ============================================================
    // КОНСТАНТЫ — РЫВКИ
    // ============================================================
    static constexpr int   DASH_COUNT_PER_CYCLE   = 3;
    static constexpr float DASH_SPEED             = 700.0f;
    static constexpr float DASH_DURATION          = 0.25f;
    static constexpr float DASH_BETWEEN_COOLDOWN  = 0.5f;
    static constexpr float RETREAT_SPEED          = 300.0f;
    static constexpr float RETREAT_DURATION       = 0.4f;
    static constexpr float RETREAT_WAIT_BY_PHASE[4] = {5.0f, 4.0f, 3.0f, 2.0f};

    // ============================================================
    // КОНСТАНТЫ — ПОЛЁТ
    // ============================================================
    static constexpr float FLY_SPEED     = 60.0f;
    static constexpr float ASCEND_SPEED  = 200.0f;
    static constexpr float TOP_MARGIN    = 40.0f;
    static constexpr int   FLY_RANGE_MARGIN_TILES = 3;

    // ============================================================
    // КОНСТАНТЫ — ФАЙРБОЛ
    // ============================================================
    static constexpr float FIREBALL_SPRITE_W      = 48.0f;
    static constexpr float FIREBALL_SPRITE_H      = 32.0f;
    static constexpr float FIREBALL_HIT_SIZE      = FIREBALL_SPRITE_W / 2.0f;
    static constexpr float FIREBALL_EXPLODE_RADIUS = FIREBALL_HIT_SIZE * 3.0f;
    static constexpr float FIREBALL_SPEED         = 350.0f;
    static constexpr float FIREBALL_DAMAGE        = 25.0f;
    static constexpr float FIREBALL_COOLDOWN      = 2.0f;
    static constexpr float FIREBALL_EXPLODE_LIFETIME = 0.3f;

    // Explosion_bomb.png 256×256 → 64×64 кадр → 4×4 = 16 кадров, one-shot
    static constexpr int   EXPLODE_FRAME_SIZE = 64;
    static constexpr int   EXPLODE_FRAMES_X = 4;
    static constexpr int   EXPLODE_FRAMES_Y = 4;
    static constexpr float EXPLODE_FRAME_DUR = FIREBALL_EXPLODE_LIFETIME / (EXPLODE_FRAMES_X * EXPLODE_FRAMES_Y);

    // ============================================================
    // КОНСТАНТЫ — ЦИКЛ ФАЗЫ
    // ============================================================
    static constexpr float SURVIVAL_TIME    = 30.0f;
    static constexpr int   MINIONS_REQUIRED = 5;
    static constexpr float PHASE_HP_THRESHOLD[4] = {0.75f, 0.50f, 0.25f, 0.0f};

    static constexpr float STATE_CHANGE_COOLDOWN = 0.2f;

    // ============================================================
    // КОНСТАНТЫ — АНИМАЦИИ (кадр 100×100)
    // ============================================================
    static constexpr int FRAME_SIZE = 100;

    // attacking.png 600×300 → 6×3 = 18 кадров. Длительность всей анимации
    // = DASH_DURATION (рывок должен визуально совпадать с реальным рывком)
    static constexpr int   ATTACKING_FRAMES_X = 6;
    static constexpr int   ATTACKING_FRAMES_Y = 3;
    static constexpr int   ATTACKING_TOTAL_FRAMES = ATTACKING_FRAMES_X * ATTACKING_FRAMES_Y;
    static constexpr float ATTACKING_FRAME_DUR = DASH_DURATION / ATTACKING_TOTAL_FRAMES;

    // death.png 1000×200 → 10×2 = 20 кадров, one-shot
    static constexpr int   DEATH_FRAMES_X = 10;
    static constexpr int   DEATH_FRAMES_Y = 2;
    static constexpr float DEATH_FRAME_DUR = 0.08f; // TODO: подобрать

    // idle.png (полёт наверху) 500×100 → 5×1 = 5 кадров, loop
    static constexpr int   IDLE_FLY_FRAMES_X = 5;
    static constexpr int   IDLE_FLY_FRAMES_Y = 1;
    static constexpr float IDLE_FLY_FRAME_DUR = 0.1f; // TODO: подобрать

    // idle2.png (на земле) 400×200 → 4×2 = 8 кадров, loop
    static constexpr int   IDLE_GROUND_FRAMES_X = 4;
    static constexpr int   IDLE_GROUND_FRAMES_Y = 2;
    static constexpr float IDLE_GROUND_FRAME_DUR = 0.1f; // TODO: подобрать

    // skill1.png (файрбол) 600×200 → 6×2 = 12 кадров, one-shot.
    // Базовая длительность кадра — масштабируется attackSpeedMult в update()
    // (быстрее сложность/фаза → быстрее анимация), поэтому тут фиксированная база.
    static constexpr int   SKILL1_FRAMES_X = 6;
    static constexpr int   SKILL1_FRAMES_Y = 2;
    static constexpr float SKILL1_BASE_FRAME_DUR = 0.05f; // TODO: подобрать базу

    // ============================================================
    // ПОЛЯ
    // ============================================================
    DeadNightState currentState = DeadNightState::FLYING_TOP;
    DeadNightState previousState = DeadNightState::FLYING_TOP;
    DeadNightPhase phase = DeadNightPhase::PHASE_1;

    float stateTimer          = 0.0f;
    float lastStateChangeTime = 0.0f;

    float topY               = 0.0f;
    float flyDirX             = 1.0f;
    float survivalTimer       = 0.0f;
    bool  survivalPassed      = false;
    float fireballTimer       = 0.0f;
    int flyMinCol = 0;
    int flyMaxCol = 0;

    int  minionsKilled = 0;

    int   dashesDoneInCycle = 0;
    float dashTimer         = 0.0f;
    float dashDirX           = 1.0f;
    bool  dashHitDealt       = false;

    bool meleeHitDealt = false;

    std::vector<Fireball> fireballs;

    // --- Анимации ---
    SDL_Texture* texAttacking  = nullptr;
    SDL_Texture* texDeath      = nullptr;
    SDL_Texture* texIdleFly    = nullptr;
    SDL_Texture* texIdleGround = nullptr;
    SDL_Texture* texSkill1     = nullptr;
    SDL_Texture* texProjectile = nullptr;
    SDL_Texture* texExplosion  = nullptr;

    Animation attackingAnim{false};
    Animation deathAnim{false};
    Animation idleFlyAnim{true};
    Animation idleGroundAnim{true};
    Animation skill1Anim{false};

    void loadAnimations();
    void initExplodeAnim(Animation& anim);

public:
    BossDeadNight(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossDeadNight() override = default;

    void update(float deltaTime, float playerX, float playerY, bool playerFacingRight = true) override;
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    [[nodiscard]] SDL_Rect getHitbox() const override {
        return { (int)(x - width / 2), (int)(y - height / 2), (int)width, (int)height };
    }

    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox, float deltaTime);

    void registerMinionKilled();
    void registerMinionReachedDoor();

    [[nodiscard]] int  getMinionsKilled()   const { return minionsKilled; }
    [[nodiscard]] int  getMinionsRequired() const { return MINIONS_REQUIRED; }
    [[nodiscard]] bool isVulnerable()       const {
        return currentState != DeadNightState::FLYING_TOP &&
               currentState != DeadNightState::DESCENDING  &&
               currentState != DeadNightState::ASCENDING   &&
               currentState != DeadNightState::DEATH;
    }
    [[nodiscard]] int  getPhaseNumber() const { return (int)phase + 1; }
    [[nodiscard]] bool getSurvivalPassed() const { return survivalPassed; }
    [[nodiscard]] float getSurvivalTimeLeft() const { return std::max(0.0f, SURVIVAL_TIME - survivalTimer); }

private:
    void setState(DeadNightState newState);
    void forceState(DeadNightState newState);
    [[nodiscard]] bool canChangeState() const;

    void updateFlyingTop(float deltaTime, float playerX, float playerY);
    void updateArena(float deltaTime, float playerX, float playerY);
    void updateDashCycle(float deltaTime, float playerX, float playerY);
    void updateDescending(float deltaTime);
    void updateAscending(float deltaTime);

    void spawnFireball(float playerX, float playerY);
    void updateFireballs(float deltaTime);

    void onPhaseHpThresholdReached();
    void resetForNextPhaseTop();
    [[nodiscard]] float getPhaseTopY() const;

    void renderFireballs(SDL_Renderer* renderer, int camX, int camY);
    void renderHitboxes(SDL_Renderer* renderer, int camX, int camY);
};