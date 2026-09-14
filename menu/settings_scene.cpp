/**
 * @file settings_scene.cpp
 * @brief Реализация экрана настроек с вкладками
 * @author evol
 * @date 2026-02-20
 */
#include "../utils/scene_manager.h"
#include "settings_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"
#include "../utils/texture_manager.h"

// ============================================================
// КОНСТАНТЫ РАСКЛАДКИ
// ============================================================

namespace {
constexpr int TAB_BTN_W   = 200;
constexpr int TAB_BTN_H   = 50;
constexpr int TAB_BTN_Y   = 120;
constexpr int TAB_BTN_GAP = 20;

// Вкладка "Управление"
constexpr int CONTROLS_LABEL_Y = 185;
constexpr int CONTROLS_BTN_W   = 300;
constexpr int CONTROLS_BTN_H   = 32;
constexpr int CONTROLS_BTN_GAP = 6;
constexpr int CONTROLS_START_Y = 215;
constexpr int WAITING_HINT_Y   = 685;

// Вкладка "Видео"
constexpr int VIDEO_BTN_W       = 300;
constexpr int VIDEO_BTN_H       = 60;
constexpr int VIDEO_FULLSCREEN_Y = 250;
constexpr int VIDEO_RESOLUTION_Y = 340;

// Вкладка "Аудио"
constexpr int SLIDER_W       = 400;
constexpr int SOUND_SLIDER_Y = 260;
constexpr int MUSIC_SLIDER_Y = 380;
}

// ============================================================
// КОНСТРУКТОР
// ============================================================

