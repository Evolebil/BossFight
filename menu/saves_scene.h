#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"
#include <string>

class SoundManager;

class SavesScene : public Scene {
private:
    // ========== КОНСТАНТЫ ==========
    static constexpr int BACK_BTN_X = 20;
    static constexpr int BACK_BTN_Y = 20;
    static constexpr int BACK_BTN_W = 100;
    static constexpr int BACK_BTN_H = 50;

    static constexpr int PLUS_BTN_W = 300;
    static constexpr int PLUS_BTN_H = 60;
    static constexpr int PLUS_BTN_Y = 180;

    static constexpr int INPUT_W = 400;
    static constexpr int INPUT_H = 50;
    static constexpr int INPUT_Y = 300;

    static constexpr int OVERLAY_ALPHA = 80;
    static constexpr int TITLE_Y       = 80;
    static constexpr int MESSAGE_Y     = 250;

    static constexpr int MAX_NAME_LENGTH = 16;   // лимит символов в имени

    // ========== ПОЛЯ С ДЕФОЛТАМИ ==========
    SceneType nextScene = SceneType::SAVES;
    SoundManager* soundMgr = nullptr;
    Button backBtn{BACK_BTN_X, BACK_BTN_Y, BACK_BTN_W, BACK_BTN_H, "Назад"};
    Button plusBtn{0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+"};

    bool isInputVisible = false;
    bool isInputFocused = false;
    std::string inputText = "";
    SDL_Rect inputRect{0, INPUT_Y, INPUT_W, INPUT_H};

public:
    SavesScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY,
                     bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;

private:
    void closeInput(bool accept);
    bool isPointInRect(int x, int y, const SDL_Rect& rect) const;
};