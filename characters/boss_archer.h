/**
 * @file boss_archer.h
 * @brief Босс-лучник с BFS AI, клонами и стрелами
 * @author evol
 * @date 2026-06-08
 */
#pragma once
#include "../config/common.h"
#include "boss.h"
#include "../utils/texture_manager.h"

struct ArcherArrow {
    float x      = 0.0f;
    float y      = 0.0f;
    float velX   = 0.0f;
    float velY   = 0.0f;
    bool  active = false;

    static constexpr float SPEED  = 500.0f;
    static constexpr float DAMAGE = 15.0f;
};

struct ArcherClone {
    float x              = 0.0f;
    float y              = 0.0f;
    float dirX           = 1.0f;
    float dirY           = 0.0f;
    float verticalOffset = 0.0f;
    float offsetX        = 0.0f;
    bool  active         = false;
    bool  isCenter       = false;
};

class BossArcher : public Boss {
private:

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — ХИТБОКС И HP
    // ════════════════════════════════════════════════════════

    static constexpr float HITBOX_W  = 50.0f;
    static constexpr float HITBOX_H  = 80.0f;
    static constexpr float BASE_HP   = 1000.0f;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — СПРАЙТ
    // ════════════════════════════════════════════════════════

    static constexpr int   FRAME_W       = 128;
    static constexpr int   FRAME_H       = 128;
    static constexpr float SPRITE_SCALE  = 1.5f;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — КАДРЫ АНИМАЦИЙ
    // ════════════════════════════════════════════════════════

    static constexpr int FRAMES_IDLE         = 9;
    static constexpr int FRAMES_WALK         = 8;
    static constexpr int FRAMES_ATTACK_1     = 5;
    static constexpr int FRAMES_ATTACK_2     = 5;
    static constexpr int FRAMES_ATTACK_3     = 6;
    static constexpr int FRAMES_HURT         = 3;
    static constexpr int FRAMES_SHOOT        = 14;
    static constexpr int FRAMES_CLONE_VOLLEY = 5;
    static constexpr int FRAMES_DEATH        = 5;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — СКОРОСТИ АНИМАЦИЙ
    // ════════════════════════════════════════════════════════

    static constexpr float ANIM_SPD_IDLE         = 0.12f;
    static constexpr float ANIM_SPD_WALK         = 0.09f;
    static constexpr float ANIM_SPD_ATTACK_1     = 0.06f;  ///< Быстрее чем было
    static constexpr float ANIM_SPD_ATTACK_2     = 0.06f;
    static constexpr float ANIM_SPD_ATTACK_3     = 0.05f;
    static constexpr float ANIM_SPD_HURT         = 0.05f;  ///< Быстро — 3 кадра
    static constexpr float ANIM_SPD_SHOOT        = 0.07f;
    static constexpr float ANIM_SPD_CLONE_VOLLEY = 0.09f;
    static constexpr float ANIM_SPD_DEATH        = 0.14f;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — ДВИЖЕНИЕ
    // ════════════════════════════════════════════════════════

    static constexpr float MOVE_SPEED        = 260.0f;  ///< Увеличено с 180
    static constexpr float JUMP_VELOCITY     = -580.0f;
    static constexpr float JUMP_COOLDOWN_MAX = 1.5f;
    static constexpr float DROP_THRESHOLD    = 60.0f;
    static constexpr float DROP_DURATION     = 0.18f;
    static constexpr float DROP_COOLDOWN     = 0.8f;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — БОЙ
    // ════════════════════════════════════════════════════════

    static constexpr float SWORD_DAMAGE        = 25.0f;
    static constexpr float MELEE_RANGE         = 80.0f;
    static constexpr float SWORD_HIT_W         = 100.0f;
    static constexpr float SWORD_HIT_H         = 80.0f;
    static constexpr int   SWORD_HIT_FRAME     = 2;       ///< Кадр засчитывания хита
    static constexpr float BASE_SWORD_COOLDOWN = 0.8f;    ///< Уменьшено с 2.0
    static constexpr float BASE_SHOOT_COOLDOWN = 0.8f;    ///< Уменьшено с 1.5

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — СТРЕЛЫ
    // ════════════════════════════════════════════════════════

    static constexpr int ARROW_HITBOX_W = 20;
    static constexpr int ARROW_HITBOX_H = 8;
    static constexpr int ARROW_W        = 64;
    static constexpr int ARROW_H        = 64;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — КЛОНЫ
    // ════════════════════════════════════════════════════════

    static constexpr int   CLONE_COUNT           = 4;
    static constexpr int   CLONE_COUNT_P2        = 6;
    static constexpr float CLONE_SPACING         = 120.0f;
    static constexpr float CLONE_SHOOT_INTERVAL  = 1.2f;
    static constexpr float VERTICAL_CLONE_OFFSET = 200.0f;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — ТЕЛЕПОРТ
    // ════════════════════════════════════════════════════════

