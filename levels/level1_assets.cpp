/**
 * @file level1_assets.cpp
 * @brief Отрисовка 3 слоёв карты уровня 1 через тайлсет map1.png
 * @author evol
 * @date 2026-02-18
 */

#include "level1_assets.h"
#include "../utils/texture_manager.h"
#include <cstdlib>

// ============================================================
// LOOKUP-ТАБЛИЦА
// ============================================================

const std::unordered_map<std::string, TileInfo>& getTileLookup() {
    static const std::unordered_map<std::string, TileInfo> lookup = {

    // --- Кирпичные стены структурные (solid=true) ---

    // Потолок: грань сверху, смотрит вниз (внутрь арены) — ОК
    {"mwf0000", {1, 2,  0.0, SDL_FLIP_NONE,       true}},

        // Пол: грань снизу (flip V от потолка), смотрит вверх (внутрь) — ОК
        {"mwf0001", {3, 2,  0.0, SDL_FLIP_NONE,       true}},

        // Правая стена арены: грань смотрит влево (внутрь) — mww0000 без изменений
        {"mww0000", {2, 1,  0.0, SDL_FLIP_NONE,       true}},

        // Левая стена арены: грань смотрит вправо (внутрь) — flip H от mww0000
        // NOTE(evol): mww0001 — наш кастомный код, в PNG используем те же [2,1]
        //             но с SDL_FLIP_HORIZONTAL
        {"mww0001", {2, 1,  0.0, SDL_FLIP_HORIZONTAL, true}},

        // Углы (для арены — грань смотрит внутрь):
        // верх-лево арены = грань вправо+вниз = поворот 90° от исходного
        {"mwc0010", {1, 3,  0.0, SDL_FLIP_NONE,       true}},  // верх-лево

        // верх-право арены = грань влево+вниз = исходный 0°
        {"mwc0000", {1, 1,  0.0, SDL_FLIP_NONE,       true}},  // верх-право

        // низ-лево арены = грань вправо+вверх = 270°
        {"mwc0030", {3, 3,  0.0, SDL_FLIP_NONE,       true}},  // низ-лево

        // низ-право арены = грань влево+вверх = 180°
        {"mwc0020", {3, 1,  0.0, SDL_FLIP_NONE,       true}},  // низ-право

        // --- Платформы (solid=true) ---
        {"spf0000", {9, 1,  0.0, SDL_FLIP_NONE,       true}},  // левый край
        {"spf1000", {9, 2,  0.0, SDL_FLIP_NONE,       true}},  // середина
        {"spf2000", {9, 3,  0.0, SDL_FLIP_NONE,       true}},  // правый край

        // --- Фоновые кирпичи (solid=false) ---
        {"mwb1000", {1, 8,  0.0, SDL_FLIP_NONE,       false}},
        {"mwb2000", {1, 9,  0.0, SDL_FLIP_NONE,       false}},
        {"mwb3000", {1, 12, 0.0, SDL_FLIP_NONE,       false}},
        {"mwb4000", {1, 13, 0.0, SDL_FLIP_NONE,       false}},
        {"mwb5000", {2, 8,  0.0, SDL_FLIP_NONE,       false}},
        {"mwb6000", {2, 9,  0.0, SDL_FLIP_NONE,       false}},
        {"mwb7000", {2, 12, 0.0, SDL_FLIP_NONE,       false}},
        {"mwb8000", {2, 13, 0.0, SDL_FLIP_NONE,       false}},
        {"mwb9000", {3, 8,  0.0, SDL_FLIP_NONE,       false}},

        // --- Лампа 2×2 (solid=false) ---
        {"wlb00000", {1, 10, 0.0, SDL_FLIP_NONE,      false}},
        {"wlb10000", {1, 11, 0.0, SDL_FLIP_NONE,      false}},
        {"wlb20000", {2, 10, 0.0, SDL_FLIP_NONE,      false}},
        {"wlb30000", {2, 11, 0.0, SDL_FLIP_NONE,      false}},

        // --- Окно 2×2 (solid=false) ---
        {"swb00000", {3, 10, 0.0, SDL_FLIP_NONE,      false}},
        {"swb10000", {3, 11, 0.0, SDL_FLIP_NONE,      false}},
        {"swb20000", {4, 10, 0.0, SDL_FLIP_NONE,      false}},
        {"swb30000", {4, 11, 0.0, SDL_FLIP_NONE,      false}},

        // --- Открытая дверь (solid=false) ---
        {"odb0000",  {10, 13, 0.0, SDL_FLIP_NONE,     false}},
        {"odb1000",  {11, 13, 0.0, SDL_FLIP_NONE,     false}},
        };
return lookup;
}

// ============================================================
// СМЕЩЕНИЕ КАРТЫ (центрирование на экране)
// ============================================================

void getMapOffset(int& outOffsetX, int& outOffsetY) {
    int W = Config::getWindowWidth();
    int H = Config::getWindowHeight();
    outOffsetX = (W - LEVEL1_WIDTH  * TILE_SIZE) / 2;
    outOffsetY = (H - LEVEL1_HEIGHT * TILE_SIZE) / 2;
}

SDL_Rect getTileRect(int col, int row) {
    int ox, oy;
    getMapOffset(ox, oy);
    return SDL_Rect{ox + col * TILE_SIZE, oy + row * TILE_SIZE, TILE_SIZE, TILE_SIZE};
}

// ============================================================
// РИСОВАНИЕ ОДНОГО ТАЙЛА
// ============================================================

