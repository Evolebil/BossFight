/**
 * @file saves_scene.cpp
 * @brief Экран сохранений — работа с SaveManager
 * @author evol
 * @date 2026-04-21
 */
#include "saves_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"

// ============================================================
// UTF-8 ВСПОМОГАТЕЛЬНЫЕ (без изменений)
// ============================================================

static size_t countUTF8Chars(const std::string& str) {
    size_t count = 0;
    for (size_t i = 0; i < str.size(); ++i)
        if ((str[i] & 0xC0) != 0x80) count++;
    return count;
}

static std::string truncateUTF8(const std::string& str, size_t maxChars) {
    if (countUTF8Chars(str) <= maxChars) return str;
    size_t chars = 0, bytePos = 0;
    while (bytePos < str.size() && chars < maxChars) {
        unsigned char c = static_cast<unsigned char>(str[bytePos]);
        if      ((c & 0x80) == 0x00) bytePos += 1;
        else if ((c & 0xE0) == 0xC0) bytePos += 2;
        else if ((c & 0xF0) == 0xE0) bytePos += 3;
        else if ((c & 0xF8) == 0xF0) bytePos += 4;
        else                          bytePos += 1;
        chars++;
    }
    return str.substr(0, bytePos);
}

static void popLastUTF8Char(std::string& str) {
    if (str.empty()) return;
    size_t pos = str.length() - 1;
    while (pos > 0 && (static_cast<unsigned char>(str[pos]) & 0xC0) == 0x80)
        pos--;
    str.erase(pos);
}

// ============================================================
// КОНСТРУКТОР
// ============================================================

SavesScene::SavesScene() {
    soundMgr = getSoundManager();

    const int W = Config::getWindowWidth();
    inputRect.x = (W - INPUT_W) / 2;

    // Кнопки меню действий (позиции проставляются здесь)
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");

    for (auto& btn : menuButtons) btn.centerX(W);
    for (size_t i = 0; i < menuButtons.size(); ++i)
        menuButtons[i].rect.y = MENU_START_Y + (int)i * (MENU_BTN_H + MENU_BTN_GAP);

    // Загружаем индекс и строим кнопки
    SaveManager::get().loadIndex();
    rebuildSlots();
}

// ============================================================
// ПОСТРОЕНИЕ КНОПОК
// ============================================================

void SavesScene::rebuildSlots() {
    slotButtons.clear();
    slotIsNew.clear();

    // Именованные слоты из SaveManager
    for (const auto& entry : SaveManager::get().getEntries()) {
        slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, entry.name);
        slotIsNew.push_back(false);
    }

    // Кнопка "+" — только если лимит не достигнут
    if ((int)slotButtons.size() < MAX_SAVES) {
        slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+");
        slotIsNew.push_back(true);
    }

    rebuildButtonsLayout();
}

void SavesScene::rebuildButtonsLayout() {
    const int W        = Config::getWindowWidth();
    const size_t total = slotButtons.size();
    const int rowStepY = PLUS_BTN_H + PLUS_BTN_ROW_GAP_Y;

    for (size_t row = 0; row * PLUS_BTN_COLUMNS < total; ++row) {
        const size_t rowStart = row * PLUS_BTN_COLUMNS;
        const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);

        const int rowWidth = static_cast<int>(
            rowCount * PLUS_BTN_W +
            (rowCount > 1 ? (rowCount - 1) * PLUS_BTN_GAP_X : 0));
        const int startX = (W - rowWidth) / 2;

        for (size_t col = 0; col < rowCount; ++col) {
            const size_t idx = rowStart + col;
            slotButtons[idx].rect.x = startX + static_cast<int>(col * (PLUS_BTN_W + PLUS_BTN_GAP_X));
            slotButtons[idx].rect.y = PLUS_BTN_Y + static_cast<int>(row * rowStepY);
        }
    }
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ
// ============================================================

bool SavesScene::isPointInRect(int x, int y, const SDL_Rect& rect) const {
    return x >= rect.x && x <= rect.x + rect.w &&
           y >= rect.y && y <= rect.y + rect.h;
}

