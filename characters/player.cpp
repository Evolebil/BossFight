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
    isAttacking(false),
    isCastingMagic(false),
    isDefending(false),
    isHurt(false),
    isDead(false),
    attackCooldown(ATTACK_COOLDOWN),
    attackTimer(0.0f),
    attackCombo(0),
    attackHitActive(false),
    attackHitTimer(0.0f),
    attackDamage(0.0f),
    defendCooldown(0.0f),
    mana(MANA_MAX),
    maxMana(MANA_MAX),
    wantsToCastMagic(false),
    mouseX(0),
    mouseY(0),
    wantsToJump(false),
    wantsToAttack(false),
    wantsToDefend(false),
    isDashing(false),
    dashTimer(0.0f),
    dashCooldown(0.0f),
    wantsToDash(false),
    texIdle(nullptr), texRun(nullptr), texWalk(nullptr),
    texJump(nullptr), texAttack1(nullptr), texAttack2(nullptr),
    texAttack3(nullptr), texDefend(nullptr),
    texHurt(nullptr), texDeath(nullptr), texMagic(nullptr),
    idleAnim(true),
    runAnim(true),
    jumpAnim(false),
    attack1Anim(false),
    attack2Anim(false),
    attack3Anim(false),
    magicAnim(false),
    defendAnim(true, true),
    hurtAnim(false),
    deathAnim(false)
{
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
    texMagic   = TextureManager::getTexture("assets/magic/01.png");

    for (int i = 0; i < 7; i++)
        idleAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.15f);

    for (int i = 0; i < 8; i++)
        runAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.09f);

    for (int i = 0; i < 5; i++)
        jumpAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.12f);

    for (int i = 0; i < 6; i++)
        attack1Anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.08f);

    for (int i = 0; i < 5; i++)
        attack2Anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.09f);

    for (int i = 0; i < 6; i++)
        attack3Anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.10f);

    // Магическая атака — та же ATTACK_3
    for (int i = 0; i < 6; i++)
        magicAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.10f);

    for (int i = 0; i < 6; i++)
        defendAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.07f);

    for (int i = 0; i < 4; i++)
        hurtAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.10f);

    for (int i = 0; i < 14; i++)
        deathAnim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, 0.12f);
}

// ============================================================
//  ВВОД
// ============================================================

void Player::processInput() {
    if (isDead) return;

    const Config::Controls& controls = Config::getControls();

    wantsToJump      = false;
    wantsToAttack    = false;
    wantsToCastMagic = false;
    velocityX        = 0;

    const bool left  = InputManager::isKeyDown(controls.left);
    const bool right = InputManager::isKeyDown(controls.right);

    if (left  && !right) { velocityX = -MOVE_SPEED; facingRight = false; }
    if (right && !left)  { velocityX =  MOVE_SPEED; facingRight = true;  }

    if (InputManager::isKeyPressed(controls.jump)) wantsToJump = true;

    // ЛКМ — ближняя атака
    if (!isAttacking && !isCastingMagic && !isHurt && !isDefending && attackTimer <= 0.0f) {
        if (InputManager::isMousePressed(controls.attackMouseButton))
            wantsToAttack = true;
    }

    // ПКМ — магическая атака (из настроек)
    if (!isAttacking && !isCastingMagic && !isHurt && !isDefending) {
        if (InputManager::isMousePressed(controls.magicMouseButton) &&
            mana >= MANA_COST_MAGIC) {
            wantsToCastMagic = true;
            InputManager::getMousePos(mouseX, mouseY);
        }
    }

    // Щит — из настроек (controls.shield)
    wantsToDefend = InputManager::isKeyDown(controls.shield) &&
                    defendCooldown <= 0.0f &&
                    !isAttacking && !isCastingMagic && !isHurt;

    // Рывок — из настроек (controls.dash)
    if (InputManager::isKeyPressed(controls.dash) &&
        dashCooldown <= 0.0f && !isDashing &&
        !isAttacking && !isCastingMagic && !isHurt) {
        wantsToDash = true;
    }
}

