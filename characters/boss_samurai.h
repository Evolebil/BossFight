/**
 * @file boss_samurai.h
 * @brief Босс-самурай — дуэлянт средней дистанции (Уровень 2)
 * @author evol
 * @date 2026-05-20
 *
 * ─── ЛОГИКА БОЯ ────────────────────────────────────────────────
 *
 *  Самурай держит предпочтительную дистанцию PREFERRED_DISTANCE (200px).
 *  В зависимости от расстояния до игрока он выбирает атаку:
 *
 *   dist ≥ DIST_FAR (500px)    → телепорт за спину игрока
 *   DIST_CLOSE…DIST_FAR        → веер из 5 бомб
 *   dist < DIST_CLOSE (80px)   → стойка парирования
 *     └ игрок ударил в стойке  → парирование (телепорт + бомбы + стан игрока)
 *     └ стойка истекла 5 сек   → самурай оглушён 2 сек
 *   Все кулдауны активны       → серия из 3 ударов мечом, затем отскок
 *
 * ─── ФАЗЫ ──────────────────────────────────────────────────────
 *
 *   PHASE_1 → стандартное поведение
 *   DYING   → HP ≤ 0, идёт анимация смерти (логика AI остановлена)
 *
 * ─── СВЯЗИ ─────────────────────────────────────────────────────
 *
 *   Наследует Boss → Character
 *   Использует g_camera (camera.h) для перевода мировых координат в экранные
 *   Использует g_currentLevel (ilevel.h) через CollisionSystem
 */
#pragma once
#include "boss.h"
#include "../utils/texture_manager.h"

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ СТРУКТУРЫ
// ============================================================

/**
 * @struct Bomb
 * @brief Одна летящая / взорвавшаяся бомба.
 *
 * Жизненный цикл:
 *   1. Создаётся в throwBombsFan() с active=true, exploded=false
 *   2. Летит по заданной скорости (velX, velY)
 *   3. После истечения fuseTimer → exploded = true (взрыв)
 *   4. Взрыв наносит урон если игрок в радиусе EXPLODE_RADIUS
 *   5. После нанесения урона / или конца анимации → active = false → удаляется
 */
struct Bomb {
    float x, y;        ///< Текущая позиция (мировые координаты)
    float velX, velY;  ///< Скорость (px/s)
    float fuseTimer;   ///< Секунд до взрыва (считается вниз)
    bool  active;      ///< false = убрать из вектора
    bool  exploded;    ///< true = показывать анимацию взрыва, наносить урон

    Animation explodeAnim { false };  // ← своя анимация у каждой бомбы
    // --- Константы бомбы ---
    static constexpr float FUSE_TIME      = 2.0f;   ///< Секунд до взрыва
    static constexpr float SPEED          = 300.0f; ///< Начальная скорость (px/s)
    static constexpr float DAMAGE         = 20.0f;  ///< Урон взрыва (не используется напрямую — см. BossSamurai::DAMAGE_BOMB)
    static constexpr float EXPLODE_RADIUS = 80.0f;  ///< Радиус взрыва (px)
};

/**
 * @struct SmokeParticle
 * @brief Одна частица дымки вокруг самурая.
 *
 * Спавнится в spawnSmoke(), рисуется в renderSmoke().
 * Размер частицы растёт по мере угасания (8px → 32px).
 */
struct SmokeParticle {
    float x, y;         ///< Позиция (мировые координаты)
    float velX, velY;   ///< Скорость дрейфа (px/s)
    float lifetime;     ///< Оставшееся время жизни (сек)
    float maxLifetime;  ///< Начальное время жизни (для вычисления альфы)
    Uint8 alpha;        ///< Текущая прозрачность (0 = невидима)
};

// ============================================================
// КЛАСС BOSSAMURAI
// ============================================================

/**
 * @class BossSamurai
 * @brief Второй босс игры — самурай с телепортом, бомбами и парированием.
 *
 * Наследует Boss, который наследует Character.
 * Всю AI-логику описывает updateAI().
 * Урон по игроку проверяет GameScene через checkPlayerDamage().
 */
class BossSamurai : public Boss {
private:

    // ============================================================
    // КОНСТАНТЫ — ХИТБОКС И HP
    // ============================================================

