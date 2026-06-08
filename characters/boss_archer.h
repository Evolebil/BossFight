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

// ============================================================
// СТРУКТУРА СТРЕЛЫ
// ============================================================

/**
 * @struct ArcherArrow
 * @brief Летящая стрела от клона или лучника.
 */
struct ArcherArrow {
    float x      = 0.0f;
    float y      = 0.0f;
    float velX   = 0.0f;
    float velY   = 0.0f;
    bool  active = false;

    static constexpr float SPEED  = 500.0f; ///< Скорость стрелы (px/s)
    static constexpr float DAMAGE = 15.0f;  ///< Урон стрелы
};

// ============================================================
// СТРУКТУРА КЛОНА
// ============================================================

/**
 * @struct ArcherClone
 * @brief Клон-фантом лучника. Нематаемый — урон принимает только настоящий лучник.
 *        Направление стрельбы задаётся при спавне и не меняется (кроме центрального).
 */
struct ArcherClone {
    float x              = 0.0f;
    float y              = 0.0f;
    float dirX           = 0.0f;
    float dirY           = 0.0f;
    float verticalOffset = 0.0f; ///< Смещение по Y от лучника (задаётся при спавне)
    float offsetX        = 0.0f; ///< Смещение по X от центрального (сейчас 0)
    bool  active         = false;
    bool  isCenter       = false;
};

