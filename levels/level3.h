/**
 * @file level3.h
 * @brief Уровень 3 — арена летающего босса, лестница-пандус (треугольный
 *        slope-коллайдер) + платформы миньонов.
 *        Физ-слой задан вручную (0-6), размер карты 40×28 тайлов.
 * @author evol
 * @date 2026-08-12
 *
 * Заголовок = только объявления. Все определения (массивы, тела методов) —
 * в level3.cpp.
 *
 * ВАЖНО — НУЖНО ДОБАВИТЬ В getTileLookup() (level1_assets.cpp):
 * ─────────────────────────────────────────────
 * Этот файл использует тайлы, которых пока нет в общей таблице
 * getTileLookup(). Без них drawTileByCode() нарисует пурпурные
 * квадраты-заглушки. Добавь в level1_assets.cpp внутрь getTileLookup():
 *
 *     {"ssf0000", {1, 5, 0.0, SDL_FLIP_NONE, true}},   // ступени лестницы (визуал)
 *     {"unb0000", {2, 5, 0.0, SDL_FLIP_NONE, false}},  // подложка лестницы (фон)
 *     {"em00000", {2, 2, 0.0, SDL_FLIP_NONE, false}},  // чистый чёрный фон
 *
 * ЛЕСТНИЦА — ТРЕУГОЛЬНЫЙ SLOPE-КОЛЛАЙДЕР (не отдельные ступени-блоки):
 * ─────────────────────────────────────────────
 * Ступени "5" в физ-слое — это только ВИЗУАЛ (рисуются тайлом ssf0000).
 * Реальная коллизия лестницы — это getStairGroundY() из ILevel: сплошная
 * диагональная гипотенуза от нижней ступени (у пола) до верхней площадки.
 * Поэтому Level3::isSolid() для кодов "ss" всегда возвращает false —
 * иначе игрок утыкался бы в каждую ступеньку как в стену и не мог бы
 * пройти по плавному уклону. Гравитация нигде не выключается — см.
 * Player::update() в player.cpp.
 *
 * ЧТО ЕСТЬ НА КАРТЕ:
 * ─────────────────────────────────────────────
 *  1 — пол             → mwf0001 (solid)
 *  2 — потолок          → mwf0000 (solid)
 *  3 — левая стена      → mww0000 (solid)
 *  4 — правая стена     → mww0001 (solid)
 *  5 — ступени лестницы → ssf0000 (визуал, НЕ solid — см. выше про slope)
 *  6 — платформа миньона → spf0000/spf1000/spf2000 (одностороннее приземление)
 */
#pragma once
#include "ilevel.h"
#include "level1_assets.h"  // TILE_SIZE, TILE_SOURCE, getTileLookup(), drawTileByCode()

#include "../characters/boss_deadnight.h"
// ============================================================
// ТОЧКА СПАВНА МИНЬОНА-ЛУЧНИКА
// ============================================================

struct MinionSpawnPoint {
    int col;
    int row;
};

class Level3 : public ILevel {
public:
    static constexpr int WIDTH_TILES  = 40;
    static constexpr int HEIGHT_TILES = 28;

    // Игрок — у двери
    static constexpr int L3_PLAYER_COL = 3;
    static constexpr int L3_PLAYER_ROW = 26;

    // Босс — на верхней площадке над лестницей (landing col33-38, row19)
    static constexpr int L3_BOSS_COL = 35;
    static constexpr int L3_BOSS_ROW = 18;

    static constexpr int MINION_COUNT = 4;

    static constexpr int GROUND_FLOOR_ROW      = 27; // ряд пола для наземных миньонов
    static constexpr int MINION_WALK_SPAWN_COL = 24; // TODO: подтвердить колонку спавна
    static constexpr int DOOR_COL              = 3;  // колонка двери (odb-тайлы)

    void drawMap(SDL_Renderer* renderer, int camX = 0, int camY = 0) override;
    bool isSolid(int pixelX, int pixelY) override;
    bool isPlatform(int pixelX, int pixelY) override;
    void getMapOffset(int& outX, int& outY) override;

    // Треугольный slope-коллайдер лестницы (гипотенуза обращена к ступенькам)
    bool getStairGroundY(float pixelX, float& outGroundY) override;

    std::pair<float, float> getPlayerSpawn() override;
    std::pair<float, float> getBossSpawn() override;

    std::unique_ptr<Character> createBoss(float x, float y, float attackSpeedMult) override;

    [[nodiscard]] std::pair<float, float> getMinionSpawn(int index) const;
    [[nodiscard]] int getMinionCount() const;

    std::string getMusicName() override;
    std::string getLevelName() override;

    int getMapWidth()  const override;
    int getMapHeight() const override;

private:
    static void getL3MapOffset(int& ox, int& oy);
};

extern const std::string LEVEL3_BG   [Level3::HEIGHT_TILES][Level3::WIDTH_TILES];
extern const std::string LEVEL3_SOLID[Level3::HEIGHT_TILES][Level3::WIDTH_TILES];
extern const std::string LEVEL3_DECO [Level3::HEIGHT_TILES][Level3::WIDTH_TILES];
extern const MinionSpawnPoint LEVEL3_MINION_SPAWNS[Level3::MINION_COUNT];