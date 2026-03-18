/**
 * @file game_scene.cpp
 * @brief Реализация игровой сцены
 * @author evol
 * @date 2026-02-20
 */
#include "../utils/scene_manager.h"
#include "game_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../levels/level1_assets.h"
#include "../characters/boss_golem.h"
#include "../characters/player.h"
#include "../utils/sound_manager.h"

// ============================================================
//  КОНСТРУКТОР
// ============================================================

GameScene::GameScene()
    : nextScene(SceneType::GAME),
    soundMgr(getSoundManager()),
    isPaused(false),
    gameStarted(false),
    continueBtn(0, 200, 300, 60, "Продолжить"),
    saveBtn    (0, 280, 300, 60, "Сохранить"),
    exitBtn    (0, 360, 300, 60, "Выйти в меню"),
    nextBtn    (0, 430, 300, 60, "В меню уровней"),
    retryBtn   (0, 350, 300, 60, "Заново"),
    player(nullptr),
    boss(nullptr),
    currentLevel(0),
    livesLeft(0),
    levelTimer(0.0f),
    playerTookDamage(false),
    bossDefeated(false),
    resultState(ResultState::PLAYING),
    earnedStars(0),
    starRevealTimer(0.0f),
    starsRevealed(0) {

    const int W = Config::getWindowWidth();
    continueBtn.centerX(W);
    saveBtn.centerX(W);
    exitBtn.centerX(W);
    nextBtn.centerX(W);
    retryBtn.centerX(W);

    // Кнопки экрана поражения позиционируем здесь (не в render каждый кадр!)
    retryBtn.rect.y = 320;
    retryBtn.rect.x = (W - retryBtn.rect.w) / 2;
    exitBtn.rect.y  = 400;
    exitBtn.rect.x  = (W - exitBtn.rect.w) / 2;

    currentLevel = Config::getSelectedLevel();
    initPositions();
}

// ============================================================
//  ВЫЧИСЛЕНИЕ ПОЗИЦИИ СПАВНА ИГРОКА
// ============================================================

std::pair<float, float> GameScene::getPlayerSpawnPos() {
    int ox = 0, oy = 0;
    getMapOffset(ox, oy);
    return {
        ox + PLAYER_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f,
        oy + PLAYER_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f
    };
}

// ============================================================
//  ИНИЦИАЛИЗАЦИЯ ПОЗИЦИЙ
// ============================================================

void GameScene::initPositions() {
    auto [px, py] = getPlayerSpawnPos();

    int ox = 0, oy = 0;
    getMapOffset(ox, oy);
    float bossX = ox + BOSS_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f;
    float bossY = oy + BOSS_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f;

    const Config::Difficulty& diff = Config::getDifficulties()[Config::getCurrentDifficulty()];
    livesLeft = diff.respawns;

    player = std::make_unique<Player>(px, py);
    boss   = std::make_unique<BossGolem>(bossX, bossY, diff.projectileSpeed);
    gameStarted = true;
}

// ============================================================
//  ВВОД
// ============================================================

void GameScene::handleInput(SDL_Event& event, int mx, int my,
                            bool clicked, bool /*mouseDown*/) {
    if (resultState == ResultState::PLAYING) {
        if (event.type == SDL_KEYDOWN &&
            event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            isPaused = !isPaused;
            if (soundMgr) soundMgr->playClick();
        }
    }

    if (isPaused && resultState == ResultState::PLAYING) {
        if (updateButton(continueBtn, mx, my, clicked, soundMgr)) isPaused = false;
        if (updateButton(saveBtn,     mx, my, clicked, soundMgr)) saveGame();
        if (updateButton(exitBtn,     mx, my, clicked, soundMgr)) nextScene = SceneType::LEVEL_SELECT;
        return;
    }

    if (resultState == ResultState::VICTORY && starsRevealed >= earnedStars) {
        if (updateButton(nextBtn, mx, my, clicked, soundMgr)) nextScene = SceneType::LEVEL_SELECT;
    }

    if (resultState == ResultState::DEFEAT) {
        if (updateButton(retryBtn, mx, my, clicked, soundMgr)) nextScene = SceneType::GAME;
        if (updateButton(exitBtn,  mx, my, clicked, soundMgr)) nextScene = SceneType::LEVEL_SELECT;
    }
}

// ============================================================
//  UPDATE
// ============================================================

