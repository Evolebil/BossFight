/**
 * @file boss_samurai.cpp
 * @brief Реализация босса-самурая
 * @author evol
 * @date 2026-05-20
 */
#include "boss_samurai.h"

BossSamurai::BossSamurai(float spawnX, float spawnY, float attackSpeedMult)
    : Boss(spawnX, spawnY, HITBOX_W, HITBOX_H, BASE_HP, attackSpeedMult)
{
    loadAnimations();
}

void BossSamurai::update(float deltaTime, float playerX, float playerY) {
    lastPlayerX = playerX;
    lastPlayerY = playerY;
}

void BossSamurai::render(SDL_Renderer* renderer) {
    const int cx = g_camera ? (int)g_camera->getOffsetX() : 0;
    const int cy = g_camera ? (int)g_camera->getOffsetY() : 0;

    auto texIt  = textures.find(currentState);
    auto animIt = animations.find(currentState);

    if (texIt == textures.end() || !texIt->second || animIt == animations.end()) {
        // Заглушка если текстура не загружена
        SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
        SDL_Rect rect = {
            (int)(x - width/2) - cx,
            (int)(y - height/2) - cy,
            (int)width, (int)height
        };
        SDL_RenderFillRect(renderer, &rect);
        return;
    }

    SDL_Rect src = animIt->second.getCurrentFrame();
    int dstW = (int)(FRAME_W * SPRITE_SCALE);
    int dstH = (int)(FRAME_H * SPRITE_SCALE);

    SDL_Rect dst = {
        (int)(x - dstW / 2) - cx,
        (int)(y - dstH / 2) - cy,
        dstW, dstH
    };

    SDL_RendererFlip flip = facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer, texIt->second, &src, &dst, 0, nullptr, flip);
}

void BossSamurai::setState(SamuraiState newState) {
    if (currentState == newState) return;
    if (!canChangeState()) return;

    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
}

void BossSamurai::forceState(SamuraiState newState) {
    previousState       = currentState;
    currentState        = newState;
    lastStateChangeTime = stateTimer;
}

bool BossSamurai::canChangeState() const {
    return (stateTimer - lastStateChangeTime) >= STATE_CHANGE_COOLDOWN;
}

void BossSamurai::loadAnimations() {
    // Каждая анимация — отдельный PNG файл
    struct AnimInfo {
        SamuraiState state;
        const char*  path;
        int          frames;
        float        speed;
        bool         loop;
    };

    static const AnimInfo ANIMS[] = {
                                    { SamuraiState::IDLE,         "assets/Samurai/Idle.png",       FRAMES_IDLE,         ANIM_SPD_IDLE,         true  },
                                    { SamuraiState::WALK,         "assets/Samurai/Run.png",        FRAMES_WALK,         ANIM_SPD_WALK,         true  },
                                    { SamuraiState::JUMP,         "assets/Samurai/Jump.png",       FRAMES_JUMP,         ANIM_SPD_JUMP,         false },
                                    { SamuraiState::TELEPORT,     "assets/Samurai/Run.png",        FRAMES_WALK,         ANIM_SPD_WALK,         true  },
                                    { SamuraiState::SWORD_ATTACK, "assets/Samurai/Attack_1.png",   FRAMES_SWORD_ATTACK, ANIM_SPD_SWORD_ATTACK, false },
                                    { SamuraiState::THROW_BOMBS,  "assets/Samurai/Attack_2.png",   FRAMES_THROW_BOMBS,  ANIM_SPD_THROW_BOMBS,  false },
                                    { SamuraiState::POWER_ATTACK, "assets/Samurai/Attack_3.png",   FRAMES_POWER_ATTACK, ANIM_SPD_POWER_ATTACK, false },
                                    { SamuraiState::STANCE,       "assets/Samurai/Protection.png", FRAMES_STANCE,       ANIM_SPD_STANCE,       true  },
                                    { SamuraiState::STUNNED,      "assets/Samurai/Hurt.png",       FRAMES_STUNNED,      ANIM_SPD_STUNNED,      false },
                                    { SamuraiState::DEATH,        "assets/Samurai/Dead.png",       FRAMES_DEATH,        ANIM_SPD_DEATH,        false },
                                    };

    for (const auto& info : ANIMS) {
        SDL_Texture* tex = TextureManager::getTexture(info.path);
        Animation anim(info.loop);
        for (int i = 0; i < info.frames; i++)
            anim.addFrame(i * FRAME_W, 0, FRAME_W, FRAME_H, info.speed);
        animations[info.state] = anim;

        // Текстура хранится отдельно для каждого состояния
        textures[info.state] = tex;
    }
}