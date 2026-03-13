#include "forest_bg.h"
#include "../config/config.h"
#include "../config/common.h"

const int GROUND_Y = 600;

void drawCircleOutline(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int angle = 0; angle < 360; angle += 2) {
        float rad = angle * M_PI / 180.0f;
        int x = centerX + (int)(radius * cos(rad));
        int y = centerY + (int)(radius * sin(rad));
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

void drawCircleFilled(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius) {
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
        
        float t1 = (y2 == y1) ? 1.0f : (float)(y - y1) / (y2 - y1);
        float t2 = (y3 == y1) ? 1.0f : (float)(y - y1) / (y3 - y1);
        
        int xa = x1 + (int)((x2 - x1) * t1);
        int xb = x1 + (int)((x3 - x1) * t2);
        
        if (xa > xb) std::swap(xa, xb);
        SDL_RenderDrawLine(renderer, xa, y, xb, y);
    }
}

void drawForestBackground(SDL_Renderer* renderer, float brightness) {
    int W = Config::getWindowWidth();
    int H = Config::getWindowHeight();
    
    // ПРИМЕНЯЕМ ЯРКОСТЬ через SDL модификатор цвета
    Uint8 brightnessValue = (Uint8)(255 * brightness);
    SDL_SetRenderDrawColor(renderer, brightnessValue, brightnessValue, brightnessValue, 255);
    
    // 1. НЕБО
    for (int y = 0; y < H; y++) {
        int r = (int)((100 + (y * 20) / H) * brightness);
        int g = (int)((150 + (y * 30) / H) * brightness);
        int b = (int)(200 * brightness);
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, W, y);
    }
    
    // 2. ГОРЫ
    int mr = (int)(120 * brightness);
    int mg = (int)(120 * brightness);
    int mb = (int)(140 * brightness);
    SDL_SetRenderDrawColor(renderer, mr, mg, mb, 255);
    drawTriangleFilled(renderer, 150, GROUND_Y, 350, 300, 550, GROUND_Y);
    drawTriangleFilled(renderer, 450, GROUND_Y, 650, 250, 850, GROUND_Y);
    drawTriangleFilled(renderer, 750, GROUND_Y, 950, 280, 1150, GROUND_Y);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 150, GROUND_Y, 350, 300);
    SDL_RenderDrawLine(renderer, 350, 300, 550, GROUND_Y);
    SDL_RenderDrawLine(renderer, 450, GROUND_Y, 650, 250);
    SDL_RenderDrawLine(renderer, 650, 250, 850, GROUND_Y);
    SDL_RenderDrawLine(renderer, 750, GROUND_Y, 950, 280);
    SDL_RenderDrawLine(renderer, 950, 280, 1150, GROUND_Y);
    
    // 3. СНЕЖНЫЕ ВЕРШИНЫ
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    drawTriangleFilled(renderer, 330, 310, 350, 300, 370, 310);
    drawTriangleFilled(renderer, 630, 260, 650, 250, 670, 260);
    drawTriangleFilled(renderer, 930, 290, 950, 280, 970, 290);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 330, 310, 350, 300);
    SDL_RenderDrawLine(renderer, 350, 300, 370, 310);
    SDL_RenderDrawLine(renderer, 630, 260, 650, 250);
    SDL_RenderDrawLine(renderer, 650, 250, 670, 260);
    SDL_RenderDrawLine(renderer, 930, 290, 950, 280);
    SDL_RenderDrawLine(renderer, 950, 280, 970, 290);
    
    // 4. ЦЕНТРАЛЬНАЯ ГОРА С БАШНЕЙ
    SDL_SetRenderDrawColor(renderer, 100, 100, 120, 255);
    drawTriangleFilled(renderer, 500, GROUND_Y, 700, 200, 900, GROUND_Y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 500, GROUND_Y, 700, 200);
    SDL_RenderDrawLine(renderer, 700, 200, 900, GROUND_Y);
    
    // БАШНЯ
    int towerX = 680, towerY = 180;
    SDL_SetRenderDrawColor(renderer, 80, 80, 100, 255);
    SDL_Rect towerBase = {towerX, towerY, 40, 50};
    SDL_RenderFillRect(renderer, &towerBase);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &towerBase);
    
    SDL_SetRenderDrawColor(renderer, 120, 60, 60, 255);
    drawTriangleFilled(renderer, towerX - 5, towerY, towerX + 20, towerY - 30, towerX + 45, towerY);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, towerX - 5, towerY, towerX + 20, towerY - 30);
    SDL_RenderDrawLine(renderer, towerX + 20, towerY - 30, towerX + 45, towerY);
    
    SDL_SetRenderDrawColor(renderer, 200, 180, 100, 255);
    SDL_Rect window1 = {towerX + 12, towerY + 10, 16, 16};
    SDL_Rect window2 = {towerX + 12, towerY + 30, 16, 16};
    SDL_RenderFillRect(renderer, &window1);
    SDL_RenderFillRect(renderer, &window2);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &window1);
    SDL_RenderDrawRect(renderer, &window2);
    
    SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
    SDL_Rect flag = {towerX + 20, towerY - 35, 15, 8};
    SDL_RenderFillRect(renderer, &flag);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &flag);
    
    // 5. ХОЛМЫ
    int hills[][3] = {{200, GROUND_Y, 80}, {400, GROUND_Y, 100}, {650, GROUND_Y, 90}, 
                      {900, GROUND_Y, 95}, {1150, GROUND_Y, 85}};
    
    SDL_SetRenderDrawColor(renderer, 100, 140, 80, 255);
    for (int i = 0; i < 5; i++) {
        for (int y = 0; y <= hills[i][2]; y++) {
            int width = (int)(sqrt(hills[i][2] * hills[i][2] - y * y) * 2);
            SDL_RenderDrawLine(renderer, hills[i][0] - width/2, hills[i][1] - y, 
                             hills[i][0] + width/2, hills[i][1] - y);
        }
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < 5; i++) {
        drawCircleOutline(renderer, hills[i][0], hills[i][1], hills[i][2]);
    }
    
    // 6. ДЕРЕВЬЯ (дальние)
    int farTrees[][2] = {{300, 480}, {500, 460}, {750, 470}, {1000, 465}};
    for (int i = 0; i < 4; i++) {
        SDL_SetRenderDrawColor(renderer, 80, 120, 70, 255);
        drawCircleFilled(renderer, farTrees[i][0], farTrees[i][1], 20);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCircleOutline(renderer, farTrees[i][0], farTrees[i][1], 20);
        
        SDL_SetRenderDrawColor(renderer, 80, 60, 40, 255);
        SDL_Rect trunk = {farTrees[i][0] - 3, farTrees[i][1] + 15, 6, 25};
        SDL_RenderFillRect(renderer, &trunk);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &trunk);
    }
    
    // 7. ДЕРЕВЬЯ (передние)
    int trees[][2] = {{100, GROUND_Y}, {250, GROUND_Y}, {450, GROUND_Y}, 
                      {600, GROUND_Y}, {800, GROUND_Y}, {950, GROUND_Y}, {1180, GROUND_Y}};
    
    for (int i = 0; i < 7; i++) {
        SDL_SetRenderDrawColor(renderer, 60, 140, 60, 255);
        drawCircleFilled(renderer, trees[i][0], trees[i][1] - 50, 40);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCircleOutline(renderer, trees[i][0], trees[i][1] - 50, 40);
        
        SDL_SetRenderDrawColor(renderer, 100, 70, 50, 255);
        SDL_Rect trunk = {trees[i][0] - 8, trees[i][1] - 15, 16, 15};
        SDL_RenderFillRect(renderer, &trunk);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &trunk);
    }
    
    // 8. ЗЕМЛЯ
    SDL_SetRenderDrawColor(renderer, 80, 120, 60, 255);
    SDL_Rect ground = {0, GROUND_Y, W, H - GROUND_Y};
    SDL_RenderFillRect(renderer, &ground);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, GROUND_Y, W, GROUND_Y);
}

