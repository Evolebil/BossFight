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
 * - A/D       — движение влево/вправо
 * - Space     — прыжок
 * - ЛКМ       — атака (чередует ATTACK_1 → ATTACK_2 → ATTACK_3)
 * - ПКМ       — щит (блокирует урон пока зажат)
 *
 * Анимации (отдельные файлы, кадр 84x84):
 * - IDLE.png     8 кадров — стоит
 * - RUN.png      9 кадров — бежит
 * - WALK.png     9 кадров — идёт медленно (TODO: не используется пока)
 * - JUMP.png     6 кадров — прыжок
 * - ATTACK_1.png 7 кадров — атака 1
 * - ATTACK_2.png 6 кадров — атака 2
 * - ATTACK_3.png 7 кадров — атака 3
 * - DEFEND.png   7 кадров — щит (pingPong)
 * - HURT.png     4 кадра  — получение урона
 * - DEATH.png    14 кадров — смерть
 */
class Player : public Character {
private:
    // --- Состояние боя ---
    bool isAttacking;       // сейчас проигрывается анимация атаки
    bool isDefending;       // ПКМ зажат
    bool isHurt;            // сейчас проигрывается анимация получения урона
    bool isDead;            // умер, проигрывается DEATH

    float attackCooldown;   // задержка между атаками (секунды)
    float attackTimer;      // сколько осталось до следующей атаки
    int   attackCombo;      // 0, 1, 2 — какая атака следующая

    // Хитбокс атаки — активен только во время удара
    bool  attackHitActive;  // урон уже нанесён в этой атаке?
    float attackHitTimer;   // через сколько секунд после старта анимации наносить урон
    float attackDamage;     // урон текущей атаки

    // Блок — один раз полностью, потом перезарядка
    bool  defendReady;      // блок готов к использованию
    float defendCooldown;   // таймер перезарядки блока

    // --- Флаги ввода ---
    bool wantsToJump;
    bool wantsToAttack;
    bool wantsToDefend;

    // --- Текстуры (отдельный файл на каждую анимацию) ---
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
    static constexpr float JUMP_VELOCITY  = -600.0f;
    static constexpr float MOVE_SPEED     = 200.0f;
    static constexpr float ATTACK_COOLDOWN = 0.5f;

    // Высота кадра одинакова для всех анимаций
    static constexpr int FRAME_H = 84;

    static constexpr int FRAME_W = 96;

    // Размер игрока на экране
    static constexpr float RENDER_W = 96.0f;
    static constexpr float RENDER_H = 84.0f;

    // Урон атак
    static constexpr float DAMAGE_ATTACK1 = 25.0f;
    static constexpr float DAMAGE_ATTACK2 = 35.0f;
    static constexpr float DAMAGE_ATTACK3 = 50.0f;

    static constexpr float DEFEND_DAMAGE_REDUCTION = 1.0f;  // блок снимает 100% урона
    static constexpr float DEFEND_COOLDOWN         = 2.0f;  // перезарядка блока (секунды)

public:
    explicit Player(float spawnX, float spawnY);
    ~Player() override = default;

    // --- Основной цикл ---
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;

    // --- Взаимодействие ---
    /**
     * @brief Получение урона. Учитывает блок и запускает анимацию HURT.
     * @param damage Входящий урон
     */
    void takeDamage(float damage) override;

    /**
     * @brief Возвращает хитбокс атаки (активен только во время удара).
     * Используется в game_scene для нанесения урона боссу.
     * @return SDL_Rect{0,0,0,0} если атаки нет
     */
    [[nodiscard]] SDL_Rect getAttackHitbox() const;

    /**
     * @brief Урон который наносит текущая атака.
     * Вернёт > 0 только один раз за атаку (флаг attackHitActive).
     * После вызова флаг сбрасывается.
     * @return Урон или 0 если атаки нет
     */
    [[nodiscard]] float consumeAttackDamage();

    // --- Геттеры ---
    [[nodiscard]] SDL_Rect getHitbox() const {
        // Хитбокс = спрайт (96x84 = RENDER_W x RENDER_H)
        return {
            (int)(x - width / 2),
            (int)(y - height / 2),
            (int)width,
            (int)height
        };
    }

    [[nodiscard]] bool getIsDefending() const { return isDefending; }
    [[nodiscard]] bool getIsDead()      const { return isDead; }

private:
    /**
     * @brief Загружает все текстуры и настраивает анимации.
     * Вызывается один раз в конструкторе.
     */
    void loadAnimations();

    /**
     * @brief Обрабатывает ввод с клавиатуры и мыши.
     * Вызывается в начале update().
     */
    void processInput();

    /**
     * @brief Запускает атаку (выбирает комбо 1/2/3).
     */
    void startAttack();
};
