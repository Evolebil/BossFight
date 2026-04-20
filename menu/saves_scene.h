/**
 * @file saves_scene.h
 * @brief Экран сохранений
 * @author evol
 * @date 2026-04-21
 */
#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"
#include "../utils/save_manager.h"

class SoundManager;

class SavesScene : public Scene {
private:
    // ========== КОНСТАНТЫ ==========
    static constexpr int BACK_BTN_X = 20;//это один из размеров кнопки
    static constexpr int BACK_BTN_Y = 20;
    static constexpr int BACK_BTN_W = 100;
    static constexpr int BACK_BTN_H = 50;

    static constexpr int PLUS_BTN_W       = 300;
    static constexpr int PLUS_BTN_H       = 60;
    static constexpr int PLUS_BTN_Y       = 180;
    static constexpr int PLUS_BTN_COLUMNS = 3;
    static constexpr int PLUS_BTN_GAP_X   = 20;
    static constexpr int PLUS_BTN_ROW_GAP_Y = 20;

    static constexpr int INPUT_W    = 400;
    static constexpr int INPUT_H    = 50;
    static constexpr int INPUT_Y    = 300;

    static constexpr int OVERLAY_ALPHA  = 80;
    static constexpr int TITLE_Y        = 80;
    static constexpr int MESSAGE_Y      = 140;  // ← чуть выше кнопок

    static constexpr int MAX_NAME_LENGTH = 16;
    static constexpr int MAX_SAVES       = 12;

    // Константы меню действий
    static constexpr int MENU_BTN_W   = 300;
    static constexpr int MENU_BTN_H   = 60;
    static constexpr int MENU_BTN_GAP = 20;
    static constexpr int MENU_START_Y = 200;

    // ========== ПОЛЯ ==========
    SceneType     nextScene = SceneType::SAVES;
    SoundManager* soundMgr  = nullptr;

    Button backBtn{BACK_BTN_X, BACK_BTN_Y, BACK_BTN_W, BACK_BTN_H, "Назад"};

    // Кнопки слотов:
    //   Именованные слоты берём из SaveManager::get().getEntries()
    //   Последняя кнопка — "+" для нового сохранения (если < MAX_SAVES)
    std::vector<Button> slotButtons;
    // true = кнопка "+" (новый слот), false = именованный слот
    std::vector<bool>   slotIsNew;

    int activePlusIndex = -1;

    bool        isInputVisible = false;
    bool        isInputFocused = false;
    std::string inputText;
    SDL_Rect    inputRect{0, INPUT_Y, INPUT_W, INPUT_H};

    // Меню действий для именованной кнопки
    bool              isMenuVisible   = false;
    int               menuTargetIndex = -1;
    std::vector<Button> menuButtons;

public:
    SavesScene();
    void handleInput(SDL_Event& event, int mouseX, int mouseY,
                     bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;

private:
    // Строит slotButtons из SaveManager + кнопка "+"
    void rebuildSlots();
    void rebuildButtonsLayout();

    void closeInput(bool accept);
    void openInputForButton(int index);

    [[nodiscard]] bool isPointInRect(int x, int y, const SDL_Rect& rect) const;
};