void SavesScene::closeInput(bool accept) {
    if (accept && activePlusIndex >= 0 && !inputText.empty()) {
        const int idx = activePlusIndex;

        if (idx >= 0 && idx < (int)slotButtons.size()) {
            if (slotIsNew[idx]) {
                // Создаём новое именованное сохранение
                int result = SaveManager::get().createNamedSave(inputText);
                if (result >= 0) {
                    // Пересоздаём все кнопки из обновлённого индекса
                    rebuildSlots();
                }
            } else {
                // Переименование: удаляем старое, создаём с новым именем на том же месте
                // Простая стратегия: перезаписываем файл с новым именем не меняя данных
                // TODO(evol): если нужно физически переименовать файл — реализовать отдельно
                // Пока просто обновляем текст кнопки (визуально)
                slotButtons[idx].text = inputText;
                // NOTE: полноценное переименование файла — задача следующего этапа
            }
        }
    }

    activePlusIndex = -1;
    isInputVisible  = false;
    isInputFocused  = false;
    inputText.clear();
    SDL_StopTextInput();
}

void SavesScene::openInputForButton(int index) {
    if (index < 0 || index >= (int)slotButtons.size()) return;
    activePlusIndex = index;
    isInputVisible  = true;
    isInputFocused  = false;
    inputText.clear();
}

// ============================================================
// ОБРАБОТКА ВВОДА
// ============================================================

void SavesScene::handleInput(SDL_Event& event, int mx, int my,
                             bool mouseClicked, bool /*mouseDown*/) {
    // Сворачивание — закрываем всё
    if (event.type == SDL_APP_WILLENTERBACKGROUND) {
        if (isInputVisible) closeInput(false);
        if (isMenuVisible)  isMenuVisible = false;
        return;
    }

    // ---- РЕЖИМ ВВОДА ТЕКСТА ----
    if (isInputVisible) {
        if (!isInputFocused && mouseClicked) {
            if (isPointInRect(mx, my, inputRect)) {
                isInputFocused = true;
                SDL_StartTextInput();
                return;
            }
        }

        if (isInputFocused) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_RETURN:
                case SDL_SCANCODE_KP_ENTER:
                    closeInput(true);
                    return;
                case SDL_SCANCODE_ESCAPE:
                    closeInput(false);
                    return;
                case SDL_SCANCODE_BACKSPACE:
                    popLastUTF8Char(inputText);
                    return;
                case SDL_SCANCODE_V:
                    if (SDL_GetModState() & KMOD_CTRL) {
                        char* clip = SDL_GetClipboardText();
                        if (clip) {
                            std::string pasted = clip;
                            SDL_free(clip);
                            // Убираем переносы строк
                            pasted.erase(std::remove_if(pasted.begin(), pasted.end(),
                                                        [](char c){ return c == '\n' || c == '\r'; }), pasted.end());

                            std::string combined = inputText + pasted;
                            if (countUTF8Chars(combined) <= static_cast<size_t>(MAX_NAME_LENGTH)) {
                                inputText = combined;
                            } else {
                                size_t available = MAX_NAME_LENGTH - countUTF8Chars(inputText);
                                inputText += truncateUTF8(pasted, available);
                            }
                        }
                        return;
                    }
                    break;

                case SDL_SCANCODE_C:
                    if (SDL_GetModState() & KMOD_CTRL) {
                        SDL_SetClipboardText(inputText.c_str());
                        return;
                    }
                    break;

                case SDL_SCANCODE_A:
                    if (SDL_GetModState() & KMOD_CTRL) {
                        // Ctrl+A — выделить всё (у нас нет выделения, просто игнорируем)
                        return;
                    }
                    break;
                default:
                    break;
                }
            }

            if (event.type == SDL_TEXTINPUT) {
                std::string newText = inputText + event.text.text;
                if (countUTF8Chars(newText) <= static_cast<size_t>(MAX_NAME_LENGTH)) {
                    inputText = newText;
                } else {
                    size_t available = MAX_NAME_LENGTH - countUTF8Chars(inputText);
                    if (available > 0)
                        inputText += truncateUTF8(event.text.text, available);
                }
                return;
            }

            if (mouseClicked && !isPointInRect(mx, my, inputRect)) {
                closeInput(false);
                return;
            }
        }
        return;
    }

    // ---- РЕЖИМ МЕНЮ ДЕЙСТВИЙ ----
    if (isMenuVisible) {
        bool anyClicked = false;

        for (size_t i = 0; i < menuButtons.size(); ++i) {
            if (updateButton(menuButtons[i], mx, my, mouseClicked, soundMgr)) {
                anyClicked = true;

                if (i == 0) {
                    // СОХРАНИТЬ — перезаписать текущий слот
                    SaveManager::get().overwriteNamedSave(menuTargetIndex);
                    isMenuVisible = false;

                } else if (i == 1) {
                    // ЗАГРУЗИТЬ — применить к Config + autosave
                    SaveManager::get().loadNamedSave(menuTargetIndex);
                    isMenuVisible = false;
                    // Переходим в меню — сцена не GAME, т.к. нужен перезапуск вручную
                    // Пользователь сам нажмёт "Играть"

                } else if (i == 2) {
                    // УДАЛИТЬ — удаляем файл и кнопку
                    SaveManager::get().deleteNamedSave(menuTargetIndex);
                    rebuildSlots();  // кнопки сдвигаются
                    isMenuVisible = false;

                } else if (i == 3) {
                    // ПЕРЕИМЕНОВАТЬ — открываем поле ввода
                    isMenuVisible = false;
                    openInputForButton(menuTargetIndex);
                }
                break;
            }
        }

        if (!anyClicked && mouseClicked)  isMenuVisible = false;
        if (event.type == SDL_KEYDOWN &&
            event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            isMenuVisible = false;

        return;
    }

    // ---- ОБЫЧНЫЙ РЕЖИМ ----
    if (updateButton(backBtn, mx, my, mouseClicked, soundMgr))
        nextScene = SceneType::MAIN_MENU;

    for (size_t i = 0; i < slotButtons.size(); ++i) {
        if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
            if (slotIsNew[i]) {
                // Кнопка "+" — открываем инпут для нового сохранения
                openInputForButton(static_cast<int>(i));
            } else {
                // Именованный слот — открываем меню
                menuTargetIndex = static_cast<int>(i);
                isMenuVisible   = true;
            }
        }
    }
}

