#pragma once
#include "../config/common.h"
// Типы сцен

// Базовый класс для всех сцен
class Scene {
public:
    virtual ~Scene() = default;
    
    // Обработка ввода
    virtual void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) = 0;
    
    // Обновление логики
    virtual void update(float deltaTime) = 0;
    
    // Отрисовка
    virtual void render(SDL_Renderer* renderer) = 0;
    
    // Получить следующую сцену (если нужно переключиться)
    virtual SceneType getNextScene() = 0;
};

// Менеджер сцен
class SceneManager {
private:
    Scene* currentScene;
    SceneType currentSceneType;
    SDL_Renderer* renderer;
    
public:
    SceneManager(SDL_Renderer* rend);
    ~SceneManager();
    
    // Загрузить новую сцену
    void loadScene(SceneType type);
    
    // Обработка событий
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown);
    
    // Обновление
    void update(float deltaTime);
    
    // Отрисовка
    void render();
    
    // Проверка на выход
    bool shouldQuit() { return currentSceneType == SceneType::QUIT; }
};
