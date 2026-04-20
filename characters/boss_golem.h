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
    SDL_Rect rect;
    float    damage;
    float    lifetime;
    bool     active;
    bool     hitDealt;
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
    DASH_STRIKE,
    JUMP_SLAM,
    TELEPORT_LASER
};

/**
 * @class BossGolem
 * @brief Первый босс игры. Две фазы, три паттерна ближней атаки в фазе 2.
 */
class BossGolem : public Character {
private:
    // ============================================================
    // КОНСТАНТЫ — все магические числа здесь
    // ============================================================

    // --- Размеры и HP ---
    static constexpr float HITBOX_W              = 100.0f;
    static constexpr float HITBOX_H              = 100.0f;
    static constexpr float BASE_HP               = 1000.0f;

    // --- Урон ---
    static constexpr float DAMAGE_MELEE          = 25.0f;
    static constexpr float DAMAGE_MELEE_P2       = 30.0f;
    static constexpr float DAMAGE_RANGE          = 15.0f;
    static constexpr float DAMAGE_RANGE_P2       = 20.0f;
    static constexpr float DAMAGE_LASER_SEC      = 30.0f;
    static constexpr float DAMAGE_MEGA_LASER_SEC = 50.0f;
    static constexpr float DAMAGE_SPIKE          = 35.0f;

    // --- Дистанции (в клетках) ---
    static constexpr float RANGE_MELEE           = 2.0f;
    static constexpr float RANGE_RANGED          = 99.0f;
    static constexpr float RANGE_LASER           = 6.0f;

    // --- Скорости ---
    static constexpr float PROJECTILE_SPEED      = 400.0f;
    static constexpr float TELEPORT_SPEED        = 3000.0f;
    static constexpr float TELEPORT_P2_CELLS     = 8.0f;
    static constexpr float MOVE_SPEED_MULT       = 1.3f;

    // --- Спрайт ---
    static constexpr float SPRITE_SCALE          = 2.5f;
    static constexpr int   SPRITE_OFFSET_Y       = 0;
    static constexpr int   SPRITE_FRAME_W        = 100;
    static constexpr int   SPRITE_FRAME_H        = 100;

    // --- Строки спрайтшита (Y позиции) ---
    static constexpr int   ANIM_ROW_IDLE         = 0;
    static constexpr int   ANIM_ROW_HURT         = 100;
    static constexpr int   ANIM_ROW_RANGE        = 200;
    static constexpr int   ANIM_ROW_BLOCK        = 300;
    static constexpr int   ANIM_ROW_MELEE        = 400;
    static constexpr int   ANIM_ROW_LASER        = 500;
    static constexpr int   ANIM_ROW_WALK         = 600;
    static constexpr int   ANIM_ROW_DEATH1       = 700;
    static constexpr int   ANIM_ROW_DEATH2       = 800;

    // --- Количество кадров ---
    static constexpr int   FRAMES_IDLE           = 4;
    static constexpr int   FRAMES_HURT           = 8;
    static constexpr int   FRAMES_RANGE          = 7;
    static constexpr int   FRAMES_BLOCK          = 8;
    static constexpr int   FRAMES_MELEE          = 7;
    static constexpr int   FRAMES_LASER          = 7;
    static constexpr int   FRAMES_WALK           = 10;
    static constexpr int   FRAMES_DEATH1         = 10;
    static constexpr int   FRAMES_DEATH2         = 4;
    static constexpr int   FRAMES_REVIVE1        = 4;
    static constexpr int   FRAMES_REVIVE2        = 10;

    // --- Скорости анимаций ---
    static constexpr float ANIM_SPEED_IDLE       = 0.2f;
    static constexpr float ANIM_SPEED_HURT       = 0.07f;
    static constexpr float ANIM_SPEED_RANGE      = 0.09f;
    static constexpr float ANIM_SPEED_BLOCK      = 0.1f;
    static constexpr float ANIM_SPEED_MELEE      = 0.1f;
    static constexpr float ANIM_SPEED_LASER      = 0.13f;
    static constexpr float ANIM_SPEED_WALK       = 0.08f;
    static constexpr float ANIM_SPEED_DEATH1     = 0.1f;
    static constexpr float ANIM_SPEED_DEATH2     = 0.15f;
    static constexpr float ANIM_SPEED_REVIVE1    = 0.12f;
    static constexpr float ANIM_SPEED_REVIVE2    = 0.08f;

    // --- Спрайтшит снарядов ---
    static constexpr int   PROJ_FRAME_W          = 102;
    static constexpr int   PROJ_FRAME_H          = 102;
    static constexpr int   PROJ_FRAME_ROWS       = 2;
    static constexpr int   PROJ_FRAME_COLS       = 3;
    static constexpr float PROJ_ANIM_SPEED       = 0.18f;

    // --- Спрайтшит лазера ---
    static constexpr int   LASER_FRAME_W         = 308;
    static constexpr int   LASER_FRAME_H         = 108;
    static constexpr int   LASER_CHARGE_FRAMES   = 8;
    static constexpr int   LASER_BEAM_FRAMES     = 6;
    static constexpr float LASER_CHARGE_SPEED    = 0.07f;
    static constexpr float LASER_BEAM_SPEED      = 0.08f;
    static constexpr int   LASER_BEAM_ROW_START  = 8;

    // --- Хитбоксы ---
    static constexpr int   PROJ_HIT_SIZE         = 36;
    static constexpr int   PROJ_RENDER_SIZE      = 80;
    static constexpr int   CHARGE_RENDER_SIZE    = 96;
    static constexpr int   DASH_HIT_W            = 80;
    static constexpr int   DASH_HIT_H            = 80;
    static constexpr int   HITBOX_LINE_LEN       = 40;
    static constexpr float MELEE_WIDTH_MULT      = 1.0f;
    static constexpr float MELEE_HEIGHT_MULT     = 0.85f;
    static constexpr float MELEE_OFFSET_X        = 0.1f;

