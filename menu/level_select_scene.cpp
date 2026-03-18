/**
 * @file level_select_scene.cpp
 * @brief Реализация экрана выбора уровня и сложности
 * @author evol
 * @date 2026-02-20
 */
#include "../utils/scene_manager.h"
#include "level_select_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"

LevelSelectScene::LevelSelectScene()
    : nextScene(SceneType::LEVEL_SELECT),
    soundMgr(getSoundManager()),
    backBtn (20, 20, 100, 50, "Назад"),
    diffBtn (20, Config::getWindowHeight() - 70, 250, 50, ""),
    resetBtn(Config::getWindowWidth() - 120, 20, 100, 50, "Сброс") {

    const int W = Config::getWindowWidth();
    for (int i = 0; i < 3; i++) {
        levelBtns.push_back(Button(
            W / 2 - 75,
            550 - i * 150,
            150, 100,
            std::to_string(i + 1)
            ));
    }
}

void LevelSelectScene::handleInput(SDL_Event& /*event*/, int mx, int my,
                                   bool clicked, bool /*mouseDown*/) {
    // Обновляем текст кнопки сложности перед обработкой
    diffBtn.text = Config::getDifficulties()[Config::getCurrentDifficulty()].name;

    if (updateButton(backBtn,  mx, my, clicked, soundMgr)) nextScene = SceneType::MAIN_MENU;
    if (updateButton(resetBtn, mx, my, clicked, soundMgr)) Config::resetProgress();

    if (updateButton(diffBtn, mx, my, clicked, soundMgr)) {
        int newDiff = (Config::getCurrentDifficulty() + 1) % Config::getDifficultyCount();
        Config::setCurrentDifficulty(newDiff);
    }

    for (size_t i = 0; i < levelBtns.size(); i++) {
        if (updateButton(levelBtns[i], mx, my, clicked, soundMgr)) {
            Config::setSelectedLevel(static_cast<int>(i));
            nextScene = SceneType::GAME;
        }
    }
}

void LevelSelectScene::update(float /*deltaTime*/) {}

void LevelSelectScene::render(SDL_Renderer* renderer) {
    drawTowerBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 60);
    drawText(renderer, Config::getFont(), "Выбор уровня", 0, 50,
             {255, 255, 255, 255}, true, Config::getTitleFont());

    drawButton(renderer, Config::getFont(), backBtn);
    drawButton(renderer, Config::getFont(), diffBtn);
    drawButton(renderer, Config::getFont(), resetBtn);

    for (size_t i = 0; i < levelBtns.size(); i++) {
        drawButton(renderer, Config::getFont(), levelBtns[i]);
        drawStars(renderer,
                  levelBtns[i].rect.x + 35,
                  levelBtns[i].rect.y + 110,
                  Config::getLevelStars(static_cast<int>(i)));
    }
}

SceneType LevelSelectScene::getNextScene() {
    return nextScene;
}