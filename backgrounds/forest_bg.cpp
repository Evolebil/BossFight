/**
 * @file forest_bg.cpp
 * @brief Реализация процедурных фонов (без PNG-ассетов)
 * @author evol
 * @date 2026-02-20
 */
#include "forest_bg.h"
#include "../config/config.h"
#include "../config/common.h"

// Общая линия горизонта для обоих фонов: выше — небо/горы, ниже — земля
static constexpr int GROUND_Y = 600;

// ============================================================
// ПРИМИТИВЫ
// ============================================================

namespace {
constexpr int OUTLINE_ANGLE_STEP_DEG = 2; // шаг угла при обходе окружности точками
}

void drawCircleOutline(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int angle = 0; angle < 360; angle += OUTLINE_ANGLE_STEP_DEG) {
        const float rad = angle * (float)M_PI / 180.0f;
        const int x = centerX + (int)(radius * std::cos(rad));
        const int y = centerY + (int)(radius * std::sin(rad));
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

void drawCircleFilled(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
}

void drawTriangleFilled(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (y1 > y2) { std::swap(y1, y2); std::swap(x1, x2); }
    if (y2 > y3) { std::swap(y2, y3); std::swap(x2, x3); }
    if (y1 > y2) { std::swap(y1, y2); std::swap(x1, x2); }

    for (int y = y1; y <= y3; y++) {
        if (y < 0 || y >= Config::getWindowHeight()) continue;

        const float t1 = (y2 == y1) ? 1.0f : (float)(y - y1) / (y2 - y1);
        const float t2 = (y3 == y1) ? 1.0f : (float)(y - y1) / (y3 - y1);

        int xa = x1 + (int)((x2 - x1) * t1);
        int xb = x1 + (int)((x3 - x1) * t2);

        if (xa > xb) std::swap(xa, xb);
        SDL_RenderDrawLine(renderer, xa, y, xb, y);
    }
}

// ============================================================
// ФОН ГЛАВНОГО МЕНЮ
// ============================================================

namespace {

struct Triangle { int x1, y1, x2, y2, x3, y3; };
struct Hill      { int x; int radius; };
struct TreePos   { int x; int y; };

// --- 1. Небо (вертикальный градиент, учитывает brightness) ---
constexpr int SKY_R_BASE = 100, SKY_R_RANGE = 20;
constexpr int SKY_G_BASE = 150, SKY_G_RANGE = 30;
constexpr int SKY_B      = 200;

// --- 2. Дальние горы (учитывают brightness) ---
constexpr std::array<Triangle, 3> FAR_MOUNTAINS = {{
                                                     {150, GROUND_Y, 350, 300, 550, GROUND_Y},
                                                     {450, GROUND_Y, 650, 250, 850, GROUND_Y},
                                                     {750, GROUND_Y, 950, 280, 1150, GROUND_Y},
                                                     }};
constexpr int MOUNTAIN_R = 120, MOUNTAIN_G = 120, MOUNTAIN_B = 140;

// --- 3. Снежные шапки — считаются от вершины горы, не хардкодятся отдельно ---
constexpr int SNOW_CAP_HALF_WIDTH = 20; // ширина шапки от вершины в каждую сторону
constexpr int SNOW_CAP_DROP       = 10; // насколько шапка "сползает" от вершины вниз
constexpr SDL_Color SNOW_CAP_COLOR = {255, 255, 255, 255};

// --- 4. Центральная гора с башней (brightness НЕ применяется, как и раньше) ---
constexpr Triangle CENTRAL_MOUNTAIN = {500, GROUND_Y, 700, 200, 900, GROUND_Y};
constexpr SDL_Color CENTRAL_MOUNTAIN_COLOR = {100, 100, 120, 255};

constexpr int TOWER_X = 680, TOWER_Y = 180;
constexpr int TOWER_W = 40,  TOWER_H = 50;
constexpr SDL_Color TOWER_COLOR = {80, 80, 100, 255};

constexpr int ROOF_LEFT_OFFSET   = -5;
constexpr int ROOF_PEAK_OFFSET_X = 20;
constexpr int ROOF_PEAK_OFFSET_Y = -30;
constexpr int ROOF_RIGHT_OFFSET  = TOWER_W + 5;
constexpr SDL_Color ROOF_COLOR = {120, 60, 60, 255};

constexpr int WINDOW_SIZE      = 16;
constexpr int WINDOW_OFFSET_X  = 12;
constexpr int WINDOW1_OFFSET_Y = 10;
constexpr int WINDOW2_OFFSET_Y = 30;
constexpr SDL_Color WINDOW_COLOR = {200, 180, 100, 255};

constexpr int FLAG_OFFSET_X = 20, FLAG_OFFSET_Y = -35;
constexpr int FLAG_W = 15, FLAG_H = 8;
constexpr SDL_Color FLAG_COLOR = {200, 50, 50, 255};

// --- 5. Холмы ---
constexpr std::array<Hill, 5> HILLS = {{
                                         {200, 80}, {400, 100}, {650, 90}, {900, 95}, {1150, 85},
                                         }};
constexpr SDL_Color HILL_COLOR = {100, 140, 80, 255};

// --- 6. Дальние деревья (на склонах холмов, выше линии земли) ---
constexpr std::array<TreePos, 4> FAR_TREES = {{
                                                {300, 480}, {500, 460}, {750, 470}, {1000, 465},
                                                }};
constexpr int FAR_TREE_CANOPY_RADIUS = 20;
constexpr SDL_Color FAR_TREE_CANOPY_COLOR = {80, 120, 70, 255};
constexpr SDL_Color FAR_TREE_TRUNK_COLOR  = {80, 60, 40, 255};
constexpr int FAR_TREE_TRUNK_W = 6, FAR_TREE_TRUNK_H = 25;
constexpr int FAR_TREE_TRUNK_OFFSET_Y = 15; // от центра кроны вниз до верха ствола

// --- 7. Ближние деревья (стоят прямо на линии земли) ---
constexpr std::array<int, 7> NEAR_TREE_X = {100, 250, 450, 600, 800, 950, 1180};
constexpr int NEAR_TREE_CANOPY_RADIUS   = 40;
constexpr int NEAR_TREE_CANOPY_Y_OFFSET = -50; // центр кроны над землёй
constexpr SDL_Color NEAR_TREE_CANOPY_COLOR = {60, 140, 60, 255};
constexpr SDL_Color NEAR_TREE_TRUNK_COLOR  = {100, 70, 50, 255};
constexpr int NEAR_TREE_TRUNK_W = 16, NEAR_TREE_TRUNK_H = 15;
constexpr int NEAR_TREE_TRUNK_Y_OFFSET = -15; // верх ствола относительно земли

// --- 8. Земля ---
constexpr SDL_Color GROUND_COLOR = {80, 120, 60, 255};

} // namespace

void drawForestBackground(SDL_Renderer* renderer, float brightness) {
    const int W = Config::getWindowWidth();
    const int H = Config::getWindowHeight();

    // 1. НЕБО
    for (int y = 0; y < H; y++) {
        const int r = (int)((SKY_R_BASE + (y * SKY_R_RANGE) / H) * brightness);
        const int g = (int)((SKY_G_BASE + (y * SKY_G_RANGE) / H) * brightness);
        const int b = (int)(SKY_B * brightness);
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, W, y);
    }

    // 2. ДАЛЬНИЕ ГОРЫ
    const int mr = (int)(MOUNTAIN_R * brightness);
    const int mg = (int)(MOUNTAIN_G * brightness);
    const int mb = (int)(MOUNTAIN_B * brightness);
    SDL_SetRenderDrawColor(renderer, mr, mg, mb, 255);
    for (const auto& m : FAR_MOUNTAINS)
        drawTriangleFilled(renderer, m.x1, m.y1, m.x2, m.y2, m.x3, m.y3);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (const auto& m : FAR_MOUNTAINS) {
        SDL_RenderDrawLine(renderer, m.x1, m.y1, m.x2, m.y2);
        SDL_RenderDrawLine(renderer, m.x2, m.y2, m.x3, m.y3);
    }

    // 3. СНЕЖНЫЕ ШАПКИ
    SDL_SetRenderDrawColor(renderer, SNOW_CAP_COLOR.r, SNOW_CAP_COLOR.g, SNOW_CAP_COLOR.b, SNOW_CAP_COLOR.a);
    for (const auto& m : FAR_MOUNTAINS) {
        const int peakX = m.x2, peakY = m.y2;
        drawTriangleFilled(renderer,
                           peakX - SNOW_CAP_HALF_WIDTH, peakY + SNOW_CAP_DROP,
                           peakX,                        peakY,
                           peakX + SNOW_CAP_HALF_WIDTH, peakY + SNOW_CAP_DROP);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (const auto& m : FAR_MOUNTAINS) {
        const int peakX = m.x2, peakY = m.y2;
        SDL_RenderDrawLine(renderer, peakX - SNOW_CAP_HALF_WIDTH, peakY + SNOW_CAP_DROP, peakX, peakY);
        SDL_RenderDrawLine(renderer, peakX, peakY, peakX + SNOW_CAP_HALF_WIDTH, peakY + SNOW_CAP_DROP);
    }

    // 4. ЦЕНТРАЛЬНАЯ ГОРА С БАШНЕЙ
    SDL_SetRenderDrawColor(renderer, CENTRAL_MOUNTAIN_COLOR.r, CENTRAL_MOUNTAIN_COLOR.g, CENTRAL_MOUNTAIN_COLOR.b, 255);
    drawTriangleFilled(renderer, CENTRAL_MOUNTAIN.x1, CENTRAL_MOUNTAIN.y1,
                       CENTRAL_MOUNTAIN.x2, CENTRAL_MOUNTAIN.y2,
                       CENTRAL_MOUNTAIN.x3, CENTRAL_MOUNTAIN.y3);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, CENTRAL_MOUNTAIN.x1, CENTRAL_MOUNTAIN.y1, CENTRAL_MOUNTAIN.x2, CENTRAL_MOUNTAIN.y2);
    SDL_RenderDrawLine(renderer, CENTRAL_MOUNTAIN.x2, CENTRAL_MOUNTAIN.y2, CENTRAL_MOUNTAIN.x3, CENTRAL_MOUNTAIN.y3);

    // Башня
    SDL_SetRenderDrawColor(renderer, TOWER_COLOR.r, TOWER_COLOR.g, TOWER_COLOR.b, 255);
    SDL_Rect towerBase = {TOWER_X, TOWER_Y, TOWER_W, TOWER_H};
    SDL_RenderFillRect(renderer, &towerBase);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &towerBase);

    SDL_SetRenderDrawColor(renderer, ROOF_COLOR.r, ROOF_COLOR.g, ROOF_COLOR.b, 255);
    drawTriangleFilled(renderer,
                       TOWER_X + ROOF_LEFT_OFFSET,   TOWER_Y,
                       TOWER_X + ROOF_PEAK_OFFSET_X, TOWER_Y + ROOF_PEAK_OFFSET_Y,
                       TOWER_X + ROOF_RIGHT_OFFSET,  TOWER_Y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, TOWER_X + ROOF_LEFT_OFFSET, TOWER_Y, TOWER_X + ROOF_PEAK_OFFSET_X, TOWER_Y + ROOF_PEAK_OFFSET_Y);
    SDL_RenderDrawLine(renderer, TOWER_X + ROOF_PEAK_OFFSET_X, TOWER_Y + ROOF_PEAK_OFFSET_Y, TOWER_X + ROOF_RIGHT_OFFSET, TOWER_Y);

    SDL_SetRenderDrawColor(renderer, WINDOW_COLOR.r, WINDOW_COLOR.g, WINDOW_COLOR.b, 255);
    SDL_Rect window1 = {TOWER_X + WINDOW_OFFSET_X, TOWER_Y + WINDOW1_OFFSET_Y, WINDOW_SIZE, WINDOW_SIZE};
    SDL_Rect window2 = {TOWER_X + WINDOW_OFFSET_X, TOWER_Y + WINDOW2_OFFSET_Y, WINDOW_SIZE, WINDOW_SIZE};
    SDL_RenderFillRect(renderer, &window1);
    SDL_RenderFillRect(renderer, &window2);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &window1);
    SDL_RenderDrawRect(renderer, &window2);

    SDL_SetRenderDrawColor(renderer, FLAG_COLOR.r, FLAG_COLOR.g, FLAG_COLOR.b, 255);
    SDL_Rect flag = {TOWER_X + FLAG_OFFSET_X, TOWER_Y + FLAG_OFFSET_Y, FLAG_W, FLAG_H};
    SDL_RenderFillRect(renderer, &flag);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &flag);

    // 5. ХОЛМЫ
    SDL_SetRenderDrawColor(renderer, HILL_COLOR.r, HILL_COLOR.g, HILL_COLOR.b, 255);
    for (const auto& hill : HILLS) {
        for (int y = 0; y <= hill.radius; y++) {
            const int width = (int)(std::sqrt((double)(hill.radius * hill.radius - y * y)) * 2);
            SDL_RenderDrawLine(renderer, hill.x - width / 2, GROUND_Y - y,
                               hill.x + width / 2, GROUND_Y - y);
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (const auto& hill : HILLS)
        drawCircleOutline(renderer, hill.x, GROUND_Y, hill.radius);

    // 6. ДАЛЬНИЕ ДЕРЕВЬЯ
    for (const auto& tree : FAR_TREES) {
        SDL_SetRenderDrawColor(renderer, FAR_TREE_CANOPY_COLOR.r, FAR_TREE_CANOPY_COLOR.g, FAR_TREE_CANOPY_COLOR.b, 255);
        drawCircleFilled(renderer, tree.x, tree.y, FAR_TREE_CANOPY_RADIUS);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCircleOutline(renderer, tree.x, tree.y, FAR_TREE_CANOPY_RADIUS);

        SDL_SetRenderDrawColor(renderer, FAR_TREE_TRUNK_COLOR.r, FAR_TREE_TRUNK_COLOR.g, FAR_TREE_TRUNK_COLOR.b, 255);
        SDL_Rect trunk = {tree.x - FAR_TREE_TRUNK_W / 2, tree.y + FAR_TREE_TRUNK_OFFSET_Y,
                          FAR_TREE_TRUNK_W, FAR_TREE_TRUNK_H};
        SDL_RenderFillRect(renderer, &trunk);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &trunk);
    }

    // 7. БЛИЖНИЕ ДЕРЕВЬЯ
    for (const int treeX : NEAR_TREE_X) {
        const int canopyY = GROUND_Y + NEAR_TREE_CANOPY_Y_OFFSET;

        SDL_SetRenderDrawColor(renderer, NEAR_TREE_CANOPY_COLOR.r, NEAR_TREE_CANOPY_COLOR.g, NEAR_TREE_CANOPY_COLOR.b, 255);
        drawCircleFilled(renderer, treeX, canopyY, NEAR_TREE_CANOPY_RADIUS);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCircleOutline(renderer, treeX, canopyY, NEAR_TREE_CANOPY_RADIUS);

        SDL_SetRenderDrawColor(renderer, NEAR_TREE_TRUNK_COLOR.r, NEAR_TREE_TRUNK_COLOR.g, NEAR_TREE_TRUNK_COLOR.b, 255);
        SDL_Rect trunk = {treeX - NEAR_TREE_TRUNK_W / 2, GROUND_Y + NEAR_TREE_TRUNK_Y_OFFSET,
                          NEAR_TREE_TRUNK_W, NEAR_TREE_TRUNK_H};
        SDL_RenderFillRect(renderer, &trunk);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &trunk);
    }

    // 8. ЗЕМЛЯ
    SDL_SetRenderDrawColor(renderer, GROUND_COLOR.r, GROUND_COLOR.g, GROUND_COLOR.b, 255);
    SDL_Rect ground = {0, GROUND_Y, W, H - GROUND_Y};
    SDL_RenderFillRect(renderer, &ground);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, GROUND_Y, W, GROUND_Y);
}