    static constexpr float HITBOX_W = 50.0f;   ///< Ширина хитбокса (px)
    static constexpr float HITBOX_H = 80.0f;   ///< Высота хитбокса (px)
    static constexpr float BASE_HP  = 800.0f;  ///< Начальное HP

    // ============================================================
    // КОНСТАНТЫ — ДВИЖЕНИЕ
    // ============================================================

    static constexpr float MOVE_SPEED          = 200.0f;  ///< Скорость ходьбы (px/s)
    static constexpr float PREFERRED_DISTANCE  = 120.0f;  ///< Комфортная дистанция до игрока (px)
    static constexpr float DISTANCE_THRESHOLD  = 30.0f;   ///< Мёртвая зона — меньше этого не двигаемся (px)
    static constexpr float JUMP_VELOCITY       = -580.0f; ///< Начальная скорость прыжка (px/s вверх)
    static constexpr float JUMP_COOLDOWN_MAX   = 1.5f;    ///< Кулдаун прыжка (сек)

    // ============================================================
    // КОНСТАНТЫ — ЗОНЫ ДИСТАНЦИИ (определяют выбор атаки)
    // ============================================================

    static constexpr float DIST_CLOSE  =  80.0f;  ///< Ближняя зона — стойка (px)
    static constexpr float DIST_MEDIUM = 250.0f;  ///< Средняя зона (не используется напрямую)
    static constexpr float DIST_FAR    = 500.0f;  ///< Дальняя зона — телепорт (px)

    // ============================================================
    // КОНСТАНТЫ — ТЕЛЕПОРТ
    // ============================================================

    static constexpr float TELEPORT_OFFSET   = 150.0f;  ///< Смещение за спиной игрока (px)
    static constexpr float TELEPORT_COOLDOWN = 4.0f;    ///< Кулдаун телепорта (сек)
    static constexpr float TELEPORT_BACKOFF  = 120.0f;  ///< Отскок НАЗАД после телепорта для создания расстояния (px)

    // ============================================================
    // КОНСТАНТЫ — БОМБЫ
    // ============================================================

    static constexpr int   BOMB_COUNT        = 5;      ///< Бомб в одном броске
    static constexpr float BOMB_SPREAD_ANGLE = 20.0f;  ///< Угол между бомбами в веере (градусы)
    static constexpr float BOMB_COOLDOWN     = 3.0f;   ///< Кулдаун броска бомб (сек)
    static constexpr float DAMAGE_BOMB       = 25.0f;  ///< Урон взрыва бомбы

    // ============================================================
    // КОНСТАНТЫ — СТОЙКА И СТАН
    // ============================================================

    static constexpr float STANCE_DURATION   = 1.5f;  ///< Максимум стойки до автостана (сек)
    static constexpr float STUN_DURATION   = 2.0f;  ///< Длительность стана (сек)

    // ============================================================
    // КОНСТАНТЫ — УДАР МЕЧОМ
    // ============================================================

    static constexpr float DAMAGE_SWORD       = 20.0f;   ///< Урон одного удара меча
    static constexpr int   SWORD_HIT_FRAME    = 2;       ///< Кадр анимации когда засчитывается хит
    static constexpr int   SWORD_HIT_W        = 100;      ///< Ширина хитбокса меча (px)
    static constexpr int   SWORD_HIT_H        = 150;      ///< Высота хитбокса меча (px)
    static constexpr float SWORD_COOLDOWN     = 2.0f;    ///< Кулдаун между ударами меча (сек)
    static constexpr int   SWORD_COMBO_MAX    = 3;       ///< Ударов подряд в серии
    static constexpr float SWORD_BREAK_SPEED  = 400.0f;  ///< Скорость отскока после серии (px/s)
    static constexpr float BREAK_AWAY_DURATION = 0.5f;  ///< Длительность отскока (сек)

    // ============================================================
    // КОНСТАНТЫ — ДЫМКА
    // ============================================================

    static constexpr float SMOKE_COOLDOWN = 8.0f;  ///< Пауза между порциями дыма (сек)

    // ============================================================
    // КОНСТАНТЫ — АНИМАЦИИ СПРАЙТА
    // ============================================================

