/**
 * @file boss_archer.h
 * @brief Босс-лучник с BFS AI, клонами и стрелами
 * @author evol
 * @date 2026-06-08
 *
 * Второй босс (уровень 2). Движется через BFS, прыгает/падает,
 * спавнит клонов-фантомов. На 50% HP переходит в фазу 2 с дополнительными клонами.
 */
#pragma once
#include "../config/common.h"
#include "boss.h"
#include "../utils/texture_manager.h"

// ============================================================
// СТРУКТУРЫ ДАННЫХ
// ============================================================

/**
 * @struct ArcherArrow
 * @brief Летящая стрела. Спавнится клонами, урон фиксирован.
 */
struct ArcherArrow {
    float x      = 0.0f;
    float y      = 0.0f;
    float velX   = 0.0f;
    float velY   = 0.0f;
    bool  active = false;

    static constexpr float SPEED  = 500.0f;  ///< px/s
    static constexpr float DAMAGE = 15.0f;
};

/**
 * @struct ArcherClone
 * @brief Фантом лучника (полупрозрачный). Неуязвим, только стреляет.
 *        Центральный клон следит за игроком, боковые идут в фиксированных направлениях.
 */
struct ArcherClone {
    float x              = 0.0f;
    float y              = 0.0f;
    float dirX           = 1.0f;  ///< Направление стрельбы (нормализовано)
    float dirY           = 0.0f;
    float verticalOffset = 0.0f;  ///< Смещение от лучника по Y (зафиксировано при спавне)
    float offsetX        = 0.0f;  ///< Смещение от центра по X (всегда 0 сейчас)
    bool  active         = false;
    bool  isCenter       = false; ///< true = следит за игроком, false = фиксированный угол
};

// ============================================================
// ПЕРЕЧИСЛЕНИЯ (должны быть в common.h или enum_boss.h)
// ============================================================

// Убедись что эти есть в твоём common.h:
// enum class ArcherState { IDLE, WALK, SWORD_ATTACK, SHOOT, CLONE_VOLLEY, DEATH };
// enum class ArcherPhase { PHASE_1, PHASE_2, DYING };

// ============================================================
// КЛАСС BOSSARCHER
// ============================================================

class BossArcher : public Boss {
private:

    // ════════════════════════════════════════════════════════
    // КОНСТАНТЫ
    // ════════════════════════════════════════════════════════

    // Физика и хитбокс
    static constexpr float HITBOX_W = 50.0f;
    static constexpr float HITBOX_H = 80.0f;
    static constexpr float BASE_HP  = 1000.0f;

    // Спрайт
    static constexpr int   FRAME_W      = 128;
    static constexpr int   FRAME_H      = 128;
    static constexpr float SPRITE_SCALE = 1.5f;

    // Анимации
    static constexpr int FRAMES_IDLE         = 9;
    static constexpr int FRAMES_WALK         = 8;
    static constexpr int FRAMES_SWORD_ATTACK = 5;
    static constexpr int FRAMES_SHOOT        = 14;
    static constexpr int FRAMES_CLONE_VOLLEY = 5;
    static constexpr int FRAMES_DEATH        = 5;

    static constexpr float ANIM_SPD_IDLE         = 0.12f;
    static constexpr float ANIM_SPD_WALK         = 0.09f;
    static constexpr float ANIM_SPD_SWORD_ATTACK = 0.09f;
    static constexpr float ANIM_SPD_SHOOT        = 0.07f;
    static constexpr float ANIM_SPD_CLONE_VOLLEY = 0.09f;
    static constexpr float ANIM_SPD_DEATH        = 0.14f;

    // Движение и боевые характеристики
    static constexpr float MOVE_SPEED       = 180.0f;  ///< Скорость преследования
    static constexpr float SWORD_DAMAGE     = 25.0f;
    static constexpr float MELEE_RANGE      = 80.0f;   ///< До какой дистанции бить мечом
    static constexpr float SWORD_HIT_W      = 100.0f;
    static constexpr float SWORD_HIT_H      = 80.0f;
    static constexpr int   SWORD_HIT_FRAME  = 3;       ///< На каком кадре засчитывается хит

