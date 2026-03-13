#include "../utils/scene_manager.h"
#include "main_menu_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"
#include <iostream>

// Убрать весь класс MainMenuScene { ... } и заменить на:

MainMenuScene::MainMenuScene() 
    : nextScene(SceneType::MAIN_MENU), 
      soundMgr(getSoundManager()),
      playBtn(0, 250, 300, 60, "Играть"),
      settingsBtn(0, 330, 300, 60, "Настройки"),
      creditsBtn(0, 410, 300, 60, "Разработчики"),
      quitBtn(0, 490, 300, 60, "Выход") {
    
    // Центрируем кнопки
    playBtn.centerX(Config::getWindowWidth());
    settingsBtn.centerX(Config::getWindowWidth());
    creditsBtn.centerX(Config::getWindowWidth());
    quitBtn.centerX(Config::getWindowWidth());
}

void MainMenuScene::handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) {
    // Обновляем состояние наведения
    playBtn.isHovered = playBtn.contains(mouseX, mouseY);
    settingsBtn.isHovered = settingsBtn.contains(mouseX, mouseY);
    creditsBtn.isHovered = creditsBtn.contains(mouseX, mouseY);
    quitBtn.isHovered = quitBtn.contains(mouseX, mouseY);
    
    // Звуки наведения
    if (playBtn.isHovered && !playBtn.wasHovered) {
        if (soundMgr) {
            soundMgr->playHover();
        } else {
            std::cout << "WARNING: soundMgr is NULL in MainMenu!" << std::endl;
        }
    }
    playBtn.wasHovered = playBtn.isHovered;
    
    if (settingsBtn.isHovered && !settingsBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    settingsBtn.wasHovered = settingsBtn.isHovered;
    
    if (creditsBtn.isHovered && !creditsBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    creditsBtn.wasHovered = creditsBtn.isHovered;
    
    if (quitBtn.isHovered && !quitBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    quitBtn.wasHovered = quitBtn.isHovered;
    
    // Обработка кликов
    if (mouseClicked) {
        if (playBtn.isHovered) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::LEVEL_SELECT;
        }
        else if (settingsBtn.isHovered) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::SETTINGS;
        }
        else if (creditsBtn.isHovered) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::CREDITS;
        }
        else if (quitBtn.isHovered) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::QUIT;
        }
    }
}

void MainMenuScene::update(float deltaTime) {
    // Нет логики обновления
}

void MainMenuScene::render(SDL_Renderer* renderer) {
    // Фон
    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 80);
    
    // Заголовок
    drawText(renderer, Config::getFont(), "BOSS FIGHT", 0, 80, 
             {255, 230, 150, 255}, true, Config::getTitleFont());
    
    // Кнопки
    drawButton(renderer, Config::getFont(), playBtn);
    drawButton(renderer, Config::getFont(), settingsBtn);
    drawButton(renderer, Config::getFont(), creditsBtn);
    drawButton(renderer, Config::getFont(), quitBtn);
}

SceneType MainMenuScene::getNextScene() {
    return nextScene;
}