    static constexpr int   FRAME_W       = 128;   ///< Ширина одного кадра спрайта (px)
    static constexpr int   FRAME_H       = 128;   ///< Высота одного кадра спрайта (px)
    static constexpr float SPRITE_SCALE  = 1.5f;  ///< Масштаб при отрисовке

    // Количество кадров для каждого состояния
    static constexpr int FRAMES_IDLE         = 6;
    static constexpr int FRAMES_WALK         = 8;
    static constexpr int FRAMES_JUMP         = 9;
    static constexpr int FRAMES_SWORD_ATTACK = 4;
    static constexpr int FRAMES_THROW_BOMBS  = 5;
    static constexpr int FRAMES_POWER_ATTACK = 4;
    static constexpr int FRAMES_STANCE       = 2;
    static constexpr int FRAMES_STUNNED      = 3;
    static constexpr int FRAMES_DEATH        = 6;

    // Скорость анимаций (секунд на кадр)
    static constexpr float ANIM_SPD_IDLE         = 0.15f;
    static constexpr float ANIM_SPD_WALK         = 0.09f;
    static constexpr float ANIM_SPD_JUMP         = 0.10f;
    static constexpr float ANIM_SPD_SWORD_ATTACK = 0.08f;
    static constexpr float ANIM_SPD_THROW_BOMBS  = 0.09f;
    static constexpr float ANIM_SPD_POWER_ATTACK = 0.08f;
    static constexpr float ANIM_SPD_STANCE       = 0.12f;
    static constexpr float ANIM_SPD_STUNNED      = 0.12f;
    static constexpr float ANIM_SPD_DEATH        = 0.12f;

    // ============================================================
    // КОНСТАНТЫ — АНИМАЦИИ БОМБЫ И ВЗРЫВА
    // ============================================================

    static constexpr int   BOMB_FRAME_W      = 80;     ///< Ширина кадра бомбы (px)
    static constexpr int   BOMB_FRAME_H      = 80;     ///< Высота кадра бомбы (px)
    static constexpr int   BOMB_FRAMES       = 40;     ///< Кадров в анимации бомбы
    static constexpr float BOMB_ANIM_SPEED   = 0.05f;  ///< Сек на кадр анимации бомбы

    static constexpr int   EXPLODE_FRAME_W   = 64;     ///< Ширина кадра взрыва (px)
    static constexpr int   EXPLODE_FRAME_H   = 64;     ///< Высота кадра взрыва (px)
    static constexpr int   EXPLODE_FRAMES    = 16;     ///< Всего кадров взрыва
    static constexpr int   EXPLODE_COLS      = 4;      ///< Столбцов в спрайтшите взрыва
    static constexpr float EXPLODE_ANIM_SPEED = 0.04f; ///< Сек на кадр взрыва

    // ============================================================
    // КОНСТАНТЫ — СМЕНА СОСТОЯНИЙ
    // ============================================================

    /// Минимальный интервал между сменами состояний (сек).
    /// Защищает от мгновенного переключения туда-обратно.
    static constexpr float STATE_CHANGE_COOLDOWN = 0.3f;

    // ============================================================
    // ПОЛЯ — СОСТОЯНИЕ И ФАЗА
    // ============================================================

    SamuraiState currentState      = SamuraiState::IDLE;   ///< Активное состояние
    SamuraiState previousState     = SamuraiState::IDLE;   ///< Предыдущее (для отладки)
    SamuraiPhase phase             = SamuraiPhase::PHASE_1;
    SamuraiState queuedAttack = SamuraiState::IDLE;  // атака запланированная после телепорта

    float stateTimer               = 0.0f;  ///< Монотонно растущий таймер (сек от старта)
    float lastStateChangeTime      = 0.0f;  ///< stateTimer в момент последней смены состояния

    // ============================================================
    // ПОЛЯ — ТАЙМЕРЫ КУЛДАУНОВ
    // ============================================================

    float teleportTimer    = 0.0f;  ///< Сколько осталось до следующего телепорта (сек)
    float bombTimer        = 0.0f;  ///< Сколько осталось до следующего броска бомб (сек)
    float smokeTimer       = 0.0f;  ///< Сколько осталось до следующей порции дыма (сек)
    float swordTimer       = 0.0f;  ///< Сколько осталось до следующего удара меча (сек)
    float stanceTimer      = 0.0f;  ///< Сколько секунд стойка уже активна
    float stunTimer        = 0.0f;  ///< Сколько осталось оглушения (сек)
    float jumpCooldown     = 0.0f;  ///< Сколько осталось до следующего прыжка (сек)
    float spawnDelay = 0.5f;  ///< Задержка перед началом действий после спавна
    float platformDropTimer = 0.0f; ///< >0 = активно проваливаемся через платформу


