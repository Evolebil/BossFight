/**
 * @file boss_deadnight.h
 * @brief Финальный босс "Смерть Ночи" — 4 фазы, летающая неуязвимая стадия
 *        над ареной + уязвимая ближнебойная стадия на земле.
 * @author evol
 * @date 2026-09-03
 *
 * ЗАГЛУШКА ГРАФИКИ: спрайты ещё не готовы. render() рисует красный
 * прямоугольник вместо тела, оранжевый квадрат вместо файрбола.
 * Анимации подключим позже отдельным патчем.
 *
 * ЦИКЛ ФАЗЫ:
 *   FLYING_TOP (неуязвим, файрболы вниз) --30 сек--> начинают спавниться
 *   миньоны (спавн миньонов НЕ реализован в этом файле — это отдельная
 *   система GroundMinion, будет подключена позже через registerMinionKilled()).
 *   Когда 5/5 миньонов убито снаружи вызывается onFiveMinionsKilled() →
 *   DESCENDING → ARENA_IDLE/DASHING/MELEE_ATTACK/RETREATING (уязвим) →
 *   после потери 25% MAX HP → ASCENDING → снова FLYING_TOP, phase++,
 *   прогресс миньонов и таймер сбрасываются.
 */
#pragma once
#include "boss.h"
#include "../utils/texture_manager.h"

// ============================================================
// ФАЙРБОЛ
// ============================================================
struct Fireball {
    float x = 0.0f, y = 0.0f;
    float velX = 0.0f, velY = 0.0f;
    bool  active   = false;
    bool  exploded = false;
    float explodeTimer = 0.0f;  ///< сколько ещё показывать взрыв
    bool  damageDealt   = false;
};

class BossDeadNight : public Boss {
private:
    // ============================================================
    // КОНСТАНТЫ — ХИТБОКС И HP
    // ============================================================
    static constexpr float HITBOX_W = 80.0f;   // TODO: подогнать под спрайт
    static constexpr float HITBOX_H = 100.0f;  // TODO: подогнать под спрайт
    static constexpr float BASE_HP  = 1200.0f; // TODO: согласовать число

    // ============================================================
    // КОНСТАНТЫ — БЛИЖНИЙ БОЙ (посчитано по ТЗ)
    // ============================================================
    // 1.5x урона самурая (DAMAGE_SWORD самурая = 20.0f)
    static constexpr float DAMAGE_MELEE = 30.0f;
    // Хитбокс ближней атаки: тело x2 по длине, выдвинут в сторону игрока
    static constexpr float MELEE_HIT_W = HITBOX_W * 2.0f;
    static constexpr float MELEE_HIT_H = HITBOX_H;
    // TODO: урон рывка не зафиксирован в ТЗ отдельно — временно = DAMAGE_MELEE
    static constexpr float DAMAGE_DASH = DAMAGE_MELEE;

    // ============================================================
    // КОНСТАНТЫ — РЫВКИ (3 рывка -> отступление -> ожидание)
    // ============================================================
    static constexpr int   DASH_COUNT_PER_CYCLE   = 3;
    static constexpr float DASH_SPEED             = 700.0f; // TODO: подобрать
    static constexpr float DASH_DURATION          = 0.25f;  // TODO: подобрать
    static constexpr float DASH_BETWEEN_COOLDOWN  = 0.5f;   // TODO: подобрать
    static constexpr float RETREAT_SPEED          = 300.0f; // TODO: подобрать
    static constexpr float RETREAT_DURATION       = 0.4f;   // TODO: подобрать
    // Ожидание между циклами рывков — уменьшается с фазой ("рывки чаще")
    static constexpr float RETREAT_WAIT_BY_PHASE[4] = {5.0f, 4.0f, 3.0f, 2.0f}; // TODO: подобрать

    // ============================================================
    // КОНСТАНТЫ — ПОЛЁТ НАВЕРХУ / СПУСК / ПОДЪЁМ
    // ============================================================
    static constexpr float FLY_SPEED     = 60.0f;  // TODO: подобрать ("летает медленно")
    static constexpr float ASCEND_SPEED  = 200.0f; // TODO: подобрать
    static constexpr float TOP_MARGIN    = 40.0f;  ///< отступ от краёв карты при полёте
    static constexpr int FLY_RANGE_MARGIN_TILES = 3; // TODO: подобрать запас с краёв
    // ============================================================
    // КОНСТАНТЫ — ФАЙРБОЛ
    // ============================================================
    static constexpr float FIREBALL_SPRITE_SIZE = 64.0f;                    // TODO: под реальный спрайт
    static constexpr float FIREBALL_HIT_SIZE     = FIREBALL_SPRITE_SIZE / 2.0f;
    static constexpr float FIREBALL_EXPLODE_RADIUS = FIREBALL_HIT_SIZE * 3.0f;
    static constexpr float FIREBALL_SPEED         = 350.0f; // TODO: подобрать
    static constexpr float FIREBALL_DAMAGE        = 25.0f;  // TODO: согласовать
    static constexpr float FIREBALL_COOLDOWN      = 2.0f;   // TODO: подобрать
    static constexpr float FIREBALL_EXPLODE_LIFETIME = 0.3f; ///< сколько кадров висит взрыв

