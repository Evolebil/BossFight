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

#include <unordered_map>

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

// Кэш текстур текста: раньше каждая надпись каждый кадр заново растеризовалась
// шрифтом и загружалась в видеопамять — главный источник лагов в меню и HUD
namespace {
struct CachedText { SDL_Texture* texture; int w, h; };
std::unordered_map<std::string, CachedText> g_textCache;
constexpr size_t TEXT_CACHE_LIMIT = 512;  // счётчики (таймер, HP) плодят новые строки

const CachedText* getTextTexture(SDL_Renderer* renderer, TTF_Font* font,
                                 const std::string& text, SDL_Color color) {
    std::string key;
    key.reserve(text.size() + 24);
    key.append(reinterpret_cast<const char*>(&font), sizeof(font));
    key.append(reinterpret_cast<const char*>(&color), sizeof(color));
    key += text;

    auto it = g_textCache.find(key);
    if (it != g_textCache.end()) return &it->second;

    if (g_textCache.size() >= TEXT_CACHE_LIMIT) clearTextCache();

    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    if (!surface) return nullptr;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    CachedText entry{texture, surface->w, surface->h};
    SDL_FreeSurface(surface);
    if (!texture) return nullptr;
    return &g_textCache.emplace(std::move(key), entry).first->second;
}
}  // namespace

void clearTextCache() {
    for (auto& [key, entry] : g_textCache) SDL_DestroyTexture(entry.texture);
    g_textCache.clear();
}

void drawText(SDL_Renderer* renderer, TTF_Font* defaultFont,
              const std::string& text, int x, int y,
              SDL_Color color, bool centered, TTF_Font* customFont) {
    TTF_Font* useFont = customFont ? customFont : defaultFont;
    if (!useFont || text.empty()) return;

    const CachedText* cached = getTextTexture(renderer, useFont, text, color);
    if (!cached) return;

    SDL_Rect dst = {x, y, cached->w, cached->h};
    if (centered) dst.x = (Config::getWindowWidth() - cached->w) / 2;
    SDL_RenderCopy(renderer, cached->texture, nullptr, &dst);
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
    if (!font || btn.text.empty()) return;
    const CachedText* cached = getTextTexture(renderer, font, btn.text, {255, 255, 255, 255});
    if (!cached) return;

    SDL_Rect textRect = {
        btn.rect.x + (btn.rect.w - cached->w) / 2,
        btn.rect.y + (btn.rect.h - cached->h) / 2,
        cached->w, cached->h
    };
    SDL_RenderCopy(renderer, cached->texture, nullptr, &textRect);
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

void drawStars(SDL_Renderer* renderer, int x, int y, int stars, SDL_Color color) {
    for (int i = 0; i < 3; i++) {
        if (i < stars) SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        else           SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_Rect starRect = {x + i * 30, y, 25, 25};
        SDL_RenderFillRect(renderer, &starRect);
    }
}

std::string getKeyName(SDL_Scancode scancode) {
    const char* name = SDL_GetScancodeName(scancode);
    return name ? std::string(name) : "Unknown";
}