    // ── НОВЫЕ ПОЛЯ ──────────────────────────────────────────
    float lastPlayerX           = 0.0f;   ///< X позиция игрока (сохранено в update)
    float lastPlayerY           = 0.0f;   ///< Y позиция игрока (сохранено в update)
    bool  lastPlayerFacingRight = true;   ///< Направление взгляда игрока (true=вправо)

    // ============================================================
    // ПОЛЯ — ФЛАГИ
    // ============================================================

    bool stanceActive   = false;  ///< true = стойка активна, парирование засчитывается
    bool meleeHitDealt  = false;  ///< true = удар меча уже нанёс урон в этом замахе
    bool attackSpawned  = false;  ///< true = атака этого состояния уже запущена
    bool isJumping      = false;  ///< true = персонаж в прыжке (физика прыжка активна)
    bool isBreakingAway = false;  ///< true = выполняется отскок после серии ударов

    // ============================================================
    // ПОЛЯ — СЕРИЯ УДАРОВ МЕЧОМ
    // ============================================================

    int   swordComboCount = 0;    ///< Сколько ударов уже нанесено в текущей серии
    float breakAwayTimer  = 0.0f; ///< Таймер отскока после серии (сек)

    // ============================================================
    // ПОЛЯ — АНИМАЦИИ И ТЕКСТУРЫ
    // ============================================================

    std::map<SamuraiState, SDL_Texture*> textures;    ///< PNG для каждого состояния
    std::map<SamuraiState, Animation>    animations;  ///< Анимация для каждого состояния

    SDL_Texture* bombTexture    = nullptr;  ///< Спрайт летящей бомбы
    SDL_Texture* explodeTexture = nullptr;  ///< Спрайтшит взрыва

    Animation bombAnim    { true };   ///< Анимация летящей бомбы (зацикленная)

    // ============================================================
    // ПОЛЯ — ОБЪЕКТЫ В МИРЕ
    // ============================================================

    std::vector<Bomb>          bombs;          ///< Активные бомбы (летящие и взорвавшиеся)
    std::vector<SmokeParticle> smokeParticles; ///< Активные частицы дыма

    // ============================================================
    // ПРИВАТНЫЕ МЕТОДЫ — УПРАВЛЕНИЕ СОСТОЯНИЕМ
    // ============================================================

    /**
     * @brief Сменить состояние с соблюдением кулдауна STATE_CHANGE_COOLDOWN.
     *        Если то же состояние или кулдаун не прошёл — игнорируется.
     */
    void setState(SamuraiState newState);

    /**
     * @brief Принудительно сменить состояние, игнорируя кулдаун.
     *        Используется для атак и смерти.
     */
    void forceState(SamuraiState newState);

    /**
     * @brief Вернуть true если можно сменить состояние через setState().
     */
    [[nodiscard]] bool canChangeState() const;

    // ============================================================
    // ПРИВАТНЫЕ МЕТОДЫ — ОТЛАДКА
    // ============================================================

    /**
     * @brief Нарисовать все хитбоксы (вызывается только если showHitboxes = true).
     *
     *   Зелёный прямоугольник — физический хитбокс босса
     *   Красный прямоугольник — хитбокс меча (только при атаке)
     *   Синий прямоугольник  — радиус взрыва каждой бомбы
     *   Белая точка          — центр (x, y)
     */
    void renderHitboxes(SDL_Renderer* renderer);

    // В boss_samurai.h — приватный метод:
    void initBombExplodeAnim(Animation& anim);

public:

    // ============================================================
    // ПУБЛИЧНЫЕ МЕТОДЫ
    // ============================================================

    /**
     * @brief Создать самурая в позиции (spawnX, spawnY).
     * @param attackSpeedMult Множитель скорости атак (сложность уровня)
     */
    BossSamurai(float spawnX, float spawnY, float attackSpeedMult = 1.0f);

    ~BossSamurai() override = default;

    // ---- Основной цикл ----

