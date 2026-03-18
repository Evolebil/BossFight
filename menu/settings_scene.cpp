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
    brightnessSlider  (350, 150, 400, "Яркость",           &tempBrightness,  0),
    soundSlider       (350, 250, 400, "Звук",               &tempSoundVolume, 1),
    musicSlider       (350, 350, 400, "Музыка",             &tempMusicVolume, 2),
    sensitivitySlider (350, 450, 400, "Чувствительность",   &tempSensitivity, 3),
    backBtn(20, 20, 100, 50, "Назад") {

    Config::Controls& ctrl = Config::getControls();
    controlButtons = {
                       {"Атака вблизи",   &ctrl.attack,   &ctrl.attackMouseButton, {850, 180, 250, 40}, false, false},
                       {"Выстрел",        &ctrl.shoot,    &ctrl.shootMouseButton,  {850, 225, 250, 40}, false, false},
                       {"Прыжок",         &ctrl.jump,     nullptr,                 {850, 270, 250, 40}, false, false},
                       {"Влево",          &ctrl.left,     nullptr,                 {850, 315, 250, 40}, false, false},
                       {"Вправо",         &ctrl.right,    nullptr,                 {850, 360, 250, 40}, false, false},
                       {"Пригнуться",     &ctrl.crouch,   nullptr,                 {850, 405, 250, 40}, false, false},
                       {"Взаимодействие", &ctrl.interact, nullptr,                 {850, 450, 250, 40}, false, false},
                       };
}

void SettingsScene::handleInput(SDL_Event& event, int mx, int my,
                                bool clicked, bool mouseDown) {
    // Переназначение кнопки мыши — ждём следующего нажатия
    if (mouseButtonBeingRebound && event.type == SDL_MOUSEBUTTONDOWN) {
        *mouseButtonBeingRebound = event.button.button;
        if (soundMgr) soundMgr->playClick();
        mouseButtonBeingRebound = nullptr;
        keyBeingRebound         = nullptr;
        return;
    }

    // Переназначение клавиши — ждём следующего нажатия
    if (keyBeingRebound && event.type == SDL_KEYDOWN) {
        *keyBeingRebound = event.key.keysym.scancode;
        if (soundMgr) soundMgr->playClick();
        keyBeingRebound         = nullptr;
        mouseButtonBeingRebound = nullptr;
        return;
    }

    // Определяем активный слайдер
    if (!mouseDown) activeSlider = -1;
    std::array<Slider*, 4> sliders = {
        &brightnessSlider, &soundSlider, &musicSlider, &sensitivitySlider
    };
    for (auto* s : sliders) {
        if (s->isDragging) activeSlider = s->id;
    }

    // Обновляем все слайдеры
    for (auto* s : sliders) s->update(mx, my, mouseDown, activeSlider);

    // Применяем значения в Config
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

    // Кнопки переназначения управления
    for (auto& cb : controlButtons) {
        cb.isHovered = mx >= cb.rect.x && mx <= cb.rect.x + cb.rect.w &&
                       my >= cb.rect.y && my <= cb.rect.y + cb.rect.h;
        if (cb.isHovered && clicked) {
            if (soundMgr) soundMgr->playClick();
            keyBeingRebound         = cb.key;
            mouseButtonBeingRebound = cb.mouseBtn;
        }
    }
}

void SettingsScene::update(float /*deltaTime*/) {}

void SettingsScene::render(SDL_Renderer* renderer) {
    // Синхронизируем значения если слайдер не перетаскивается
    if (!brightnessSlider.isDragging)   tempBrightness  = Config::getBrightness();
    if (!soundSlider.isDragging)        tempSoundVolume  = Config::getSoundVolume();
    if (!musicSlider.isDragging)        tempMusicVolume  = Config::getMusicVolume();
    if (!sensitivitySlider.isDragging)  tempSensitivity  = Config::getSensitivity();

    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 100);
    drawText(renderer, Config::getFont(), "Настройки", 0, 50,
             {255, 255, 255, 255}, true, Config::getTitleFont());

    // Слайдеры — через массив
    std::array<Slider*, 4> sliders = {
        &brightnessSlider, &soundSlider, &musicSlider, &sensitivitySlider
    };
    for (auto* s : sliders) drawSlider(renderer, Config::getFont(), *s, soundMgr);

    // Секция управления
    drawText(renderer, Config::getFont(), "Управление (клик для изменения):", 850, 140);

    for (const auto& cb : controlButtons) {
        const bool isWaiting = (keyBeingRebound == cb.key) ||
                               (cb.mouseBtn && mouseButtonBeingRebound == cb.mouseBtn);

        SDL_SetRenderDrawColor(renderer,
                               isWaiting  ? 255 : (cb.isHovered ? 100 : 60),
                               isWaiting  ? 200 : (cb.isHovered ? 150 : 80),
                               isWaiting  ?   0 : (cb.isHovered ? 220 : 120),
                               isWaiting  ? 255 : 200);
        SDL_RenderFillRect(renderer, &cb.rect);
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderDrawRect(renderer, &cb.rect);

        std::string keyText = isWaiting ? "..." : getKeyName(*cb.key);
        if (!isWaiting && cb.mouseBtn && *cb.mouseBtn > 0) {
            const char* mouseNames[] = {"", "ЛКМ", "ПКМ", "СКМ"};
            if (*cb.mouseBtn <= 3)
                keyText += " / " + std::string(mouseNames[*cb.mouseBtn]);
        }
        drawText(renderer, Config::getFont(), cb.label + ": " + keyText,
                 cb.rect.x + 10, cb.rect.y + 8);
    }

    // Подсказка внизу
    if (keyBeingRebound || mouseButtonBeingRebound) {
        drawText(renderer, Config::getFont(), "Нажмите клавишу или кнопку мыши...",
                 850, 510, {255, 200, 0, 255});
    } else {
        drawText(renderer, Config::getFont(),
                 "Чувствительность: " + std::to_string((int)(Config::getSensitivity() * 100)) + "%",
                 850, 510, {200, 200, 200, 255});
    }

    drawButton(renderer, Config::getFont(), backBtn);
}

SceneType SettingsScene::getNextScene() {
    return nextScene;
}