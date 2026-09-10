/**
 * @file ground_minion.cpp
 * @brief Реализация наземного миньона
 * @author evol
 * @date 2026-09-03
 */
#include "ground_minion.h"
#include "../levels/ilevel.h"
#include "../utils/camera.h"

extern ILevel* g_currentLevel;

GroundMinion::GroundMinion(float spawnX, float spawnY, float doorTargetX, int phase)
    : Character(spawnX, spawnY, WIDTH, HEIGHT, BASE_HP)
{
    phaseIndex = std::clamp(phase - 1, 0, 3);
    doorX = doorTargetX;
    loadAnimations();
    appearAnim.reset();
}

void GroundMinion::loadAnimations() {
    texAppear = TextureManager::getTexture("assets/boss_3/summonAppear.png");
    texWalk   = TextureManager::getTexture("assets/boss_3/summonIdle.png");
    texDeath  = TextureManager::getTexture("assets/boss_3/summonDeath.png");

    for (int row = 0; row < APPEAR_FRAMES_Y; row++)
        for (int col = 0; col < APPEAR_FRAMES_X; col++)
            appearAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, APPEAR_FRAME_DUR);

    for (int row = 0; row < WALK_FRAMES_Y; row++)
        for (int col = 0; col < WALK_FRAMES_X; col++)
            walkAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, WALK_FRAME_DUR);

    for (int row = 0; row < DEATH_FRAMES_Y; row++)
        for (int col = 0; col < DEATH_FRAMES_X; col++)
            deathAnim.addFrame(col * FRAME_SIZE, row * FRAME_SIZE, FRAME_SIZE, FRAME_SIZE, DEATH_FRAME_DUR);
}

void GroundMinion::startDying() {
    if (dying) return; // уже начали — не перезапускаем анимацию повторно
    dying = true;
    velocityX = 0.0f;
    deathAnim.reset();
}

void GroundMinion::update(float deltaTime) {
    // --- Появление (summonAppear) — движение заморожено ---
    if (appearing) {
        appearAnim.update(deltaTime);
        applyGravityAndCollisions(deltaTime); // не выключаем гравитацию, чтобы не "висел"
        if (appearAnim.isFinished()) appearing = false;
        return;
    }

    // --- Умирает / исчезает в двери (summonDeath) ---
    if (dying) {
        deathAnim.update(deltaTime);
        applyGravityAndCollisions(deltaTime);
        if (deathAnim.isFinished()) deathAnimDone = true;
        return;
    }

    // --- Обычное поведение (как было) ---
    const GroundMinionPhaseParams& p = PHASE_PARAMS[phaseIndex];

    velocityX = -p.speed; // дверь всегда левее точки спавна
    facingRight = false;

    float groundY = 0.0f;
    if (g_currentLevel && g_currentLevel->getStairGroundY(x, groundY)) {
        y = groundY - height / 2.0f;
        velocityY = 0.0f;
        isGrounded = true;
        x += velocityX * deltaTime;
    } else {
        x += velocityX * deltaTime;
        applyCollisionsX();
        applyGravityAndCollisions(deltaTime);
    }

    if (attackTimer > 0.0f) attackTimer -= deltaTime;

    if (x <= doorX) doorReached = true;

    walkAnim.update(deltaTime);

    // Переход в "исчезновение" — по смерти ИЛИ по достижении двери
    if (isDead() || doorReached) startDying();
}

void GroundMinion::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    SDL_Texture* tex = texWalk;
    SDL_Rect src = walkAnim.getCurrentFrame();

    if (appearing) {
        tex = texAppear;
        src = appearAnim.getCurrentFrame();
    } else if (dying) {
        tex = texDeath;
        src = deathAnim.getCurrentFrame();
    }

    SDL_Rect dst = {
        (int)(x - width / 2) - cx,
        (int)(y - height / 2) - cy,
        (int)width, (int)height
    };

    if (tex) {
        SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, tex, &src, &dst, 0, nullptr, flip);
    } else {
        SDL_SetRenderDrawColor(renderer, 150, 30, 200, 255); // фиолетовый — заглушка, если спрайт не найден
        SDL_RenderFillRect(renderer, &dst);
    }

    // Полоска HP над головой — не показываем во время появления/исчезновения
    if (!appearing && !dying) {
        const int barX = (int)(x - HP_BAR_W / 2) - cx;
        const int barY = (int)(y - height / 2) - cy - HP_BAR_OFFSET;
        const float pct = getHP() / getMaxHP();

        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
        SDL_Rect bg = {barX, barY, HP_BAR_W, HP_BAR_H};
        SDL_RenderFillRect(renderer, &bg);

        SDL_SetRenderDrawColor(renderer, 220, 50, 50, 255);
        SDL_Rect bar = {barX, barY, (int)(HP_BAR_W * pct), HP_BAR_H};
        SDL_RenderFillRect(renderer, &bar);

        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderDrawRect(renderer, &bg);
    }
}

float GroundMinion::checkPlayerDamage(SDL_Rect playerBox) {
    if (appearing || dying) return 0.0f; // не атакует пока появляется/исчезает

    const GroundMinionPhaseParams& p = PHASE_PARAMS[phaseIndex];
    if (!p.canAttack || attackTimer > 0.0f || isDead()) return 0.0f;

    if (rectsOverlap(playerBox, getHitbox())) {
        attackTimer = p.attackCooldown;
        return p.attackDamage;
    }
    return 0.0f;
}

bool GroundMinion::consumeKillEvent() {
    // Засчитываем УБИЙСТВО в момент реальной смерти (не через дверь),
    // независимо от того, доиграна ли анимация исчезновения —
    // счётчик боссу не должен ждать анимацию.
    if (isDead() && !doorReached && !killEventConsumed) {
        killEventConsumed = true;
        return true;
    }
    return false;
}