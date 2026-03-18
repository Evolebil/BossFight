/**
 * @file player.cpp
 * @brief Реализация класса Player
 * @author evol
 * @date 2026-02-24
 */
#include "player.h"
#include "../utils/texture_manager.h"
#include "../utils/input_manager.h"

// ============================================================
//  КОНСТРУКТОР
// ============================================================

Player::Player(float spawnX, float spawnY)
    : Character(spawnX, spawnY, 35.0f, 40.0f, 100.0f),
    // --- бой ---
    isAttacking(false),
    isDefending(false),
    isHurt(false),
    isDead(false),
    attackCooldown(ATTACK_COOLDOWN),
    attackTimer(0.0f),
    attackCombo(0),
    attackHitActive(false),
    attackHitTimer(0.0f),
    attackDamage(0.0f),
    // --- блок (инициализированы! были UB) ---
    defendReady(true),
    defendCooldown(0.0f),
    // --- ввод ---
    wantsToJump(false),
    wantsToAttack(false),
    wantsToDefend(false),
    // --- текстуры ---
    texIdle(nullptr), texRun(nullptr), texWalk(nullptr),
    texJump(nullptr), texAttack1(nullptr), texAttack2(nullptr),
    texAttack3(nullptr), texDefend(nullptr),
    texHurt(nullptr), texDeath(nullptr),
    // --- анимации ---
    idleAnim(true),
    runAnim(true),
    jumpAnim(false),
    attack1Anim(false),
    attack2Anim(false),
    attack3Anim(false),
    defendAnim(true, true),
    hurtAnim(false),
    deathAnim(false) {
    loadAnimations();
}

// ============================================================
//  ЗАГРУЗКА АНИМАЦИЙ
// ============================================================

void Player::loadAnimations() {
    texIdle    = TextureManager::getTexture("assets/player/IDLE.png");
    texRun     = TextureManager::getTexture("assets/player/RUN.png");
    texWalk    = TextureManager::getTexture("assets/player/WALK.png");
    texJump    = TextureManager::getTexture("assets/player/JUMP.png");
    texAttack1 = TextureManager::getTexture("assets/player/ATTACK_1.png");
    texAttack2 = TextureManager::getTexture("assets/player/ATTACK_2.png");
    texAttack3 = TextureManager::getTexture("assets/player/ATTACK_3.png");
    texDefend  = TextureManager::getTexture("assets/player/DEFEND.png");
    texHurt    = TextureManager::getTexture("assets/player/HURT.png");
    texDeath   = TextureManager::getTexture("assets/player/DEATH.png");

    // IDLE: 7 кадров
    for (int i = 0; i < 7; i++)
        idleAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.15f);

    // RUN: 8 кадров
    for (int i = 0; i < 8; i++)
        runAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.09f);

    // JUMP: 5 кадров
    for (int i = 0; i < 5; i++)
        jumpAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.12f);

    // ATTACK_1: 6 кадров
    for (int i = 0; i < 6; i++)
        attack1Anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.08f);

    // ATTACK_2: 5 кадров
    for (int i = 0; i < 5; i++)
        attack2Anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.09f);

    // ATTACK_3: 6 кадров
    for (int i = 0; i < 6; i++)
        attack3Anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.10f);

    // DEFEND: 6 кадров, pingPong
    for (int i = 0; i < 6; i++)
        defendAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.07f);

    // HURT: 4 кадра
    for (int i = 0; i < 4; i++)
        hurtAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.10f);

    // DEATH: 14 кадров
    for (int i = 0; i < 14; i++)
        deathAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.12f);
}

// ============================================================
//  ВВОД
// ============================================================

void Player::processInput() {
    if (isDead) return;

    const Config::Controls& controls = Config::getControls();

    wantsToJump   = false;
    wantsToAttack = false;
    velocityX     = 0;

    const bool left  = InputManager::isKeyDown(controls.left);
    const bool right = InputManager::isKeyDown(controls.right);

    if (left && !right) { velocityX = -MOVE_SPEED; facingRight = false; }
    if (right && !left) { velocityX =  MOVE_SPEED; facingRight = true;  }

    if (InputManager::isKeyPressed(controls.jump)) wantsToJump = true;

    if (!isAttacking && !isHurt && attackTimer <= 0.0f) {
        if (InputManager::isMousePressed(1)) wantsToAttack = true;
    }

    wantsToDefend = InputManager::isMouseDown(3);
}

// ============================================================
//  ЗАПУСК АТАКИ
// ============================================================

void Player::startAttack() {
    isAttacking     = true;
    attackTimer     = attackCooldown;
    attackHitActive = false;

    if (attackCombo == 0) {
        attack1Anim.reset();
        attackDamage   = DAMAGE_ATTACK1;
        attackHitTimer = 0.25f;
    } else if (attackCombo == 1) {
        attack2Anim.reset();
        attackDamage   = DAMAGE_ATTACK2;
        attackHitTimer = 0.25f;
    } else {
        attack3Anim.reset();
        attackDamage   = DAMAGE_ATTACK3;
        attackHitTimer = 0.30f;
    }

    attackCombo = (attackCombo + 1) % 3;
}

// ============================================================
//  UPDATE
// ============================================================

