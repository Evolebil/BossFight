#include "../utils/scene_manager.h"
#include "splash_scene.h"  // ✅ ДОБАВИТЬ свой .h файл
#include "../config/config.h"
#include "../utils/sound_manager.h"
#include <cmath>
#include <algorithm>

// УБРАТЬ класс - он уже объявлен в splash_scene.h

SplashScene::SplashScene()  // ✅ Добавить SplashScene::
    : splashTime(0.0f), nextScene(SceneType::SPLASH), soundMgr(getSoundManager()) {}

void SplashScene::handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) {  // ✅ SplashScene::
    // Пропуск заставки по нажатию любой клавиши
    if (event.type == SDL_KEYDOWN) {
        nextScene = SceneType::MAIN_MENU;
    }
}

void SplashScene::update(float deltaTime) {  // ✅ SplashScene::
    splashTime += deltaTime;
    // Автоматический переход через 3 секунды
    if (splashTime > 3.0f) {
        nextScene = SceneType::MAIN_MENU;
    }
}

void SplashScene::render(SDL_Renderer* renderer) {  // ✅ SplashScene::
    // Чёрный фон
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Яркость круга увеличивается - ЗЕЛЁНЫЙ
    int brightness = (int)(std::min(255.0f, splashTime * 100));
    SDL_SetRenderDrawColor(renderer, 0, brightness, 0, 255);
        
    // Круг с лучами
    int centerX = Config::getWindowWidth() / 2;
    int centerY = Config::getWindowHeight() / 2;
    int radius = 80;
    
    // Рисуем заполненный круг
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
    
    // Лучи (8 штук, толстые)
    int numRays = 8;
    int rayLength = 150;
    for (int i = 0; i < numRays; i++) {
        float angle = (i * 2 * M_PI) / numRays;
        int x1 = centerX + (int)(cos(angle) * (radius + 10));
        int y1 = centerY + (int)(sin(angle) * (radius + 10));
        int x2 = centerX + (int)(cos(angle) * (radius + rayLength));
        int y2 = centerY + (int)(sin(angle) * (radius + rayLength));
        
        // Рисуем толстые линии
        for (int thickness = -2; thickness <= 2; thickness++) {
            SDL_RenderDrawLine(renderer, x1 + thickness, y1, x2 + thickness, y2);
            SDL_RenderDrawLine(renderer, x1, y1 + thickness, x2, y2 + thickness);
        }
    }
}
    
SceneType SplashScene::getNextScene() {  // ✅ SplashScene::
    return nextScene;
}