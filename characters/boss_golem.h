/**
 * @file boss_golem.h
 * @brief Босс-голем — две фазы, паттерны атак, телепорт
 * @author evol
 * @date 2026-02-20
 */

#pragma once
#include "../config/common.h"
#include "../utils/animation.h"
#include "../utils/texture_manager.h"
#include "../config/config.h"
#include "character.h"

// --- Снаряд ---
struct Projectile {
    float x, y;
    float velX, velY;
    float damage;
    bool  active;
    float trackingTime;
    float targetX, targetY;
    bool  predictive;
};

// --- Лазер (только фаза 1) ---
struct LaserBeam {
    bool  active;
    float x, y;
    bool  facingRight;
    float damagePerSec;
    float height;
};

// --- Фаза босса ---
enum class BossPhase {
    PHASE_1,        // обычная
    DYING,          // анимация смерти фазы 1 проигрывается
    PAUSING,        // пауза после смерти (игрок радуется)
    TRANSITIONING,  // воскрешение (HURT наоборот)
    PHASE_2         // агрессивная
};

// --- Паттерн ближней атаки фазы 2 ---
enum class MeleePattern {
    NONE,
    DOUBLE_STRIKE,         // удар → 0.2 сек → удар (то же направление)
    DOUBLE_DIRECTION,      // удар → мгновенный разворот → удар в другую сторону
    STRIKE_TELEPORT_RANGE  // удар → телепорт назад → снаряды
};

/**
 * @class BossGolem
 * @brief Первый босс игры. Две фазы, три паттерна ближней атаки в фазе 2.
 *
 * Переход фаза1→фаза2:
 *   HP=0 → DYING (анимация смерти) → PAUSING (1.5 сек пауза) → TRANSITIONING (воскрешение) → PHASE_2
 */
class BossGolem : public Character {
private:
    // --- Состояния ---
    BossState currentState;
    BossState previousState;

    // --- Фаза ---
    BossPhase phase;
    float     phaseTimer;       // таймер для DYING/PAUSING/TRANSITIONING
    bool      phase2Triggered;

    // --- Паттерн ближней атаки (фаза 2) ---
    MeleePattern currentMeleePattern;
    int          meleePatternStep;
    float        meleePatternTimer;
    bool         meleeTeleportDone;
    float        meleeAttackDirX;
    bool         patternFacingRight;

    // --- Телепорт ---
    bool  isTeleporting;
    float teleportTargetX;
    float teleportTargetY;

    // --- Анимации ---
    std::map<BossState, Animation> animations;
    Animation reviveAnim;

    // --- Боевые параметры ---
    float defense;
    float moveSpeed;
    int   cellSize;

    // --- Таймеры ---
    float attackCooldown;
    float attackTimer;
    float blockCooldown;
    float blockTimer;
    float blockDuration;
    float blockActiveTimer;
    float stateTimer;
    float lastStateChangeTime;

    // --- Атаки ---
    bool  meleeHitDealt;
    bool  meleeSecondHitDealt;
    float meleeHitTime;
    std::vector<Projectile> projectiles;
    LaserBeam laser;
    bool  attackSpawned;

    // --- Очередь снарядов ---
    int   projectileQueue;
    float projectileQueueTimer;
    float lastPlayerX, lastPlayerY;

    // --- Сложность ---
    float attackSpeedMult;

    // --- Текстуры ---
    SDL_Texture* armTexture;
    SDL_Texture* laserTexture;

    // --- Константы урона ---
    static constexpr float DAMAGE_MELEE        = 25.0f;
    static constexpr float DAMAGE_MELEE_P2     = 30.0f;
    static constexpr float DAMAGE_RANGE        = 15.0f;
    static constexpr float DAMAGE_RANGE_P2     = 20.0f;
    static constexpr float DAMAGE_LASER_SEC    = 30.0f;

    // --- Дистанции ---
    static constexpr float RANGE_MELEE  = 2.0f;
    static constexpr float RANGE_RANGED = 6.0f;
    static constexpr float RANGE_LASER  = 12.0f;

    // --- Скорости ---
    static constexpr float PROJECTILE_SPEED = 400.0f;
    static constexpr float TELEPORT_SPEED   = 1200.0f;

    // --- Прочее ---
    static constexpr float STATE_CHANGE_COOLDOWN = 0.5f;
    static constexpr float SPRITE_SCALE          = 2.5f;
    static constexpr float BLOCK_HP_THRESHOLD    = 0.7f;
    static constexpr float PHASE2_PAUSE_DURATION = 1.5f; // пауза между смертью и воскрешением

    // --- RNG ---
    std::mt19937 rng;

public:
    BossGolem(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossGolem() override = default;

    void update(float deltaTime, float playerX, float playerY);
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    [[nodiscard]] float     getDefense() const { return defense; }
    [[nodiscard]] BossState getState()   const { return currentState; }
    [[nodiscard]] BossPhase getPhase()   const { return phase; }

    [[nodiscard]] SDL_Rect getHitbox() const {
        return { (int)(x - width/2), (int)(y - height/2), (int)width, (int)height };
    }

    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerHitbox, float deltaTime);

private:
    void loadAnimations();
    void loadAttackTextures();

    void updateAI(float deltaTime, float playerX, float playerY);
    void updateAI_Phase1(float deltaTime, float playerX, float playerY);
    void updateAI_Phase2(float deltaTime, float playerX, float playerY);

    // Переход фаза 1 → фаза 2
    void updatePhaseTransition(float deltaTime);

    void startMeleePattern(float playerX, float playerY);
    void updateMeleePattern(float deltaTime);

    void startTeleport(float targetX, float targetY);
    void updateTeleport(float deltaTime);

    void setState(BossState newState);
    void forceState(BossState newState);
    [[nodiscard]] bool canChangeState() const;

    void spawnProjectile(float playerX, float playerY, bool predictive = false);
    void spawnLaser(bool phase2 = false);

    void renderProjectiles(SDL_Renderer* renderer);
    void renderLaser(SDL_Renderer* renderer);
};