void Player::update(float deltaTime) {
    // ШАГ 1: Ввод
    processInput();

    // ШАГ 2: Если умер — только анимация смерти
    if (isDead) {
        deathAnim.update(deltaTime);
        return;
    }

    // ШАГ 3: Прыжок
    if (wantsToJump && isGrounded) {
        velocityY  = JUMP_VELOCITY;
        isGrounded = false;
        jumpAnim.reset();
    }

    // ШАГ 4: Атака
    if (wantsToAttack) startAttack();

    // ШАГ 5: Кулдаун атаки
    if (attackTimer > 0.0f) attackTimer -= deltaTime;

    // ШАГ 6: Таймер нанесения урона
    // После срабатывания уходит в -999 чтобы не повторяться
    if (isAttacking && attackHitTimer > -999.0f) {
        attackHitTimer -= deltaTime;
        if (attackHitTimer <= 0.0f && !attackHitActive) {
            attackHitActive = true;
            attackHitTimer  = -999.0f;
        }
    }

    // ШАГ 7: Щит
    if (!isAttacking && !isHurt) {
        if (wantsToDefend) {
            isDefending = true;
            if (defendAnim.isGoingForward()) defendAnim.update(deltaTime);
        } else if (isDefending) {
            // ПКМ отпустили — откатываем анимацию назад
            defendAnim.playReverse();
            defendAnim.update(deltaTime);
            if (defendAnim.isFinished()) {
                isDefending = false;
                defendAnim.reset();
            }
        }
    }

    // ШАГ 8: Движение по X + коллизии
    if (!isDefending) {
        x += velocityX * deltaTime;
        applyCollisionsX();
    }

    // ШАГ 9: Гравитация + коллизии по Y
    applyGravityAndCollisions(deltaTime);

    // ШАГ 10: Анимации
    if (isHurt) {
        hurtAnim.update(deltaTime);
        if (hurtAnim.isFinished()) isHurt = false;
    } else if (isAttacking) {
        // Текущая атака = предыдущий шаг комбо
        const int combo = (attackCombo + 2) % 3;
        if (combo == 0) {
            attack1Anim.update(deltaTime);
            if (attack1Anim.isFinished()) isAttacking = false;
        } else if (combo == 1) {
            attack2Anim.update(deltaTime);
            if (attack2Anim.isFinished()) isAttacking = false;
        } else {
            attack3Anim.update(deltaTime);
            if (attack3Anim.isFinished()) isAttacking = false;
        }
    } else if (!isGrounded) {
        jumpAnim.update(deltaTime);
    } else if (velocityX != 0) {
        runAnim.update(deltaTime);
    } else {
        idleAnim.update(deltaTime);
    }
}

// ============================================================
//  ПОЛУЧЕНИЕ УРОНА
// ============================================================

void Player::takeDamage(float damage) {
    if (isDead) return;

    // Щит снижает урон на 75%
    if (isDefending) damage *= (1.0f - DEFEND_DAMAGE_REDUCTION);

    hp -= damage;
    if (hp < 0.0f) hp = 0.0f;

    if (hp <= 0.0f) {
        isDead      = true;
        isAttacking = false;
        isDefending = false;
        isHurt      = false;
        deathAnim.reset();
    } else if (damage > 0.0f) {
        isHurt      = true;
        isAttacking = false;
        hurtAnim.reset();
    }
}

// ============================================================
//  ХИТБОКС АТАКИ
// ============================================================

SDL_Rect Player::getAttackHitbox() const {
    if (!isAttacking) return {0, 0, 0, 0};

    constexpr int HIT_W = 60;
    constexpr int HIT_H = 50;
    int hx = facingRight
                 ? (int)(x + width / 2)
                 : (int)(x - width / 2 - HIT_W);
    int hy = (int)(y - height / 4);
    return {hx, hy, HIT_W, HIT_H};
}

float Player::consumeAttackDamage() {
    if (!attackHitActive) return 0.0f;
    attackHitActive = false;
    return attackDamage;
}

// ============================================================
//  ОТРИСОВКА
// ============================================================

void Player::render(SDL_Renderer* renderer) {
    SDL_Texture* tex = nullptr;
    SDL_Rect     src = {0, 0, 0, 0};

    if (isDead) {
        tex = texDeath; src = deathAnim.getCurrentFrame();
    } else if (isHurt) {
        tex = texHurt;  src = hurtAnim.getCurrentFrame();
    } else if (isAttacking) {
        const int combo = (attackCombo + 2) % 3;
        if      (combo == 0) { tex = texAttack1; src = attack1Anim.getCurrentFrame(); }
        else if (combo == 1) { tex = texAttack2; src = attack2Anim.getCurrentFrame(); }
        else                 { tex = texAttack3; src = attack3Anim.getCurrentFrame(); }
    } else if (isDefending) {
        tex = texDefend; src = defendAnim.getCurrentFrame();
    } else if (!isGrounded) {
        tex = texJump;   src = jumpAnim.getCurrentFrame();
    } else if (velocityX != 0) {
        tex = texRun;    src = runAnim.getCurrentFrame();
    } else {
        tex = texIdle;   src = idleAnim.getCurrentFrame();
    }

    SDL_Rect dst = {
        (int)(x - RENDER_W / 2),
        (int)(y - RENDER_H / 2),
        (int)RENDER_W,
        (int)RENDER_H
    };
    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    if (tex) {
        SDL_RenderCopyEx(renderer, tex, &src, &dst, 0, nullptr, flip);
    } else {
        // Заглушка если текстура не загружена
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
        SDL_RenderFillRect(renderer, &dst);
    }
}