    // Стрелы
    static constexpr int ARROW_HITBOX_W = 20;
    static constexpr int ARROW_HITBOX_H = 8;
    static constexpr int ARROW_W        = 64;
    static constexpr int ARROW_H        = 64;

    // Клоны (фаза 1: 4 клона, фаза 2: 6 + 2 новых)
    static constexpr int   CLONE_COUNT           = 4;
    static constexpr int   CLONE_COUNT_P2        = 6;
    static constexpr float CLONE_SPACING         = 120.0f; ///< Расстояние между клонами по Y
    static constexpr float CLONE_SHOOT_INTERVAL  = 1.2f;   ///< Интервал стрельбы клонов
    static constexpr float VERTICAL_CLONE_OFFSET = 200.0f; ///< Где спавнится вертикальный клон

    // Кулдауны атак (уменьшаются на attackSpeedMult)
    static constexpr float BASE_SWORD_COOLDOWN = 2.0f;
    static constexpr float BASE_SHOOT_COOLDOWN = 1.5f;

    // Прыжок и провал
    static constexpr float JUMP_VELOCITY      = -580.0f;
    static constexpr float JUMP_COOLDOWN_MAX  = 1.5f;
    static constexpr float DROP_THRESHOLD     = 60.0f;  ///< На сколько ниже игрока = провал
    static constexpr float DROP_DURATION      = 0.18f;
    static constexpr float DROP_COOLDOWN      = 0.8f;

    // Смена состояний
    static constexpr float STATE_CHANGE_COOLDOWN = 0.3f;

    // BFS (поиск пути через тайлы)
    static constexpr int   BFS_TILE_SIZE  = 32;
    static constexpr float BFS_INTERVAL   = 0.5f;   ///< Как часто пересчитывать путь
    static constexpr int   BFS_MAX_TILES  = 8000;   ///< Макс узлов в BFS
    static constexpr float BFS_REACH_DIST = 40.0f;  ///< Считаем узел достигнутым

    // ════════════════════════════════════════════════════════
    // ТИПЫ ДАННЫХ BFS
    // ════════════════════════════════════════════════════════

    /// Действие для перемещения между двумя тайлами
    enum class PathAction {
        WALK_LEFT,
        WALK_RIGHT,
        JUMP,
        DROP
    };

    /// Узел пути: тайл + действие чтобы туда попасть
    struct PathNode {
        int        col    = 0;
        int        row    = 0;
        PathAction action = PathAction::WALK_RIGHT;
    };

    // ════════════════════════════════════════════════════════
    // СОСТОЯНИЕ: Игровые переменные
    // ════════════════════════════════════════════════════════

    // Состояние и фаза
    ArcherState currentState      = ArcherState::IDLE;
    ArcherState previousState     = ArcherState::IDLE;
    ArcherPhase phase             = ArcherPhase::PHASE_1;

    // Таймеры
    float stateTimer          = 0.0f;  ///< Монотонно считаем вверх
    float lastStateChangeTime = 0.0f;  ///< Когда последний раз сменилось состояние
    float cloneShootTimer     = 0.0f;  ///< Когда клоны должны стрелять

    // Кулдауны и таймеры атак
    float swordCooldown = 0.0f;  ///< Между ударами мечом (зависит от attackSpeedMult)
    float swordTimer    = 0.0f;  ///< Текущий отсчёт до удара
    float shootCooldown = 0.0f;  ///< Между выстрелами
    float shootTimer    = 0.0f;
    float spawnDelay    = 0.5f;  ///< Задержка при спавне босса