SettingsScene::SettingsScene()
    : nextScene(SceneType::SETTINGS),
    soundMgr(getSoundManager()),
    activeSlider(-1),
    keyBeingRebound(nullptr),
    mouseButtonBeingRebound(nullptr),
    tempSoundVolume(Config::getSoundVolume()),
    tempMusicVolume(Config::getMusicVolume()),
    soundSlider(0, SOUND_SLIDER_Y, SLIDER_W, "Звук",   &tempSoundVolume, 1),
    musicSlider(0, MUSIC_SLIDER_Y, SLIDER_W, "Музыка", &tempMusicVolume, 2),
    fullscreenBtn(0, VIDEO_FULLSCREEN_Y, VIDEO_BTN_W, VIDEO_BTN_H, "Полный экран"),
    resolutionBtn(0, VIDEO_RESOLUTION_Y, VIDEO_BTN_W, VIDEO_BTN_H, ""),
    backBtn(20, 20, 100, 50, "Назад"),
    tabControlsBtn(0, TAB_BTN_Y, TAB_BTN_W, TAB_BTN_H, "Управление"),
    tabVideoBtn   (0, TAB_BTN_Y, TAB_BTN_W, TAB_BTN_H, "Видео"),
    tabAudioBtn   (0, TAB_BTN_Y, TAB_BTN_W, TAB_BTN_H, "Аудио") {

    const int W = Config::getWindowWidth();

    soundSlider.track.x = (W - SLIDER_W) / 2; soundSlider.updateHandle();
    musicSlider.track.x = (W - SLIDER_W) / 2; musicSlider.updateHandle();

    fullscreenBtn.centerX(W);
    resolutionBtn.centerX(W);

    const int totalTabsW = 3 * TAB_BTN_W + 2 * TAB_BTN_GAP;
    const int tabsStartX = (W - totalTabsW) / 2;
    tabControlsBtn.rect.x = tabsStartX;
    tabVideoBtn.rect.x    = tabsStartX + (TAB_BTN_W + TAB_BTN_GAP);
    tabAudioBtn.rect.x    = tabsStartX + 2 * (TAB_BTN_W + TAB_BTN_GAP);

    Config::Controls& ctrl = Config::getControls();

    const int cbX = (W - CONTROLS_BTN_W) / 2;
    int y = CONTROLS_START_Y;
    auto nextY = [&]() { int v = y; y += CONTROLS_BTN_H + CONTROLS_BTN_GAP; return v; };

    // "Взаимодействие" убрано из списка (не используется в геймплее).
    // "Чувствительность" убрана целиком — не влияла ни на что в игре.
    controlButtons = {
                       {"Прыжок",     &ctrl.jump,       nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Влево",      &ctrl.left,       nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Вправо",     &ctrl.right,      nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Пригнуться", &ctrl.crouch,     nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Рывок",      &ctrl.dash,       nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Щит",        &ctrl.shield,     nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Заново",     &ctrl.restart,    nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Сохранить",  &ctrl.quickSave,  nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Загрузить",  &ctrl.quickLoad,  nullptr, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       {"Магия",      nullptr, &ctrl.magicMouseButton, {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H}, false, false},
                       };

    attackBtnRect = {cbX, nextY(), CONTROLS_BTN_W, CONTROLS_BTN_H};
}

// ============================================================
// ВВОД
// ============================================================

void SettingsScene::handleInput(SDL_Event& event, int mx, int my,
                                bool clicked, bool mouseDown) {
    // Ожидание бинда для атаки (двойной тип — клавиша ИЛИ мышь) — проверяем первым
    if (waitingForAttackBind) {
        Config::Controls& ctrl = Config::getControls();
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            ctrl.attackBinding.isMouse     = true;
            ctrl.attackBinding.mouseButton = event.button.button;
            waitingForAttackBind = false;
            if (soundMgr) soundMgr->playClick();
            return;
        }
        if (event.type == SDL_KEYDOWN) {
            ctrl.attackBinding.isMouse = false;
            ctrl.attackBinding.key     = event.key.keysym.scancode;
            waitingForAttackBind = false;
            if (soundMgr) soundMgr->playClick();
            return;
        }
    }

    // Переназначение кнопки мыши (для фиксированных пунктов вроде "Магии")
    if (mouseButtonBeingRebound && event.type == SDL_MOUSEBUTTONDOWN) {
        *mouseButtonBeingRebound = event.button.button;
        if (soundMgr) soundMgr->playClick();
        mouseButtonBeingRebound = nullptr;
        keyBeingRebound         = nullptr;
        return;
    }

    // Переназначение клавиши
    if (keyBeingRebound && event.type == SDL_KEYDOWN) {
        *keyBeingRebound = event.key.keysym.scancode;
        if (soundMgr) soundMgr->playClick();
        keyBeingRebound         = nullptr;
        mouseButtonBeingRebound = nullptr;
        return;
    }

    // Кнопка "Назад"
    if (updateButton(backBtn, mx, my, clicked, soundMgr)) {
        keyBeingRebound         = nullptr;
        mouseButtonBeingRebound = nullptr;
        waitingForAttackBind    = false;
        nextScene = SceneType::MAIN_MENU;
        return;
    }

    // Переключение вкладок — отменяет любое незавершённое ожидание ввода
    if (updateButton(tabControlsBtn, mx, my, clicked, soundMgr)) {
        currentTab = SettingsTab::CONTROLS;
        keyBeingRebound = nullptr; mouseButtonBeingRebound = nullptr; waitingForAttackBind = false;
    }
    if (updateButton(tabVideoBtn, mx, my, clicked, soundMgr)) {
        currentTab = SettingsTab::VIDEO;
        keyBeingRebound = nullptr; mouseButtonBeingRebound = nullptr; waitingForAttackBind = false;
    }
    if (updateButton(tabAudioBtn, mx, my, clicked, soundMgr)) {
        currentTab = SettingsTab::AUDIO;
        keyBeingRebound = nullptr; mouseButtonBeingRebound = nullptr; waitingForAttackBind = false;
    }

    if (!mouseDown) activeSlider = -1;

    if (currentTab == SettingsTab::CONTROLS) {
        for (auto& cb : controlButtons) {
            cb.isHovered = mx >= cb.rect.x && mx <= cb.rect.x + cb.rect.w &&
                           my >= cb.rect.y && my <= cb.rect.y + cb.rect.h;
            if (cb.isHovered && clicked) {
                if (soundMgr) soundMgr->playClick();
                if (cb.mouseBtn) {
                    mouseButtonBeingRebound = cb.mouseBtn;
                    keyBeingRebound         = nullptr;
                } else {
                    keyBeingRebound         = cb.key;
                    mouseButtonBeingRebound = nullptr;
                }
            }
        }

        attackBtnHovered = mx >= attackBtnRect.x && mx <= attackBtnRect.x + attackBtnRect.w &&
                           my >= attackBtnRect.y && my <= attackBtnRect.y + attackBtnRect.h;
        if (attackBtnHovered && clicked) {
            if (soundMgr) soundMgr->playClick();
            waitingForAttackBind   = true;
            keyBeingRebound         = nullptr;
            mouseButtonBeingRebound = nullptr;
        }

    } else if (currentTab == SettingsTab::VIDEO) {
        if (updateButton(fullscreenBtn, mx, my, clicked, soundMgr)) {
            Config::toggleFullscreen(g_gameWindow);
        }
        if (updateButton(resolutionBtn, mx, my, clicked, soundMgr)) {
            int nextIdx = (Config::getResolutionIndex() + 1) % Config::getResolutionPresetCount();
            Config::setResolutionIndex(nextIdx);
            Config::applyWindowResize(g_gameWindow, TextureManager::getRenderer());
        }

    } else if (currentTab == SettingsTab::AUDIO) {
        if (soundSlider.isDragging) activeSlider = soundSlider.id;
        if (musicSlider.isDragging) activeSlider = musicSlider.id;
        soundSlider.update(mx, my, mouseDown, activeSlider);
        musicSlider.update(mx, my, mouseDown, activeSlider);

        Config::setSoundVolume(tempSoundVolume);
        Config::setMusicVolume(tempMusicVolume);
        if (soundMgr) {
            soundMgr->soundVolume = Config::getSoundVolume();
            soundMgr->musicVolume = Config::getMusicVolume();
        }
    }
}

