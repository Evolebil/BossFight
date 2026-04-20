/**
 * @file save_manager.cpp
 * @brief Реализация SaveManager
 * @author evol
 * @date 2026-04-21
 *
 * ФОРМАТ autosave.txt и save<N>_<name>.txt:
 * ─────────────────────────────────────────
 * [объекты]
 * player_x <float>
 * player_y <float>
 * player_facing <0|1>
 * player_hp <float>
 * boss_x <float>
 * boss_y <float>
 * boss_facing <0|1>
 * boss_hp <float>
 * [прогресс]
 * level_timer <float>
 * current_level <int>
 * lives_left <int>
 * best_stars_0 <int>
 * best_stars_1 <int>
 * best_stars_2 <int>
 * difficulty <int>
 * [управление]  ← только в именованных файлах
 * attack_mouse <int>
 * magic_mouse <int>
 * jump_key <int>
 * left_key <int>
 * right_key <int>
 * crouch_key <int>
 * interact_key <int>
 * dash_key <int>
 * shield_key <int>
 *
 * ФОРМАТ saves_index.txt:
 * ────────────────────────
 * next_number <int>
 * count <int>
 * entry <number> <filename> <name с пробелами...>
 * ...
 */
#include "save_manager.h"

#include <fstream>
#include <sstream>
#include <filesystem>  // C++17 — удаление файлов
#include <iostream>

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ (приватные)
// ============================================================

std::string SaveManager::makeFilename(int number, const std::string& name) const {
    // Заменяем пробелы на '_' чтобы имя файла не ломалось
    std::string safeName = name;
    for (char& c : safeName) {
        if (c == ' ') c = '_';
    }
    return std::string(SAVE_DIR) + "save" + std::to_string(number) + "_" + safeName + ".txt";
}

void SaveManager::writeAutosaveFile(const GameSaveState& state) {
    std::ofstream f(AUTOSAVE_FILE);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Не могу открыть " << AUTOSAVE_FILE << "\n";
        return;
    }

    // --- Объекты ---
    f << "player_x "      << state.player.x           << "\n";
    f << "player_y "      << state.player.y           << "\n";
    f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
    f << "player_hp "     << state.player.hp          << "\n";
    f << "boss_x "        << state.boss.x             << "\n";
    f << "boss_y "        << state.boss.y             << "\n";
    f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
    f << "boss_hp "       << state.boss.hp            << "\n";
    f << "boss_phase "    << state.bossPhase          << "\n";

    // --- Прогресс ---
    f << "level_timer "   << state.levelTimer         << "\n";
    f << "current_level " << state.currentLevel       << "\n";
    f << "lives_left "    << state.livesLeft          << "\n";
    f << "best_stars_0 "  << state.bestStars[0]       << "\n";
    f << "best_stars_1 "  << state.bestStars[1]       << "\n";
    f << "best_stars_2 "  << state.bestStars[2]       << "\n";
    f << "difficulty "    << state.difficulty         << "\n";
}

void SaveManager::writeSaveFile(const std::string& path,
                                const GameSaveState& state,
                                const std::string& saveName) {
    std::ofstream f(path);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Не могу создать " << path << "\n";
        return;
    }

    // Заголовок
    f << "# Boss Fight Save — " << saveName << "\n";

    // --- Всё из autosave ---
    f << "player_x "      << state.player.x           << "\n";
    f << "player_y "      << state.player.y           << "\n";
    f << "player_facing " << (state.player.facingRight ? 1 : 0) << "\n";
    f << "player_hp "     << state.player.hp          << "\n";
    f << "boss_x "        << state.boss.x             << "\n";
    f << "boss_y "        << state.boss.y             << "\n";
    f << "boss_facing "   << (state.boss.facingRight ? 1 : 0) << "\n";
    f << "boss_hp "       << state.boss.hp            << "\n";
    f << "boss_phase "    << state.bossPhase          << "\n";
    f << "level_timer "   << state.levelTimer         << "\n";
    f << "current_level " << state.currentLevel       << "\n";
    f << "lives_left "    << state.livesLeft          << "\n";
    f << "best_stars_0 "  << state.bestStars[0]       << "\n";
    f << "best_stars_1 "  << state.bestStars[1]       << "\n";
    f << "best_stars_2 "  << state.bestStars[2]       << "\n";
    f << "difficulty "    << state.difficulty         << "\n";

    // --- Управление (только в именованных) ---
    f << "attack_mouse "  << state.attackMouse        << "\n";
    f << "magic_mouse "   << state.magicMouse         << "\n";
    f << "jump_key "      << state.jumpKey            << "\n";
    f << "left_key "      << state.leftKey            << "\n";
    f << "right_key "     << state.rightKey           << "\n";
    f << "crouch_key "    << state.crouchKey          << "\n";
    f << "interact_key "  << state.interactKey        << "\n";
    f << "dash_key "      << state.dashKey            << "\n";
    f << "shield_key "    << state.shieldKey          << "\n";
}

