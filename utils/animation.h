/**
 * @file animation.h
 * @brief Покадровая анимация спрайтов
 * @author evol
 * @date 2026-02-20
 */

#pragma once
#include "../config/common.h"

// ============================================================
// КАДР АНИМАЦИИ
// ============================================================

struct AnimationFrame {
    SDL_Rect rect;
    float    duration;

    AnimationFrame(int x, int y, int w, int h, float dur = 0.1f)
        : rect{x, y, w, h}, duration(dur) {}
};

// ============================================================
// АНИМАЦИЯ
// ============================================================

/**
 * @class Animation
 * @brief Покадровая анимация с тремя режимами:
 *   - loop=true,  pingPong=false → зацикленная (idle, walk)
 *   - loop=false, pingPong=false → одноразовая (hurt, death, attack)
 *   - loop=true,  pingPong=true  → ping-pong (блок)
 *
 * Для блока: вызови playReverse() когда нужно откатиться назад.
 * finished=true после отката = анимация блока завершена.
 */
class Animation {
private:
    std::vector<AnimationFrame> frames;
    int   currentFrame;
    float currentTime;
    bool  looping;
    bool  pingPong;
    bool  goingForward;
    bool  finished;

public:
    Animation(bool loop = true, bool pingpong = false)
        : currentFrame(0), currentTime(0),
        looping(loop), pingPong(pingpong),
        goingForward(true), finished(false) {}

    // Добавить кадр в анимацию
    void addFrame(int x, int y, int w, int h, float duration = 0.1f) {
        frames.push_back(AnimationFrame(x, y, w, h, duration));
    }

    // Обновление — вызывать каждый кадр
    void update(float deltaTime);

    // Запустить обратное воспроизведение (только для pingPong)
    void playReverse();

    // Получить текущий кадр для SDL_RenderCopyEx
    [[nodiscard]] SDL_Rect getCurrentFrame() const;

    // Сброс в начало
    void reset();

    // Принудительно установить кадр (для рывка)
    void setFrame(int index);


    // Геттеры
    [[nodiscard]] bool isFinished()         const { return finished; }
    [[nodiscard]] bool isGoingForward()     const { return goingForward; }
    [[nodiscard]] bool isAtLastFrame()      const {
        return !frames.empty() && currentFrame == (int)frames.size() - 1;
    }
    [[nodiscard]] int  getCurrentFrameIndex() const { return currentFrame; }
    [[nodiscard]] int  getFrameCount()        const { return (int)frames.size(); }
};