// ============================================================
// КЛАСС BOSSARCHER
// ============================================================

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

    static constexpr float MOVE_SPEED      = 180.0f; ///< Скорость преследования (px/s)
    static constexpr float SWORD_DAMAGE    = 25.0f;  ///< Урон удара мечом
    static constexpr float MELEE_RANGE     = 80.0f;  ///< Дистанция для атаки мечом (px)
    static constexpr float SWORD_HIT_W     = 100.0f; ///< Ширина хитбокса меча (px)
    static constexpr float SWORD_HIT_H     = 80.0f;  ///< Высота хитбокса меча (px)
    static constexpr int   SWORD_HIT_FRAME = 3;      ///< Кадр анимации когда засчитывается хит

    // ============================================================
    // КОНСТАНТЫ — СТРЕЛА
    // ============================================================

    static constexpr int ARROW_HITBOX_W = 20; ///< Ширина хитбокса стрелы (px)
    static constexpr int ARROW_HITBOX_H = 8;  ///< Высота хитбокса стрелы (px)
    static constexpr int ARROW_W        = 64; ///< Ширина спрайта стрелы (px)
    static constexpr int ARROW_H        = 64; ///< Высота спрайта стрелы (px)

    // ============================================================
    // КОНСТАНТЫ — КЛОНЫ
    // ============================================================

    static constexpr int   CLONE_COUNT           = 4;      ///< Клонов в фазе 1
    static constexpr int   CLONE_COUNT_P2        = 6;      ///< Клонов в фазе 2
    static constexpr float CLONE_SPACING         = 120.0f; ///< Вертикальный отступ между клонами (px)
    static constexpr float CLONE_SHOOT_INTERVAL  = 1.2f;   ///< Интервал стрельбы клонов (сек)
    static constexpr float VERTICAL_CLONE_OFFSET = 200.0f; ///< Смещение вертикального клона над лучником (px)

    // ============================================================
    // КОНСТАНТЫ — СМЕНА СОСТОЯНИЙ
    // ============================================================

    static constexpr float STATE_CHANGE_COOLDOWN = 0.3f;

    // ============================================================
    // КОНСТАНТЫ — БАЗОВЫЕ КУЛДАУНЫ
    // ============================================================

    static constexpr float BASE_SWORD_COOLDOWN = 2.0f; ///< Базовый кулдаун меча (сек)
    static constexpr float BASE_SHOOT_COOLDOWN = 1.5f; ///< Базовый кулдаун выстрела (сек)

    // ============================================================
    // КОНСТАНТЫ — РАЗМЕРЫ СПРАЙТА
    // ============================================================

    static constexpr int   FRAME_W      = 128;  ///< Ширина кадра (px)
    static constexpr int   FRAME_H      = 128;  ///< Высота кадра (px)
    static constexpr float SPRITE_SCALE = 1.5f; ///< Масштаб при отрисовке

    // ============================================================
    // КОНСТАНТЫ — КОЛИЧЕСТВО КАДРОВ
    // ============================================================

    static constexpr int FRAMES_IDLE         = 9;
    static constexpr int FRAMES_WALK         = 8;
    static constexpr int FRAMES_SWORD_ATTACK = 5;  ///< Attack_1.png
    static constexpr int FRAMES_SHOOT        = 14; ///< Shot.png
    static constexpr int FRAMES_CLONE_VOLLEY = 5;  ///< Attack_2.png
    static constexpr int FRAMES_DEATH        = 5;  ///< Dead.png

    // ============================================================
    // КОНСТАНТЫ — СКОРОСТИ АНИМАЦИЙ
    // ============================================================

    static constexpr float ANIM_SPD_IDLE         = 0.12f;
    static constexpr float ANIM_SPD_WALK         = 0.09f;
    static constexpr float ANIM_SPD_SWORD_ATTACK = 0.09f;
    static constexpr float ANIM_SPD_SHOOT        = 0.07f;
    static constexpr float ANIM_SPD_CLONE_VOLLEY = 0.09f;
    static constexpr float ANIM_SPD_DEATH        = 0.14f;

    // ============================================================
    // ПОЛЯ — СОСТОЯНИЕ И ФАЗА
    // ============================================================

    ArcherState currentState      = ArcherState::IDLE;
    ArcherState previousState     = ArcherState::IDLE;
    ArcherPhase phase             = ArcherPhase::PHASE_1;

    float stateTimer          = 0.0f; ///< Монотонно растущий таймер (сек)
    float lastStateChangeTime = 0.0f; ///< stateTimer в момент последней смены
    float cloneShootTimer     = 0.0f; ///< Общий таймер стрельбы клонов (сек)

    // ============================================================
    // ПОЛЯ — ТАЙМЕРЫ И КУЛДАУНЫ
    // ============================================================

    float swordCooldown = 0.0f; ///< Текущий кулдаун меча (зависит от attackSpeedMult)
    float swordTimer    = 0.0f; ///< До следующего удара мечом (сек)
    float shootCooldown = 0.0f; ///< Текущий кулдаун выстрела (зависит от attackSpeedMult)
    float shootTimer    = 0.0f; ///< До следующего выстрела (сек)
    float spawnDelay    = 0.5f; ///< Задержка после спавна (сек)

    // ============================================================
    // ПОЛЯ — ПРЫЖОК И ПРОВАЛ
    // ============================================================

    float jumpCooldown      = 0.0f;   ///< До следующего прыжка (сек)
    float platformDropTimer = 0.0f;   ///< >0 = проваливаемся через платформу
    float dropCooldown      = 0.0f;   ///< Защита от повторного провала

    // ============================================================
    // КОНСТАНТЫ — BFS
    // ============================================================

    static constexpr int   BFS_TILE_SIZE  = 32;    ///< Размер тайла (px)
    static constexpr float BFS_INTERVAL   = 0.5f;  ///< Пересчёт пути (сек)
    static constexpr int   BFS_MAX_TILES  = 8000;  ///< Лимит узлов (160*50)
    static constexpr float BFS_REACH_DIST = 40.0f; ///< Считаем узел достигнутым (px)

    // ============================================================
    // СТРУКТУРЫ BFS
    // ============================================================

    /// Тип действия между двумя узлами пути
    enum class PathAction {
        WALK_LEFT,   ///< Идти влево
        WALK_RIGHT,  ///< Идти вправо
        JUMP,        ///< Прыгнуть вверх
        DROP         ///< Провалиться вниз
    };

    /// Один узел пути — тайл + действие чтобы туда попасть
    struct PathNode {
        int        col    = 0;
        int        row    = 0;
        PathAction action = PathAction::WALK_RIGHT;
    };

    // ============================================================
    // ПОЛЯ — BFS
    // ============================================================

    std::vector<PathNode> path;          ///< Текущий найденный путь
    int                   pathIndex = 0; ///< Текущий узел пути
    float                 bfsTimer  = 0.0f; ///< Таймер пересчёта пути

    // ============================================================
    // КОНСТАНТЫ — ПРЫЖОК И ПРОВАЛ
    // ============================================================

    static constexpr float JUMP_VELOCITY    = -580.0f;  ///< Начальная скорость прыжка
    static constexpr float JUMP_COOLDOWN_MAX = 1.5f;    ///< Кулдаун прыжка (сек)
    static constexpr float DROP_THRESHOLD   = 60.0f;    ///< Игрок ниже на столько → провал (px)
    static constexpr float DROP_DURATION    = 0.18f;    ///< Длительность провала (сек)
    static constexpr float DROP_COOLDOWN    = 0.8f;     ///< Кулдаун между провалами (сек)

    // ============================================================
    // ПОЛЯ — ФЛАГИ
    // ============================================================

    bool meleeHitDealt = false; ///< Удар мечом уже нанёс урон в этом замахе
    bool clonesSpawned = false; ///< Клоны уже заспавнены

    // ============================================================
    // ПОЛЯ — КЛОНЫ, СТРЕЛЫ, ТЕКСТУРЫ
    // ============================================================

    std::vector<ArcherClone> clones; ///< Активные клоны
    std::vector<ArcherArrow> arrows; ///< Активные стрелы

    std::map<ArcherState, SDL_Texture*> textures;   ///< PNG для каждого состояния
    std::map<ArcherState, Animation>    animations; ///< Анимация для каждого состояния
    SDL_Texture* arrowTexture = nullptr;            ///< Arrow.png

    // ============================================================
    // ПРИВАТНЫЕ МЕТОДЫ
    // ============================================================

    void setState(ArcherState newState);
    void forceState(ArcherState newState);
    [[nodiscard]] bool canChangeState() const;

    void loadAnimations();
    void spawnClones();
    void updateClones(float dt, float playerX, float playerY);
    void checkPhaseTransition();
    void updateAI(float dt, float playerX, float playerY);
    void renderHitboxes(SDL_Renderer* renderer);
    void updateMovement(float dt, float playerX, float playerY);
    /// Пересчитать путь от лучника к игроку через BFS
    void recalcPath(float playerX, float playerY);

    /// Проверить можно ли прыгнуть из (col,row) и приземлиться на платформу выше
    [[nodiscard]] bool canJumpTo(int col, int row, int& landRow) const;

    /// Найти ближайшую платформу ниже (col,row) — возвращает row платформы или -1
    [[nodiscard]] int  findPlatformBelow(int col, int row) const;

    /// Тайл является платформой (есть на чём стоять снизу)
    [[nodiscard]] bool isSolidTile(int col, int row) const;

    /// Тайл пустой (можно пройти сквозь)
    [[nodiscard]] bool isFreeTile(int col, int row) const;

public:

    // ============================================================
    // ПУБЛИЧНЫЕ МЕТОДЫ
    // ============================================================

    BossArcher(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossArcher() override = default;

    void update(float deltaTime, float playerX, float playerY,
                bool playerFacingRight = false) override;

    void update(float deltaTime) override { (void)deltaTime; }

    void render(SDL_Renderer* renderer) override;

    [[nodiscard]] SDL_Rect getHitbox() const override;
    [[nodiscard]] bool  isDeathAnimFinished() const;
    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox, float deltaTime);
};