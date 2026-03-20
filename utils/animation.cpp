/**
 * @file animation.cpp
 * @brief Реализация класса Animation
 * @author evol
 * @date 2026-02-20
 */

#include "animation.h"

// ============================================================
// UPDATE
// ============================================================

void Animation::update(float deltaTime) {
    if (frames.empty() || finished) return;

    currentTime += deltaTime;
    if (currentTime < frames[currentFrame].duration) return;
    currentTime = 0;

    if (pingPong) {
        if (goingForward) {
            // Идём вперёд — ждём вызова playReverse() снаружи
            if (currentFrame < (int)frames.size() - 1) {
                currentFrame++;
            }
        } else {
            // Идём назад
            currentFrame--;
            if (currentFrame <= 0) {
                currentFrame = 0;
                finished = true;
            }
        }
    } else {
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

// ============================================================
// ОСТАЛЬНЫЕ МЕТОДЫ
// ============================================================

void Animation::playReverse() {
    goingForward = false;
}

SDL_Rect Animation::getCurrentFrame() const {
    if (frames.empty()) return {0, 0, 0, 0};
    return frames[currentFrame].rect;
}

void Animation::reset() {
    currentFrame = 0;
    currentTime  = 0;
    finished     = false;
    goingForward = true;
}

void Animation::setFrame(int index) {
    if (index >= 0 && index < (int)frames.size())
        currentFrame = index;
}