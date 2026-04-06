#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"
#include "../config/config.h"

class SoundManager;

class LevelSelectScene : public Scene {
private:
    SceneType nextScene;
    SoundManager* soundMgr;
    Button backBtn;
    Button diffBtn;
    Button resetBtn;
    std::vector<Button> levelBtns;
public:
    LevelSelectScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};