// ============================================================
//  ЗАПУСК БЛИЖНЕЙ АТАКИ
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
//  ЗАПУСК МАГИЧЕСКОЙ АТАКИ
// ============================================================

void Player::castMagic() {
    isCastingMagic = true;
    mana -= MANA_COST_MAGIC;
    if (mana < 0.0f) mana = 0.0f;

    magicAnim.reset();

    float dx  = (float)mouseX - x;
    float dy  = (float)mouseY - y;
    float len = std::sqrt(dx*dx + dy*dy);
    if (len < 1.0f) len = 1.0f;

    const float speed = MOVE_SPEED * MAGIC_SPEED_MULT;

    MagicProjectile proj;
    proj.x      = x + (facingRight ? width / 2.0f : -width / 2.0f);
    proj.y      = y;
    proj.velX   = (dx / len) * speed;
    proj.velY   = (dy / len) * speed;
    proj.active = true;

    magicProjectiles.push_back(proj);
}

// ============================================================
//  UPDATE
// ============================================================

void Player::update(float deltaTime) {
    processInput();

    if (isDead) {
        deathAnim.update(deltaTime);
        return;
    }

    // Прыжок — при щите запрещён
    if (wantsToJump && isGrounded && !isDefending) {
        velocityY  = JUMP_VELOCITY;
        isGrounded = false;
        jumpAnim.reset();
    }

    if (wantsToAttack)    startAttack();
    if (wantsToCastMagic) castMagic();

    // Рывок
    if (dashCooldown > 0.0f) dashCooldown -= deltaTime;

    if (wantsToDash) {
        isDashing    = true;
        dashTimer    = DASH_DURATION;
        dashCooldown = DASH_COOLDOWN_MAX;
        if (isDefending) {
            isDefending = false;
            defendAnim.reset();
        }
        runAnim.reset();
        runAnim.setFrame(2);
    }
    wantsToDash = false;

    if (isDashing) {
        dashTimer -= deltaTime;
        velocityX = facingRight ? DASH_SPEED : -DASH_SPEED;
        if (dashTimer <= 0.0f) {
            isDashing = false;
            velocityX = 0.0f;
        }
    }

    // Кулдаун ближней атаки
    if (attackTimer > 0.0f) attackTimer -= deltaTime;

    // Таймер хита
    if (isAttacking && attackHitTimer > -999.0f) {
        attackHitTimer -= deltaTime;
        if (attackHitTimer <= 0.0f && !attackHitActive) {
            attackHitActive = true;
            attackHitTimer  = -999.0f;
        }
    }

    // Щит
    if (defendCooldown > 0.0f) defendCooldown -= deltaTime;

    if (!isAttacking && !isCastingMagic && !isHurt) {
        if (wantsToDefend) {
            isDefending = true;
            if (defendAnim.isGoingForward()) defendAnim.update(deltaTime);
        } else if (isDefending) {
            defendAnim.playReverse();
            defendAnim.update(deltaTime);
            if (defendAnim.isFinished()) {
                isDefending    = false;
                defendCooldown = DEFEND_COOLDOWN_MAX;
                defendAnim.reset();
            }
        }
    }

    // Движение
    x += velocityX * deltaTime;
    applyCollisionsX();
    applyGravityAndCollisions(deltaTime);

    // Мана восстанавливается
    mana += MANA_REGEN * deltaTime;
    if (mana > maxMana) mana = maxMana;

    // Магические снаряды
    for (auto& proj : magicProjectiles) {
        if (!proj.active) continue;
        proj.x += proj.velX * deltaTime;
        proj.y += proj.velY * deltaTime;

        if (proj.x < -50 || proj.x > Config::getWindowWidth()  + 50 ||
            proj.y < -50 || proj.y > Config::getWindowHeight() + 50)
            proj.active = false;
    }

    magicProjectiles.erase(
        std::remove_if(magicProjectiles.begin(), magicProjectiles.end(),
                       [](const MagicProjectile& p){ return !p.active; }),
        magicProjectiles.end());

    // Анимации
    if (isDashing) {
        runAnim.update(deltaTime);
    } else if (isHurt) {
        hurtAnim.update(deltaTime);
        if (hurtAnim.isFinished()) isHurt = false;
    } else if (isCastingMagic) {
        magicAnim.update(deltaTime);
        if (magicAnim.isFinished()) isCastingMagic = false;
    } else if (isAttacking) {
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
    } else if (isDefending) {
        // Обновляется в блоке щита выше
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

    if (isDefending) damage *= (1.0f - DEFEND_DAMAGE_REDUCTION);

    hp -= damage;
    if (hp < 0.0f) hp = 0.0f;

    if (hp <= 0.0f) {
        isDead         = true;
        isAttacking    = false;
        isCastingMagic = false;
        isDefending    = false;
        isHurt         = false;
        deathAnim.reset();
    } else if (damage > 0.0f) {
        if (isDefending) {
            isDefending    = false;
            defendCooldown = DEFEND_COOLDOWN_MAX;
            defendAnim.reset();
        }
        isHurt         = true;
        isAttacking    = false;
        isCastingMagic = false;
        hurtAnim.reset();
    }
}

// ============================================================
//  ХИТБОКС БЛИЖНЕЙ АТАКИ
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
    // Магические снаряды
    for (const auto& proj : magicProjectiles) {
        if (!proj.active) continue;
        constexpr int PROJ_RENDER = 32;
        SDL_Rect dst = {
            (int)(proj.x - PROJ_RENDER / 2),
            (int)(proj.y - PROJ_RENDER / 2),
            PROJ_RENDER, PROJ_RENDER
        };
        if (texMagic) {
            SDL_RenderCopy(renderer, texMagic, nullptr, &dst);
        } else {
            SDL_SetRenderDrawColor(renderer, 80, 160, 255, 255);
            SDL_RenderFillRect(renderer, &dst);
        }
    }

    // Спрайт игрока
    SDL_Texture* tex = nullptr;
    SDL_Rect     src = {0, 0, 0, 0};

    if (isDead) {
        tex = texDeath;   src = deathAnim.getCurrentFrame();
    } else if (isHurt) {
        tex = texHurt;    src = hurtAnim.getCurrentFrame();
    } else if (isCastingMagic) {
        tex = texAttack3; src = magicAnim.getCurrentFrame();
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
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
        SDL_RenderFillRect(renderer, &dst);
    }

    // Кулдауны над игроком
    constexpr int BAR_W   = 40;
    constexpr int BAR_H   = 5;
    constexpr int BAR_GAP = 3;
    const int barX = (int)(x - BAR_W / 2);
    const int barY = (int)(y - RENDER_H / 2) - 18;

    // Рывок (красный)
    if (dashCooldown > 0.0f) {
        float pct = dashCooldown / DASH_COOLDOWN_MAX;
        SDL_SetRenderDrawColor(renderer, 60, 20, 20, 200);
        SDL_Rect bg = {barX, barY, BAR_W, BAR_H};
        SDL_RenderFillRect(renderer, &bg);
        SDL_SetRenderDrawColor(renderer, 220, 50, 50, 255);
        SDL_Rect fill = {barX, barY, (int)(BAR_W * pct), BAR_H};
        SDL_RenderFillRect(renderer, &fill);
    }

    // Щит (жёлтый)
    if (defendCooldown > 0.0f) {
        float pct = defendCooldown / DEFEND_COOLDOWN_MAX;
        SDL_SetRenderDrawColor(renderer, 60, 60, 20, 200);
        SDL_Rect bg = {barX, barY + BAR_H + BAR_GAP, BAR_W, BAR_H};
        SDL_RenderFillRect(renderer, &bg);
        SDL_SetRenderDrawColor(renderer, 220, 200, 50, 255);
        SDL_Rect fill = {barX, barY + BAR_H + BAR_GAP, (int)(BAR_W * pct), BAR_H};
        SDL_RenderFillRect(renderer, &fill);
    }
}