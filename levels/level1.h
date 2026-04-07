/**
 * @file level1.h
 * @brief Уровень 1 — голем, кирпичная арена
 * @author evol
 * @date 2026-04-06
 */
#pragma once
#include "ilevel.h"
#include "../levels/level1_assets.h"
#include "../characters/boss_golem.h"

class Level1 : public ILevel {
public:
    void drawMap(SDL_Renderer* renderer, int camX = 0, int camY = 0) override {
        drawLevel1Map(renderer, camX, camY);
    }

    bool isSolid(int pixelX, int pixelY) override {
        return isSolidAt(pixelX, pixelY);
    }

    bool isPlatform(int pixelX, int pixelY) override {
        return isPlatformAt(pixelX, pixelY);
    }

    void getMapOffset(int& outX, int& outY) override {
        ::getMapOffset(outX, outY);
    }

    std::pair<float, float> getPlayerSpawn() override {
        int ox = 0, oy = 0;
        ::getMapOffset(ox, oy);
        return {
            ox + PLAYER_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f,
            oy + PLAYER_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f
        };
    }

    std::pair<float, float> getBossSpawn() override {
        int ox = 0, oy = 0;
        ::getMapOffset(ox, oy);
        return {
            ox + BOSS_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f,
            oy + BOSS_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f
        };
    }

    std::unique_ptr<Character> createBoss(float x, float y, float attackSpeedMult) override {
        return std::make_unique<BossGolem>(x, y, attackSpeedMult);
    }

    std::string getMusicName() override { return "level1_music"; }
    std::string getLevelName() override { return "Уровень 1: Голем"; }
};