#include "saves_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"

/**
 * @file saves_scene.cpp
 * @brief Сцена управления сохранениями с модальным полем ввода UTF-8 текста
 */

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ДЛЯ UTF-8
// ============================================================

/**
 * @brief Подсчитывает количество UTF-8 символов в строке.
 */
static size_t countUTF8Chars(const std::string& str) {
    size_t count = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if ((str[i] & 0xC0) != 0x80) count++;
    }
    return count;
}

/**
 * @brief Обрезает UTF-8 строку до указанного количества символов.
 */
static std::string truncateUTF8(const std::string& str, size_t maxChars) {
    if (countUTF8Chars(str) <= maxChars) return str;

    size_t chars = 0;
    size_t bytePos = 0;
    while (bytePos < str.size() && chars < maxChars) {
        if ((str[bytePos] & 0x80) == 0) {
            bytePos += 1;
        } else if ((str[bytePos] & 0xE0) == 0xC0) {
            bytePos += 2;
        } else if ((str[bytePos] & 0xF0) == 0xE0) {
            bytePos += 3;
        } else if ((str[bytePos] & 0xF8) == 0xF0) {
            bytePos += 4;
        } else {
            bytePos += 1;
        }
        chars++;
    }
    return str.substr(0, bytePos);
}

/**
 * @brief Удаляет последний символ из UTF-8 строки.
 */
static bool popLastUTF8Char(std::string& str) {
    if (str.empty()) return false;
    size_t pos = str.length() - 1;
    while (pos > 0 && (str[pos] & 0xC0) == 0x80) pos--;
    str.erase(pos);
    return true;
}

// ============================================================
// КОНСТРУКТОР
// ============================================================

SavesScene::SavesScene() {
    soundMgr = getSoundManager();
    const int W = Config::getWindowWidth();

    slotButtons.clear();
    slotIsNew.clear();

    // Одна кнопка "+" в начале
    slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+");
    slotIsNew.push_back(true);   // это новая (ещё не переименованная) кнопка

    rebuildButtonsLayout();      // расставить одну кнопку по центру

    inputRect.x = (W - INPUT_W) / 2;

    // Создаём кнопки меню (пока без позиций, заполним позже при отрисовке)
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "СОХРАНИТЬ");
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ЗАГРУЗИТЬ");
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "УДАЛИТЬ СОХРАНЕНИЕ");
    menuButtons.emplace_back(0, 0, MENU_BTN_W, MENU_BTN_H, "ПЕРЕИМЕНОВАТЬ");
    // Центрируем каждую по горизонтали
    for (auto& btn : menuButtons) {
        btn.centerX(W);
    }
    // Вертикальные позиции зададим при отрисовке или здесь:
    for (size_t i = 0; i < menuButtons.size(); ++i) {
        menuButtons[i].rect.y = MENU_START_Y + i * (MENU_BTN_H + MENU_BTN_GAP);
    }
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ
// ============================================================

bool SavesScene::isPointInRect(int x, int y, const SDL_Rect& rect) const {
    return x >= rect.x && x <= rect.x + rect.w &&
           y >= rect.y && y <= rect.y + rect.h;
}

void SavesScene::closeInput(bool accept) {
    if (accept && activePlusIndex >= 0 && !inputText.empty()) {
        const int idx = activePlusIndex;
        if (idx >= 0 && idx < (int)slotButtons.size()) {
            // Меняем текст кнопки на введённый
            slotButtons[idx].text = inputText;

            // Если это была НОВАЯ кнопка (isNewSlot == true)
            if (slotIsNew[idx]) {
                // Теперь она уже не новая
                slotIsNew[idx] = false;

                // Создаём новую кнопку "+" (новая, isNewSlot = true)
                slotButtons.emplace_back(0, PLUS_BTN_Y, PLUS_BTN_W, PLUS_BTN_H, "+");
                slotIsNew.push_back(true);

                // Перестраиваем расположение ВСЕХ кнопок (они сместятся)
                rebuildButtonsLayout();
            }
            // Если кнопка была уже именованной (isNewSlot == false):
            //   - ничего не создаём, не перестраиваем
            //   - кнопка остаётся на том же месте
        }
    }

    activePlusIndex = -1;
    isInputVisible = false;
    isInputFocused = false;
    inputText.clear();
    SDL_StopTextInput();
}

