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
#include "../utils/camera.h"
#include "../levels/level1_assets.h"

// Forward declarations
class Player;
class BossGolem;
class SoundManager;

// NOTE: PLAYER_SPAWN_COL/ROW и BOSS_SPAWN_COL/ROW объявлены в level1_assets.h
// Здесь НЕ переопределяем — иначе redefinition error

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
    SceneType     nextScene;
    SoundManager* soundMgr;

    bool isPaused;
    bool gameStarted;

    // Кнопки паузы
    Button continueBtn;
    Button saveBtn;
    Button exitBtn;
    // Кнопки результата
    Button nextBtn;
    Button retryBtn;

    // Персонажи — unique_ptr: не нужен ручной delete
    std::unique_ptr<Player>    player;
    std::unique_ptr<Character>  boss;
    std::unique_ptr<ILevel>     level;
    std::unique_ptr<Camera> camera;

    int   currentLevel;
    int   livesLeft;
    float levelTimer;

    bool playerTookDamage;
    bool bossDefeated;

    ResultState resultState;
    int         earnedStars;
    float       starRevealTimer;
    int         starsRevealed;

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