    // --- Лазер параметры ---
    static constexpr float LASER_HEIGHT_DEFAULT  = 80.0f;
    static constexpr float LASER_MEGA_HEIGHT     = 120.0f;
    static constexpr float LASER_NORMAL_DURATION = 2.0f;
    static constexpr float LASER_MEGA_DURATION   = 3.5f;
    static constexpr float LASER_BODY_Y_OFFSET   = 0.3f;

    // --- Таймеры и кулдауны ---
    static constexpr float STATE_CHANGE_COOLDOWN = 0.5f;
    static constexpr float BLOCK_HP_THRESHOLD    = 0.7f;
    static constexpr float PHASE2_PAUSE_DURATION = 1.5f;
    static constexpr float BLOCK_COOLDOWN_P1     = 5.0f;
    static constexpr float BLOCK_DURATION        = 3.0f;
    static constexpr float BLOCK_HP_REGEN        = 50.0f;
    static constexpr float BLOCK_DEFENSE_VALUE   = 0.5f;
    static constexpr float ATTACK_COOLDOWN       = 2.2f;
    static constexpr float MELEE_HIT_TIME        = 0.5f;
    static constexpr float PROJ_QUEUE_DELAY      = 0.35f;

    // --- Прыжок ---
    static constexpr float JUMP_VELOCITY         = -700.0f;
    static constexpr float GRAVITY_JUMP          = 1200.0f;
    static constexpr float SPIKE_AREA_CELLS      = 10.0f;
    static constexpr float SPIKE_LIFETIME        = 1.8f;

    // --- Рывок ---
    static constexpr float DASH_STRIKE_SPEED     = 700.0f;
    static constexpr float DASH_STRIKE_DURATION  = 0.18f;

    // --- Карта ---
    static constexpr int   CELL_SIZE             = 32;
    static constexpr int   PROJ_MARGIN           = 200;

    // ============================================================
    // ПОЛЯ
    // ============================================================

    // --- Состояния ---
    BossState currentState    = BossState::IDLE;
    BossState previousState   = BossState::IDLE;

    // --- Фаза ---
    BossPhase phase           = BossPhase::PHASE_1;
    float     phaseTimer      = 0.0f;
    bool      phase2Triggered = false;

    // --- Паттерн ближней атаки (фаза 2) ---
    MeleePattern currentMeleePattern = MeleePattern::NONE;
    int          meleePatternStep    = 0;
    float        meleePatternTimer   = 0.0f;
    bool         meleeTeleportDone   = false;
    float        meleeAttackDirX     = 1.0f;
    bool         patternFacingRight  = true;

    // --- Прыжок (JUMP_SLAM) ---
    bool  isJumping     = false;
    float jumpVelocityY = 0.0f;
    bool  jumpLanded    = false;

    // --- Шипы ---
    std::vector<GroundSpike> groundSpikes;

    // --- Телепорт ---
    bool  isTeleporting   = false;
    float teleportTargetX = 0.0f;
    float teleportTargetY = 0.0f;

    // --- Анимации ---
    std::map<BossState, Animation> animations;
    Animation reviveAnim{false, true};

    // --- Боевые параметры ---
    float defense   = 0.0f;
    float moveSpeed = 0.0f;
    int   cellSize  = CELL_SIZE;

    // --- Таймеры ---
    float attackCooldown      = ATTACK_COOLDOWN;
    float attackTimer         = 0.0f;
    float blockCooldown       = BLOCK_COOLDOWN_P1;
    float blockTimer          = 0.0f;
    float blockDuration       = BLOCK_DURATION;
    float blockActiveTimer    = 0.0f;
    float stateTimer          = 0.0f;
    float lastStateChangeTime = 0.0f;

    // --- Атаки ---
    bool  meleeHitDealt       = false;
    bool  meleeSecondHitDealt = false;
    float meleeHitTime        = MELEE_HIT_TIME;
    std::vector<Projectile> projectiles;
    LaserBeam laser = {false, 0, 0, true, DAMAGE_LASER_SEC, LASER_HEIGHT_DEFAULT};
    bool  attackSpawned       = false;

    // --- Очередь снарядов ---
    int   projectileQueue      = 0;
    float projectileQueueTimer = 0.0f;
    float lastPlayerX          = 0.0f;
    float lastPlayerY          = 0.0f;

    // --- Сложность ---
    float attackSpeedMult = 1.0f;

    // --- Текстуры ---
    SDL_Texture* armTexture   = nullptr;
    SDL_Texture* laserTexture = nullptr;

    // --- DASH_STRIKE ---
    float dashStrikeVelX     = 0.0f;
    float dashStrikeTimer    = 0.0f;
    bool  dashStrikeHitDealt = false;

    // --- Анимации снарядов и лазера ---
    Animation projectileAnim;
    Animation laserChargeAnim;
    Animation laserBeamAnim;
    bool  laserFullyCharged = false;
    float laserTimer        = 0.0f;
    float laserDuration     = 0.0f;

    // --- Размер карты ---
    int mapW = Config::getWindowWidth();
    int mapH = Config::getWindowHeight();

    // --- RNG ---
    std::mt19937 rng = std::mt19937(std::random_device{}());

public:
    bool showHitboxes = false;

    BossGolem(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossGolem() override = default;

    void update(float deltaTime, float playerX, float playerY);
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;
    void setMapSize(int w, int h) { mapW = w; mapH = h; }
    void forcePhase2();

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