void SavesScene::openInputForButton(int index) {
    if (index < 0 || index >= (int)slotButtons.size()) return;
    // Разрешаем открывать для любой кнопки (и новой, и именованной)
    activePlusIndex = index;
    isInputVisible = true;
    isInputFocused = false;
    inputText.clear();
}

void SavesScene::rebuildButtonsLayout() {
    const int windowWidth = Config::getWindowWidth();
    const size_t total = slotButtons.size();
    const int rowStepY = PLUS_BTN_H + PLUS_BTN_ROW_GAP_Y;

    for (size_t row = 0; row * PLUS_BTN_COLUMNS < total; ++row) {
        const size_t rowStart = row * PLUS_BTN_COLUMNS;
        const size_t rowCount = std::min<size_t>(PLUS_BTN_COLUMNS, total - rowStart);

        const int rowWidth =
            static_cast<int>(rowCount * PLUS_BTN_W + (rowCount > 1 ? (rowCount - 1) * PLUS_BTN_GAP_X : 0));
        const int startX = (windowWidth - rowWidth) / 2;

        for (size_t col = 0; col < rowCount; ++col) {
            const size_t idx = rowStart + col;
            slotButtons[idx].rect.x = startX + static_cast<int>(col * (PLUS_BTN_W + PLUS_BTN_GAP_X));
            slotButtons[idx].rect.y = PLUS_BTN_Y + static_cast<int>(row * rowStepY);
        }
    }
}

// ============================================================
// ОБРАБОТКА ВВОДА
// ============================================================

void SavesScene::handleInput(SDL_Event& event, int mx, int my,
                             bool mouseClicked, bool /*mouseDown*/) {
    // При сворачивании окна закрываем поле и меню
    if (event.type == SDL_APP_WILLENTERBACKGROUND) {
        if (isInputVisible) closeInput(false);
        if (isMenuVisible) isMenuVisible = false;
        return;
    }

    // ---- Режим ввода текста (приоритет) ----
    if (isInputVisible) {
        // Если поле видимо, но не в фокусе — проверяем клик по полю
        if (!isInputFocused && mouseClicked) {
            if (isPointInRect(mx, my, inputRect)) {
                isInputFocused = true;
                SDL_StartTextInput();
                return;
            }
        }

        // Если поле в фокусе
        if (isInputFocused) {
            // Обработка клавиатуры
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
                default:
                    break;
                }
            }

            // Обработка текстового ввода
            if (event.type == SDL_TEXTINPUT) {
                std::string newText = inputText + event.text.text;
                if (countUTF8Chars(newText) <= MAX_NAME_LENGTH) {
                    inputText = newText;
                } else {
                    size_t currentLen = countUTF8Chars(inputText);
                    size_t available = MAX_NAME_LENGTH - currentLen;
                    if (available > 0) {
                        std::string toAdd = truncateUTF8(event.text.text, available);
                        inputText += toAdd;
                    }
                }
                return;
            }

            // Клик вне поля — закрываем
            if (mouseClicked && !isPointInRect(mx, my, inputRect)) {
                closeInput(false);
                return;
            }
        }
        return;
    }

    // ---- Режим меню действий ----
    if (isMenuVisible) {
        // Обработка кликов по кнопкам меню
        bool anyClicked = false;
        for (auto& btn : menuButtons) {
            if (updateButton(btn, mx, my, mouseClicked, soundMgr)) {
                anyClicked = true;
                if (btn.text == "ПЕРЕИМЕНОВАТЬ") {
                    // Закрываем меню и открываем поле ввода для этой кнопки
                    isMenuVisible = false;
                    openInputForButton(menuTargetIndex);
                } else {
                    // Для других кнопок пока просто закрываем меню
                    isMenuVisible = false;
                }
                break;
            }
        }
        // Клик вне меню или Escape закрывают меню
        if (!anyClicked && mouseClicked) {
            isMenuVisible = false;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            isMenuVisible = false;
        }
        return;
    }

    // ---- Обычный режим (нет ни ввода, ни меню) ----
    if (updateButton(backBtn, mx, my, mouseClicked, soundMgr))
        nextScene = SceneType::MAIN_MENU;

    for (size_t i = 0; i < slotButtons.size(); ++i) {
        if (updateButton(slotButtons[i], mx, my, mouseClicked, soundMgr)) {
            if (slotIsNew[i]) {
                openInputForButton(static_cast<int>(i));
            } else {
                // Открываем меню для именованной кнопки
                menuTargetIndex = static_cast<int>(i);
                isMenuVisible = true;
            }
        }
    }
}

