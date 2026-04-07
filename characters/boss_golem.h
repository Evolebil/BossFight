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
#include "../utils/camera.h"

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

// --- Лазер ---
struct LaserBeam {
    bool  active;
    float x, y;
    bool  facingRight;
    float damagePerSec;
    float height;
};

// --- Шипы (атака прыжком по площади) ---
struct GroundSpike {
    SDL_Rect rect;   // позиция и размер на экране
    float    damage;
    float    lifetime;
    bool     active;
    bool     hitDealt; // урон наносится только один раз
};

// --- Фаза босса ---
enum class BossPhase {
    PHASE_1,
    DYING,
    PAUSING,
    TRANSITIONING,
    PHASE_2
};

// --- Паттерн ближней атаки фазы 2 ---
enum class MeleePattern {
    NONE,
    DASH_STRIKE,        // два очень быстрых удара
    JUMP_SLAM,            // прыжок → приземление → шипы по площади
    TELEPORT_LASER        // удар → телепорт → лазер на всю карту через 0.1 сек
};

/**
 * @class BossGolem
 * @brief Первый босс игры. Две фазы, три паттерна ближней атаки в фазе 2.
 */
class BossGolem : public Character {
private:
    // --- Состояния ---
    BossState currentState;
    BossState previousState;

    // --- Фаза ---
    BossPhase phase;
    float     phaseTimer;
    bool      phase2Triggered;

    // --- Паттерн ближней атаки (фаза 2) ---
    MeleePattern currentMeleePattern;
    int          meleePatternStep;
    float        meleePatternTimer;
    bool         meleeTeleportDone;
    float        meleeAttackDirX;
    bool         patternFacingRight;

    // --- Прыжок (JUMP_SLAM) ---
    bool  isJumping;
    float jumpVelocityY;
    bool  jumpLanded;

    // --- Шипы ---
    std::vector<GroundSpike> groundSpikes;

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
    static constexpr float DAMAGE_MEGA_LASER_SEC = 50.0f;
    static constexpr float DAMAGE_SPIKE        = 35.0f;

    // --- Дистанции (в клетках) ---
    static constexpr float RANGE_MELEE  = 2.0f;
    static constexpr float RANGE_RANGED = 99.0f;
    static constexpr float RANGE_LASER  = 6.0f;

    // --- Скорости ---
    static constexpr float PROJECTILE_SPEED  = 400.0f;
    static constexpr float TELEPORT_SPEED    = 3000.0f;
    static constexpr float TELEPORT_P2_CELLS = 8.0f;

    // --- Прочее ---
    static constexpr float STATE_CHANGE_COOLDOWN = 0.5f;
    static constexpr float SPRITE_SCALE          = 2.5f;
    static constexpr int   SPRITE_OFFSET_Y       = 0;//подбор насколько спрайт сходиться по высоте
    static constexpr float BLOCK_HP_THRESHOLD    = 0.7f;
    static constexpr float PHASE2_PAUSE_DURATION = 1.5f;

    // --- Блок (фаза 1) ---
    static constexpr float BLOCK_COOLDOWN_P1 = 5.0f;

    // --- Прыжок ---
    static constexpr float JUMP_VELOCITY     = -700.0f;
    static constexpr float SPIKE_AREA_CELLS  = 10.0f;
    static constexpr float SPIKE_LIFETIME    = 1.8f;

    // --- DASH_STRIKE поля ---
    float dashStrikeVelX     = 0.0f;
    float dashStrikeTimer    = 0.0f;
    bool  dashStrikeHitDealt = false;

    static constexpr float DASH_STRIKE_SPEED    = 700.0f;
    static constexpr float DASH_STRIKE_DURATION = 0.18f;

    // --- Анимации снарядов и лазера ---
    Animation projectileAnim;
    Animation laserChargeAnim;
    Animation laserBeamAnim;
    bool  laserFullyCharged;
    float laserTimer    = 0.0f;
    float laserDuration = 0.0f;

    // --- RNG ---
    std::mt19937 rng;

public:
    // --- Debug ---
    bool showHitboxes = false;

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

    void updatePhaseTransition(float deltaTime);

    void startMeleePattern(float playerX, float playerY);
    void updateMeleePattern(float deltaTime);

    void updateJump(float deltaTime);
    void spawnSpikes();
    void updateSpikes(float deltaTime);

    void startTeleport(float targetX, float targetY);
    void updateTeleport(float deltaTime);

    void setState(BossState newState);
    void forceState(BossState newState);
    [[nodiscard]] bool canChangeState() const;

    void spawnProjectile(float playerX, float playerY, bool predictive = false);
    void spawnLaser(bool megaLaser = false);
    void spawnTwoProjectiles(float playerX, float playerY, bool withTracking);

    void renderProjectiles(SDL_Renderer* renderer);
    void renderLaser(SDL_Renderer* renderer);
    void renderSpikes(SDL_Renderer* renderer);
    mutable int currentSpriteW = 0;
    mutable int currentSpriteH = 0;

    [[nodiscard]] SDL_Rect getCurrentFrame() const;
    void renderHitboxes(SDL_Renderer* renderer, int spriteX, int spriteY, int spriteW, int spriteH);
};