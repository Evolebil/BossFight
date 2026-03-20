/**
 * @file settings_scene.cpp
 * @brief Реализация экрана настроек
 * @author evol
 * @date 2026-02-20
 */
#include "../utils/scene_manager.h"
#include "settings_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"

SettingsScene::SettingsScene()
    : nextScene(SceneType::SETTINGS),
    soundMgr(getSoundManager()),
    activeSlider(-1),
    keyBeingRebound(nullptr),
    mouseButtonBeingRebound(nullptr),
    tempBrightness (Config::getBrightness()),
    tempSoundVolume(Config::getSoundVolume()),
    tempMusicVolume(Config::getMusicVolume()),
    tempSensitivity(Config::getSensitivity()),
    brightnessSlider  (350, 150, 400, "Яркость",         &tempBrightness,  0),
    soundSlider       (350, 250, 400, "Звук",             &tempSoundVolume, 1),
    musicSlider       (350, 350, 400, "Музыка",           &tempMusicVolume, 2),
    sensitivitySlider (350, 450, 400, "Чувствительность", &tempSensitivity, 3),
    backBtn(20, 20, 100, 50, "Назад") {

    Config::Controls& ctrl = Config::getControls();

    // Кнопки управления — теперь включают дэш, щит и магию
    // Кнопки только-мышь: mouseBtn указан, key = nullptr (фиктивный)
    controlButtons = {
                       // Клавиатура
                       {"Прыжок",         &ctrl.jump,     nullptr,               {850, 155, 250, 35}, false, false},
                       {"Влево",          &ctrl.left,     nullptr,               {850, 195, 250, 35}, false, false},
                       {"Вправо",         &ctrl.right,    nullptr,               {850, 235, 250, 35}, false, false},
                       {"Пригнуться",     &ctrl.crouch,   nullptr,               {850, 275, 250, 35}, false, false},
                       {"Взаимодействие", &ctrl.interact, nullptr,               {850, 315, 250, 35}, false, false},
                       {"Рывок",          &ctrl.dash,     nullptr,               {850, 355, 250, 35}, false, false},
                       {"Щит",            &ctrl.shield,   nullptr,               {850, 395, 250, 35}, false, false},
                       // Мышь
                       {"Ближняя атака",  &ctrl.attack,   &ctrl.attackMouseButton, {850, 435, 250, 35}, false, false},
                       {"Магия",          &ctrl.attack,   &ctrl.magicMouseButton,  {850, 475, 250, 35}, false, false},
                       };
}

void SettingsScene::handleInput(SDL_Event& event, int mx, int my,
                                bool clicked, bool mouseDown) {
    // Переназначение кнопки мыши
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

    // Слайдеры
    if (!mouseDown) activeSlider = -1;
    std::array<Slider*, 4> sliders = {
        &brightnessSlider, &soundSlider, &musicSlider, &sensitivitySlider
    };
    for (auto* s : sliders) {
        if (s->isDragging) activeSlider = s->id;
    }
    for (auto* s : sliders) s->update(mx, my, mouseDown, activeSlider);

    Config::setBrightness (tempBrightness);
    Config::setSoundVolume(tempSoundVolume);
    Config::setMusicVolume(tempMusicVolume);
    Config::setSensitivity(tempSensitivity);

    if (soundMgr) {
        soundMgr->soundVolume = Config::getSoundVolume();
        soundMgr->musicVolume = Config::getMusicVolume();
    }

    // Кнопка "Назад"
    if (updateButton(backBtn, mx, my, clicked, soundMgr)) {
        keyBeingRebound         = nullptr;
        mouseButtonBeingRebound = nullptr;
        nextScene = SceneType::MAIN_MENU;
    }

    // Кнопки переназначения
    for (auto& cb : controlButtons) {
        cb.isHovered = mx >= cb.rect.x && mx <= cb.rect.x + cb.rect.w &&
                       my >= cb.rect.y && my <= cb.rect.y + cb.rect.h;
        if (cb.isHovered && clicked) {
            if (soundMgr) soundMgr->playClick();
            // Если есть mouseBtn — ждём кнопку мыши
            // Если только key — ждём клавишу
            if (cb.mouseBtn) {
                mouseButtonBeingRebound = cb.mouseBtn;
                keyBeingRebound         = nullptr;
            } else {
                keyBeingRebound         = cb.key;
                mouseButtonBeingRebound = nullptr;
            }
        }
    }
}

void SettingsScene::update(float /*deltaTime*/) {}

void SettingsScene::render(SDL_Renderer* renderer) {
    if (!brightnessSlider.isDragging)  tempBrightness  = Config::getBrightness();
    if (!soundSlider.isDragging)       tempSoundVolume = Config::getSoundVolume();
    if (!musicSlider.isDragging)       tempMusicVolume = Config::getMusicVolume();
    if (!sensitivitySlider.isDragging) tempSensitivity = Config::getSensitivity();

    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 100);
    drawText(renderer, Config::getFont(), "Настройки", 0, 50,
             {255, 255, 255, 255}, true, Config::getTitleFont());

    std::array<Slider*, 4> sliders = {
        &brightnessSlider, &soundSlider, &musicSlider, &sensitivitySlider
    };
    for (auto* s : sliders) drawSlider(renderer, Config::getFont(), *s, soundMgr);

    drawText(renderer, Config::getFont(), "Управление (клик для изменения):", 850, 120);

    // Имена кнопок мыши (SDL: 1=ЛКМ, 2=СКМ, 3=ПКМ)
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
        if (isWaiting) {
            keyText = "...";
        } else if (cb.mouseBtn) {
            // Кнопка мыши
            keyText = mouseButtonName(*cb.mouseBtn);
        } else {
            // Клавиша
            keyText = getKeyName(*cb.key);
        }

        drawText(renderer, Config::getFont(),
                 cb.label + ": " + keyText,
                 cb.rect.x + 10, cb.rect.y + 8);
    }

    if (keyBeingRebound || mouseButtonBeingRebound) {
        drawText(renderer, Config::getFont(),
                 "Нажмите клавишу или кнопку мыши...",
                 850, 520, {255, 200, 0, 255});
    }

    drawButton(renderer, Config::getFont(), backBtn);
}

SceneType SettingsScene::getNextScene() {
    return nextScene;
}