// ============================================================
// ОБНОВЛЕНИЕ
// ============================================================

void SavesScene::update(float /*deltaTime*/) {
    if (!isInputFocused) {
        SDL_StopTextInput();
    }
}

// ============================================================
// ОТРИСОВКА
// ============================================================

void SavesScene::render(SDL_Renderer* renderer) {
    drawForestBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, OVERLAY_ALPHA);

    drawText(renderer, Config::getFont(), "Сохранения", 0, TITLE_Y,
             {255, 230, 150, 255}, true, Config::getTitleFont());
    drawText(renderer, Config::getFont(), "Функция временно отключена", 0, MESSAGE_Y,
             {200, 200, 200, 255}, true);

    drawButton(renderer, Config::getFont(), backBtn);
    for (auto& btn : slotButtons) {
        drawButton(renderer, Config::getFont(), btn);
    }

    if (isInputVisible) {
        // Затемняющий оверлей
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
        SDL_Rect fullOverlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
        SDL_RenderFillRect(renderer, &fullOverlay);

        // Рамка поля
        SDL_SetRenderDrawColor(renderer, 50, 100, 200, 255);
        SDL_RenderDrawRect(renderer, &inputRect);

        // Фон поля (темнее на 50%)
        SDL_SetRenderDrawColor(renderer, 25, 50, 100, 200);
        SDL_RenderFillRect(renderer, &inputRect);

        // Текст с мигающим курсором
        std::string displayText = inputText;
        if (isInputFocused && (SDL_GetTicks() / 500 % 2 == 0)) {
            displayText += "_";
        }
        drawText(renderer, Config::getFont(), displayText,
                 inputRect.x + 10, inputRect.y + (INPUT_H - 24) / 2, {255, 255, 255, 255});

        // Счётчик символов (опционально)
        char counter[32];
        std::snprintf(counter, sizeof(counter), "%zu/%d", countUTF8Chars(inputText), MAX_NAME_LENGTH);
        drawText(renderer, Config::getFont(), counter,
                 inputRect.x + inputRect.w - 50, inputRect.y + (INPUT_H - 24) / 2, {180, 180, 180, 255});

        // Подсказка
        const char* hint = isInputFocused
                               ? "Введите имя (Enter - применить, Esc - отмена)"
                               : "Кликните для ввода";
        drawText(renderer, Config::getFont(), hint,
                 0, inputRect.y + INPUT_H + 20, {200, 200, 200, 255}, true);
    }
    // Если меню активно – рисуем оверлей и кнопки меню
    if (isMenuVisible) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
        SDL_Rect fullOverlay = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
        SDL_RenderFillRect(renderer, &fullOverlay);

        for (auto& btn : menuButtons) {
            drawButton(renderer, Config::getFont(), btn);
        }

        drawText(renderer, Config::getFont(), "Esc - отмена",
                 0, Config::getWindowHeight() - 50, {200, 200, 200, 255}, true);
    }
}

// ============================================================
// ПОЛУЧЕНИЕ СЛЕДУЮЩЕЙ СЦЕНЫ
// ============================================================

SceneType SavesScene::getNextScene() {
    return nextScene;
}