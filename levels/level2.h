/**
 * @file level2.h
 * @brief Уровень 2 — горизонтальный скролл 160×50, камера с dead zone
 * @author evol
 * @date 2026-04-10
 */
#pragma once
#include "ilevel.h"
#include "../levels/level1_assets.h"
#include "../characters/boss_golem.h"
#include "../utils/camera.h"

class Level2 : public ILevel {
public:
    static constexpr int WIDTH_TILES  = 160;
    static constexpr int HEIGHT_TILES = 50;

    static constexpr int L2_PLAYER_COL = 4;
    static constexpr int L2_PLAYER_ROW = 46;
    static constexpr int L2_BOSS_COL   = 80;
    static constexpr int L2_BOSS_ROW   = 46;

    // Урон от шипов — 25 в секунду
    static constexpr float SPIKE_DAMAGE_PER_SEC = 25.0f;

    void drawMap(SDL_Renderer* renderer, int camX = 0, int camY = 0) override;
    bool isSolid(int pixelX, int pixelY) override;
    bool isPlatform(int pixelX, int pixelY) override;
    void getMapOffset(int& outX, int& outY) override;

    std::pair<float, float> getPlayerSpawn() override;
    std::pair<float, float> getBossSpawn() override;

    std::unique_ptr<Character> createBoss(float x, float y, float attackSpeedMult) override;

    // Проверка шипа — вызывать из GameScene каждый кадр
    bool isSpike(int worldX, int worldY);

    std::string getMusicName() override { return "level2_music"; }
    std::string getLevelName() override { return "Уровень 2: Простор"; }

    int getMapWidth()  const override { return WIDTH_TILES  * TILE_SIZE; }
    int getMapHeight() const override { return HEIGHT_TILES * TILE_SIZE; }
};

extern const std::string LEVEL2_SOLID[Level2::HEIGHT_TILES][Level2::WIDTH_TILES];
extern const std::string LEVEL2_DECO [Level2::HEIGHT_TILES][Level2::WIDTH_TILES];