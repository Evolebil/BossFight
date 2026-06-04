/**
 * @file boss_archer.h
 * @brief Босс-лучник — второй босс уровня 2 (появляется после смерти самурая)
 * @author evol
 * @date 2026-06-03
 */
#pragma once
#include "../config/common.h"
#include "boss.h"
#include "../utils/texture_manager.h"

/**
 * @struct ArcherClone
 * @brief Клон-фантом лучника. Нематаемый — урон принимает только настоящий лучник.
 *        Направление стрельбы задаётся при спавне и не меняется (кроме центрального).
 */
struct ArcherClone {
    float x        = 0.0f;
    float y        = 0.0f;
    float dirX     = 0.0f;
    float dirY     = 0.0f;
    bool  active   = false;
    bool  isCenter = false;
};

class BossArcher : public Boss {
private:

    // ============================================================
    // КОНСТАНТЫ — ХИТБОКС И HP
    // ============================================================

    static constexpr float HITBOX_W = 50.0f;
    static constexpr float HITBOX_H = 80.0f;
    static constexpr float BASE_HP  = 1000.0f;

    // ============================================================
    // КОНСТАНТЫ — ДВИЖЕНИЕ И БОЙ
    // ============================================================

    static constexpr float MOVE_SPEED      = 180.0f;  ///< Скорость преследования (px/s)
    static constexpr float SWORD_DAMAGE    = 25.0f;   ///< Урон удара мечом

    // ============================================================
    // КОНСТАНТЫ — КЛОНЫ
    // ============================================================

    static constexpr int   CLONE_COUNT     = 4;       ///< Клонов в фазе 1
    static constexpr int   CLONE_COUNT_P2  = 6;       ///< Клонов в фазе 2
    static constexpr float CLONE_SPACING   = 120.0f;  ///< Вертикальный отступ между клонами (px)

    // ============================================================
    // ПОЛЯ — СОСТОЯНИЕ И ФАЗА
    // ============================================================

    ArcherState currentState      = ArcherState::IDLE;
    ArcherState previousState     = ArcherState::IDLE;
    ArcherPhase phase             = ArcherPhase::PHASE_1;

    float stateTimer          = 0.0f; ///< Монотонно растущий таймер (сек)
    float lastStateChangeTime = 0.0f; ///< stateTimer в момент последней смены

    // ============================================================
    // КОНСТАНТЫ — СМЕНА СОСТОЯНИЙ
    // ============================================================

    static constexpr float STATE_CHANGE_COOLDOWN = 0.3f;

    // ============================================================
    // ПРИВАТНЫЕ МЕТОДЫ — УПРАВЛЕНИЕ СОСТОЯНИЕМ
    // ============================================================

    std::vector<ArcherClone> clones; ///< Активные клоны
    void setState(ArcherState newState);
    void forceState(ArcherState newState);
    [[nodiscard]] bool canChangeState() const;

public:

    BossArcher(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossArcher() override = default;

    void update(float deltaTime, float playerX, float playerY,
                bool playerFacingRight = false) override;

    void update(float deltaTime) override { (void)deltaTime; }

    void render(SDL_Renderer* renderer) override;

    [[nodiscard]] SDL_Rect getHitbox() const override;
};