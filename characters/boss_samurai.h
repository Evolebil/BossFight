/**
 * @file boss_samurai.h
 * @brief Босс-самурай — дуэлянт средней дистанции
 * @author evol
 * @date 2026-05-20
 */
#pragma once
#include "boss.h"
#include "../utils/texture_manager.h"

class BossSamurai : public Boss {
private:
    // ============================================================
    // КОНСТАНТЫ
    // ============================================================

    static constexpr float HITBOX_W           = 50.0f;
    static constexpr float HITBOX_H           = 60.0f;
    static constexpr float BASE_HP            = 800.0f;

    static constexpr float MOVE_SPEED         = 200.0f;
    static constexpr float PREFERRED_DISTANCE = 200.0f;  // дистанция удержания
    static constexpr float TELEPORT_OFFSET    = 150.0f;  // смещение за спину игрока

    static constexpr int   BOMB_COUNT         = 5;
    static constexpr float STUN_DURATION      = 2.0f;
    static constexpr float STANCE_DURATION    = 5.0f;    // максимум стойки

    static constexpr float STATE_CHANGE_COOLDOWN = 0.3f;

    // ============================================================
    // СОСТОЯНИЕ И ФАЗА
    // ============================================================

    SamuraiState currentState     = SamuraiState::IDLE;
    SamuraiState previousState    = SamuraiState::IDLE;
    SamuraiPhase phase            = SamuraiPhase::PHASE_1;

    float stateTimer              = 0.0f;
    float lastStateChangeTime     = 0.0f;

    void setState(SamuraiState newState);
    void forceState(SamuraiState newState);
    [[nodiscard]] bool canChangeState() const;

    // ============================================================
    // ТАЙМЕРЫ И КУЛДАУНЫ
    // ============================================================

    static constexpr float TELEPORT_COOLDOWN  = 5.0f;
    static constexpr float BOMB_COOLDOWN      = 4.0f;
    static constexpr float SMOKE_COOLDOWN     = 8.0f;
    static constexpr float SWORD_COOLDOWN     = 2.0f;

    float teleportTimer  = 0.0f;
    float bombTimer      = 0.0f;
    float smokeTimer     = 0.0f;
    float swordTimer     = 0.0f;
    float stanceTimer    = 0.0f;
    float stunTimer      = 0.0f;

    // ============================================================
    // ФЛАГИ
    // ============================================================

    bool stanceActive  = false;
    bool meleeHitDealt = false;
    bool attackSpawned = false;

    // ============================================================
    // АНИМАЦИИ
    // ============================================================

    std::map<SamuraiState, SDL_Texture*> textures;
    std::map<SamuraiState, Animation> animations;

    static constexpr int FRAME_W = 128;
    static constexpr int FRAME_H = 128;

    static constexpr int   FRAMES_IDLE         = 6;
    static constexpr int   FRAMES_WALK         = 8;
    static constexpr int   FRAMES_JUMP         = 9;
    static constexpr int   FRAMES_SWORD_ATTACK = 4;
    static constexpr int   FRAMES_THROW_BOMBS  = 5;
    static constexpr int   FRAMES_POWER_ATTACK = 4;
    static constexpr int   FRAMES_STANCE       = 2;
    static constexpr int   FRAMES_STUNNED      = 3;
    static constexpr int   FRAMES_DEATH        = 6;

    static constexpr float ANIM_SPD_IDLE         = 0.15f;
    static constexpr float ANIM_SPD_WALK         = 0.09f;
    static constexpr float ANIM_SPD_JUMP         = 0.10f;
    static constexpr float ANIM_SPD_SWORD_ATTACK = 0.08f;
    static constexpr float ANIM_SPD_THROW_BOMBS  = 0.09f;
    static constexpr float ANIM_SPD_POWER_ATTACK = 0.08f;
    static constexpr float ANIM_SPD_STANCE       = 0.12f;
    static constexpr float ANIM_SPD_STUNNED      = 0.12f;
    static constexpr float ANIM_SPD_DEATH        = 0.12f;
    static constexpr float SPRITE_SCALE = 1.5f;

    void loadAnimations();

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