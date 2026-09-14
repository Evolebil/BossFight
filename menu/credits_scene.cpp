#include "credits_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"
#include "../utils/scene_manager.h"

// Убрать весь класс CreditsScene { ... } и заменить на:

CreditsScene::CreditsScene() 
    : nextScene(SceneType::CREDITS),
      soundMgr(getSoundManager()),
      backBtn(20, 20, 100, 50, "Назад") {}

void CreditsScene::handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) {
    backBtn.isHovered = backBtn.contains(mouseX, mouseY);
    
    // Звук наведения
    if (backBtn.isHovered && !backBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    backBtn.wasHovered = backBtn.isHovered;
    
    if (backBtn.isHovered && mouseClicked) {
        if (soundMgr) soundMgr->playClick();
        nextScene = SceneType::MAIN_MENU;
    }
}

void CreditsScene::update(float deltaTime) {
    // Нет логики обновления
}

void CreditsScene::render(SDL_Renderer* renderer) {
    // Фон
    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 100);
    
    // Заголовок
    drawText(renderer, Config::getFont(), "Разработчики", 0, 100, 
             {255, 230, 150, 255}, true, Config::getTitleFont());
    
    // Текст
    // Текст
    drawText(renderer, Config::getFont(), "Игра создана:", 0, 160,
             {255, 255, 255, 255}, true);
    drawText(renderer, Config::getFont(), "evol (Бобров Владислав Витальевич)", 0, 200,
             {200, 200, 255, 255}, true);
    drawText(renderer, Config::getFont(), "Программист и Дизайнер", 0, 230,
             {180, 180, 220, 255}, true);

    drawText(renderer, Config::getFont(), "AI-ассистенты:", 0, 280,
             {255, 230, 150, 255}, true);
    drawText(renderer, Config::getFont(), "Claude, Copilot - Код", 0, 315,
             {200, 200, 255, 255}, true);
    drawText(renderer, Config::getFont(), "ChatGPT, DeepSeek - Идеи и ТЗ", 0, 345,
             {200, 200, 255, 255}, true);
    drawText(renderer, Config::getFont(), "Grok, Kimi - Тестирование", 0, 375,
             {200, 200, 255, 255}, true);
    drawText(renderer, Config::getFont(), "Open-Code Qwen - КАЛЛкодинг", 0, 405,
             {200, 200, 255, 255}, true);

    drawText(renderer, Config::getFont(), "Спрайты: Medieval King Pack 2 (luizmelo, itch.io)", 0, 460,
             {150, 150, 150, 255}, true);
    drawText(renderer, Config::getFont(), "SDL2 - Графическая библиотека", 0, 490,
             {150, 150, 150, 255}, true);
    drawButton(renderer, Config::getFont(), backBtn);
}

SceneType CreditsScene::getNextScene() {
    return nextScene;
}