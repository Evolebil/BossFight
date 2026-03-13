#include "../utils/scene_manager.h"
#include "game_scene.h"
#include "../config/config.h"
#include "../ui/ui.h"
#include "../levels/level1_assets.h"
#include "../characters/boss_golem.h"
#include "../characters/player.h"
#include "../utils/sound_manager.h"

// ============================================================
//  КОНСТРУКТОР / ДЕСТРУКТОР
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
    starsRevealed(0)
{
    int W = Config::getWindowWidth();
    continueBtn.centerX(W);
    saveBtn.centerX(W);
    exitBtn.centerX(W);
    nextBtn.centerX(W);
    retryBtn.centerX(W);

    currentLevel = Config::getSelectedLevel();
    initPositions();
}

GameScene::~GameScene() {
    delete player;
    delete boss;
}

void GameScene::initPositions() {
    int offsetX = 0, offsetY = 0;
    getMapOffset(offsetX, offsetY);

    float playerX = offsetX + PLAYER_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f;
    float playerY = offsetY + PLAYER_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f;
    float bossX   = offsetX + BOSS_SPAWN_COL   * TILE_SIZE + TILE_SIZE / 2.0f;
    float bossY   = offsetY + BOSS_SPAWN_ROW   * TILE_SIZE + TILE_SIZE / 2.0f;

    int diffIdx = Config::getCurrentDifficulty();
    const Config::Difficulty* diffs = Config::getDifficulties();
    const Config::Difficulty& diff  = diffs[diffIdx];

    livesLeft = diff.respawns;

    player = new Player(playerX, playerY);
    boss   = new BossGolem(bossX, bossY, diff.projectileSpeed);
    gameStarted = true;
}

// ============================================================
//  ВВОД
// ============================================================

void GameScene::handleInput(SDL_Event& event, int mouseX, int mouseY,
                            bool mouseClicked, bool mouseDown) {
    if (resultState == ResultState::PLAYING) {
        if (event.type == SDL_KEYDOWN &&
            event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            isPaused = !isPaused;
            if (soundMgr) soundMgr->playClick();
        }
    }

    if (isPaused && resultState == ResultState::PLAYING) {
        continueBtn.isHovered = continueBtn.contains(mouseX, mouseY);
        if (continueBtn.isHovered && !continueBtn.wasHovered && soundMgr) soundMgr->playHover();
        continueBtn.wasHovered = continueBtn.isHovered;
        if (continueBtn.isHovered && mouseClicked) { if (soundMgr) soundMgr->playClick(); isPaused = false; }

        saveBtn.isHovered = saveBtn.contains(mouseX, mouseY);
        if (saveBtn.isHovered && !saveBtn.wasHovered && soundMgr) soundMgr->playHover();
        saveBtn.wasHovered = saveBtn.isHovered;
        if (saveBtn.isHovered && mouseClicked) { if (soundMgr) soundMgr->playClick(); saveGame(); }

        exitBtn.isHovered = exitBtn.contains(mouseX, mouseY);
        if (exitBtn.isHovered && !exitBtn.wasHovered && soundMgr) soundMgr->playHover();
        exitBtn.wasHovered = exitBtn.isHovered;
        if (exitBtn.isHovered && mouseClicked) { if (soundMgr) soundMgr->playClick(); nextScene = SceneType::LEVEL_SELECT; }
        return;
    }

    if (resultState == ResultState::VICTORY && starsRevealed >= earnedStars) {
        nextBtn.isHovered = nextBtn.contains(mouseX, mouseY);
        if (nextBtn.isHovered && !nextBtn.wasHovered && soundMgr) soundMgr->playHover();
        nextBtn.wasHovered = nextBtn.isHovered;
        if (nextBtn.isHovered && mouseClicked) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::LEVEL_SELECT;
        }
    }

    if (resultState == ResultState::DEFEAT) {
        retryBtn.isHovered = retryBtn.contains(mouseX, mouseY);
        if (retryBtn.isHovered && !retryBtn.wasHovered && soundMgr) soundMgr->playHover();
        retryBtn.wasHovered = retryBtn.isHovered;
        if (retryBtn.isHovered && mouseClicked) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::RESTART_GAME;
        }

        exitBtn.isHovered = exitBtn.contains(mouseX, mouseY);
        if (exitBtn.isHovered && !exitBtn.wasHovered && soundMgr) soundMgr->playHover();
        exitBtn.wasHovered = exitBtn.isHovered;
        if (exitBtn.isHovered && mouseClicked) {
            if (soundMgr) soundMgr->playClick();
            nextScene = SceneType::LEVEL_SELECT;
        }
    }
}

