#pragma once
#include "../config/common.h"

struct AnimationFrame {
    SDL_Rect rect;
    float duration;
    AnimationFrame(int x, int y, int w, int h, float dur = 0.1f)
        : rect{x, y, w, h}, duration(dur) {}
};

/**
 * @class Animation
 * @brief Покадровая анимация с поддержкой трёх режимов:
 *   - loop=true,  pingPong=false → зацикленная вперёд (idle, walk)
 *   - loop=false, pingPong=false → одноразовая (hurt, death, attack)
 *   - loop=true,  pingPong=true  → зацикленный ping-pong туда-обратно
 *
 * Для блока используй pingPong=true + вызови playReverse() когда нужно откатиться.
 * finished=true после отката означает что анимация блока завершена.
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

    void addFrame(int x, int y, int w, int h, float duration = 0.1f) {
        frames.push_back(AnimationFrame(x, y, w, h, duration));
    }

    void update(float deltaTime) {
        if (frames.empty() || finished) return;

        currentTime += deltaTime;
        if (currentTime < frames[currentFrame].duration) return;
        currentTime = 0;

        if (pingPong) {
            if (goingForward) {
                // Идём вперёд — если дошли до конца, просто стоим
                // playReverse() запустит откат снаружи
                if (currentFrame < (int)frames.size() - 1) {
                    currentFrame++;
                }
                // Иначе ждём вызова playReverse()
            } else {
                // Идём назад
                currentFrame--;
                if (currentFrame <= 0) {
                    currentFrame = 0;
                    finished = true; // откат завершён
                }
            }
        } else {
            // Обычный режим
            currentFrame++;
            if (currentFrame >= (int)frames.size()) {
                if (looping) {
                    currentFrame = 0;
                } else {
                    currentFrame = (int)frames.size() - 1;
                    finished = true;
                }
            }
        }
    }

    // Запустить обратное воспроизведение (только для pingPong анимаций)
    void playReverse() {
        goingForward = false;
    }

    SDL_Rect getCurrentFrame() const {
        if (frames.empty()) return {0, 0, 0, 0};
        return frames[currentFrame].rect;
    }

    void reset() {
        currentFrame = 0;
        currentTime  = 0;
        finished     = false;
        goingForward = true;
    }
    // Принудительно установить кадр (для рывка)
    void setFrame(int index) {
        if (index >= 0 && index < (int)frames.size())
            currentFrame = index;
    }

    [[nodiscard]] bool isFinished()    const { return finished; }
    [[nodiscard]] bool isGoingForward() const { return goingForward; }
    [[nodiscard]] bool isAtLastFrame() const {
        return !frames.empty() && currentFrame == (int)frames.size() - 1;
    }
    [[nodiscard]] int getCurrentFrameIndex() const { return currentFrame; }
    [[nodiscard]] int getFrameCount()  const { return (int)frames.size(); }
};
