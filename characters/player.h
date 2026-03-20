/**
 * @file player.h
 * @brief Класс игрока — управление, прыжки, бой, анимации
 * @author evol
 * @date 2026-02-24
 */
#pragma once
#include "../config/common.h"
#include "../config/config.h"
#include "../utils/animation.h"
#include "character.h"

/**
 * @class Player
 * @brief Главный персонаж игры. Наследует физику и HP от Character.
 *
 * Управление:
 * - A/D   — движение влево/вправо
 * - Space — прыжок
 * - ЛКМ  — атака (чередует ATTACK_1 → ATTACK_2 → ATTACK_3)
 * - F    — щит (кулдаун 1 сек, спадает при получении урона)
 * - Shift — рывок (кулдаун 2 сек)
 *
 * Анимации (отдельные файлы, кадр 96x84):
 * - IDLE.png     7 кадров  — стоит
 * - RUN.png      8 кадров  — бежит
 * - WALK.png     8 кадров  — не используется пока
 * - JUMP.png     5 кадров  — прыжок
 * - ATTACK_1.png 6 кадров  — атака 1
 * - ATTACK_2.png 5 кадров  — атака 2
 * - ATTACK_3.png 6 кадров  — атака 3
 * - DEFEND.png   6 кадров  — щит (pingPong)
 * - HURT.png     4 кадра   — получение урона
 * - DEATH.png    14 кадров — смерть
 */
class Player : public Character {
private:
    // --- Состояние боя ---
    bool isAttacking;
    bool isDefending;
    bool isHurt;
    bool isDead;

    float attackCooldown;
    float attackTimer;
    int   attackCombo;

    // Флаг и таймер активного хита — урон наносится один раз за атаку
    bool  attackHitActive;
    float attackHitTimer;
    float attackDamage;

    // Щит — кулдаун после снятия
    float defendCooldown;    // текущий кулдаун (убывает до 0)

    // --- Флаги ввода ---
    bool wantsToJump;
    bool wantsToAttack;
    bool wantsToDefend;

    // --- Рывок ---
    bool  isDashing;
    float dashTimer;
    float dashCooldown;      // текущий кулдаун (убывает до 0)
    bool  wantsToDash;

    // --- Текстуры ---
    SDL_Texture* texIdle;
    SDL_Texture* texRun;
    SDL_Texture* texWalk;
    SDL_Texture* texJump;
    SDL_Texture* texAttack1;
    SDL_Texture* texAttack2;
    SDL_Texture* texAttack3;
    SDL_Texture* texDefend;
    SDL_Texture* texHurt;
    SDL_Texture* texDeath;

    // --- Анимации ---
    Animation idleAnim;
    Animation runAnim;
    Animation jumpAnim;
    Animation attack1Anim;
    Animation attack2Anim;
    Animation attack3Anim;
    Animation defendAnim;
    Animation hurtAnim;
    Animation deathAnim;

    // --- Константы ---
    static constexpr float JUMP_VELOCITY   = -600.0f;
    static constexpr float MOVE_SPEED      = 200.0f;
    static constexpr float ATTACK_COOLDOWN = 0.5f;

    static constexpr int   FRAME_W  = 96;
    static constexpr int   FRAME_H  = 84;
    static constexpr float RENDER_W = 96.0f;
    static constexpr float RENDER_H = 84.0f;

    // Урон атак
    static constexpr float DAMAGE_ATTACK1 = 25.0f;
    static constexpr float DAMAGE_ATTACK2 = 35.0f;
    static constexpr float DAMAGE_ATTACK3 = 50.0f;

    // Блок снижает урон на 75%
    static constexpr float DEFEND_DAMAGE_REDUCTION = 0.99f;
    static constexpr float DEFEND_COOLDOWN_MAX     = 1.0f;  // кулдаун щита (сек)

    static constexpr float DASH_SPEED       = 600.0f;
    static constexpr float DASH_DURATION    = 0.15f;
    static constexpr float DASH_COOLDOWN_MAX = 2.0f;        // кулдаун рывка (сек)

public:
    explicit Player(float spawnX, float spawnY);
    ~Player() override = default;

    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    [[nodiscard]] SDL_Rect getAttackHitbox() const;
    [[nodiscard]] float    consumeAttackDamage();

    [[nodiscard]] SDL_Rect getHitbox() const {
        return {
            (int)(x - width  / 2),
            (int)(y - height / 2),
            (int)width,
            (int)height
        };
    }

    // Геттеры для отображения кулдаунов в HUD
    [[nodiscard]] float getDefendCooldown()    const { return defendCooldown; }
    [[nodiscard]] float getDefendCooldownMax() const { return DEFEND_COOLDOWN_MAX; }
    [[nodiscard]] float getDashCooldown()      const { return dashCooldown; }
    [[nodiscard]] float getDashCooldownMax()   const { return DASH_COOLDOWN_MAX; }

    [[nodiscard]] bool getIsDefending() const { return isDefending; }
    [[nodiscard]] bool getIsDead()      const { return isDead; }

private:
    void loadAnimations();
    void processInput();
    void startAttack();
};