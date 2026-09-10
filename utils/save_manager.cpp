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
// 16-РИЧНОЕ КОДИРОВАНИЕ ФАЙЛА
// ============================================================
// Не криптография — просто обфускация. Не даёт открыть сохранение
// в блокноте и вручную подправить значения. От целенаправленного
// взлома не защищает.

static std::string toHex(const std::string& data) {
    static const char* hexDigits = "0123456789abcdef";
    std::string out;
    out.reserve(data.size() * 2);
    for (unsigned char c : data) {
        out.push_back(hexDigits[c >> 4]);
        out.push_back(hexDigits[c & 0x0F]);
    }
    return out;
}

// false = не hex (нечётная длина или запрещённый символ) — сигнал о повреждённом файле
static bool fromHex(const std::string& hex, std::string& out) {
    if (hex.size() % 2 != 0) return false;
    out.clear();
    out.reserve(hex.size() / 2);

    auto hexVal = [](char c) -> int {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        return -1;
    };

    for (size_t i = 0; i < hex.size(); i += 2) {
        int hi = hexVal(hex[i]);
        int lo = hexVal(hex[i + 1]);
        if (hi < 0 || lo < 0) return false;
        out.push_back(static_cast<char>((hi << 4) | lo));
    }
    return true;
}

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

int SaveManager::findFreeSaveNumber() const {
    // Минимальный свободный положительный номер, а не растущий счётчик —
    // после удаления сохранения его номер снова становится доступен.
    int n = 1;
    while (true) {
        bool taken = false;
        for (const auto& e : entries) {
            if (e.number == n) { taken = true; break; }
        }
        if (!taken) return n;
        n++;
    }
}

void SaveManager::writeAutosaveFile(const GameSaveState& state) {
    std::ostringstream oss;

    // --- Объекты ---
    oss << "player_x "          << state.player.x           << "\n";
    oss << "player_y "          << state.player.y           << "\n";
    oss << "player_facing "     << (state.player.facingRight ? 1 : 0) << "\n";
    oss << "player_hp "         << state.player.hp          << "\n";
    oss << "player_move_speed " << state.playerMoveSpeed    << "\n";
    oss << "boss_x "            << state.boss.x             << "\n";
    oss << "boss_y "            << state.boss.y             << "\n";
    oss << "boss_facing "       << (state.boss.facingRight ? 1 : 0) << "\n";
    oss << "boss_hp "           << state.boss.hp            << "\n";
    oss << "boss_max_hp "       << state.bossMaxHP          << "\n";
    oss << "boss_phase "        << state.bossPhase          << "\n";

    // --- Прогресс ---
    oss << "level_timer "   << state.levelTimer         << "\n";
    oss << "current_level " << state.currentLevel       << "\n";
    oss << "lives_left "    << state.livesLeft          << "\n";
    oss << "best_stars_0 "  << state.bestStars[0]       << "\n";
    oss << "best_stars_1 "  << state.bestStars[1]       << "\n";
    oss << "best_stars_2 "  << state.bestStars[2]       << "\n";
    oss << "difficulty "    << state.difficulty         << "\n";

    std::ofstream f(AUTOSAVE_FILE, std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Не могу открыть " << AUTOSAVE_FILE << "\n";
        return;
    }
    f << toHex(oss.str());
}

