/**
 * @file main_menu_scene.cpp
 * @brief Реализация главного меню
 * @author evol
 * @date 2026-02-20
 */
#include "../utils/scene_manager.h"
#include "main_menu_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"

MainMenuScene::MainMenuScene()
    : nextScene(SceneType::MAIN_MENU),
    soundMgr(getSoundManager()),
    playBtn    (0, 250, 300, 60, "Играть"),
    settingsBtn(0, 330, 300, 60, "Настройки"),
    creditsBtn (0, 410, 300, 60, "Разработчики"),
    savesBtn   (0, 490, 300, 60, "Сохранения"),
    quitBtn    (0, 570, 300, 60, "Выход") {

    const int W = Config::getWindowWidth();
    playBtn.centerX(W);
    settingsBtn.centerX(W);
    creditsBtn.centerX(W);
    savesBtn.centerX(W);
    quitBtn.centerX(W);
}

void MainMenuScene::handleInput(SDL_Event& /*event*/, int mx, int my,
                                bool clicked, bool /*mouseDown*/) {
    // updateButton возвращает true если кликнули — сразу меняем сцену
    if (updateButton(playBtn,     mx, my, clicked, soundMgr)) nextScene = SceneType::LEVEL_SELECT;
    if (updateButton(settingsBtn, mx, my, clicked, soundMgr)) nextScene = SceneType::SETTINGS;
    if (updateButton(creditsBtn,  mx, my, clicked, soundMgr)) nextScene = SceneType::CREDITS;
    if (updateButton(savesBtn, mx, my, clicked, soundMgr)) nextScene = SceneType::SAVES;
    if (updateButton(quitBtn,     mx, my, clicked, soundMgr)) nextScene = SceneType::QUIT;
}

void MainMenuScene::update(float /*deltaTime*/) {}

void MainMenuScene::render(SDL_Renderer* renderer) {
    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 80);
    drawText(renderer, Config::getFont(), "BOSS FIGHT", 0, 80,
             {255, 230, 150, 255}, true, Config::getTitleFont());
    drawButton(renderer, Config::getFont(), playBtn);
    drawButton(renderer, Config::getFont(), settingsBtn);
    drawButton(renderer, Config::getFont(), creditsBtn);
    drawButton(renderer, Config::getFont(), savesBtn);
    drawButton(renderer, Config::getFont(), quitBtn);
}

SceneType MainMenuScene::getNextScene() {
    return nextScene;
}