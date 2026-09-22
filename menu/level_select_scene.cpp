/**
 * @file level_select_scene.cpp
 * @brief Реализация экрана выбора уровня и сложности
 * @author evol
 * @date 2026-02-20
 */
#include "../utils/scene_manager.h"
#include "level_select_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../backgrounds/forest_bg.h"
#include "../utils/sound_manager.h"
#include "../utils/save_manager.h"
#include "../utils/texture_manager.h"

namespace {
constexpr int INFO_BTN_SIZE = 40;
constexpr int INFO_BTN_GAP  = 20;   // отступ между кнопкой уровня и "?"
constexpr int PREVIEW_SIZE  = 100;
constexpr int PREVIEW_GAP   = 20;   // отступ между "?" и превью босса

struct BossPreview {
    const char* texturePath;
    int frameW; // 0 = кадр неизвестен, рисуем текстуру целиком без обрезки
    int frameH;
};

// Первый кадр IDLE-анимации каждого босса — те же файлы/размеры, что
// используют сами боссы в бою (см. boss_golem.h/boss_samurai.cpp).
constexpr BossPreview BOSS_PREVIEWS[3] = {
    {"assets/boss1/Character.png", 100, 100},
    {"assets/Samurai/Idle.png",    128, 128},
    {"assets/boss_3/idle.png",       0,   0},  // TODO: размер кадра не подтверждён
};

const std::vector<std::vector<std::string>>& getBossTips() {
    static const std::vector<std::vector<std::string>> tips = {
        {
            "Фаза 1 (100-50% HP):",
            "атакуйте мечом",
            "Фаза 2 (50-0% HP):",
            "атакуйте магией",
        },
        {
            "Самурай: дождитесь",
            "стойки (блока),",
            "бейте после неё,",
            "отступите, повторите",
            "",
            "Лучник: бегите",
            "и стреляйте",
        },
        {
            "Ждите 30 секунд",
            "Убейте 5 миньонов",
            "Ударьте босса",
            "Повторить 5 раз",
        },
    };
    return tips;
}
}

LevelSelectScene::LevelSelectScene()
    : nextScene(SceneType::LEVEL_SELECT),
    soundMgr(getSoundManager()),
    backBtn (20, 20, 100, 50, "Назад"),
    diffBtn (20, Config::getWindowHeight() - 70, 250, 50, ""),
    resetBtn(Config::getWindowWidth() - 120, 20, 100, 50, "Сброс"),
    // Кнопки диалога — позиции по центру экрана
    loadBtn   (0, 280, 250, 55, "Загрузить"),
    newGameBtn(0, 350, 250, 55, "Новая игра"),
    cancelBtn (0, 430, 250, 55, "Отмена")
{
    const int W = Config::getWindowWidth();

    loadBtn   .centerX(W);
    newGameBtn.centerX(W);
    cancelBtn .centerX(W);

    for (int i = 0; i < 3; i++) {
        levelBtns.push_back(Button(
            W / 2 - 75,
            550 - i * 150,
            150, 100,
            std::to_string(i + 1)
            ));

        const auto& lvlRect = levelBtns.back().rect;
        infoBtns.push_back(Button(
            lvlRect.x + lvlRect.w + INFO_BTN_GAP,
            lvlRect.y + (lvlRect.h - INFO_BTN_SIZE) / 2,
            INFO_BTN_SIZE, INFO_BTN_SIZE, "?"
            ));
    }

    if (soundMgr) soundMgr->playMusic("menu_music");
}

void LevelSelectScene::handleInput(SDL_Event& event, int mx, int my,
                                   bool clicked, bool mouseDown) {
    // ---- ДИАЛОГ "Загрузить / Новая игра" ----
    if (showLoadDialog) {
        if (updateButton(loadBtn, mx, my, clicked, soundMgr)) {
            GameSaveState s;
            bool hasCompatibleSave = SaveManager::get().loadAutosave(s)
                                     && s.currentLevel == dialogLevel;
            Config::setSelectedLevel(dialogLevel);
            Config::setLoadFromSave(hasCompatibleSave);
            nextScene = SceneType::GAME;
            showLoadDialog = false;
        }
        if (updateButton(newGameBtn, mx, my, clicked, soundMgr)) {
            Config::setSelectedLevel(dialogLevel);
            Config::setLoadFromSave(false);
            nextScene = SceneType::GAME;
            showLoadDialog = false;
        }
        if (updateButton(cancelBtn,  mx, my, clicked, soundMgr)) {
            showLoadDialog = false;
        }
        return;  // пока диалог открыт — блокируем остальное
    }

    // ---- ОБЫЧНЫЙ РЕЖИМ ----
    diffBtn.text = Config::getDifficulties()[Config::getCurrentDifficulty()].name;

    if (updateButton(backBtn,  mx, my, clicked, soundMgr)) nextScene = SceneType::MAIN_MENU;
    if (updateButton(resetBtn, mx, my, clicked, soundMgr)) Config::resetProgress();
    if (updateButton(diffBtn,  mx, my, clicked, soundMgr)) {
        int newDiff = (Config::getCurrentDifficulty() + 1) % Config::getDifficultyCount();
        Config::setCurrentDifficulty(newDiff);
    }

    for (size_t i = 0; i < levelBtns.size(); i++) {
        if (updateButton(levelBtns[i], mx, my, clicked, soundMgr)) {
            dialogLevel    = static_cast<int>(i);
            showLoadDialog = true;  // всегда показываем панель
        }
    }

    // "?" — только подсветка/звук наведения, клик ничего не делает
    for (auto& btn : infoBtns)
        updateButton(btn, mx, my, clicked, soundMgr);
}

