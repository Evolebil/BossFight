/**
 * @file ilevel.h
 * @brief Абстрактный интерфейс уровня
 * @author evol
 * @date 2026-04-06
 */
#pragma once
#include "../config/common.h"
#include "../config/config.h"
#include "../characters/character.h"

/**
 * @class ILevel
 * @brief Интерфейс уровня — GameScene работает только через него.
 *
 * Каждый уровень реализует этот интерфейс:
 * Level1 → голем, карта 1
 * Level2 → ниндзя, карта 2
 * Level3 → финальный босс, карта 3
 */
class ILevel {
public:
    virtual ~ILevel() = default;

    // --- Карта ---
    virtual void drawMap(SDL_Renderer* renderer, int camX = 0, int camY = 0) = 0;
    virtual bool isSolid(int pixelX, int pixelY) = 0;
    virtual bool isPlatform(int pixelX, int pixelY) = 0;
    virtual void getMapOffset(int& outX, int& outY) = 0;

    // --- Спавны ---
    virtual std::pair<float, float> getPlayerSpawn() = 0;
    virtual std::pair<float, float> getBossSpawn() = 0;

    // --- Босс ---
    virtual std::unique_ptr<Character> createBoss(float x, float y, float attackSpeedMult) = 0;

    // --- Мета ---
    virtual std::string getMusicName() = 0;
    virtual std::string getLevelName() = 0;
};

/**
 * @brief Фабрика уровней — создаёт нужный уровень по индексу (0-based).
 * @param index  0 = уровень 1, 1 = уровень 2, 2 = уровень 3
 */
std::unique_ptr<ILevel> createLevel(int index);