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

struct MagicProjectile {
    float x, y;
    float velX, velY;
    bool  active;

    static constexpr float DAMAGE = 50.0f;
    static constexpr float SIZE   = 24.0f;
};

class Player : public Character {
private:
    // ============================================================
    // КОНСТАНТЫ ФИЗИКИ
    // ============================================================

    static constexpr float JUMP_VELOCITY    = -650.0f;
    static constexpr float MOVE_SPEED       = 200.0f;
    static constexpr float HITBOX_W         = 35.0f;   // ← было в конструкторе
    static constexpr float HITBOX_H         = 40.0f;   // ← было в конструкторе
    static constexpr float BASE_HP          = 100.0f;  // ← было в конструкторе

    // ============================================================
    // КОНСТАНТЫ СПРАЙТА
    // ============================================================

    static constexpr int   FRAME_W          = 96;
    static constexpr int   FRAME_H          = 84;
    static constexpr float RENDER_W         = 96.0f;
    static constexpr float RENDER_H         = 84.0f;

    // ============================================================
    // КОНСТАНТЫ БОЯ
    // ============================================================

    static constexpr float ATTACK_COOLDOWN      = 0.5f;
    static constexpr float DAMAGE_ATTACK1       = 25.0f;
    static constexpr float DAMAGE_ATTACK2       = 35.0f;
    static constexpr float DAMAGE_ATTACK3       = 50.0f;

    // ← было магическое 0.25f и 0.25f в startAttack()
    static constexpr float ATTACK1_HIT_DELAY    = 0.25f;
    static constexpr float ATTACK2_HIT_DELAY    = 0.25f;
    static constexpr float ATTACK3_HIT_DELAY    = 0.30f;

    // ============================================================
    // КОНСТАНТЫ ЗАЩИТЫ
    // ============================================================

    static constexpr float DEFEND_DAMAGE_REDUCTION = 0.99f;
    static constexpr float DEFEND_COOLDOWN_MAX     = 1.0f;

    // ============================================================
    // КОНСТАНТЫ РЫВКА
    // ============================================================

    static constexpr float DASH_SPEED           = 900.0f;
    static constexpr float DASH_DURATION        = 0.22f;
    static constexpr float DASH_COOLDOWN_MAX    = 2.0f;


    static constexpr float PLATFORM_DROP_PUSH = 2.0f;   // пикселей вниз за кадр при провале
    static constexpr float PLATFORM_DROP_DURATION = 0.08f; // секунд игнорируем платформы

    // ============================================================
    // КОНСТАНТЫ МАНЫ
    // ============================================================

    static constexpr float MANA_MAX             = 100.0f;
    static constexpr float MANA_REGEN           = 2.0f;
    static constexpr float MANA_COST_MAGIC      = 10.0f;
    static constexpr float MAGIC_SPEED_MULT     = 1.5f;

    // ============================================================
    // КОНСТАНТЫ СНАРЯДОВ
    // ============================================================

    static constexpr int   PROJ_OUT_OF_BOUNDS_MARGIN = 200;
    static constexpr int   PROJ_RENDER_SIZE          = 32;  // ← было магическое 32 в render()

    // ============================================================
    // КОНСТАНТЫ ХИТБОКСА АТАКИ
    // ============================================================

    static constexpr int   ATTACK_HIT_W         = 60;   // ← было магическое 60 в getAttackHitbox()
    static constexpr int   ATTACK_HIT_H         = 50;   // ← было магическое 50

    // ============================================================
    // КОНСТАНТЫ HUD (кулдаун бары над игроком)
    // ============================================================

    static constexpr int   HUD_BAR_W            = 40;   // ← было магическое 40 в render()
    static constexpr int   HUD_BAR_H            = 5;    // ← было магическое 5
    static constexpr int   HUD_BAR_GAP          = 3;    // ← было магическое 3
    static constexpr int   HUD_BAR_OFFSET_Y     = 18;   // ← было магическое 18


    // ============================================================
    // СОСТОЯНИЕ БОЯ
    // ============================================================

    bool  isAttacking     = false;
    bool  isCastingMagic  = false;
    bool  isDefending     = false;
    bool  isHurt          = false;
    bool  isDead          = false;

    float attackCooldown  = ATTACK_COOLDOWN;
    float attackTimer     = 0.0f;
    int   attackCombo     = 0;
    bool  attackHitActive = false;
    float attackHitTimer  = 0.0f;
    float attackDamage    = 0.0f;

    float defendCooldown  = 0.0f;

    // ============================================================
    // МАНА
    // ============================================================

    float mana    = MANA_MAX;
    float maxMana = MANA_MAX;

    // ============================================================
    // МАГИЧЕСКИЕ СНАРЯДЫ
    // ============================================================

    std::vector<MagicProjectile> magicProjectiles;
    bool wantsToCastMagic = false;
    int  mouseX           = 0;
    int  mouseY           = 0;

    // ============================================================
    // ФЛАГИ ВВОДА
    // ============================================================

    bool wantsToJump    = false;
    bool wantsToAttack  = false;
    bool wantsToDefend  = false;

    // ============================================================
    // РЫВОК
    // ============================================================

    bool  isDashing    = false;
    float dashTimer    = 0.0f;
    float dashCooldown = 0.0f;
    bool  wantsToDash  = false;


    float platformDropTimer = 0.0f;  // > 0 = игнорируем платформы (провал)

    // ============================================================
    // РАЗМЕР КАРТЫ
    // ============================================================

    int mapW = Config::getWindowWidth();
    int mapH = Config::getWindowHeight();

    // ============================================================
    // ТЕКСТУРЫ
    // ============================================================

    SDL_Texture* texIdle    = nullptr;
    SDL_Texture* texRun     = nullptr;
    SDL_Texture* texWalk    = nullptr;
    SDL_Texture* texJump    = nullptr;
    SDL_Texture* texAttack1 = nullptr;
    SDL_Texture* texAttack2 = nullptr;
    SDL_Texture* texAttack3 = nullptr;
    SDL_Texture* texDefend  = nullptr;
    SDL_Texture* texHurt    = nullptr;
    SDL_Texture* texDeath   = nullptr;
    SDL_Texture* texMagic   = nullptr;

    // ============================================================
    // АНИМАЦИИ
    // ============================================================

    Animation idleAnim    {true};
    Animation runAnim     {true};
    Animation jumpAnim    {false};
    Animation attack1Anim {false};
    Animation attack2Anim {false};
    Animation attack3Anim {false};
    Animation magicAnim   {false};
    Animation defendAnim  {true, true};
    Animation hurtAnim    {false};
    Animation deathAnim   {false};

public:
    bool showHitboxes = false;

    explicit Player(float spawnX, float spawnY);
    ~Player() override = default;

    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

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
    [[nodiscard]] bool isDropping() const { return platformDropTimer > 0.0f; }


private:
    void loadAnimations();
    void processInput();
    void startAttack();
    void castMagic();
    void renderHitboxes(SDL_Renderer* renderer); // ← это было удалено!
};