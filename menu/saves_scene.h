#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"

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
    static constexpr int PLUS_BTN_COLUMNS = 3;
    static constexpr int PLUS_BTN_GAP_X = 20;        // расстояние между кнопками по X
    static constexpr int PLUS_BTN_ROW_GAP_Y = 20;    // зазор между рядами по Y

    // Константы для меню действий
    static constexpr int MENU_BTN_W = 300;
    static constexpr int MENU_BTN_H = 60;
    static constexpr int MENU_BTN_GAP = 20;        // расстояние между кнопками по вертикали
    static constexpr int MENU_START_Y = 200;       // Y первой кнопки

    // ========== ПОЛЯ С ДЕФОЛТАМИ ==========
    SceneType nextScene = SceneType::SAVES;
    SoundManager* soundMgr = nullptr;
    Button backBtn{BACK_BTN_X, BACK_BTN_Y, BACK_BTN_W, BACK_BTN_H, "Назад"};
    std::vector<Button> slotButtons; // заполненные имена + активный "+" (всегда последняя)
    std::vector<bool> slotIsNew;   // true = кнопка-плюс (ещё не переименована)
    int activePlusIndex = -1;         // индекс кнопки "+" для текущего инпута

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
    void openInputForButton(int index);
    void rebuildButtonsLayout();
    bool isPointInRect(int x, int y, const SDL_Rect& rect) const;

    // Меню для именованных кнопок
    bool isMenuVisible = false;
    int menuTargetIndex = -1;                // индекс кнопки, для которой открыто меню
    std::vector<Button> menuButtons;         // 4 кнопки: Сохранить, Загрузить, Удалить, Переименовать
};