/**
 * @file level2.h
 * @brief Уровень 2 – большая арена 140x30
 * @author evol
 * @date 2026-04-08
 */
#pragma once
#include "ilevel.h"
#include "../levels/level1_assets.h"   // переиспользуем отрисовку тайлов
#include "../characters/boss_golem.h"
#include "../config/config.h"
#include "../config/common.h"

class Level2 : public ILevel {
private:
    // Размеры карты (тайлы)
    static constexpr int WIDTH  = 140;
    static constexpr int HEIGHT = 30;

    // Спавны (в пикселях, но храним колонки/строки для вычисления с учётом оффсета)
    static constexpr int PLAYER_SPAWN_COL = WIDTH / 2;
    static constexpr int PLAYER_SPAWN_ROW = HEIGHT - 2;
    static constexpr int BOSS_SPAWN_COL   = WIDTH / 2;
    static constexpr int BOSS_SPAWN_ROW   = 3;

    // Данные карты (генерируются в конструкторе)
    std::vector<std::vector<std::string>> solidLayer;
    std::vector<std::vector<std::string>> decoLayer;

    void generateSolidLayer();
    void generateDecoLayer();

public:
    Level2();
    ~Level2() override = default;

    void drawMap(SDL_Renderer* renderer, int camX = 0, int camY = 0) override;
    bool isSolid(int pixelX, int pixelY) override;
    bool isPlatform(int pixelX, int pixelY) override;
    void getMapOffset(int& outX, int& outY) override;

    std::pair<float, float> getPlayerSpawn() override;
    std::pair<float, float> getBossSpawn() override;

    std::unique_ptr<Character> createBoss(float x, float y, float attackSpeedMult) override;

    std::string getMusicName() override { return "level2_music"; }
    std::string getLevelName() override { return "Уровень 2: Простор"; }
};