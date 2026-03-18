/**
 * @file ui.cpp
 * @brief Реализация UI-компонентов
 * @author evol
 * @date 2026-02-20
 */
#include "ui.h"
#include "../config/config.h"
#include "../config/common.h"
#include "../utils/sound_manager.h"

// ============================================================
// BUTTON
// ============================================================

Button::Button(int x, int y, int w, int h, const std::string& t)
    : rect{x, y, w, h}, text(t) {}

bool Button::contains(int mx, int my) const {
    return mx >= rect.x && mx <= rect.x + rect.w &&
           my >= rect.y && my <= rect.y + rect.h;
}

void Button::centerX(int windowWidth) {
    rect.x = (windowWidth - rect.w) / 2;
}

// ============================================================
// SLIDER
// ============================================================

Slider::Slider(int x, int y, int w, const std::string& lbl, float* val, int sliderID)
    : label(lbl), value(val), id(sliderID) {
    track = {x, y, w, 10};
    updateHandle();
}

void Slider::updateHandle() {
    int handleX = track.x + (int)((*value) * track.w) - 10;
    handle = {handleX, track.y - 10, 20, 30};
}

bool Slider::handleContains(int mx, int my) const {
    return mx >= handle.x && mx <= handle.x + handle.w &&
           my >= handle.y && my <= handle.y + handle.h;
}

void Slider::update(int mx, int my, bool mouseDown, int activeSlider) {
    if (mouseDown && handleContains(mx, my) && activeSlider == -1)
        isDragging = true;

    if (!mouseDown)
        isDragging = false;

    if (isDragging && activeSlider == id) {
        *value = std::clamp((float)(mx - track.x) / track.w, 0.0f, 1.0f);
        updateHandle();
    }
}

// ============================================================
// ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ ДЛЯ КНОПОК
// ============================================================

// updateButton — тело в .cpp (не inline) чтобы избежать circular include в ui.h
bool updateButton(Button& btn, int mx, int my, bool clicked, SoundManager* snd) {
    btn.isHovered = btn.contains(mx, my);
    if (btn.isHovered && !btn.wasHovered && snd) snd->playHover();
    btn.wasHovered = btn.isHovered;
    if (btn.isHovered && clicked) {
        if (snd) snd->playClick();
        return true;
    }
    return false;
}

// ============================================================
// ФУНКЦИИ ОТРИСОВКИ
// ============================================================

void drawText(SDL_Renderer* renderer, TTF_Font* defaultFont,
              const std::string& text, int x, int y,
              SDL_Color color, bool centered, TTF_Font* customFont) {
    TTF_Font* useFont = customFont ? customFont : defaultFont;
    if (!useFont) return;

    SDL_Surface* surface = TTF_RenderUTF8_Blended(useFont, text.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture) {
        SDL_Rect dst = {x, y, surface->w, surface->h};
        if (centered) dst.x = (Config::getWindowWidth() - surface->w) / 2;
        SDL_RenderCopy(renderer, texture, nullptr, &dst);
        SDL_DestroyTexture(texture);
    }

    SDL_FreeSurface(surface);
}

void drawUIOverlay(SDL_Renderer* renderer, int alpha) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, alpha);
    SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
    SDL_RenderFillRect(renderer, &overlay);
}

void drawButton(SDL_Renderer* renderer, TTF_Font* font, Button& btn,
                SoundManager* /*soundMgr*/) {
    // Фон кнопки
    SDL_SetRenderDrawColor(renderer,
                           btn.isHovered ? 100 : 50,
                           btn.isHovered ? 150 : 70,
                           btn.isHovered ? 220 : 100,
                           btn.isHovered ? 255 : 200);
    SDL_RenderFillRect(renderer, &btn.rect);

    // Контур
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderDrawRect(renderer, &btn.rect);

    // Текст по центру кнопки
    if (!font) return;
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, btn.text.c_str(), {255, 255, 255, 255});
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture) {
        SDL_Rect textRect = {
            btn.rect.x + (btn.rect.w - surface->w) / 2,
            btn.rect.y + (btn.rect.h - surface->h) / 2,
            surface->w, surface->h
        };
        SDL_RenderCopy(renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
    }
    SDL_FreeSurface(surface);
}

void drawSlider(SDL_Renderer* renderer, TTF_Font* font, Slider& slider,
                SoundManager* soundMgr) {
    // Звук начала перетаскивания
    if (slider.isDragging && !slider.wasDragging && soundMgr)
        soundMgr->playSliderMove();
    slider.wasDragging = slider.isDragging;

    drawText(renderer, font, slider.label, slider.track.x, slider.track.y - 40);

    // Трек
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderFillRect(renderer, &slider.track);

    // Ручка
    SDL_SetRenderDrawColor(renderer,
                           slider.isDragging ? 100 : 150,
                           slider.isDragging ? 200 : 150,
                           255, 255);
    SDL_RenderFillRect(renderer, &slider.handle);

    // Значение в процентах справа от трека
    std::string valText = std::to_string((int)((*slider.value) * 100)) + "%";
    drawText(renderer, font, valText, slider.track.x + slider.track.w + 20, slider.track.y - 10);
}

void drawStars(SDL_Renderer* renderer, int x, int y, int stars) {
    for (int i = 0; i < 3; i++) {
        SDL_SetRenderDrawColor(renderer,
                               i < stars ? 255 : 100,
                               i < stars ? 215 : 100,
                               i < stars ?   0 : 100,
                               255);
        SDL_Rect starRect = {x + i * 30, y, 25, 25};
        SDL_RenderFillRect(renderer, &starRect);
    }
}

std::string getKeyName(SDL_Scancode scancode) {
    const char* name = SDL_GetScancodeName(scancode);
    return name ? std::string(name) : "Unknown";
}