static void drawTileByCode(SDL_Renderer* renderer,
                           SDL_Texture* tileset,
                           const std::string& code,
                           int x, int y)
{
    if (code.empty()) return;

    const auto& lookup = getTileLookup();
    auto it = lookup.find(code);
    if (it == lookup.end()) {
        // Неизвестный код — пурпурный квадрат для отладки
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        SDL_Rect err = {x, y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(renderer, &err);
        return;
    }

    const TileInfo& t = it->second;
    SDL_Rect src = {t.col * TILE_SOURCE, t.row * TILE_SOURCE, TILE_SOURCE, TILE_SOURCE};
    SDL_Rect dst = {x, y, TILE_SIZE, TILE_SIZE};
    SDL_RenderCopyEx(renderer, tileset, &src, &dst, t.angle, nullptr, t.flip);
}

// ============================================================
// РАНДОМНЫЙ ФОН — генерируется ОДИН РАЗ
// ============================================================

static std::string g_randomBg[LEVEL1_HEIGHT][LEVEL1_WIDTH];
static bool g_randomBgGenerated = false;

static void generateRandomBg() {
    if (g_randomBgGenerated) return;

    static const std::string BG_POOL[] = {
        "mwb1000","mwb2000","mwb3000","mwb4000",
        "mwb5000","mwb6000","mwb7000","mwb8000","mwb9000"
    };
    constexpr int POOL_SIZE = 9;

    for (int row = 0; row < LEVEL1_HEIGHT; row++) {
        for (int col = 0; col < LEVEL1_WIDTH; col++) {
            // Края (стены/пол/потолок) — не нужен фон, SOLID перекрывает
            if (col == 0 || col == LEVEL1_WIDTH-1 || row == 0 || row == LEVEL1_HEIGHT-1) {
                g_randomBg[row][col] = "";
            } else {
                g_randomBg[row][col] = BG_POOL[rand() % POOL_SIZE];
            }
        }
    }
    g_randomBgGenerated = true;
}

// ============================================================
// ГЛАВНАЯ ФУНКЦИЯ ОТРИСОВКИ
// ============================================================

void drawLevel1Map(SDL_Renderer* renderer) {
    SDL_Texture* tileset = TextureManager::getTexture("assets/map1/map1.png");
    if (!tileset) {
        // Заглушка — тёмный прямоугольник
        int ox, oy;
        getMapOffset(ox, oy);
        SDL_SetRenderDrawColor(renderer, 40, 40, 50, 255);
        SDL_Rect fb = {ox, oy, LEVEL1_WIDTH * TILE_SIZE, LEVEL1_HEIGHT * TILE_SIZE};
        SDL_RenderFillRect(renderer, &fb);
        return;
    }

    generateRandomBg();

    int ox, oy;
    getMapOffset(ox, oy);

    // СЛОЙ 1: рандомный фон
    for (int row = 0; row < LEVEL1_HEIGHT; row++) {
        for (int col = 0; col < LEVEL1_WIDTH; col++) {
            drawTileByCode(renderer, tileset,
                           g_randomBg[row][col],
                           ox + col * TILE_SIZE,
                           oy + row * TILE_SIZE);
        }
    }

    // СЛОЙ 2: твёрдые (стены, пол, платформы)
    for (int row = 0; row < LEVEL1_HEIGHT; row++) {
        for (int col = 0; col < LEVEL1_WIDTH; col++) {
            const std::string& code = LEVEL1_SOLID[row][col];
            if (code.empty()) continue;
            drawTileByCode(renderer, tileset, code,
                           ox + col * TILE_SIZE,
                           oy + row * TILE_SIZE);
        }
    }

    // СЛОЙ 3: декорации (лампы, окно, дверь)
    for (int row = 0; row < LEVEL1_HEIGHT; row++) {
        for (int col = 0; col < LEVEL1_WIDTH; col++) {
            const std::string& code = LEVEL1_DECO[row][col];
            if (code.empty()) continue;
            drawTileByCode(renderer, tileset, code,
                           ox + col * TILE_SIZE,
                           oy + row * TILE_SIZE);
        }
    }
}

// ============================================================
// КОЛЛИЗИИ (по SOLID слою)
// ============================================================

bool isSolidAt(int pixelX, int pixelY) {
    int ox, oy;
    getMapOffset(ox, oy);

    int col = (pixelX - ox) / TILE_SIZE;
    int row = (pixelY - oy) / TILE_SIZE;

    // За пределами карты = стена
    if (col < 0 || col >= LEVEL1_WIDTH || row < 0 || row >= LEVEL1_HEIGHT) {
        return true;
    }

    const std::string& code = LEVEL1_SOLID[row][col];
    if (code.empty()) return false;
    if (code.size() < 3) return false;

    // ВАЖНО: платформы (spf...) НЕ являются solid-стенами.
    // Их коллизия обрабатывается отдельно в isPlatformAt — только сверху вниз.
    // Без этой проверки платформы блокировали бы движение сбоку (shape == 'f').
    if (code.size() >= 2 && code[0] == 's' && code[1] == 'p') return false;

    char shape = code[2];
    return (shape == 'w' || shape == 'f' || shape == 'c');
}
bool isPlatformAt(int pixelX, int pixelY) {
    int ox, oy;
    getMapOffset(ox, oy);

    int col = (pixelX - ox) / TILE_SIZE;
    int row = (pixelY - oy) / TILE_SIZE;

    if (col < 0 || col >= LEVEL1_WIDTH || row < 0 || row >= LEVEL1_HEIGHT)
        return false;

    const std::string& code = LEVEL1_SOLID[row][col];
    // Платформы начинаются с "sp"
    return (code.size() >= 2 && code[0] == 's' && code[1] == 'p');
}