    /**
     * @brief Обновить логику самурая на один кадр.
     * @param deltaTime           Время кадра (сек)
     * @param playerX             Текущая X игрока (мировые координаты)
     * @param playerY             Текущая Y игрока (мировые координаты)
     * @param playerFacingRight   Направление взгляда игрока (true = вправо, false = влево)
     */
    void update(float deltaTime, float playerX, float playerY, bool playerFacingRight = false) override;

    /// Сказать боссу: игрок сейчас смотрит вправо (true) или влево (false)
    void setPlayerDirection(bool facingRight) {
        lastPlayerFacingRight = facingRight;
    }


    /// Заглушка — босс требует координаты игрока, используй версию выше
    void update(float deltaTime) override { (void)deltaTime; }

    /**
     * @brief Нарисовать самурая, дым, бомбы (и хитбоксы если showHitboxes=true).
     */
    void render(SDL_Renderer* renderer) override;

    // ---- Хитбокс ----

    /// Физический прямоугольник для коллизий и нанесения урона
    [[nodiscard]] SDL_Rect getHitbox() const override {
        return {
            (int)(x - width  / 2),
            (int)(y - height / 2),
            (int)width,
            (int)height
        };
    }

    // ---- Загрузка ресурсов ----

    /**
     * @brief Загрузить все текстуры и заполнить анимации.
     *        Вызывается один раз в конструкторе.
     */
    void loadAnimations();

    // ---- Атаки ----

    /**
     * @brief Мгновенно переместиться за спину игрока.
     *        Направление: противоположная сторона от текущего взгляда самурая.
     */
    void teleportBehindPlayer();

    /**
     * @brief Выпустить веер из BOMB_COUNT бомб вперёд-вниз.
     *        Угол между бомбами — BOMB_SPREAD_ANGLE градусов.
     */
    void throwBombsFan();

    /**
     * @brief Создать 20 частиц дыма вокруг самурая.
     *        Вызывается автоматически по таймеру и при входе в стойку.
     */
    void spawnSmoke();

    // ---- Проверки ----

    /**
     * @brief Вызвать из GameScene когда игрок атакует самурая.
     *        Если стойка активна — засчитывается парирование:
     *        самурай телепортируется, бросает бомбы, стан снимается.
     * @return true — игроку нужно наложить стан
     * @return false — стойки нет, обычный удар
     */
    [[nodiscard]] bool checkParry();

    /**
     * @brief Вернуть true когда анимация смерти дошла до конца.
     *        GameScene использует это чтобы убрать босса со сцены.
     */
    [[nodiscard]] bool isDeathAnimFinished() const;

    /**
     * @brief Вычислить урон нанесённый игроку за этот кадр.
     *
     * Проверяет:
     *   - хитбокс меча (при SWORD_ATTACK, один раз за замах)
     *   - радиусы взорвавшихся бомб
     *
     * @param playerBox  Хитбокс игрока (мировые координаты)
     * @param deltaTime  Время кадра (сек) — не используется, оставлен для совместимости
     * @return Суммарный урон за кадр (0.0 если попаданий нет)
     */
    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerBox, float deltaTime);

    // ---- Вспомогательные update-методы (публичные для тестирования) ----

    /// Обновить позицию и скорость самурая (движение, прыжок, гравитация)
    void updateMovement(float deltaTime, float playerX, float playerY);

    /// Обновить AI — выбор атаки по дистанции до игрока
    void updateAI(float deltaTime, float playerX, float playerY);

    /// Обновить стойку — отслеживать таймаут и автостан
    void updateStance(float deltaTime);

    /// Обновить бомбы: физика полёта + взрывы по таймеру
    void updateBombs(float deltaTime);

    /// Обновить частицы дыма: движение, угасание, удаление мёртвых
    void updateSmoke(float deltaTime);

    /// Нарисовать частицы дыма
    void renderSmoke(SDL_Renderer* renderer);

    /**
     * @brief Фоллбэк когда телепорт и бомбы на кулдауне.
     *        Выполняет серию из SWORD_COMBO_MAX ударов мечом,
     *        затем отскакивает на SWORD_BREAK_SPEED на BREAK_AWAY_DURATION сек.
     */
    void updateMeleeFallback(float deltaTime, float playerX, float playerY);
};