// ============================================================
// ОБНОВЛЕНИЕ
// ============================================================

void SavesScene::update(float /*deltaTime*/) {
    // SDL_StopTextInput вызывается только в closeInput — не каждый кадр
}

// ============================================================
// ОТРИСОВКА
// ============================================================

void SavesScene::render(SDL_Renderer* renderer) {
    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, OVERLAY_ALPHA);

    drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
             {255, 230, 150, 255}, true, Config::getTitleFont());

    // Подсказка об autosave
    const char* autoMsg = SaveManager::get().hasAutosaveFile()
                              ? "Автосохранение найдено"
                              : "Автосохранения нет (сначала поиграйте)";
    drawText(renderer, Config::getFont(), autoMsg, 0, MESSAGE_Y,
             {180, 220, 180, 255}, true);

    drawButton(renderer, Config::getFont(), backBtn);

    for (auto& btn : slotButtons)
        drawButton(renderer, Config::getFont(), btn);

    // ---- Инпут ----
    if (isInputVisible) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
        SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
        SDL_RenderFillRect(renderer, &overlay);

        SDL_SetRenderDrawColor(renderer, 50, 100, 200, 255);
        SDL_RenderDrawRect(renderer, &inputRect);
        SDL_SetRenderDrawColor(renderer, 25, 50, 100, 200);
        SDL_RenderFillRect(renderer, &inputRect);

        std::string displayText = inputText;
        if (isInputFocused && (SDL_GetTicks() / 500 % 2 == 0))
            displayText += "_";

        drawText(renderer, Config::getFont(), displayText,
                 inputRect.x + 10,
                 inputRect.y + (INPUT_H - 24) / 2,
                 {255, 255, 255, 255});

        char counter[32];
        std::snprintf(counter, sizeof(counter), "%zu/%d",
                      countUTF8Chars(inputText), MAX_NAME_LENGTH);
        drawText(renderer, Config::getFont(), counter,
                 inputRect.x + inputRect.w - 55,
                 inputRect.y + (INPUT_H - 24) / 2,
                 {180, 180, 180, 255});

        const char* hint = isInputFocused
                               ? "Enter — сохранить, Esc — отмена"
                               : "Кликните для ввода";
        drawText(renderer, Config::getFont(), hint,
                 0, inputRect.y + INPUT_H + 20,
                 {200, 200, 200, 255}, true);
    }

    // ---- Меню действий ----
    if (isMenuVisible) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
        SDL_Rect overlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
        SDL_RenderFillRect(renderer, &overlay);

        for (auto& btn : menuButtons)
            drawButton(renderer, Config::getFont(), btn);

        drawText(renderer, Config::getFont(), "Esc — закрыть",
                 0, Config::getWindowHeight() - 50,
                 {200, 200, 200, 255}, true);
    }
}

// ============================================================
// СЛЕДУЮЩАЯ СЦЕНА
// ============================================================

SceneType SavesScene::getNextScene() {
    return nextScene;
}