    // Прыжок и платформы
    float jumpCooldown      = 0.0f;  ///< До следующего прыжка
    float platformDropTimer = 0.0f;  ///< Проваливаемся через платформу (>0 = активно)
    float dropCooldown      = 0.0f;  ///< После провала не прыгаем

    // BFS
    std::vector<PathNode> path;   ///< Текущий рассчитанный путь
    int                   pathIndex = 0;  ///< Какой узел пути мы выполняем
    float                 bfsTimer  = 0.0f;  ///< Отсчёт до пересчёта

    // Флаги
    bool meleeHitDealt = false;  ///< Удар мечом в этом цикле уже нанёс урон?
    bool clonesSpawned = false;  ///< Клоны уже спавнены?

    // Сущности
    std::vector<ArcherClone> clones;  ///< Фантомы
    std::vector<ArcherArrow> arrows;  ///< Летящие стрелы

    // Графика
    std::map<ArcherState, SDL_Texture*> textures;
    std::map<ArcherState, Animation>    animations;
    SDL_Texture* arrowTexture = nullptr;

    // ════════════════════════════════════════════════════════
    // ПРИВАТНЫЕ МЕТОДЫ
    // ════════════════════════════════════════════════════════

    // Управление состояниями
    void setState(ArcherState newState);
    void forceState(ArcherState newState);
    [[nodiscard]] bool canChangeState() const;

    // Инициализация
    void loadAnimations();

    // Клоны
    void spawnClones();
    void updateClones(float dt, float playerX, float playerY);
    void checkPhaseTransition();

    // AI
    void updateAI(float dt, float playerX, float playerY);
    void updateMovement(float dt, float playerX, float playerY);

    // BFS — поиск пути
    void recalcPath(float playerX, float playerY);

    /// Можно ли прыгнуть выше из (col,row) и приземлиться?
    [[nodiscard]] bool canJumpTo(int col, int row, int& outLandRow) const;

    /// Найти платформу ниже текущей позиции
    [[nodiscard]] int findPlatformBelow(int col, int row) const;

    /// Тайл — платформа (есть опора снизу)
    [[nodiscard]] bool isSolidTile(int col, int row) const;

    /// Тайл — пустой (можно пройти)
    [[nodiscard]] bool isFreeTile(int col, int row) const;

    // Отрисовка отладочных хитбоксов
    void renderHitboxes(SDL_Renderer* renderer);

public:

    // ════════════════════════════════════════════════════════
    // ПУБЛИЧНЫЕ МЕТОДЫ
    // ════════════════════════════════════════════════════════

    /**
     * @brief Конструктор босса-лучника
     * @param spawnX Позиция X
     * @param spawnY Позиция Y
     * @param attackSpeedMult Множитель скорости атаки (1.0 = базовая, 2.0 = в 2 раза быстрее)
     */
    BossArcher(float spawnX, float spawnY, float attackSpeedMult = 1.0f);

    ~BossArcher() override = default;

    /**
     * @brief Главный update босса
     * @param deltaTime Время кадра (сек)
     * @param playerX X игрока (для AI)
     * @param playerY Y игрока (для AI)
     * @param playerFacingRight Не используется
     */
    void update(float deltaTime, float playerX, float playerY,
                bool playerFacingRight = false) override;

    /**
     * @brief Пустой override из Boss
     */
    void update(float deltaTime) override { (void)deltaTime; }

    /**
     * @brief Отрисовка: клоны → стрелы → босс + хитбоксы
     */
    void render(SDL_Renderer* renderer) override;

    /**
     * @brief Получить хитбокс (для коллизий)
     */
    [[nodiscard]] SDL_Rect getHitbox() const override;

    /**
     * @brief Закончилась ли анимация смерти?
     */
    [[nodiscard]] bool isDeathAnimFinished() const;

    /**
     * @brief Проверить урон игроку (меч + стрелы)
     * @param playerBox Хитбокс игрока
     * @param deltaTime Не используется
     * @return Общий урон (0 если не попала)
     */
    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox, float deltaTime);
};