bool SaveManager::readSaveFile(const std::string& path, GameSaveState& out) {
    std::ifstream f(path);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Файл не найден: " << path << "\n";
        return false;
    }

    std::string key;
    while (f >> key) {
        if (key == "#") {
            // Пропускаем строку-комментарий
            std::string line;
            std::getline(f, line);
            continue;
        }

        // Читаем значение после ключа
        if      (key == "player_x")      f >> out.player.x;
        else if (key == "player_y")      f >> out.player.y;
        else if (key == "player_facing") { int v; f >> v; out.player.facingRight = (v == 1); }
        else if (key == "player_hp")     f >> out.player.hp;
        else if (key == "boss_x")        f >> out.boss.x;
        else if (key == "boss_y")        f >> out.boss.y;
        else if (key == "boss_facing")   { int v; f >> v; out.boss.facingRight = (v == 1); }
        else if (key == "boss_hp")       f >> out.boss.hp;
        else if (key == "boss_phase")    f >> out.bossPhase;
        else if (key == "level_timer")   f >> out.levelTimer;
        else if (key == "current_level") f >> out.currentLevel;
        else if (key == "lives_left")    f >> out.livesLeft;
        else if (key == "best_stars_0")  f >> out.bestStars[0];
        else if (key == "best_stars_1")  f >> out.bestStars[1];
        else if (key == "best_stars_2")  f >> out.bestStars[2];
        else if (key == "difficulty")    f >> out.difficulty;
        else if (key == "attack_mouse")  f >> out.attackMouse;
        else if (key == "magic_mouse")   f >> out.magicMouse;
        else if (key == "jump_key")      f >> out.jumpKey;
        else if (key == "left_key")      f >> out.leftKey;
        else if (key == "right_key")     f >> out.rightKey;
        else if (key == "crouch_key")    f >> out.crouchKey;
        else if (key == "interact_key")  f >> out.interactKey;
        else if (key == "dash_key")      f >> out.dashKey;
        else if (key == "shield_key")    f >> out.shieldKey;
        // Неизвестные ключи — пропускаем
    }
    return true;
}

// ============================================================
// АВТОСОХРАНЕНИЕ
// ============================================================

void SaveManager::tickAutosave(float deltaTime, const GameSaveState& state) {
    autosaveTimer += deltaTime;
    if (autosaveTimer >= AUTOSAVE_INTERVAL) {
        autosaveTimer = 0.0f;
        writeAutosaveFile(state);
        lastAutosave  = state;
        hasAutosave   = true;
    }
}

void SaveManager::saveOnExit(const GameSaveState& state) {
    writeAutosaveFile(state);
    lastAutosave = state;
    hasAutosave  = true;
}

bool SaveManager::loadAutosave(GameSaveState& outState) {
    return readSaveFile(AUTOSAVE_FILE, outState);
}

bool SaveManager::hasAutosaveFile() const {
    std::ifstream f(AUTOSAVE_FILE);
    return f.good();
}

// ============================================================
// ИМЕНОВАННЫЕ СОХРАНЕНИЯ
// ============================================================

int SaveManager::createNamedSave(const std::string& name) {
    // Лимит 12 сохранений
    if ((int)entries.size() >= 12) {
        std::cerr << "[SaveManager] Достигнут лимит сохранений (12)\n";
        return -1;
    }

    // Читаем текущий autosave
    GameSaveState state;
    if (!readSaveFile(AUTOSAVE_FILE, state)) {
        // Если autosave нет — берём нули (первый запуск)
        std::cerr << "[SaveManager] autosave не найден, сохраняем пустое состояние\n";
    }

    // Подтягиваем управление из Config
    fillControlsFromConfig(state);

    // Подтягиваем звёзды из Config
    for (int i = 0; i < 3; i++)
        state.bestStars[i] = Config::getLevelStars(i);
    state.difficulty = Config::getCurrentDifficulty();

    // Создаём запись
    SaveEntry entry;
    entry.number   = nextSaveNumber++;
    entry.name     = name;
    entry.filename = makeFilename(entry.number, name);
    entries.push_back(entry);

    // Пишем файл
    writeSaveFile(entry.filename, state, name);

    // Обновляем индекс
    saveIndex();

    return (int)entries.size() - 1;
}

