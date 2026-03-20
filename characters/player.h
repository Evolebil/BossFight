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
 * - ПКМ  — щит (снижает урон на 75% пока зажат)
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
    int   attackCombo;     // 0, 1, 2 — какая атака следующая

    // Флаг и таймер активного хита — урон наносится один раз за атаку
    bool  attackHitActive;
    float attackHitTimer;
    float attackDamage;

    // Блок — поля объявлены и инициализированы (были UB!)
    bool  defendReady;
    float defendCooldown;

    // --- Флаги ввода ---
    bool wantsToJump;
    bool wantsToAttack;
    bool wantsToDefend;

    // --- Рывок ---
    bool  isDashing;
    float dashTimer;
    float dashCooldown;
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

    // Блок снижает урон на 75% (было 1.0f = 100% — баг!)
    static constexpr float DEFEND_DAMAGE_REDUCTION = 0.75f;
    static constexpr float DEFEND_COOLDOWN         = 2.0f;

    static constexpr float DASH_SPEED    = 600.0f; // скорость рывка (px/s)
    static constexpr float DASH_DURATION = 0.15f;  // длительность (сек)
    static constexpr float DASH_COOLDOWN = 2.0f;   // кулдаун (сек)


public:
    explicit Player(float spawnX, float spawnY);
    ~Player() override = default;

    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    /**
     * @brief Хитбокс атаки перед игроком. {0,0,0,0} если атаки нет.
     */
    [[nodiscard]] SDL_Rect getAttackHitbox() const;

    /**
     * @brief Урон текущей атаки. Возвращает > 0 только один раз за удар.
     */
    [[nodiscard]] float consumeAttackDamage();

    [[nodiscard]] SDL_Rect getHitbox() const {
        return {
            (int)(x - width  / 2),
            (int)(y - height / 2),
            (int)width,
            (int)height
        };
    }

    [[nodiscard]] bool getIsDefending() const { return isDefending; }
    [[nodiscard]] bool getIsDead()      const { return isDead; }

private:
    void loadAnimations();
    void processInput();
    void startAttack();
};