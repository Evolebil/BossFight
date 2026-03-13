#include "ui.h"
#include "../config/config.h"
#include "../config/common.h"
#include "../utils/sound_manager.h"

// === РЕАЛИЗАЦИЯ BUTTON ===

Button::Button(int x, int y, int w, int h, const std::string& t) 
    : rect{x, y, w, h}, text(t), isHovered(false), wasHovered(false) {}

bool Button::contains(int mx, int my) {
    return mx >= rect.x && mx <= rect.x + rect.w &&
           my >= rect.y && my <= rect.y + rect.h;
}

void Button::centerX(int windowWidth) {
    rect.x = (windowWidth - rect.w) / 2;
}

// === РЕАЛИЗАЦИЯ SLIDER ===

Slider::Slider(int x, int y, int w, const std::string& lbl, float* val, int sliderID)
    : label(lbl), value(val), isDragging(false), wasDragging(false), id(sliderID) {
    track = {x, y, w, 10};
    updateHandle();
}

void Slider::updateHandle() {
    int handleX = track.x + (int)((*value) * track.w) - 10;
    handle = {handleX, track.y - 10, 20, 30};
}

bool Slider::handleContains(int mx, int my) {
    return mx >= handle.x && mx <= handle.x + handle.w &&
           my >= handle.y && my <= handle.y + handle.h;
}

void Slider::update(int mx, int my, bool mouseDown, int activeSlider) {
    // Начинаем перетаскивание только если нет другого активного слайдера
    if (mouseDown && handleContains(mx, my) && activeSlider == -1) {
        isDragging = true;
    }
    
    // Прекращаем перетаскивание при отпускании мыши
    if (!mouseDown) {
        isDragging = false;
    }
    
    // Обновляем значение только для активного слайдера
    if (isDragging && activeSlider == id) {
        float newVal = (float)(mx - track.x) / track.w;
        *value = std::max(0.0f, std::min(1.0f, newVal));
        updateHandle();
    }
}

// === ФУНКЦИИ ОТРИСОВКИ ===

void drawText(SDL_Renderer* renderer, TTF_Font* defaultFont, const std::string& text, 
              int x, int y, SDL_Color color, bool centered, TTF_Font* customFont) {
    TTF_Font* useFont = customFont ? customFont : defaultFont;
    if (!useFont) return;
    
    SDL_Surface* surface = TTF_RenderUTF8_Blended(useFont, text.c_str(), color);
    if (!surface) return;
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    SDL_Rect destRect = {x, y, surface->w, surface->h};
    if (centered) {
        destRect.x = (Config::getWindowWidth() - surface->w) / 2;  // ИСПРАВЛЕНО
    }
    
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void drawUIOverlay(SDL_Renderer* renderer, int alpha) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, alpha);
    SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};  // ИСПРАВЛЕНО
    SDL_RenderFillRect(renderer, &overlay);
}

void drawButton(SDL_Renderer* renderer, TTF_Font* font, Button& btn, SoundManager* soundMgr) {
    // Цвет кнопки меняется при наведении
    if (btn.isHovered) {
        SDL_SetRenderDrawColor(renderer, 100, 150, 220, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 50, 70, 100, 200);
    }
    SDL_RenderFillRect(renderer, &btn.rect);
    
    // Белый контур
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderDrawRect(renderer, &btn.rect);
    
    // Текст по центру кнопки
    if (font) {
        SDL_Surface* surface = TTF_RenderUTF8_Blended(font, btn.text.c_str(), {255, 255, 255, 255});
        if (surface) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect = {
                btn.rect.x + (btn.rect.w - surface->w) / 2,
                btn.rect.y + (btn.rect.h - surface->h) / 2,
                surface->w, surface->h
            };
            SDL_RenderCopy(renderer, texture, nullptr, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
    }
}

void drawSlider(SDL_Renderer* renderer, TTF_Font* font, Slider& slider, SoundManager* soundMgr) {
    // Звук перетаскивания
    if (slider.isDragging && !slider.wasDragging && soundMgr) {
        soundMgr->playSliderMove();
    }
    slider.wasDragging = slider.isDragging;
    
    // Название слайдера
    drawText(renderer, font, slider.label, slider.track.x, slider.track.y - 40);
    
    // Трек (полоса)
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderFillRect(renderer, &slider.track);
    
    // Ручка
    if (slider.isDragging) {
        SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 150, 150, 200, 255);
    }
    SDL_RenderFillRect(renderer, &slider.handle);
    
    // Значение в процентах
    std::string valText = std::to_string((int)((*slider.value) * 100)) + "%";
    drawText(renderer, font, valText, slider.track.x + slider.track.w + 20, slider.track.y - 10);
}

void drawStars(SDL_Renderer* renderer, int x, int y, int stars) {
    for (int i = 0; i < 3; i++) {
        if (i < stars) {
            SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        }
        SDL_Rect starRect = {x + i * 30, y, 25, 25};
        SDL_RenderFillRect(renderer, &starRect);
    }
}

std::string getKeyName(SDL_Scancode scancode) {
    const char* name = SDL_GetScancodeName(scancode);
    return name ? std::string(name) : "Unknown";
}