    // ============================================================
    // КОНСТАНТЫ — ЦИКЛ ФАЗЫ (ТЗ, зафиксировано)
    // ============================================================
    static constexpr float SURVIVAL_TIME    = 30.0f;
    static constexpr int   MINIONS_REQUIRED = 5;
    // Порог HP (доля от MAX), по достижении которого фаза завершается
    static constexpr float PHASE_HP_THRESHOLD[4] = {0.75f, 0.50f, 0.25f, 0.0f};

    static constexpr float STATE_CHANGE_COOLDOWN = 0.2f;

    // ============================================================
    // ПОЛЯ
    // ============================================================
    DeadNightState currentState = DeadNightState::FLYING_TOP;
    DeadNightState previousState = DeadNightState::FLYING_TOP;
    DeadNightPhase phase = DeadNightPhase::PHASE_1;

    float stateTimer          = 0.0f;
    float lastStateChangeTime = 0.0f;

    // --- Верхняя стадия ---
    float topY               = 0.0f;   ///< Y-позиция "наверху" (запоминается при спавне)
    float flyDirX             = 1.0f;
    float survivalTimer       = 0.0f;  ///< тикает до SURVIVAL_TIME
    bool  survivalPassed      = false; ///< true = миньоны уже могут спавниться (внешняя система)
    float fireballTimer       = 0.0f;
    int flyMinCol = 0;
    int flyMaxCol = 0;

    // --- Прогресс миньонов (счёт ведёт внешняя система через registerMinionKilled) ---
    int  minionsKilled = 0;

    // --- Рывки ---
    int   dashesDoneInCycle = 0;
    float dashTimer         = 0.0f; ///< обратный отсчёт текущего действия (рывок/отступление/ожидание)
    float dashDirX           = 1.0f;
    bool  dashHitDealt       = false;

    // --- Ближняя атака ---
    bool meleeHitDealt = false;

    // --- Файрболы ---
    std::vector<Fireball> fireballs;

    // --- Текстуры (пока не используются — заглушка) ---
    SDL_Texture* spritesheet_placeholder = nullptr;

public:
    BossDeadNight(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossDeadNight() override = default;

    void update(float deltaTime, float playerX, float playerY, bool playerFacingRight = true) override;
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    [[nodiscard]] SDL_Rect getHitbox() const override {
        return { (int)(x - width / 2), (int)(y - height / 2), (int)width, (int)height };
    }

    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox, float deltaTime);

    // --- API для внешней системы миньонов/дверей (миньоны — отдельная задача) ---
    void registerMinionKilled();       ///< вызывать когда игрок убил наземного миньона
    void registerMinionReachedDoor();  ///< миньон дошёл до двери — просто лог, счётчик не трогаем

    // --- Геттеры для HUD ---
    [[nodiscard]] int  getMinionsKilled()   const { return minionsKilled; }
    [[nodiscard]] int  getMinionsRequired() const { return MINIONS_REQUIRED; }
    [[nodiscard]] bool isVulnerable()       const {
        return currentState != DeadNightState::FLYING_TOP &&
               currentState != DeadNightState::DESCENDING  &&
               currentState != DeadNightState::ASCENDING   &&
               currentState != DeadNightState::DEATH;
    }
    [[nodiscard]] int  getPhaseNumber() const { return (int)phase + 1; } // 1..4
    [[nodiscard]] bool getSurvivalPassed() const { return survivalPassed; }
    [[nodiscard]] float getSurvivalTimeLeft() const { return std::max(0.0f, SURVIVAL_TIME - survivalTimer); }

private:
    void setState(DeadNightState newState);
    void forceState(DeadNightState newState);
    [[nodiscard]] bool canChangeState() const;

    void updateFlyingTop(float deltaTime, float playerX, float playerY);
    void updateArena(float deltaTime, float playerX, float playerY);
    void updateDashCycle(float deltaTime, float playerX, float playerY);
    void updateDescending(float deltaTime);
    void updateAscending(float deltaTime);

    void spawnFireball(float playerX, float playerY);
    void updateFireballs(float deltaTime);

    void onPhaseHpThresholdReached(); ///< вызывается из takeDamage
    void resetForNextPhaseTop();      ///< сброс таймера/счётчика при возврате наверх

    void renderFireballs(SDL_Renderer* renderer, int camX, int camY);
    void renderHitboxes(SDL_Renderer* renderer, int camX, int camY);
};