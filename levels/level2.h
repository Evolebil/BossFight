/**
 * @file level2.h
 * @brief Уровень 2 — горизонтальный скролл 160×50, камера с dead zone
 * @author evol
 * @date 2026-04-08
 */
#pragma once
#include "ilevel.h"
#include "../levels/level1_assets.h"   // TILE_SIZE, TILE_SOURCE, getTileLookup(), drawTileByCode()
#include "../characters/boss_golem.h"
#include "../utils/camera.h"

class Level2 : public ILevel {
public:
    // --- Размеры карты ---
    static constexpr int WIDTH_TILES  = 160;
    static constexpr int HEIGHT_TILES = 50;

    // --- Спавны (в тайлах) ---
    static constexpr int L2_PLAYER_COL = 4;
    static constexpr int L2_PLAYER_ROW = 46;   // близко к полу, левый край
    static constexpr int L2_BOSS_COL   = 80;   // центр карты
    static constexpr int L2_BOSS_ROW   = 46;

    // --- ILevel интерфейс ---
    void drawMap(SDL_Renderer* renderer, int camX = 0, int camY = 0) override;
    bool isSolid(int pixelX, int pixelY) override;
    bool isPlatform(int pixelX, int pixelY) override;
    void getMapOffset(int& outX, int& outY) override;

    std::pair<float, float> getPlayerSpawn() override;
    std::pair<float, float> getBossSpawn() override;

    std::unique_ptr<Character> createBoss(float x, float y, float attackSpeedMult) override;

    std::string getMusicName() override { return "level2_music"; }
    std::string getLevelName() override { return "Уровень 2: Простор"; }

    int getMapWidth()  const override { return WIDTH_TILES  * TILE_SIZE; }
    int getMapHeight() const override { return HEIGHT_TILES * TILE_SIZE; }
};

// Карта объявлена в level2.cpp
extern const std::string LEVEL2_SOLID[Level2::HEIGHT_TILES][Level2::WIDTH_TILES];
extern const std::string LEVEL2_DECO [Level2::HEIGHT_TILES][Level2::WIDTH_TILES];