void SaveManager::writeSaveFile(const std::string& path,
                                const GameSaveState& state,
                                const std::string& saveName) {
    std::ostringstream oss;

    // Заголовок
    oss << "# Boss Fight Save — " << saveName << "\n";

    // --- Всё из autosave ---
    oss << "player_x "          << state.player.x           << "\n";
    oss << "player_y "          << state.player.y           << "\n";
    oss << "player_facing "     << (state.player.facingRight ? 1 : 0) << "\n";
    oss << "player_hp "         << state.player.hp          << "\n";
    oss << "player_move_speed " << state.playerMoveSpeed    << "\n";
    oss << "boss_x "            << state.boss.x             << "\n";
    oss << "boss_y "            << state.boss.y             << "\n";
    oss << "boss_facing "       << (state.boss.facingRight ? 1 : 0) << "\n";
    oss << "boss_hp "           << state.boss.hp            << "\n";
    oss << "boss_max_hp "       << state.bossMaxHP          << "\n";
    oss << "boss_phase "        << state.bossPhase          << "\n";
    oss << "level_timer "       << state.levelTimer         << "\n";
    oss << "current_level "     << state.currentLevel       << "\n";
    oss << "lives_left "        << state.livesLeft          << "\n";
    oss << "best_stars_0 "      << state.bestStars[0]       << "\n";
    oss << "best_stars_1 "      << state.bestStars[1]       << "\n";
    oss << "best_stars_2 "      << state.bestStars[2]       << "\n";
    oss << "difficulty "        << state.difficulty         << "\n";

    // --- Управление (только в именованных) ---
    oss << "attack_mouse "  << state.attackMouse        << "\n";
    oss << "magic_mouse "   << state.magicMouse         << "\n";
    oss << "jump_key "      << state.jumpKey            << "\n";
    oss << "left_key "      << state.leftKey            << "\n";
    oss << "right_key "     << state.rightKey           << "\n";
    oss << "crouch_key "    << state.crouchKey          << "\n";
    oss << "interact_key "  << state.interactKey        << "\n";
    oss << "dash_key "      << state.dashKey            << "\n";
    oss << "shield_key "    << state.shieldKey          << "\n";

    std::ofstream f(path, std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Не могу создать " << path << "\n";
        return;
    }
    f << toHex(oss.str());
}

bool SaveManager::readSaveFile(const std::string& path, GameSaveState& out) {
    std::ifstream f(path, std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "[SaveManager] Файл не найден: " << path << "\n";
        return false;
    }

    std::string hexContent((std::istreambuf_iterator<char>(f)),
                           std::istreambuf_iterator<char>());

    std::string content;
    if (!fromHex(hexContent, content)) {
        // Файл повреждён или отредактирован вручную (не валидный hex) —
        // безопасно отказываемся грузить, без краша.
        std::cerr << "[SaveManager] Повреждённый файл сохранения: " << path << "\n";
        return false;
    }

    std::istringstream stream(content);

    std::string key;
    while (stream >> key) {
        if (key == "#") {
            std::string line;
            std::getline(stream, line);
            continue;
        }

        if      (key == "player_x")          stream >> out.player.x;
        else if (key == "player_y")          stream >> out.player.y;
        else if (key == "player_facing")     { int v; stream >> v; out.player.facingRight = (v == 1); }
        else if (key == "player_hp")         stream >> out.player.hp;
        else if (key == "player_move_speed") stream >> out.playerMoveSpeed;
        else if (key == "boss_x")            stream >> out.boss.x;
        else if (key == "boss_y")            stream >> out.boss.y;
        else if (key == "boss_facing")       { int v; stream >> v; out.boss.facingRight = (v == 1); }
        else if (key == "boss_hp")           stream >> out.boss.hp;
        else if (key == "boss_max_hp")       stream >> out.bossMaxHP;
        else if (key == "boss_phase")        stream >> out.bossPhase;
        else if (key == "level_timer")       stream >> out.levelTimer;
        else if (key == "current_level")     stream >> out.currentLevel;
        else if (key == "lives_left")        stream >> out.livesLeft;
        else if (key == "best_stars_0")      stream >> out.bestStars[0];
        else if (key == "best_stars_1")      stream >> out.bestStars[1];
        else if (key == "best_stars_2")      stream >> out.bestStars[2];
        else if (key == "difficulty")        stream >> out.difficulty;
        else if (key == "attack_mouse")      stream >> out.attackMouse;
        else if (key == "magic_mouse")       stream >> out.magicMouse;
        else if (key == "jump_key")          stream >> out.jumpKey;
        else if (key == "left_key")          stream >> out.leftKey;
        else if (key == "right_key")         stream >> out.rightKey;
        else if (key == "crouch_key")        stream >> out.crouchKey;
        else if (key == "interact_key")      stream >> out.interactKey;
        else if (key == "dash_key")          stream >> out.dashKey;
        else if (key == "shield_key")        stream >> out.shieldKey;
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
    entry.number   = findFreeSaveNumber();  // ← стало
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