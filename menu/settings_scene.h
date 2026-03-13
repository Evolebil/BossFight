#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"
#include <vector>
#include "splash_scene.h"

class SoundManager;

class SettingsScene : public Scene {
private:
    SceneType nextScene;
    SoundManager* soundMgr;
    int activeSlider;
    SDL_Scancode* keyBeingRebound;
    int* mouseButtonBeingRebound;
    float tempBrightness;
    float tempSoundVolume;
    float tempMusicVolume;
    float tempSensitivity;
    Slider brightnessSlider;
    Slider soundSlider;
    Slider musicSlider;
    Slider sensitivitySlider;
    Button backBtn;
    struct ControlButton {
        std::string label;
        SDL_Scancode* key;
        int* mouseBtn;
        SDL_Rect rect;
        bool isHovered;
        bool wasHovered;
    };
    std::vector<ControlButton> controlButtons;
public:
    SettingsScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};