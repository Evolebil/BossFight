#include "../utils/scene_manager.h"
#include "settings_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"
#include <vector>

// Убрать весь класс SettingsScene { ... } и заменить на:

SettingsScene::SettingsScene() 
    : nextScene(SceneType::SETTINGS),
      soundMgr(getSoundManager()),
      activeSlider(-1),
      keyBeingRebound(nullptr),
      mouseButtonBeingRebound(nullptr),
      tempBrightness(Config::getBrightness()),
      tempSoundVolume(Config::getSoundVolume()),
      tempMusicVolume(Config::getMusicVolume()),
      tempSensitivity(Config::getSensitivity()),
      brightnessSlider(350, 150, 400, "Яркость", &tempBrightness, 0),
      soundSlider(350, 250, 400, "Звук", &tempSoundVolume, 1),
      musicSlider(350, 350, 400, "Музыка", &tempMusicVolume, 2),
      sensitivitySlider(350, 450, 400, "Чувствительность", &tempSensitivity, 3),
      backBtn(20, 20, 100, 50, "Назад") {
    
    // Создаём кнопки управления
    Config::Controls& controls = Config::getControls();
    controlButtons.push_back({"Атака вблизи", &controls.attack, &controls.attackMouseButton, {850, 180, 250, 40}, false, false});
    controlButtons.push_back({"Выстрел", &controls.shoot, &controls.shootMouseButton, {850, 225, 250, 40}, false, false});
    controlButtons.push_back({"Прыжок", &controls.jump, nullptr, {850, 270, 250, 40}, false, false});
    controlButtons.push_back({"Влево", &controls.left, nullptr, {850, 315, 250, 40}, false, false});
    controlButtons.push_back({"Вправо", &controls.right, nullptr, {850, 360, 250, 40}, false, false});
    controlButtons.push_back({"Пригнуться", &controls.crouch, nullptr, {850, 405, 250, 40}, false, false});
    controlButtons.push_back({"Взаимодействие", &controls.interact, nullptr, {850, 450, 250, 40}, false, false});
}

void SettingsScene::handleInput(SDL_Event& event, int mouseX, int mouseY, bool mouseClicked, bool mouseDown) {
    // ПЕРЕНАЗНАЧЕНИЕ КНОПОК МЫШИ
    if (mouseButtonBeingRebound != nullptr && event.type == SDL_MOUSEBUTTONDOWN) {
        *mouseButtonBeingRebound = event.button.button;
        if (soundMgr) soundMgr->playClick();
        mouseButtonBeingRebound = nullptr;
        keyBeingRebound = nullptr;
        return;
    }
    
    // ПЕРЕНАЗНАЧЕНИЕ КЛАВИШ
    if (keyBeingRebound != nullptr && event.type == SDL_KEYDOWN) {
        *keyBeingRebound = event.key.keysym.scancode;
        if (soundMgr) soundMgr->playClick();
        keyBeingRebound = nullptr;
        mouseButtonBeingRebound = nullptr;
        return;
    }
    
    // Определяем активный слайдер
    if (!mouseDown) activeSlider = -1;
    if (brightnessSlider.isDragging) activeSlider = 0;
    if (soundSlider.isDragging) activeSlider = 1;
    if (musicSlider.isDragging) activeSlider = 2;
    if (sensitivitySlider.isDragging) activeSlider = 3;
    
    // Обновляем слайдеры
    brightnessSlider.update(mouseX, mouseY, mouseDown, activeSlider);
    soundSlider.update(mouseX, mouseY, mouseDown, activeSlider);
    musicSlider.update(mouseX, mouseY, mouseDown, activeSlider);
    sensitivitySlider.update(mouseX, mouseY, mouseDown, activeSlider);
    
    // Применяем настройки к Config
    Config::setBrightness(tempBrightness);
    Config::setSoundVolume(tempSoundVolume);
    Config::setMusicVolume(tempMusicVolume);
    Config::setSensitivity(tempSensitivity);
    
    // Применяем громкость к звукам
    if (soundMgr) {
        soundMgr->soundVolume = Config::getSoundVolume();
        soundMgr->musicVolume = Config::getMusicVolume();
    }
    
    // Кнопка "Назад"
    backBtn.isHovered = backBtn.contains(mouseX, mouseY);
    if (backBtn.isHovered && !backBtn.wasHovered && soundMgr) {
        soundMgr->playHover();
    }
    backBtn.wasHovered = backBtn.isHovered;
    
    if (backBtn.isHovered && mouseClicked) {
        if (soundMgr) soundMgr->playClick();
        keyBeingRebound = nullptr;
        mouseButtonBeingRebound = nullptr;
        nextScene = SceneType::MAIN_MENU;
    }
    
    // Обработка кнопок управления
    for (auto& cb : controlButtons) {
        cb.isHovered = mouseX >= cb.rect.x && mouseX <= cb.rect.x + cb.rect.w &&
                       mouseY >= cb.rect.y && mouseY <= cb.rect.y + cb.rect.h;
        
        if (cb.isHovered && mouseClicked) {
            if (soundMgr) soundMgr->playClick();
            keyBeingRebound = cb.key;
            mouseButtonBeingRebound = cb.mouseBtn;
        }
    }
}