void GameScene::update(float deltaTime) {
    if (isPaused) return;

    // Анимация появления звёзд после победы
    if (resultState == ResultState::VICTORY && starsRevealed < earnedStars) {
        starRevealTimer += deltaTime;
        if (starRevealTimer >= 0.4f) {
            starRevealTimer = 0.0f;
            starsRevealed++;
        }
    }

    if (resultState != ResultState::PLAYING) return;

    levelTimer += deltaTime;

    if (player) player->update(deltaTime);

    if (boss && player) {
        boss->update(deltaTime, player->getX(), player->getY());

        // Урон боссу по игроку
        SDL_Rect pb = player->getHitbox();
        float dmgToPlayer = boss->checkPlayerDamage(pb, deltaTime);
        if (dmgToPlayer > 0.0f) {
            player->takeDamage(dmgToPlayer);
            playerTookDamage = true;
        }

        // Урон игрока по боссу — используем rectsOverlap из common.h
        float dmgToBoss = player->consumeAttackDamage();
        if (dmgToBoss > 0.0f) {
            SDL_Rect atk  = player->getAttackHitbox();
            SDL_Rect bhb  = boss->getHitbox();
            if (rectsOverlap(atk, bhb)) boss->takeDamage(dmgToBoss);
        }
    }

    // Проверяем победу
    if (boss && !boss->isAlive() && !bossDefeated) {
        bossDefeated = true;
        calculateAndSaveStars();
        resultState = ResultState::VICTORY;
    }

    // Проверяем смерть игрока
    if (player && !player->isAlive() && resultState == ResultState::PLAYING) {
        if (livesLeft == -1) {
            // Бесконечные жизни (режим "Нуб")
            respawnPlayer();
        } else if (livesLeft > 0) {
            livesLeft--;
            respawnPlayer();
        } else {
            resultState = ResultState::DEFEAT;
        }
    }
}

// ============================================================
//  РЕСПАВН
// ============================================================

void GameScene::respawnPlayer() {
    // Позиция вычисляется в одном месте — нет дублирования с initPositions
    auto [px, py] = getPlayerSpawnPos();
    player = std::make_unique<Player>(px, py);
    playerTookDamage = true;
}

// ============================================================
//  ПОДСЧЁТ ЗВЁЗД
// ============================================================

void GameScene::calculateAndSaveStars() {
    earnedStars = 1; // за убийство босса — всегда
    if (!playerTookDamage)                    earnedStars++;
    if (levelTimer <= TIME_LIMIT_SECONDS)     earnedStars++;

    int prev = Config::getLevelStars(currentLevel);
    if (earnedStars > prev)
        Config::setLevelStars(currentLevel, earnedStars);
}

// ============================================================
//  РЕНДЕР
// ============================================================

void GameScene::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 6, 6, 13, 255);
    SDL_Rect bg = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
    SDL_RenderFillRect(renderer, &bg);

    if (currentLevel == 0) drawLevel1Map(renderer);

    if (player) player->render(renderer);
    if (boss)   boss->render(renderer);

    drawHealthBars(renderer);

    // --- Пауза ---
    if (isPaused && resultState == ResultState::PLAYING) {
        drawUIOverlay(renderer, 150);
        drawText(renderer, Config::getFont(), "ПАУЗА", 0, 100,
                 {255, 255, 100, 255}, true, Config::getTitleFont());
        drawButton(renderer, Config::getFont(), continueBtn);
        drawButton(renderer, Config::getFont(), saveBtn);
        drawButton(renderer, Config::getFont(), exitBtn);
        drawText(renderer, Config::getFont(), "ESC - продолжить",
                 0, Config::getWindowHeight() - 50, {200, 200, 200, 255}, true);
        return;
    }

    if (resultState == ResultState::VICTORY) { renderVictoryScreen(renderer); return; }
    if (resultState == ResultState::DEFEAT)  { renderDefeatScreen(renderer); }
}

// ============================================================
//  ЭКРАН ПОБЕДЫ
// ============================================================

void GameScene::renderVictoryScreen(SDL_Renderer* renderer) {
    const int W = Config::getWindowWidth();
    drawUIOverlay(renderer, 170);
    drawText(renderer, Config::getFont(), "ПОБЕДА!",
             0, 130, {255, 215, 0, 255}, true, Config::getTitleFont());

    int mins = (int)levelTimer / 60;
    int secs = (int)levelTimer % 60;
    char timeBuf[32];
    std::snprintf(timeBuf, sizeof(timeBuf), "Время: %d:%02d", mins, secs);
    drawText(renderer, Config::getFont(), timeBuf, 0, 210, {200, 200, 200, 255}, true);

    constexpr int STAR_SIZE = 35;
    constexpr int STAR_GAP  = 40;
    const int totalW  = 3 * (STAR_SIZE * 2) + 2 * STAR_GAP;
    const int startX  = (W - totalW) / 2 + STAR_SIZE;
    constexpr int starY = 290;

    const char* labels[3] = {"Убить", "3 минуты", "Без урона"};
    for (int i = 0; i < 3; i++) {
        int cx = startX + i * (STAR_SIZE * 2 + STAR_GAP);
        drawStar(renderer, cx, starY, STAR_SIZE, (i < starsRevealed) && (i < earnedStars));
        SDL_Color c = (i < earnedStars) ? SDL_Color{255, 215, 0, 255} : SDL_Color{120, 120, 120, 255};
        drawText(renderer, Config::getFont(), labels[i], cx - STAR_SIZE, starY + STAR_SIZE + 12, c);
    }

    if (starsRevealed >= earnedStars)
        drawButton(renderer, Config::getFont(), nextBtn);
}