// ============================================================
//  UPDATE
// ============================================================

void GameScene::update(float deltaTime) {
    if (isPaused) return;

    if (resultState != ResultState::PLAYING) {
        if (resultState == ResultState::VICTORY && starsRevealed < earnedStars) {
            starRevealTimer += deltaTime;
            if (starRevealTimer >= 0.4f) {
                starRevealTimer = 0.0f;
                starsRevealed++;
            }
        }
        return;
    }

    levelTimer += deltaTime;

    if (player) player->update(deltaTime);

    if (boss && player) {
        boss->update(deltaTime, player->getX(), player->getY());

        SDL_Rect pb = player->getHitbox();
        float dmgToPlayer = boss->checkPlayerDamage(pb, deltaTime);
        if (dmgToPlayer > 0.0f) {
            player->takeDamage(dmgToPlayer);
            playerTookDamage = true;
        }

        float dmgToBoss = player->consumeAttackDamage();
        if (dmgToBoss > 0.0f) {
            SDL_Rect atk     = player->getAttackHitbox();
            SDL_Rect boss_hb = boss->getHitbox();
            bool hit = (atk.x < boss_hb.x + boss_hb.w &&
                        atk.x + atk.w > boss_hb.x &&
                        atk.y < boss_hb.y + boss_hb.h &&
                        atk.y + atk.h > boss_hb.y);
            if (hit) boss->takeDamage(dmgToBoss);
        }
    }

    if (boss && !boss->isAlive() && !bossDefeated) {
        bossDefeated = true;
        calculateAndSaveStars();
        resultState = ResultState::VICTORY;
    }

    if (player && !player->isAlive() && resultState == ResultState::PLAYING) {
        if (livesLeft == -1) {
            respawnPlayer();
        } else if (livesLeft > 0) {
            livesLeft--;
            respawnPlayer();
        } else {
            resultState = ResultState::DEFEAT;
        }
    }
}

void GameScene::respawnPlayer() {
    int offsetX = 0, offsetY = 0;
    getMapOffset(offsetX, offsetY);

    float playerX = offsetX + PLAYER_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f;
    float playerY = offsetY + PLAYER_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f;

    delete player;
    player = new Player(playerX, playerY);
    playerTookDamage = true;
}

// ============================================================
//  ПОДСЧЁТ ЗВЁЗД
// ============================================================

void GameScene::calculateAndSaveStars() {
    earnedStars = 0;
    earnedStars++; // убил босса
    if (!playerTookDamage) earnedStars++;
    if (levelTimer <= TIME_LIMIT_SECONDS) earnedStars++;

    int prev = Config::getLevelStars(currentLevel);
    if (earnedStars > prev)
        Config::setLevelStars(currentLevel, earnedStars);
}

// ============================================================
//  РЕНДЕР
// ============================================================