// ============================================================
// ФОН ЭКРАНА ВЫБОРА УРОВНЯ
// ============================================================

namespace {

constexpr int SKY2_R_BASE = 60, SKY2_R_RANGE = 30;
constexpr int SKY2_G_BASE = 70, SKY2_G_RANGE = 35;
constexpr int SKY2_B_BASE = 90, SKY2_B_RANGE = 40;

constexpr int TOWER2_Y = 200;
constexpr int TOWER2_W = 200, TOWER2_H = 400;
constexpr SDL_Color TOWER2_COLOR = {70, 70, 90, 255};

constexpr int ROOF2_LEFT_OFFSET   = -20;
constexpr int ROOF2_PEAK_OFFSET_X = 100;
constexpr int ROOF2_PEAK_OFFSET_Y = -60;
constexpr int ROOF2_RIGHT_OFFSET  = TOWER2_W + 20;
constexpr SDL_Color ROOF2_COLOR = {100, 60, 60, 255};

constexpr SDL_Color GROUND2_COLOR = {60, 90, 50, 255};

} // namespace

void drawTowerBackground(SDL_Renderer* renderer, float /*brightness*/) {
    const int W = Config::getWindowWidth();
    const int H = Config::getWindowHeight();

    // Градиент неба — эта версия фона brightness не учитывает (так было
    // изначально; экран выбора уровня всегда одинаковой яркости)
    for (int y = 0; y < H; y++) {
        const int r = SKY2_R_BASE + (y * SKY2_R_RANGE) / H;
        const int g = SKY2_G_BASE + (y * SKY2_G_RANGE) / H;
        const int b = SKY2_B_BASE + (y * SKY2_B_RANGE) / H;
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, W, y);
    }

    // Башня — по центру экрана
    const int towerX = W / 2 - TOWER2_W / 2;

    SDL_SetRenderDrawColor(renderer, TOWER2_COLOR.r, TOWER2_COLOR.g, TOWER2_COLOR.b, 255);
    SDL_Rect towerMain = {towerX, TOWER2_Y, TOWER2_W, TOWER2_H};
    SDL_RenderFillRect(renderer, &towerMain);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &towerMain);

    SDL_SetRenderDrawColor(renderer, ROOF2_COLOR.r, ROOF2_COLOR.g, ROOF2_COLOR.b, 255);
    drawTriangleFilled(renderer,
                       towerX + ROOF2_LEFT_OFFSET,   TOWER2_Y,
                       towerX + ROOF2_PEAK_OFFSET_X, TOWER2_Y + ROOF2_PEAK_OFFSET_Y,
                       towerX + ROOF2_RIGHT_OFFSET,  TOWER2_Y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, towerX + ROOF2_LEFT_OFFSET, TOWER2_Y, towerX + ROOF2_PEAK_OFFSET_X, TOWER2_Y + ROOF2_PEAK_OFFSET_Y);
    SDL_RenderDrawLine(renderer, towerX + ROOF2_PEAK_OFFSET_X, TOWER2_Y + ROOF2_PEAK_OFFSET_Y, towerX + ROOF2_RIGHT_OFFSET, TOWER2_Y);

    // Земля
    SDL_SetRenderDrawColor(renderer, GROUND2_COLOR.r, GROUND2_COLOR.g, GROUND2_COLOR.b, 255);
    SDL_Rect ground = {0, GROUND_Y, W, H - GROUND_Y};
    SDL_RenderFillRect(renderer, &ground);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, GROUND_Y, W, GROUND_Y);
}