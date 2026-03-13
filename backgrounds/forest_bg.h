#pragma once
#include "../config/common.h"

// Вспомогательные функции для отрисовки примитивов
void drawCircleOutline(SDL_Renderer* renderer, int centerX, int centerY, int radius);
void drawCircleFilled(SDL_Renderer* renderer, int centerX, int centerY, int radius);
void drawTriangleFilled(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3);

// Фон лесного меню
void drawForestBackground(SDL_Renderer* renderer, float brightness);

// Фон с башней (для выбора уровней)
void drawTowerBackground(SDL_Renderer* renderer, float brightness);
