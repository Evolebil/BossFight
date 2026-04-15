/**
 * @file game_scene.h
 * @brief Игровая сцена — бой с боссом, подсчёт звёзд, экран победы/поражения
 * @author evol
 * @date 2026-02-24
 */
#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"
#include "../levels/ilevel.h"
#include "../characters/boss_golem.h"
#include "../config/config.h"
#include "../characters/player.h"
#include "../utils/sound_manager.h"
#include "../utils/camera.h"      // ← Camera объявлен здесь
#include "../levels/level1_assets.h"

// Forward declarations
class Player;
class BossGolem;
class SoundManager;

// Лимит времени для звезды "быстро" — игровая логика, не данные карты
static constexpr float TIME_LIMIT_SECONDS = 180.0f;

enum class ResultState { PLAYING, VICTORY, DEFEAT };

/**
 * @class GameScene
 * @brief Управляет игровым процессом: обновляет Player и BossGolem,
 *        проверяет урон, считает звёзды, рисует HUD.
 */
class GameScene : public Scene {
private:
    // ============================================================
    // КОНСТАНТЫ КНОПОК
    // ============================================================

    static constexpr int BTN_W             = 300;
    static constexpr int BTN_H             = 60;

    // Кнопки паузы
    static constexpr int BTN_CONTINUE_Y    = 200;
    static constexpr int BTN_SAVE_Y        = 280;
    static constexpr int BTN_EXIT_PAUSE_Y  = 360;

    // Кнопки результата
    static constexpr int BTN_NEXT_Y        = 430;
    static constexpr int BTN_RETRY_Y       = 320;
    static constexpr int BTN_EXIT_RESULT_Y = 400;

    // ============================================================
    // КОНСТАНТЫ HUD (полоски HP/мана, жизни)
    // ============================================================

    static constexpr int HUD_BAR_W        = 200;
    static constexpr int HUD_BAR_H        = 18;
    static constexpr int HUD_BAR_X        = 20;
    static constexpr int HUD_BAR_Y        = 38;
    static constexpr int HUD_LABEL_Y      = 15;

    static constexpr int HUD_MANA_H       = 14;
    static constexpr int HUD_MANA_Y       = 105;
    static constexpr int HUD_MANA_LBL_Y   = 85;
    static constexpr int HUD_MANA_VAL_X   = 230;
    static constexpr int HUD_MANA_VAL_Y   = 103;

    static constexpr int HUD_LIVES_Y      = 62;
    static constexpr int HUD_LIFE_W       = 16;
    static constexpr int HUD_LIFE_H       = 12;
    static constexpr int HUD_LIFE_GAP     = 4;
    static constexpr int HUD_MAX_LIVES    = 10;  // больше 10 жизней не рисуем

    static constexpr int HUD_BOSS_X_OFF   = 220; // отступ HP босса от правого края

    // Подсказки (отступ снизу экрана)
    static constexpr int HUD_HINT_HB_Y    = 30;
    static constexpr int HUD_HINT_ESC_Y   = 55;

    // ============================================================
    // КОНСТАНТЫ ПАУЗЫ
    // ============================================================

    static constexpr int   PAUSE_TITLE_Y   = 100;
    static constexpr int   PAUSE_HINT_Y    = 50;  // отступ от низа экрана
    static constexpr int   OVERLAY_ALPHA   = 150;

    // ============================================================
    // КОНСТАНТЫ ЭКРАНОВ РЕЗУЛЬТАТА
    // ============================================================

    static constexpr int   RESULT_OVERLAY_ALPHA = 170;

    // Победа
    static constexpr int   VICTORY_TITLE_Y      = 130;
    static constexpr int   VICTORY_TIME_Y        = 210;
    static constexpr int   VICTORY_STAR_Y        = 290;
    static constexpr int   VICTORY_STAR_SIZE     = 35;
    static constexpr int   VICTORY_STAR_GAP      = 40;
    static constexpr int   VICTORY_STAR_LABEL_DY = 12; // отступ подписи ниже звезды
    static constexpr float STAR_REVEAL_DELAY     = 0.4f;

    // Поражение
    static constexpr int   DEFEAT_TITLE_Y  = 160;
    static constexpr int   DEFEAT_TIME_Y   = 250;

    // ============================================================
    // КОНСТАНТЫ ЗВЕЗДЫ (drawStar)
    // ============================================================

    static constexpr int STAR_BORDER = 2; // отступ внутренней заливки от рамки

    // ============================================================
    // КОНСТАНТЫ ФОНА ИГРОВОЙ СЦЕНЫ
    // ============================================================

    // Цвет фона — почти чёрный с синеватым оттенком
    static constexpr Uint8 BG_R = 6;
    static constexpr Uint8 BG_G = 6;
    static constexpr Uint8 BG_B = 13;

    // ============================================================
    // ПОЛЯ (с дефолтами — конструктор остаётся чистым)
    // ============================================================

    SceneType     nextScene = SceneType::GAME;
    SoundManager* soundMgr  = nullptr;

    bool isPaused        = false;
    bool gameStarted     = false;

    // Кнопки — инициализируются в конструкторе (зависят от констант)
    Button continueBtn;
    Button saveBtn;
    Button exitBtn;
    Button nextBtn;
    Button retryBtn;

    // Персонажи — unique_ptr: не нужен ручной delete
    std::unique_ptr<Player>    player;
    std::unique_ptr<Character> boss;
    std::unique_ptr<ILevel>    level;
    std::unique_ptr<Camera>    camera;  // ← Camera теперь объявлен через include

    int   currentLevel    = 0;
    int   livesLeft       = 0;
    float levelTimer      = 0.0f;

    bool playerTookDamage = false;
    bool bossDefeated     = false;

    ResultState resultState     = ResultState::PLAYING;
    int         earnedStars     = 0;
    float       starRevealTimer = 0.0f;
    int         starsRevealed   = 0;

public:
    GameScene();
    ~GameScene() override = default;

    void handleInput(SDL_Event& event, int mouseX, int mouseY,
                     bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;

    [[nodiscard]] SceneType getNextScene() override;

private:
    void initPositions();
    void respawnPlayer();
    void saveGame();
    void calculateAndSaveStars();

    [[nodiscard]] std::pair<float, float> getPlayerSpawnPos();

    void drawHealthBars(SDL_Renderer* renderer);
    void renderVictoryScreen(SDL_Renderer* renderer);
    void renderDefeatScreen(SDL_Renderer* renderer);
    void drawStar(SDL_Renderer* renderer, int cx, int cy, int size, bool filled);
};