void SettingsScene::update(float /*deltaTime*/) {}

// ============================================================
// ОТРИСОВКА
// ============================================================

void SettingsScene::render(SDL_Renderer* renderer) {
    if (!soundSlider.isDragging) tempSoundVolume = Config::getSoundVolume();
    if (!musicSlider.isDragging) tempMusicVolume = Config::getMusicVolume();

    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 100);
    drawText(renderer, Config::getFont(), "Настройки", 0, 50,
             {255, 255, 255, 255}, true, Config::getTitleFont());

    drawButton(renderer, Config::getFont(), tabControlsBtn);
    drawButton(renderer, Config::getFont(), tabVideoBtn);
    drawButton(renderer, Config::getFont(), tabAudioBtn);

    if (currentTab == SettingsTab::CONTROLS) {
        drawText(renderer, Config::getFont(), "Управление (клик для изменения):",
                 0, CONTROLS_LABEL_Y, {200, 200, 200, 255}, true);

        auto mouseButtonName = [](int btn) -> std::string {
            switch (btn) {
            case 1:  return "ЛКМ";
            case 2:  return "СКМ";
            case 3:  return "ПКМ";
            default: return "Кн." + std::to_string(btn);
            }
        };

        for (const auto& cb : controlButtons) {
            const bool isWaiting = (mouseButtonBeingRebound == cb.mouseBtn && cb.mouseBtn) ||
                                   (keyBeingRebound == cb.key && !cb.mouseBtn);

            SDL_SetRenderDrawColor(renderer,
                                   isWaiting ? 255 : (cb.isHovered ? 100 : 60),
                                   isWaiting ? 200 : (cb.isHovered ? 150 : 80),
                                   isWaiting ?   0 : (cb.isHovered ? 220 : 120),
                                   200);
            SDL_RenderFillRect(renderer, &cb.rect);
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderDrawRect(renderer, &cb.rect);

            std::string keyText;
            if (isWaiting)        keyText = "...";
            else if (cb.mouseBtn) keyText = mouseButtonName(*cb.mouseBtn);
            else                  keyText = getKeyName(*cb.key);

            drawText(renderer, Config::getFont(),
                     cb.label + ": " + keyText,
                     cb.rect.x + 10, cb.rect.y + (cb.rect.h - 20) / 2);
        }

        // "Ближняя атака" — отдельная кнопка с гибкой привязкой
        {
            const Config::Controls& ctrlConst = Config::getControls();
            SDL_SetRenderDrawColor(renderer,
                                   waitingForAttackBind ? 255 : (attackBtnHovered ? 100 : 60),
                                   waitingForAttackBind ? 200 : (attackBtnHovered ? 150 : 80),
                                   waitingForAttackBind ?   0 : (attackBtnHovered ? 220 : 120),
                                   200);
            SDL_RenderFillRect(renderer, &attackBtnRect);
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderDrawRect(renderer, &attackBtnRect);

            std::string valueText;
            if (waitingForAttackBind)          valueText = "...";
            else if (ctrlConst.attackBinding.isMouse) valueText = mouseButtonName(ctrlConst.attackBinding.mouseButton);
            else                                       valueText = getKeyName(ctrlConst.attackBinding.key);

            drawText(renderer, Config::getFont(),
                     "Ближняя атака: " + valueText,
                     attackBtnRect.x + 10, attackBtnRect.y + (attackBtnRect.h - 20) / 2);
        }

        if (keyBeingRebound || mouseButtonBeingRebound || waitingForAttackBind) {
            drawText(renderer, Config::getFont(),
                     "Нажмите клавишу или кнопку мыши...",
                     0, WAITING_HINT_Y, {255, 200, 0, 255}, true);
        }

    } else if (currentTab == SettingsTab::VIDEO) {
        fullscreenBtn.text = Config::getIsFullscreen() ? "Полный экран: Вкл" : "Полный экран: Выкл";
        drawButton(renderer, Config::getFont(), fullscreenBtn);

        int rw, rh;
        Config::getResolutionPreset(Config::getResolutionIndex(), rw, rh);
        resolutionBtn.text = "Разрешение: " + std::to_string(rw) + "x" + std::to_string(rh);
        drawButton(renderer, Config::getFont(), resolutionBtn);

    } else if (currentTab == SettingsTab::AUDIO) {
        drawSlider(renderer, Config::getFont(), soundSlider, soundMgr);
        drawSlider(renderer, Config::getFont(), musicSlider, soundMgr);
    }

    drawButton(renderer, Config::getFont(), backBtn);
}

SceneType SettingsScene::getNextScene() {
    return nextScene;
}