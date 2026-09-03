/**
 * @file common.h
 * @brief Общие включения, перечисления и константы для всего проекта
 * @author evol
 * @date 2026-02-20
 */
#pragma once

// ===== СИСТЕМНЫЕ БИБЛИОТЕКИ =====
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

// ===== СТАНДАРТНЫЕ БИБЛИОТЕКИ =====
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <cmath>
#include <random>
#include <cstring>
#include <array>
#include <unordered_map>
#include <fstream>
#include <queue>
#include <set>

// ===== НАШИ КЛАССЫ (только объявления) =====
class Config;
class Scene;
class SceneManager;
class TextureManager;
class Animation;
class BossGolem;
class SoundManager;

// ===== ПЕРЕЧИСЛЕНИЯ =====
enum class SceneType {
    SPLASH,
    MAIN_MENU,
    LEVEL_SELECT,
    SETTINGS,
    CREDITS,
    GAME,
    RESTART_GAME,  // Перезапуск игровой сцены (scene_manager обрабатывает как GAME)
    SAVES,
    QUIT
};

enum class BossState {
    IDLE,
    WALK,
    ATTACK_MELEE,
    ATTACK_RANGE,
    LASER,
    BLOCK,
    HURT,
    DEATH
};

enum class SamuraiState {
    IDLE,
    WALK,
    JUMP,
    TELEPORT,
    SWORD_ATTACK,
    POWER_ATTACK,
    STANCE,
    STUNNED,
    THROW_BOMBS,
    DEATH
};

enum class SamuraiPhase {
    PHASE_1,
    DYING
};

/**
 * @enum ArcherState
 * @brief Состояния босса-лучника (ТЗ п.32)
 */
enum class ArcherState {
    IDLE,
    WALK,
    ATTACK_1,
    ATTACK_2,
    ATTACK_3,
    HURT,
    SHOOT,
    CLONE_VOLLEY,
    DEATH
};

/**
 * @enum ArcherPhase
 * @brief Фазы жизненного цикла босса-лучника (ТЗ п.33)
 */
enum class ArcherPhase {
    PHASE_1,  ///< HP > 50%: 4 клона, горизонтальные линии огня
    PHASE_2,  ///< HP ≤ 50%: 6 клонов + диагональный + вертикальный
    DYING     ///< HP = 0: анимация смерти, AI остановлен
};

/**
 * @enum DeadNightState
 * @brief Состояния босса "Смерть Ночи" (Уровень 3, финальный босс)
 */
enum class DeadNightState {
    FLYING_TOP,    ///< Наверху, неуязвим, летает влево-вправо, кидает файрболы
    DESCENDING,    ///< Спускается на арену (после 5/5 миньонов)
    ARENA_IDLE,    ///< На арене, между рывками, уязвим
    DASHING,       ///< Выполняет рывок
    MELEE_ATTACK,  ///< Ближняя атака
    RETREATING,    ///< Отступление после серии из 3 рывков
    ASCENDING,     ///< Улетает наверх (после потери 25% MAX HP)
    DEATH          ///< Мёртв
};

/**
 * @enum DeadNightPhase
 * @brief Фазы босса "Смерть Ночи". Каждая фаза = -25% MAX HP.
 */
enum class DeadNightPhase {
    PHASE_1,
    PHASE_2,
    PHASE_3,
    PHASE_4
};

enum class TileType {
    EMPTY      = 0,
    WALL       = 1,
    PLATFORM   = 2,
    SPIKE      = 3,
    SPAWN      = 4,
    BOSS_SPAWN = 5,
    CHECKPOINT = 6,
    DECORATION = 7
};

// ===== ГЛОБАЛЬНЫЕ КОНСТАНТЫ =====
namespace Constants {
constexpr int   WINDOW_WIDTH      = 1280;
constexpr int   WINDOW_HEIGHT     = 720;
constexpr float PI                = 3.14159265358979323846f;
constexpr float SPLASH_DURATION   = 3.0f;
constexpr float FRAME_TIME_60FPS  = 1.0f / 60.0f;

// Цвета — constexpr (не const)
constexpr SDL_Color COLOR_WHITE  = {255, 255, 255, 255};
constexpr SDL_Color COLOR_BLACK  = {  0,   0,   0, 255};
constexpr SDL_Color COLOR_RED    = {255,   0,   0, 255};
constexpr SDL_Color COLOR_GREEN  = {  0, 255,   0, 255};
constexpr SDL_Color COLOR_BLUE   = {  0,   0, 255, 255};
constexpr SDL_Color COLOR_YELLOW = {255, 255,   0, 255};
constexpr SDL_Color COLOR_GOLD   = {255, 215,   0, 255};

// Утилиты углов — функции вместо макросов
constexpr float degToRad(float deg) { return deg * PI / 180.0f; }
constexpr float radToDeg(float rad) { return rad * 180.0f / PI; }
}

// ===== УТИЛИТЫ КОЛЛИЗИЙ =====

/**
 * @brief Проверяет пересечение двух прямоугольников (AABB).
 * Используется везде где нужна проверка хитбоксов.
 */
[[nodiscard]] inline bool rectsOverlap(const SDL_Rect& a, const SDL_Rect& b) {
    return a.x < b.x + b.w && a.x + a.w > b.x &&
           a.y < b.y + b.h && a.y + a.h > b.y;
}