void drawTowerBackground(SDL_Renderer* renderer, float brightness) {
    int W = Config::getWindowWidth();
    int H = Config::getWindowHeight();
    
    // Градиент
    for (int y = 0; y < H; y++) {
        int r = 60 + (y * 30) / H;
        int g = 70 + (y * 35) / H;
        int b = 90 + (y * 40) / H;
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, W, y);
    }
    
    // Башня
    int towerX = W / 2 - 100;
    int towerY = 200;
    
    SDL_SetRenderDrawColor(renderer, 70, 70, 90, 255);
    SDL_Rect towerMain = {towerX, towerY, 200, 400};
    SDL_RenderFillRect(renderer, &towerMain);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &towerMain);
    
    SDL_SetRenderDrawColor(renderer, 100, 60, 60, 255);
    drawTriangleFilled(renderer, towerX - 20, towerY, towerX + 100, towerY - 60, towerX + 220, towerY);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, towerX - 20, towerY, towerX + 100, towerY - 60);
    SDL_RenderDrawLine(renderer, towerX + 100, towerY - 60, towerX + 220, towerY);
    
    // Земля
    SDL_SetRenderDrawColor(renderer, 60, 90, 50, 255);
    SDL_Rect ground = {0, 600, W, H - 600};
    SDL_RenderFillRect(renderer, &ground);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, 600, W, 600);
}