    static constexpr float TELEPORT_MIN_DIST = 80.0f;   ///< Минимум от игрока (px)
    static constexpr float TELEPORT_MAX_DIST = 220.0f;  ///< Максимум от игрока (px)
    static constexpr float TELEPORT_COOLDOWN = 4.0f;
    static constexpr float TELEPORT_TRIGGER_DIST = 350.0f; ///< Дальше этого → телепорт

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — СМЕНА СОСТОЯНИЙ
    // ════════════════════════════════════════════════════════

    static constexpr float STATE_CHANGE_COOLDOWN = 0.3f;

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ — BFS
    // ════════════════════════════════════════════════════════

    static constexpr int   BFS_TILE_SIZE           = 32;
    static constexpr float BFS_INTERVAL            = 0.5f;
    static constexpr int   BFS_MAX_TILES           = 8000;
    static constexpr float BFS_REACH_DIST          = 40.0f;
    static constexpr int   BFS_JUMP_REACH_H        = 3;    ///< Макс тайлов вверх (было 5)
    static constexpr int   BFS_JUMP_REACH_W        = 5;    ///< Макс тайлов по горизонтали
    static constexpr float BFS_VIS_STEP_INTERVAL   = 0.015f;
    static constexpr float RECALC_DISTANCE_THRESHOLD = 80.0f;

    // ════════════════════════════════════════════════════════
    // ТИПЫ ДАННЫХ BFS
    // ════════════════════════════════════════════════════════

    enum class PathAction {
        WALK_LEFT,
        WALK_RIGHT,
        JUMP,
        DROP
    };

    struct PathNode {
        int        col    = 0;
        int        row    = 0;
        PathAction action = PathAction::WALK_RIGHT;
    };

    // ════════════════════════════════════════════════════════
    // ПОЛЯ
    // ════════════════════════════════════════════════════════

    ArcherState currentState      = ArcherState::IDLE;
    ArcherState previousState     = ArcherState::IDLE;
    ArcherPhase phase             = ArcherPhase::PHASE_1;

    float stateTimer          = 0.0f;
    float lastStateChangeTime = 0.0f;
    float cloneShootTimer     = 0.0f;

    float swordCooldown    = 0.0f;
    float swordTimer       = 0.0f;
    float shootCooldown    = 0.0f;
    float shootTimer       = 0.0f;
    float spawnDelay       = 0.5f;
    float teleportCooldown = 0.0f;

    float jumpCooldown      = 0.0f;
    float platformDropTimer = 0.0f;
    float dropCooldown      = 0.0f;

    // HURT перед телепортом
    bool  playingPreTeleportHurt = false;  ///< true = проигрываем Hurt перед тп

    // BFS
    std::vector<PathNode> path;
    int   pathIndex = 0;
    float bfsTimer  = 0.0f;
    float lastRecalcPlayerX = 0.0f;
    float lastRecalcPlayerY = 0.0f;

    bool meleeHitDealt = false;
    bool clonesSpawned = false;
    int  currentAttack = 0;  ///< 0/1/2 — какая из трёх атак сейчас

    std::vector<ArcherClone> clones;
    std::vector<ArcherArrow> arrows;

    std::map<ArcherState, SDL_Texture*> textures;
    std::map<ArcherState, Animation>    animations;
    SDL_Texture* arrowTexture = nullptr;

    // Отладка BFS
    struct BFSVisNode { int col, row, dist; };
    std::vector<BFSVisNode> bfsAllNodes;
    int   bfsVisualStep  = 0;
    float bfsVisualTimer = 0.0f;

    // ════════════════════════════════════════════════════════
    // ПРИВАТНЫЕ МЕТОДЫ
    // ════════════════════════════════════════════════════════

    void setState(ArcherState newState);
    void forceState(ArcherState newState);
    [[nodiscard]] bool canChangeState() const;

    void loadAnimations();
    void spawnClones();
    void updateClones(float dt, float playerX, float playerY);
    void checkPhaseTransition();
    void updateAI(float dt, float playerX, float playerY);
    void updateMovement(float dt, float playerX, float playerY);
    void teleportNearPlayer(float playerX, float playerY);
    void recalcPath(float playerX, float playerY);
    void getCurrentMapOffset(int& ox, int& oy) const;

    [[nodiscard]] bool canJumpTo(int col, int row, int& outLandRow) const;
    [[nodiscard]] bool isSolidTile(int col, int row) const;
    [[nodiscard]] bool isFreeTile(int col, int row) const;
    [[nodiscard]] bool hasSupport(int col, int row) const;
    [[nodiscard]] bool isWalkable(int col, int row) const;
    [[nodiscard]] int  findPlatformBelow(int col, int row) const;

    void renderHitboxes(SDL_Renderer* renderer);

public:

    BossArcher(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossArcher() override = default;

    void update(float deltaTime, float playerX, float playerY,
                bool playerFacingRight = false) override;
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;

    [[nodiscard]] SDL_Rect getHitbox() const override;
    [[nodiscard]] bool isDeathAnimFinished() const;
    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox, float deltaTime);
};