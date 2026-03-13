#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"

class SoundManager;

class CreditsScene : public Scene {
private:
    SceneType nextScene;
    SoundManager* soundMgr;
    Button backBtn;
public:
    CreditsScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};
