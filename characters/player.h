/**
 * @file player.h
 * @brief Класс игрока — управление, прыжки, бой, магия, анимации
 * @author evol
 * @date 2026-02-24
 */
#pragma once
#include "../config/common.h"
#include "../config/config.h"
#include "../utils/animation.h"
#include "character.h"
#include "../utils/camera.h"

// --- Магический снаряд ---
struct MagicProjectile {
    float x, y;       // мировые координаты
    float velX, velY;
    bool  active;

    static constexpr float DAMAGE = 50.0f;
    static constexpr float SIZE   = 24.0f;
};

/**
 * @class Player
 * @brief Главный персонаж игры. Наследует физику и HP от Character.
 */
class Player : public Character {
private:
    // --- Состояние боя ---
    bool isAttacking;
    bool isCastingMagic;
    bool isDefending;
    bool isHurt;
    bool isDead;

    float attackCooldown;
    float attackTimer;
    int   attackCombo;

    bool  attackHitActive;
    float attackHitTimer;
    float attackDamage;

    // Щит
    float defendCooldown;

    // --- Мана ---
    float mana;
    float maxMana;

    // --- Магические снаряды ---
    std::vector<MagicProjectile> magicProjectiles;
    bool wantsToCastMagic;
    int  mouseX, mouseY;   // экранные координаты курсора (виртуальные 1280x720)

    // --- Флаги ввода ---
    bool wantsToJump;
    bool wantsToAttack;
    bool wantsToDefend;

    // --- Рывок ---
    bool  isDashing;
    float dashTimer;
    float dashCooldown;
    bool  wantsToDash;

    // --- Размер карты (мировые координаты) ---
    // Нужен для правильной проверки выхода снаряда за границы карты.
    // Устанавливается из GameScene через setMapSize() после создания уровня.
    int mapW;
    int mapH;

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
    SDL_Texture* texMagic;

    // --- Анимации ---
    Animation idleAnim;
    Animation runAnim;
    Animation jumpAnim;
    Animation attack1Anim;
    Animation attack2Anim;
    Animation attack3Anim;
    Animation magicAnim;
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

    static constexpr float DAMAGE_ATTACK1 = 25.0f;
    static constexpr float DAMAGE_ATTACK2 = 35.0f;
    static constexpr float DAMAGE_ATTACK3 = 50.0f;

    static constexpr float DEFEND_DAMAGE_REDUCTION = 0.99f;
    static constexpr float DEFEND_COOLDOWN_MAX     = 1.0f;

    static constexpr float DASH_SPEED        = 900.0f;
    static constexpr float DASH_DURATION     = 0.22f;
    static constexpr float DASH_COOLDOWN_MAX = 2.0f;

    static constexpr float MANA_MAX         = 100.0f;
    static constexpr float MANA_REGEN       = 2.0f;
    static constexpr float MANA_COST_MAGIC  = 10.0f;
    static constexpr float MAGIC_SPEED_MULT = 1.5f;

    // Запас за краем карты перед деактивацией снаряда (px)
    static constexpr int PROJ_OUT_OF_BOUNDS_MARGIN = 200;

public:
    // --- Debug ---
    bool showHitboxes = false;

    explicit Player(float spawnX, float spawnY);
    ~Player() override = default;

    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    // Вызывать из GameScene сразу после создания уровня
    void setMapSize(int w, int h) { mapW = w; mapH = h; }

    [[nodiscard]] SDL_Rect getAttackHitbox() const;
    [[nodiscard]] float    consumeAttackDamage();

    [[nodiscard]] std::vector<MagicProjectile>& getMagicProjectiles() { return magicProjectiles; }

    [[nodiscard]] SDL_Rect getHitbox() const {
        return {
            (int)(x - width  / 2),
            (int)(y - height / 2),
            (int)width,
            (int)height
        };
    }

    [[nodiscard]] float getMana()              const { return mana; }
    [[nodiscard]] float getMaxMana()           const { return maxMana; }
    [[nodiscard]] float getDefendCooldown()    const { return defendCooldown; }
    [[nodiscard]] float getDefendCooldownMax() const { return DEFEND_COOLDOWN_MAX; }
    [[nodiscard]] float getDashCooldown()      const { return dashCooldown; }
    [[nodiscard]] float getDashCooldownMax()   const { return DASH_COOLDOWN_MAX; }
    [[nodiscard]] bool  getIsDefending()       const { return isDefending; }
    [[nodiscard]] bool  getIsDead()            const { return isDead; }

private:
    void loadAnimations();
    void processInput();
    void startAttack();
    void castMagic();
    void renderHitboxes(SDL_Renderer* renderer);  // DEBUG
};