// ============================================================
//  ЭКРАН ПОРАЖЕНИЯ
// ============================================================

void GameScene::renderDefeatScreen(SDL_Renderer* renderer) {
    drawUIOverlay(renderer, 170);
    drawText(renderer, Config::getFont(), "ПОРАЖЕНИЕ",
             0, 160, {220, 50, 50, 255}, true, Config::getTitleFont());

    int mins = (int)levelTimer / 60;
    int secs = (int)levelTimer % 60;
    char timeBuf[32];
    std::snprintf(timeBuf, sizeof(timeBuf), "Прожил: %d:%02d", mins, secs);
    drawText(renderer, Config::getFont(), timeBuf, 0, 250, {200, 200, 200, 255}, true);

    // Позиции кнопок выставлены в конструкторе — здесь только рисуем
    drawButton(renderer, Config::getFont(), retryBtn);
    drawButton(renderer, Config::getFont(), exitBtn);
}

// ============================================================
//  ЗВЕЗДА
// ============================================================

void GameScene::drawStar(SDL_Renderer* renderer, int cx, int cy, int size, bool filled) {
    SDL_SetRenderDrawColor(renderer, 180, 150, 0, 255);
    SDL_Rect outline = {cx - size, cy - size, size * 2, size * 2};
    SDL_RenderDrawRect(renderer, &outline);
    SDL_SetRenderDrawColor(renderer, filled ? 255 : 55, filled ? 215 : 55, filled ? 0 : 55, 255);
    SDL_Rect inner = {cx - size + 2, cy - size + 2, size * 2 - 4, size * 2 - 4};
    SDL_RenderFillRect(renderer, &inner);
}

// ============================================================
//  HP БАРЫ + ЖИЗНИ
// ============================================================

void GameScene::drawHealthBars(SDL_Renderer* renderer) {
    const int W = Config::getWindowWidth();

    // --- HP игрока ---
    if (player) {
        float pct = player->getHP() / player->getMaxHP();
        drawText(renderer, Config::getFont(), "Игрок", 20, 15, {200, 200, 200, 255});

        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
        SDL_Rect bg = {20, 38, 200, 18};
        SDL_RenderFillRect(renderer, &bg);
        SDL_SetRenderDrawColor(renderer, 60, 200, 60, 255);
        SDL_Rect bar = {20, 38, (int)(200 * pct), 18};
        SDL_RenderFillRect(renderer, &bar);
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderDrawRect(renderer, &bg);

        // Жизни
        constexpr int LIFE_W   = 16;
        constexpr int LIFE_H   = 12;
        constexpr int LIFE_GAP = 4;
        if (livesLeft == -1) {
            drawText(renderer, Config::getFont(), "∞", 20, 62, {100, 200, 255, 255});
        } else {
            const int total = std::min(livesLeft, 10);
            for (int i = 0; i < total; i++) {
                SDL_SetRenderDrawColor(renderer, 60, 160, 255, 255);
                SDL_Rect cell = {20 + i * (LIFE_W + LIFE_GAP), 62, LIFE_W, LIFE_H};
                SDL_RenderFillRect(renderer, &cell);
                SDL_SetRenderDrawColor(renderer, 120, 200, 255, 200);
                SDL_RenderDrawRect(renderer, &cell);
            }
        }
    }

    // --- Таймер по центру ---
    if (resultState == ResultState::PLAYING) {
        int remaining = std::max(0, (int)(TIME_LIMIT_SECONDS - levelTimer));
        char buf[16];
        std::snprintf(buf, sizeof(buf), "%d:%02d", remaining / 60, remaining % 60);
        drawText(renderer, Config::getFont(), buf, 0, 15, {255, 255, 255, 255}, true);
    }

    // --- HP босса ---
    if (boss) {
        float pct = boss->getHP() / boss->getMaxHP();
        drawText(renderer, Config::getFont(), "Босс", W - 220, 15, {200, 200, 200, 255});

        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
        SDL_Rect bg = {W - 220, 38, 200, 18};
        SDL_RenderFillRect(renderer, &bg);
        SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
        SDL_Rect bar = {W - 220, 38, (int)(200 * pct), 18};
        SDL_RenderFillRect(renderer, &bar);
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderDrawRect(renderer, &bg);
    }
}

void GameScene::saveGame() {}

SceneType GameScene::getNextScene() {
    return nextScene;
}