#include "../utils/scene_manager.h"
#include "level_select_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"
#include <vector>

// Убрать весь класс LevelSelectScene { ... } и заменить на:

LevelSelectScene::LevelSelectScene() 
    : nextScene(SceneType::LEVEL_SELECT),
      soundMgr(getSoundManager()),
      backBtn(20, 20, 100, 50, "Назад"),
      diffBtn(20, Config::getWindowHeight() - 70, 250, 50, ""),
      resetBtn(Config::getWindowWidth() - 120, 20, 100, 50, "Сброс") {
    
    // Создаём кнопки уровней
    for (int i = 0; i < 3; i++) {
        levelBtns.push_back(Button(
            Config::getWindowWidth() / 2 - 75,
            550 - i * 150,
            150, 100,
            std::to_string(i + 1)
        ));
    }
}

void LevelSelectScene::handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) {
    // Обновляем текст кнопки сложности
    const Config::Difficulty* difficulties = Config::getDifficulties();
    diffBtn.text = difficulties[Config::getCurrentDifficulty()].name;
    
    // Обработка кнопки "Назад"
    backBtn.isHovered = backBtn.contains(mouseX, mouseY);
    if (backBtn.isHovered && !backBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    backBtn.wasHovered = backBtn.isHovered;
    
    if (backBtn.isHovered && mouseClicked) {
        if (soundMgr) soundMgr->playClick();
        nextScene = SceneType::MAIN_MENU;
    }
    
    // Обработка кнопки сложности
    diffBtn.isHovered = diffBtn.contains(mouseX, mouseY);
    if (diffBtn.isHovered && !diffBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    diffBtn.wasHovered = diffBtn.isHovered;
    
    if (diffBtn.isHovered && mouseClicked) {
        if (soundMgr) soundMgr->playClick();
        int newDiff = (Config::getCurrentDifficulty() + 1) % Config::getDifficultyCount();
        Config::setCurrentDifficulty(newDiff);
    }
    
    // Обработка кнопки сброса
    resetBtn.isHovered = resetBtn.contains(mouseX, mouseY);
    if (resetBtn.isHovered && !resetBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    resetBtn.wasHovered = resetBtn.isHovered;
    
    if (resetBtn.isHovered && mouseClicked) {
        if (soundMgr) soundMgr->playClick();
        Config::resetProgress();
    }
    
    // Обработка кнопок уровней
    for (size_t i = 0; i < levelBtns.size(); i++) {
        levelBtns[i].isHovered = levelBtns[i].contains(mouseX, mouseY);
        if (levelBtns[i].isHovered && !levelBtns[i].wasHovered && soundMgr) {
            soundMgr->playHover();
        }
        levelBtns[i].wasHovered = levelBtns[i].isHovered;
        
        if (levelBtns[i].isHovered && mouseClicked) {
            if (soundMgr) soundMgr->playClick();
            Config::setSelectedLevel(i); // Сохраняем выбранный уровень
            nextScene = SceneType::GAME; // TODO: передавать номер уровня
        }
    }
}

void LevelSelectScene::update(float deltaTime) {
    // Нет логики обновления
}

void LevelSelectScene::render(SDL_Renderer* renderer) {
    // Фон
    drawTowerBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 60);
    
    // Заголовок
    drawText(renderer, Config::getFont(), "Выбор уровня", 0, 50, 
             {255, 255, 255, 255}, true, Config::getTitleFont());
    
    // Кнопки
    drawButton(renderer, Config::getFont(), backBtn);
    drawButton(renderer, Config::getFont(), diffBtn);
    drawButton(renderer, Config::getFont(), resetBtn);
    
    // Кнопки уровней со звёздами
    for (size_t i = 0; i < levelBtns.size(); i++) {
        drawButton(renderer, Config::getFont(), levelBtns[i]);
        drawStars(renderer, 
                  levelBtns[i].rect.x + 35, 
                  levelBtns[i].rect.y + 110, 
                  Config::getLevelStars(i));
    }
}

SceneType LevelSelectScene::getNextScene() {
    return nextScene;
}