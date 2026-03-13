#pragma once
#include "../utils/scene_manager.h"

// Forward declaration
class SoundManager;

class SplashScene : public Scene {
private:
    float splashTime;
    SceneType nextScene;
    SoundManager* soundMgr;
public:
    SplashScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};