void GameScene::render(SDL_Renderer* renderer) {
    // Фон — чёрно-синий (19/20 чёрного, 1/20 синего)
    SDL_SetRenderDrawColor(renderer, 6, 6, 13, 255);
    SDL_Rect bg = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
    SDL_RenderFillRect(renderer, &bg);

    // Карта
    if (currentLevel == 0) drawLevel1Map(renderer);

    // Персонажи
    if (player) player->render(renderer);
    if (boss)   boss->render(renderer);

    // HUD
    drawHealthBars(renderer);

    // --- Пауза ---
    if (isPaused && resultState == ResultState::PLAYING) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);
        SDL_Rect ol = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
        SDL_RenderFillRect(renderer, &ol);
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
    int W = Config::getWindowWidth();
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 170);
    SDL_Rect ol = {0, 0, W, Config::getWindowHeight()};
    SDL_RenderFillRect(renderer, &ol);

    drawText(renderer, Config::getFont(), "ПОБЕДА!",
             0, 130, {255, 215, 0, 255}, true, Config::getTitleFont());

    int mins = (int)levelTimer / 60;
    int secs = (int)levelTimer % 60;
    char timeBuf[32];
    std::snprintf(timeBuf, sizeof(timeBuf), "Время: %d:%02d", mins, secs);
    drawText(renderer, Config::getFont(), timeBuf, 0, 210, {200, 200, 200, 255}, true);

    constexpr int STAR_SIZE = 35;
    constexpr int STAR_GAP  = 40;
    int totalW = 3 * (STAR_SIZE * 2) + 2 * STAR_GAP;
    int startX = (W - totalW) / 2 + STAR_SIZE;
    int starY  = 290;

    for (int i = 0; i < 3; i++) {
        int cx = startX + i * (STAR_SIZE * 2 + STAR_GAP);
        drawStar(renderer, cx, starY, STAR_SIZE, (i < starsRevealed) && (i < earnedStars));
    }

    const char* labels[3] = {"Убить", "3 минуты", "Без урона"};
    for (int i = 0; i < 3; i++) {
        int cx = startX + i * (STAR_SIZE * 2 + STAR_GAP);
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
    int W = Config::getWindowWidth();
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 170);
    SDL_Rect ol = {0, 0, W, Config::getWindowHeight()};
    SDL_RenderFillRect(renderer, &ol);

    drawText(renderer, Config::getFont(), "ПОРАЖЕНИЕ",
             0, 160, {220, 50, 50, 255}, true, Config::getTitleFont());

    int mins = (int)levelTimer / 60;
    int secs = (int)levelTimer % 60;
    char timeBuf[32];
    std::snprintf(timeBuf, sizeof(timeBuf), "Прожил: %d:%02d", mins, secs);
    drawText(renderer, Config::getFont(), timeBuf, 0, 250, {200, 200, 200, 255}, true);

    // Позиционируем кнопки здесь, чтобы не конфликтовать с координатами паузы
    retryBtn.rect.y = 320;
    retryBtn.rect.x = (W - retryBtn.rect.w) / 2;
    exitBtn.rect.y  = 400;
    exitBtn.rect.x  = (W - exitBtn.rect.w) / 2;

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
    int W = Config::getWindowWidth();

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

        // Жизни — ячейки под HP баром
        // livesLeft == -1 → бесконечно (рисуем символ ∞)
        int lifeX = 20;
        int lifeY = 62;
        constexpr int LIFE_W = 16;
        constexpr int LIFE_H = 12;
        constexpr int LIFE_GAP = 4;

        if (livesLeft == -1) {
            drawText(renderer, Config::getFont(), "∞", lifeX, lifeY, {100, 200, 255, 255});
        } else {
            // Максимум показываем 10 ячеек
            int total = std::min(livesLeft, 10);
            for (int i = 0; i < total; i++) {
                SDL_SetRenderDrawColor(renderer, 60, 160, 255, 255);
                SDL_Rect cell = {lifeX + i * (LIFE_W + LIFE_GAP), lifeY, LIFE_W, LIFE_H};
                SDL_RenderFillRect(renderer, &cell);
                SDL_SetRenderDrawColor(renderer, 120, 200, 255, 200);
                SDL_RenderDrawRect(renderer, &cell);
            }
            // Если жизней 0 — ничего не рисуем (последняя жизнь)
        }
    }

    // --- Таймер по центру сверху ---
    if (resultState == ResultState::PLAYING) {
        int remaining = (int)(TIME_LIMIT_SECONDS - levelTimer);
        if (remaining < 0) remaining = 0;
        int mins = remaining / 60;
        int secs = remaining % 60;
        char buf[16];
        std::snprintf(buf, sizeof(buf), "%d:%02d", mins, secs);
        drawText(renderer, Config::getFont(), buf,
                 0, 15, {255, 255, 255, 255}, true);
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

// ============================================================
//  ПРОЧЕЕ
// ============================================================

void GameScene::saveGame() {}

SceneType GameScene::getNextScene() {
    return nextScene;
}
