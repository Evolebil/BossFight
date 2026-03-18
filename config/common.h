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