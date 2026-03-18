/**
 * @file ui.h
 * @brief UI-компоненты: кнопки, слайдеры, функции отрисовки текста
 * @author evol
 * @date 2026-02-20
 */
#pragma once
#include "../config/common.h"

// Forward declaration — НЕ включаем sound_manager.h здесь,
// чтобы избежать circular include (sound_manager.h → common.h → ...)
// Полный include делается только в ui.cpp
class SoundManager;

// ============================================================
// КНОПКА
// ============================================================

struct Button {
    SDL_Rect    rect;
    std::string text;
    bool        isHovered  = false;
    bool        wasHovered = false;

    Button(int x, int y, int w, int h, const std::string& t);

    [[nodiscard]] bool contains(int mx, int my) const;
    void centerX(int windowWidth);
};

// ============================================================
// СЛАЙДЕР
// ============================================================

struct Slider {
    std::string label;
    float*      value;
    SDL_Rect    track;
    SDL_Rect    handle;
    bool        isDragging  = false;
    bool        wasDragging = false;
    int         id;

    Slider(int x, int y, int w, const std::string& lbl, float* val, int sliderID);

    void updateHandle();
    [[nodiscard]] bool handleContains(int mx, int my) const;
    void update(int mx, int my, bool mouseDown, int activeSlider);
};

// ============================================================
// ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ ДЛЯ КНОПОК
// ============================================================

/**
 * @brief Обновляет hover-состояние кнопки и воспроизводит звук наведения.
 * @return true если кнопку кликнули в этом кадре
 */
bool updateButton(Button& btn, int mx, int my, bool clicked, SoundManager* snd);

// ============================================================
// ФУНКЦИИ ОТРИСОВКИ
// ============================================================

void drawText(SDL_Renderer* renderer, TTF_Font* defaultFont,
              const std::string& text, int x, int y,
              SDL_Color color = {255, 255, 255, 255},
              bool centered = false,
              TTF_Font* customFont = nullptr);

void drawUIOverlay(SDL_Renderer* renderer, int alpha);

void drawButton(SDL_Renderer* renderer, TTF_Font* font, Button& btn,
                SoundManager* soundMgr = nullptr);

void drawSlider(SDL_Renderer* renderer, TTF_Font* font, Slider& slider,
                SoundManager* soundMgr = nullptr);

void drawStars(SDL_Renderer* renderer, int x, int y, int stars);

[[nodiscard]] std::string getKeyName(SDL_Scancode scancode);