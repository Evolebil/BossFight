/**
 * @file settings_scene.h
 * @brief Экран настроек — вкладки: Управление / Видео / Аудио
 * @author evol
 * @date 2026-02-20
 */
#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"
#include "../config/config.h"
#include "splash_scene.h"

class SoundManager;

enum class SettingsTab { CONTROLS, VIDEO, AUDIO };

class SettingsScene : public Scene {
private:
    SceneType     nextScene;
    SoundManager* soundMgr;
    int           activeSlider;
    SDL_Scancode* keyBeingRebound;
    int*          mouseButtonBeingRebound;

    SettingsTab currentTab = SettingsTab::CONTROLS;

    float tempSoundVolume;
    float tempMusicVolume;

    // Вкладка "Аудио"
    Slider soundSlider;
    Slider musicSlider;

    // Вкладка "Видео"
    Button fullscreenBtn;
    Button resolutionBtn;

    Button backBtn;
    Button tabControlsBtn;
    Button tabVideoBtn;
    Button tabAudioBtn;

    struct ControlButton {
        std::string   label;
        SDL_Scancode* key;      // nullptr если управляется мышью
        int*          mouseBtn; // nullptr если управляется клавишей
        SDL_Rect      rect;
        bool          isHovered;
        bool          wasHovered;
    };
    std::vector<ControlButton> controlButtons;

    // "Ближняя атака" — единственная кнопка с гибкой привязкой
    // (клавиатура ИЛИ мышь, Config::InputBinding), поэтому обрабатывается
    // отдельно от controlButtons (там тип привязки фиксирован заранее).
    SDL_Rect attackBtnRect{};
    bool     attackBtnHovered     = false;
    bool     attackBtnWasHovered  = false;
    bool     waitingForAttackBind = false;

public:
    SettingsScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY,
                     bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;
};