void LevelSelectScene::update(float /*deltaTime*/) {}

void LevelSelectScene::render(SDL_Renderer* renderer) {
    drawTowerBackground(renderer, Config::getBrightness());
    drawUIOverlay(renderer, 60);
    drawText(renderer, Config::getFont(), "Выбор уровня", 0, 50,
             {255, 255, 255, 255}, true, Config::getTitleFont());

    drawButton(renderer, Config::getFont(), backBtn);
    drawButton(renderer, Config::getFont(), diffBtn);
    drawButton(renderer, Config::getFont(), resetBtn);

    for (size_t i = 0; i < levelBtns.size(); i++) {
        drawButton(renderer, Config::getFont(), levelBtns[i]);
        drawStars(renderer,
                  levelBtns[i].rect.x + 35,
                  levelBtns[i].rect.y + 110,
                  Config::getLevelStars(static_cast<int>(i)));

        drawButton(renderer, Config::getFont(), infoBtns[i]);

        // Превью босса — чёрный силуэт, пока на уровне 0 звёзд (не пройден)
        const SDL_Rect previewRect = {
            infoBtns[i].rect.x + infoBtns[i].rect.w + PREVIEW_GAP,
            levelBtns[i].rect.y,
            PREVIEW_SIZE, PREVIEW_SIZE
        };
        SDL_Texture* bossTex = TextureManager::getTexture(BOSS_PREVIEWS[i].texturePath);
        if (bossTex) {
            const bool locked = Config::getLevelStars(static_cast<int>(i)) == 0;
            const Uint8 tint = locked ? 0 : 255;
            SDL_SetTextureColorMod(bossTex, tint, tint, tint);

            if (BOSS_PREVIEWS[i].frameW > 0) {
                SDL_Rect src = {0, 0, BOSS_PREVIEWS[i].frameW, BOSS_PREVIEWS[i].frameH};
                SDL_RenderCopy(renderer, bossTex, &src, &previewRect);
            } else {
                SDL_RenderCopy(renderer, bossTex, nullptr, &previewRect);
            }

            // Сбрасываем тонировку сразу — это тот же закэшированный SDL_Texture*,
            // что рисует сам босс в бою; у самурая нет своего цветового сброса
            // перед отрисовкой, поэтому оставленный здесь чёрный тон "протёк" бы в GameScene
            SDL_SetTextureColorMod(bossTex, 255, 255, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
            SDL_RenderFillRect(renderer, &previewRect);
        }
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderDrawRect(renderer, &previewRect);

        // Подсказка по тактике — только при наведении на "?"
        if (infoBtns[i].isHovered) {
            const auto& lines = getBossTips()[i];
            constexpr int LINE_H = 22;
            constexpr int PAD    = 10;
            const int tooltipW = 300;
            const int tooltipH = (int)lines.size() * LINE_H + PAD * 2;
            const int tooltipX = previewRect.x + previewRect.w + PREVIEW_GAP;
            const int tooltipY = levelBtns[i].rect.y;

            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(renderer, 20, 20, 30, 230);
            SDL_Rect tooltipBg = {tooltipX, tooltipY, tooltipW, tooltipH};
            SDL_RenderFillRect(renderer, &tooltipBg);
            SDL_SetRenderDrawColor(renderer, 255, 230, 150, 255);
            SDL_RenderDrawRect(renderer, &tooltipBg);

            for (size_t l = 0; l < lines.size(); l++) {
                drawText(renderer, Config::getFont(), lines[l],
                         tooltipX + PAD, tooltipY + PAD + (int)l * LINE_H,
                         {230, 230, 230, 255});
            }
        }
    }
    // В конце render(), после drawButton для уровней:
    if (showLoadDialog) {
        drawUIOverlay(renderer, 160);
        drawText(renderer, Config::getFont(), "Продолжить игру?",
                 0, 220, {255, 230, 150, 255}, true, Config::getTitleFont());
        drawButton(renderer, Config::getFont(), loadBtn);
        drawButton(renderer, Config::getFont(), newGameBtn);
        drawButton(renderer, Config::getFont(), cancelBtn);
    }
}

SceneType LevelSelectScene::getNextScene() {
    return nextScene;
}