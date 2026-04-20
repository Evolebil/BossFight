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
    // Диалог "Загрузить / Новая игра"
    bool              showLoadDialog = false;
    int               dialogLevel    = -1;       // какой уровень нажали
    Button            loadBtn;
    Button            newGameBtn;
    Button            cancelBtn;
    [[nodiscard]] bool hasSaveForLevel(int levelIndex) const;
public:
    LevelSelectScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};