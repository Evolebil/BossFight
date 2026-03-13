#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"

class SoundManager;

class MainMenuScene : public Scene {
private:
    SceneType nextScene;
    SoundManager* soundMgr;
    Button playBtn;
    Button settingsBtn;
    Button creditsBtn;
    Button quitBtn;
public:
    MainMenuScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};