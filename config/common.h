// common.h
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
#include <chrono>
#include <cstring>
#include <array>
#include <unistd.h>

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
    RESTART_GAME,   // перезапуск боя — создаёт новый GameScene даже если уже в GAME
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
    EMPTY = 0,
    WALL = 1,
    PLATFORM = 2,
    SPIKE = 3,
    SPAWN = 4,
    BOSS_SPAWN = 5,
    CHECKPOINT = 6,
    DECORATION = 7
};

// ===== ГЛОБАЛЬНЫЕ КОНСТАНТЫ =====
namespace Constants {
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr float PI = 3.14159265358979323846f;

// Цвета
const SDL_Color COLOR_WHITE = {255, 255, 255, 255};
const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
const SDL_Color COLOR_RED = {255, 0, 0, 255};
const SDL_Color COLOR_GREEN = {0, 255, 0, 255};
const SDL_Color COLOR_BLUE = {0, 0, 255, 255};
const SDL_Color COLOR_YELLOW = {255, 255, 0, 255};

// Время
constexpr float SPLASH_DURATION = 3.0f;
constexpr float FRAME_TIME_60FPS = 1.0f / 60.0f;
}

// ===== ВСПОМОГАТЕЛЬНЫЕ МАКРОСЫ =====
#define SAFE_DELETE(ptr) if (ptr) { delete ptr; ptr = nullptr; }
#define SAFE_DELETE_ARRAY(ptr) if (ptr) { delete[] ptr; ptr = nullptr; }
#define DEG_TO_RAD(deg) ((deg) * Constants::PI / 180.0f)
#define RAD_TO_DEG(rad) ((rad) * 180.0f / Constants::PI)
