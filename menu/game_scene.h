/**
 * @file game_scene.h
 * @brief Игровая сцена — бой с боссом, подсчёт звёзд, экран победы/поражения
 * @author evol
 * @date 2026-02-24
 */

#pragma once
#include "../utils/scene_manager.h"
#include "../ui/ui.h"

class SoundManager;
class Player;
class BossGolem;

class GameScene : public Scene {
private:
    SceneType nextScene;
    SoundManager* soundMgr;
    bool isPaused;
    bool gameStarted;

    // --- Кнопки паузы ---
    Button continueBtn;
    Button saveBtn;
    Button exitBtn;

    // --- Кнопки экрана результата ---
    Button nextBtn;     // "В меню уровней" (победа)
    Button retryBtn;    // "Заново" (поражение)

    // --- Персонажи ---
    Player*    player;
    BossGolem* boss;
    int        currentLevel;

    // --- Система жизней ---
    int livesLeft;      // сколько жизней осталось (-1 = бесконечно)

    // ==============================================
    //  СИСТЕМА ЗАВЕРШЕНИЯ УРОВНЯ
    // ==============================================

    float levelTimer;           // Сколько секунд прошло с начала боя
    bool  playerTookDamage;     // Получал ли игрок урон (звезда "Без урона")
    bool  bossDefeated;         // Флаг чтобы не вызывать calculateAndSaveStars дважды

    // Состояние: бой / победа / поражение
    enum class ResultState { PLAYING, VICTORY, DEFEAT };
    ResultState resultState;

    int   earnedStars;          // Сколько звёзд заработано (0-3)
    float starRevealTimer;      // Таймер анимации появления звёзд
    int   starsRevealed;        // Сколько звёзд уже показано

    // Условие: 3 минуты
    static constexpr float TIME_LIMIT_SECONDS = 180.0f;

public:
    GameScene();
    ~GameScene();

    void initPositions();
    void handleInput(SDL_Event& event, int mouseX, int mouseY,
                     bool mouseClicked, bool mouseDown) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    SceneType getNextScene() override;

private:
    void drawHealthBars(SDL_Renderer* renderer);
    void saveGame();
    void respawnPlayer();  // пересоздаёт игрока на стартовой позиции

    // Считает звёзды и сохраняет в Config
    void calculateAndSaveStars();

    // Экраны результата
    void renderVictoryScreen(SDL_Renderer* renderer);
    void renderDefeatScreen(SDL_Renderer* renderer);

    // Рисует один квадрат-звезду
    void drawStar(SDL_Renderer* renderer, int cx, int cy, int size, bool filled);
};
