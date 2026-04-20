/**
 * @file save_manager.h
 * @brief Система сохранений: autosave, именованные сохранения, индекс
 * @author evol
 * @date 2026-04-21
 *
 * ФАЙЛЫ НА ДИСКЕ:
 *   bin/autosave.txt          — текущее состояние (перезаписывается каждую минуту)
 *   bin/save<N>_<name>.txt    — именованное сохранение
 *   bin/saves_index.txt       — порядок и имена сохранений
 *
 * ИСПОЛЬЗОВАНИЕ:
 *   // В game_scene — автосохранение:
 *   SaveManager::get().tickAutosave(deltaTime, gameState);
 *   SaveManager::get().saveOnExit(gameState);
 *
 *   // В saves_scene — именованные:
 *   SaveManager::get().createNamedSave(name);
 *   SaveManager::get().loadNamedSave(index, outState);
 *   SaveManager::get().deleteNamedSave(index);
 */
#pragma once
#include "../config/common.h"
#include "../config/config.h"

// ============================================================
// СТРУКТУРЫ ДАННЫХ
// ============================================================

/**
 * @brief Состояние игрового объекта (позиция + направление + HP)
 */
struct ObjectState {
    float x = 0.0f;
    float y = 0.0f;
    bool  facingRight = true;
    float hp = 0.0f;
};

/**
 * @brief Всё игровое состояние для сохранения/загрузки
 *
 * Заполняется в GameScene, читается в SavesScene / autosave
 */
struct GameSaveState {
    // --- Объекты ---
    ObjectState player;
    ObjectState boss;
    int         bossPhase = 0;   // 0 = PHASE_1, 1 = PHASE_2 (DYING/PAUSING/TRANSITIONING не сохраняем)

    // --- Прогресс текущего забега ---
    float levelTimer    = 0.0f;   // сколько времени прошло
    int   currentLevel  = 0;      // номер текущего уровня (0-based)
    int   livesLeft     = 0;

    // --- Лучший результат ---
    int bestStars[3]    = {0, 0, 0};  // максимум звёзд по уровням

    // --- Управление (копируется из Config::Controls) ---
    int   attackMouse   = 1;
    int   magicMouse    = 3;
    int   jumpKey       = SDL_SCANCODE_SPACE;
    int   leftKey       = SDL_SCANCODE_A;
    int   rightKey      = SDL_SCANCODE_D;
    int   crouchKey     = SDL_SCANCODE_S;
    int   interactKey   = SDL_SCANCODE_E;
    int   dashKey       = SDL_SCANCODE_LSHIFT;
    int   shieldKey     = SDL_SCANCODE_F;

    // --- Сложность ---
    int   difficulty    = 2;
};

/**
 * @brief Запись в индексе сохранений
 */
struct SaveEntry {
    int         number;      // порядковый номер (уникальный, для имени файла)
    std::string name;        // имя введённое пользователем
    std::string filename;    // полный путь к файлу
};

// ============================================================
// SAVE MANAGER
// ============================================================

/**
 * @class SaveManager
 * @brief Синглтон — управляет всеми сохранениями
 *
 * Потокобезопасность: НЕ нужна (однопоточная игра).
 */
class SaveManager {
private:
    // --- Пути ---
    static constexpr const char* SAVE_DIR       = "";
    static constexpr const char* AUTOSAVE_FILE  = "autosave.txt";
    static constexpr const char* INDEX_FILE     = "saves_index.txt";

    // --- Автосохранение ---
    static constexpr float AUTOSAVE_INTERVAL    = 60.0f;  // секунды
    float autosaveTimer = 0.0f;

    // --- Индекс сохранений ---
    std::vector<SaveEntry> entries;
    int nextSaveNumber = 1;   // счётчик для уникального имени файла

    // --- Кэш последнего autosave ---
    GameSaveState lastAutosave;
    bool hasAutosave = false;

    SaveManager() = default;

public:
    // Синглтон
    static SaveManager& get() {
        static SaveManager instance;
        return instance;
    }

    SaveManager(const SaveManager&)            = delete;
    SaveManager& operator=(const SaveManager&) = delete;

    // --------------------------------------------------------
    // АВТОСОХРАНЕНИЕ (вызывать из GameScene)
    // --------------------------------------------------------

    /**
     * @brief Тикает таймер автосохранения. Вызывать каждый кадр.
     * @param deltaTime Время кадра в секундах
     * @param state     Текущее состояние игры
     */
    void tickAutosave(float deltaTime, const GameSaveState& state);

    /**
     * @brief Сохраняет немедленно (при выходе из уровня).
     */
    void saveOnExit(const GameSaveState& state);

    /**
     * @brief Загружает autosave.txt → state. Возвращает false если файла нет.
     */
    [[nodiscard]] bool loadAutosave(GameSaveState& outState);

    [[nodiscard]] bool hasAutosaveFile() const;

    // --------------------------------------------------------
    // ИМЕНОВАННЫЕ СОХРАНЕНИЯ (вызывать из SavesScene)
    // --------------------------------------------------------

    /**
     * @brief Создаёт именованное сохранение из текущего autosave.
     * @param name Имя введённое пользователем
     * @return Индекс нового сохранения в entries, -1 при ошибке
     */
    [[nodiscard]] int createNamedSave(const std::string& name);

    /**
     * @brief Перезаписывает существующее сохранение (кнопка "Сохранить").
     * @param entryIndex Индекс в entries
     */
    bool overwriteNamedSave(int entryIndex);

    /**
     * @brief Загружает именованное сохранение.
     *        Прогресс (bestStars, difficulty) применяется к Config.
     *        Позиции записываются в autosave.txt для подхвата GameScene.
     * @param entryIndex Индекс в entries
     */
    bool loadNamedSave(int entryIndex);

    /**
     * @brief Удаляет файл и запись из индекса.
     * @param entryIndex Индекс в entries (после удаления записи сдвигаются)
     */
    bool deleteNamedSave(int entryIndex);

    // --------------------------------------------------------
    // ИНДЕКС
    // --------------------------------------------------------

    /**
     * @brief Загружает saves_index.txt → entries. Вызывать при запуске.
     */
    void loadIndex();

    /**
     * @brief Сохраняет entries → saves_index.txt.
     */
    void saveIndex();

    [[nodiscard]] const std::vector<SaveEntry>& getEntries() const { return entries; }
    [[nodiscard]] int getEntryCount() const { return (int)entries.size(); }

    // --------------------------------------------------------
    // ВСПОМОГАТЕЛЬНЫЕ
    // --------------------------------------------------------

    /**
     * @brief Заполняет GameSaveState из текущего Config::Controls.
     */
    static void fillControlsFromConfig(GameSaveState& state);

    /**
     * @brief Применяет управление из GameSaveState в Config::Controls.
     */
    static void applyControlsToConfig(const GameSaveState& state);

    /**
     * @brief Применяет прогресс (звёзды, сложность) из state в Config.
     */
    static void applyProgressToConfig(const GameSaveState& state);

private:
    void writeAutosaveFile(const GameSaveState& state);
    bool readSaveFile(const std::string& path, GameSaveState& outState);
    void writeSaveFile(const std::string& path, const GameSaveState& state, const std::string& saveName);
    [[nodiscard]] std::string makeFilename(int number, const std::string& name) const;
};