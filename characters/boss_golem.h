/**
 * @file boss_golem.h
 * @brief Босс-голем — медленный, сильный, с блоком и лазером
 * @author evol
 * @date 2026-02-20
 */

#pragma once
#include "../config/common.h"
#include "../utils/animation.h"
#include "../utils/texture_manager.h"
#include "../config/config.h"
#include "character.h"

// --- Снаряд (рука/меч) для дальней атаки ---
struct Projectile {
    float x, y;             // позиция центра
    float velX, velY;       // скорость пикселей/сек
    float damage;
    bool  active;
    float trackingTime;     // сколько секунд ещё следить за игроком (0 = летит прямо)
    float targetX, targetY; // последняя известная позиция игрока
};

// --- Лазер — держится пока идёт анимация ---
struct LaserBeam {
    bool  active;
    float x, y;          // точка выхода (от босса)
    bool  facingRight;   // направление
    float damagePerSec;  // урон в секунду
};

/**
 * @class BossGolem
 * @brief Первый босс игры. Наследует физику и HP от Character.
 *
 * Три типа атак:
 * - Melee:  хитбокс перед боссом, срабатывает в середине анимации
 * - Laser:  луч от босса до края, урон пока игрок внутри
 * - Range:  снаряд летит по вектору к игроку (arm.png)
 */
class BossGolem : public Character {
private:
    // --- Состояния ---
    BossState currentState;
    BossState previousState;

    // --- Анимации ---
    std::map<BossState, Animation> animations;

    // --- Боевые параметры ---
    float defense;
    float moveSpeed;
    int   cellSize;

    // --- Таймеры ---
    float attackCooldown;
    float attackTimer;
    float blockCooldown;
    float blockTimer;
    float blockDuration;
    float blockActiveTimer;
    float stateTimer;
    float lastStateChangeTime;

    // --- Атаки ---
    bool        meleeHitDealt;   // чтоб мили не дамажил каждый кадр
    float       meleeHitTime;    // когда в анимации наносить удар (0.0-1.0)
    std::vector<Projectile> projectiles;
    LaserBeam   laser;
    bool        attackSpawned;   // снаряд/лазер уже создан для текущей атаки

    // --- Очередь снарядов (для тройного залпа) ---
    int   projectileQueue;      // сколько снарядов ещё нужно выпустить
    float projectileQueueTimer; // таймер между снарядами в очереди
    float lastPlayerX, lastPlayerY; // последняя позиция игрока (для наведения)

    // --- Множитель сложности ---
    float attackSpeedMult;      // влияет на кулдаун и количество снарядов

    // --- Текстуры снарядов ---
    SDL_Texture* armTexture;
    SDL_Texture* laserTexture;

    // --- Константы урона ---
    static constexpr float DAMAGE_MELEE      = 25.0f;
    static constexpr float DAMAGE_RANGE      = 15.0f;
    static constexpr float DAMAGE_LASER_SEC  = 30.0f; // урон в секунду

    // --- Константы дистанций (в клетках) ---
    static constexpr float RANGE_MELEE  = 2.0f;
    static constexpr float RANGE_RANGED = 6.0f;
    static constexpr float RANGE_LASER  = 12.0f;

    // --- Скорость снаряда ---
    static constexpr float PROJECTILE_SPEED = 400.0f;

    // --- Кулдаун смены состояний ---
    static constexpr float STATE_CHANGE_COOLDOWN = 0.5f;

    // --- Масштаб спрайта ---
    static constexpr float SPRITE_SCALE = 2.5f;

    // --- Генератор случайных чисел ---
    std::mt19937 rng;

public:
    BossGolem(float spawnX, float spawnY, float attackSpeedMult = 1.0f);
    ~BossGolem() override = default;

    void update(float deltaTime, float playerX, float playerY);
    void update(float deltaTime) override { (void)deltaTime; }
    void render(SDL_Renderer* renderer) override;
    void takeDamage(float damage) override;

    // --- Геттеры ---
    [[nodiscard]] float     getDefense()   const { return defense; }
    [[nodiscard]] BossState getState()     const { return currentState; }

    [[nodiscard]] SDL_Rect getHitbox() const {
        return { (int)(x - width/2), (int)(y - height/2), (int)width, (int)height };
    }

    // Проверить урон по игроку — вызывается из GameScene
    // Возвращает урон если игрок попал под атаку, иначе 0
    [[nodiscard]] float checkPlayerDamage(SDL_Rect playerHitbox, float deltaTime);

private:
    void loadAnimations();
    void loadAttackTextures();
    void updateAI(float deltaTime, float playerX, float playerY);
    void setState(BossState newState);
    [[nodiscard]] bool canChangeState() const;

    // Спавн атак
    void spawnProjectile(float playerX, float playerY);
    void spawnLaser();

    // Рендер атак
    void renderProjectiles(SDL_Renderer* renderer);
    void renderLaser(SDL_Renderer* renderer);
    void renderMeleeHitbox(SDL_Renderer* renderer); // только для отладки
};