void SettingsScene::update(float deltaTime) {
    // НЕ синхронизируем здесь - это затирает изменения!
}

void SettingsScene::render(SDL_Renderer* renderer) {
    // Синхронизируем ПЕРЕД отрисовкой
    if (!brightnessSlider.isDragging) tempBrightness = Config::getBrightness();
    if (!soundSlider.isDragging) tempSoundVolume = Config::getSoundVolume();
    if (!musicSlider.isDragging) tempMusicVolume = Config::getMusicVolume();
    if (!sensitivitySlider.isDragging) tempSensitivity = Config::getSensitivity();
    
    // Фон
    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 100);
    
    // Заголовок
    drawText(renderer, Config::getFont(), "Настройки", 0, 50, 
             {255, 255, 255, 255}, true, Config::getTitleFont());
    
    // Слайдеры
    drawSlider(renderer, Config::getFont(), brightnessSlider, soundMgr);
    drawSlider(renderer, Config::getFont(), soundSlider, soundMgr);
    drawSlider(renderer, Config::getFont(), musicSlider, soundMgr);
    drawSlider(renderer, Config::getFont(), sensitivitySlider, soundMgr);
    
    // Управление
    drawText(renderer, Config::getFont(), "Управление (клик для изменения):", 850, 140);
    
    for (auto& cb : controlButtons) {
        // Проверка какая кнопка ждет ввода
        bool isWaiting = (keyBeingRebound == cb.key) || 
                         (cb.mouseBtn != nullptr && mouseButtonBeingRebound == cb.mouseBtn);
        
        if (isWaiting) {
            SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);
        } else if (cb.isHovered) {
            SDL_SetRenderDrawColor(renderer, 100, 150, 220, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 60, 80, 120, 200);
        }
        SDL_RenderFillRect(renderer, &cb.rect);
        
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderDrawRect(renderer, &cb.rect);
        
        // Текст
        std::string keyText;
        if (isWaiting) {
            keyText = "...";
        } else {
            keyText = getKeyName(*cb.key);
            if (cb.mouseBtn && *cb.mouseBtn > 0) {
                const char* mouseNames[] = {"", "ЛКМ", "ПКМ", "СКМ"};
                if (*cb.mouseBtn <= 3) {
                    keyText += " / " + std::string(mouseNames[*cb.mouseBtn]);
                }
            }
        }
        drawText(renderer, Config::getFont(), cb.label + ": " + keyText, 
                 cb.rect.x + 10, cb.rect.y + 8);
    }
    
    // Подсказка
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