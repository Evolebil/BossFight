#include "scene_manager.h"
#include "../menu/splash_scene.h"
#include "../menu/main_menu_scene.h"
#include "../menu/level_select_scene.h"
#include "../menu/settings_scene.h"
#include "../menu/credits_scene.h"
#include "../menu/game_scene.h"
#include "../config/common.h"
#include "../menu/saves_scene.h"

SceneManager::SceneManager(SDL_Renderer* rend)
    : currentScene(nullptr), currentSceneType(SceneType::SPLASH), renderer(rend) {}

void SceneManager::loadScene(SceneType type) {
    // Старую сцену удаляем ДО создания новой: GameScene в конструкторе
    // перезаписывает глобальные указатели (g_currentLevel, g_camera, …),
    // а деструктор старой их обнуляет
    currentScene.reset();

    // Создаём новую сцену
    switch(type) {
    case SceneType::SPLASH:
        currentScene = std::make_unique<SplashScene>();
        break;

    case SceneType::MAIN_MENU:
        currentScene = std::make_unique<MainMenuScene>();
        break;

    case SceneType::LEVEL_SELECT:
        currentScene = std::make_unique<LevelSelectScene>();
        break;

    case SceneType::SETTINGS:
        currentScene = std::make_unique<SettingsScene>();
        break;

    case SceneType::CREDITS:
        currentScene = std::make_unique<CreditsScene>();
        break;
    case SceneType::SAVES:
        currentScene = std::make_unique<SavesScene>();
        break;

    case SceneType::GAME:
    case SceneType::RESTART_GAME:
        currentScene = std::make_unique<GameScene>();
        // Оба случая живут под типом GAME — чтобы следующий RESTART_GAME снова сработал
        currentSceneType = SceneType::GAME;
        return;

    case SceneType::QUIT:
        break;
    }

    currentSceneType = type;
}

void SceneManager::handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) {
    if (currentScene) {
        currentScene->handleInput(event, mouseX, mouseY, mouseClicked, mouseDown);
    }
}

void SceneManager::update(float deltaTime) {
    if (currentScene) {
        currentScene->update(deltaTime);

        // Проверяем, нужно ли переключить сцену
        SceneType nextScene = currentScene->getNextScene();
        if (nextScene != currentSceneType) {
            loadScene(nextScene);
        }
    }
}

void SceneManager::render() {
    if (currentScene) {
        currentScene->render(renderer);
    }
}
