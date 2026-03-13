#pragma once
#include "../config/common.h"
#include "../utils/sound_manager.h"
// === СТРУКТУРЫ ===

// Кнопка с текстом
struct Button {
    SDL_Rect rect;           // Позиция и размер
    std::string text;        // Текст на кнопке
    bool isHovered;          // Наведён ли курсор
    bool wasHovered;         // Был ли наведён (для звука наведения)
    
    Button(int x, int y, int w, int h, const std::string& t);
    
    // Проверяет, находится ли точка (mx, my) внутри кнопки
    bool contains(int mx, int my);
    
    // Центрирует кнопку по горизонтали
    void centerX(int windowWidth);
};

// Слайдер (ползунок) для настроек
struct Slider {
    SDL_Rect track;          // Полоса слайдера
    SDL_Rect handle;         // Ручка (перетаскиваемая)
    std::string label;       // Название (например "Яркость")
    float* value;            // Указатель на значение (0.0 - 1.0)
    bool isDragging;         // Перетаскивается ли сейчас
    bool wasDragging;        // Был ли в перетаскивании (для звука)
    int id;                  // Уникальный ID для предотвращения конфликтов
    
    Slider(int x, int y, int w, const std::string& lbl, float* val, int sliderID);
    
    // Обновляет позицию ручки на основе *value
    void updateHandle();
    
    // Проверяет, находится ли курсор на ручке
    bool handleContains(int mx, int my);
    
    // Обновляет состояние слайдера (перетаскивание)
    void update(int mx, int my, bool mouseDown, int activeSlider);
};

// === ФУНКЦИИ ОТРИСОВКИ ===

// Рисует текст на экране
void drawText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, 
              int x, int y, SDL_Color color = {255, 255, 255, 255}, 
              bool centered = false, TTF_Font* customFont = nullptr);

// Рисует затемняющую подложку под UI
void drawUIOverlay(SDL_Renderer* renderer, int alpha = 100);

// Рисует кнопку с текстом
void drawButton(SDL_Renderer* renderer, TTF_Font* font, Button& btn, SoundManager* soundMgr = nullptr);

// Рисует слайдер с подписью и значением
void drawSlider(SDL_Renderer* renderer, TTF_Font* font, Slider& slider, SoundManager* soundMgr = nullptr);

// Рисует звёзды для уровня (0-3 звезды)
void drawStars(SDL_Renderer* renderer, int x, int y, int stars);

// Получает название клавиши по скан-коду
std::string getKeyName(SDL_Scancode scancode);