bool SaveManager::overwriteNamedSave(int entryIndex) {
    if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;

    GameSaveState state;
    if (!readSaveFile(AUTOSAVE_FILE, state)) {
        std::cerr << "[SaveManager] overwrite: autosave не найден\n";
        return false;
    }

    fillControlsFromConfig(state);
    for (int i = 0; i < 3; i++)
        state.bestStars[i] = Config::getLevelStars(i);
    state.difficulty = Config::getCurrentDifficulty();

    writeSaveFile(entries[entryIndex].filename, state, entries[entryIndex].name);
    return true;
}

bool SaveManager::loadNamedSave(int entryIndex) {
    if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;

    GameSaveState state;
    if (!readSaveFile(entries[entryIndex].filename, state)) return false;

    // --- Применяем прогресс в Config (всё кроме позиций) ---
    applyProgressToConfig(state);
    applyControlsToConfig(state);

    // --- Позиции записываем в autosave.txt чтобы GameScene их подхватила ---
    writeAutosaveFile(state);
    lastAutosave = state;
    hasAutosave  = true;

    return true;
}

bool SaveManager::deleteNamedSave(int entryIndex) {
    if (entryIndex < 0 || entryIndex >= (int)entries.size()) return false;

    const std::string& path = entries[entryIndex].filename;

    // Удаляем файл
    std::error_code ec;
    std::filesystem::remove(path, ec);
    if (ec) {
        std::cerr << "[SaveManager] Ошибка удаления " << path << ": " << ec.message() << "\n";
        // Не блокируем удаление из индекса
    }

    // Удаляем запись — остальные сдвигаются автоматически (vector::erase)
    entries.erase(entries.begin() + entryIndex);

    // Обновляем индекс
    saveIndex();
    return true;
}

// ============================================================
// ИНДЕКС
// ============================================================

void SaveManager::loadIndex() {
    entries.clear();
    nextSaveNumber = 1;

    std::ifstream f(INDEX_FILE);
    if (!f.is_open()) return;  // файла нет — первый запуск

    std::string key;
    int count = 0;

    while (f >> key) {
        if (key == "next_number") {
            f >> nextSaveNumber;
        } else if (key == "count") {
            f >> count;
        } else if (key == "entry") {
            SaveEntry e;
            f >> e.number >> e.filename;
            // Имя до конца строки (может содержать пробелы)
            std::getline(f, e.name);
            // Убираем ведущий пробел
            if (!e.name.empty() && e.name[0] == ' ')
                e.name.erase(0, 1);
            entries.push_back(e);
        }
    }
}

void SaveManager::saveIndex() {
    std::ofstream f(INDEX_FILE);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Не могу записать " << INDEX_FILE << "\n";
        return;
    }

    f << "next_number " << nextSaveNumber  << "\n";
    f << "count "       << entries.size()  << "\n";
    for (const auto& e : entries) {
        // Формат: entry <number> <filename> <name>
        f << "entry " << e.number << " " << e.filename << " " << e.name << "\n";
    }
}

// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ ПУБЛИЧНЫЕ
// ============================================================

void SaveManager::fillControlsFromConfig(GameSaveState& state) {
    const Config::Controls& c = Config::getControls();
    state.attackMouse  = c.attackMouseButton;
    state.magicMouse   = c.magicMouseButton;
    state.jumpKey      = c.jump;
    state.leftKey      = c.left;
    state.rightKey     = c.right;
    state.crouchKey    = c.crouch;
    state.interactKey  = c.interact;
    state.dashKey      = c.dash;
    state.shieldKey    = c.shield;
}

void SaveManager::applyControlsToConfig(const GameSaveState& state) {
    Config::Controls& c = Config::getControls();
    c.attackMouseButton = state.attackMouse;
    c.magicMouseButton  = state.magicMouse;
    c.jump     = static_cast<SDL_Scancode>(state.jumpKey);
    c.left     = static_cast<SDL_Scancode>(state.leftKey);
    c.right    = static_cast<SDL_Scancode>(state.rightKey);
    c.crouch   = static_cast<SDL_Scancode>(state.crouchKey);
    c.interact = static_cast<SDL_Scancode>(state.interactKey);
    c.dash     = static_cast<SDL_Scancode>(state.dashKey);
    c.shield   = static_cast<SDL_Scancode>(state.shieldKey);
}

void SaveManager::applyProgressToConfig(const GameSaveState& state) {
    for (int i = 0; i < 3; i++)
        Config::setLevelStars(i, state.bestStars[i]);
    Config::setCurrentDifficulty(state.difficulty);
    Config::setSelectedLevel(state.currentLevel);
}