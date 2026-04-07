/**
 * @file level2.cpp
 * @brief Реализация уровня 2
 * @author evol
 * @date 2026-04-08
 */
#include "level2.h"
#include "../utils/texture_manager.h"

// Внешние функции из level1_assets (отрисовка одного тайла)
extern void drawTileByCode(SDL_Renderer* renderer, SDL_Texture* tileset,
                           const std::string& code, int x, int y);
extern const std::unordered_map<std::string, TileInfo>& getTileLookup();

// Глобальный оффсет карты (центрирование) – используем тот же подход, что в level1
static void getMapOffsetForSize(int widthTiles, int heightTiles, int& outX, int& outY) {
    int W = Config::getWindowWidth();
    int H = Config::getWindowHeight();
    outX = (W - widthTiles * TILE_SIZE) / 2;
    outY = (H - heightTiles * TILE_SIZE) / 2;
}

// -------------------------------------------------------------------
// Конструктор – генерируем слои
// -------------------------------------------------------------------
Level2::Level2() {
    solidLayer.resize(HEIGHT, std::vector<std::string>(WIDTH, ""));
    decoLayer.resize(HEIGHT, std::vector<std::string>(WIDTH, ""));
    generateSolidLayer();
    generateDecoLayer();
}

// -------------------------------------------------------------------
// Генерация твёрдого слоя (стены, пол, потолок, платформы)
// -------------------------------------------------------------------
void Level2::generateSolidLayer() {
    // 1. Границы: левая/правая стена, потолок, пол
    for (int row = 0; row < HEIGHT; ++row) {
        // левая стена (колонка 0)
        solidLayer[row][0] = "mww0001";   // грань вправо
        // правая стена (колонка WIDTH-1)
        solidLayer[row][WIDTH-1] = "mww0000"; // грань влево
    }
    for (int col = 0; col < WIDTH; ++col) {
        // потолок (строка 0)
        solidLayer[0][col] = "mwf0000";   // грань вниз
        // пол (строка HEIGHT-1)
        solidLayer[HEIGHT-1][col] = "mwf0001"; // грань вверх
    }

    // 2. Углы (чтобы грани смотрели внутрь)
    solidLayer[0][0] = "mwc0010";        // верх-лево
    solidLayer[0][WIDTH-1] = "mwc0000";  // верх-право
    solidLayer[HEIGHT-1][0] = "mwc0030"; // низ-лево
    solidLayer[HEIGHT-1][WIDTH-1] = "mwc0020"; // низ-право

    // 3. Платформы – три ряда на разной высоте
    // Ряд 1: высота 8, колонки 10..20 и 30..40 и т.д.
    const int platformRows[] = {8, 15, 22};
    for (int row : platformRows) {
        for (int col = 10; col < WIDTH-10; col += 25) {
            int len = 8; // длина платформы
            for (int i = 0; i < len; ++i) {
                int c = col + i;
                if (c >= WIDTH-1) break;
                if (i == 0) solidLayer[row][c] = "spf0000";   // левый край
                else if (i == len-1) solidLayer[row][c] = "spf2000"; // правый край
                else solidLayer[row][c] = "spf1000";         // середина
            }
        }
    }

    // 4. Дополнительные одиночные платформы (лестница)
    for (int i = 0; i < 6; ++i) {
        int row = 5 + i * 2;
        int col = WIDTH/2 + 10 + i*3;
        if (row < HEIGHT-1 && col < WIDTH-1)
            solidLayer[row][col] = "spf1000";
    }
}

// -------------------------------------------------------------------
// Генерация декораций (лампы, окна)
// -------------------------------------------------------------------
void Level2::generateDecoLayer() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Лампы 2x2 – расставляем случайно вдоль стен (но не перекрывая твёрдые тайлы)
    for (int i = 0; i < 20; ++i) {
        int row = 2 + rand() % (HEIGHT-4);
        int col = 2 + rand() % (WIDTH-4);
        // Проверяем, что тайлы не заняты и не на границе
        if (solidLayer[row][col].empty() && solidLayer[row+1][col].empty() &&
            solidLayer[row][col+1].empty() && solidLayer[row+1][col+1].empty()) {
            decoLayer[row][col] = "wlb00000";
            decoLayer[row+1][col] = "wlb10000";
            decoLayer[row][col+1] = "wlb20000";
            decoLayer[row+1][col+1] = "wlb30000";
        }
    }

    // Окна 2x2 – несколько штук
    for (int i = 0; i < 8; ++i) {
        int row = 5 + rand() % (HEIGHT-10);
        int col = 5 + rand() % (WIDTH-10);
        if (solidLayer[row][col].empty() && solidLayer[row+1][col].empty() &&
            solidLayer[row][col+1].empty() && solidLayer[row+1][col+1].empty()) {
            decoLayer[row][col] = "swb00000";
            decoLayer[row+1][col] = "swb10000";
            decoLayer[row][col+1] = "swb20000";
            decoLayer[row+1][col+1] = "swb30000";
        }
    }

    // Открытая дверь (декоративная) – внизу по центру
    int doorRow = HEIGHT-2;
    int doorCol = WIDTH/2;
    if (doorRow+1 < HEIGHT && doorCol+1 < WIDTH) {
        decoLayer[doorRow][doorCol] = "odb0000";
        decoLayer[doorRow+1][doorCol] = "odb1000";
    }
}

// -------------------------------------------------------------------
// Отрисовка карты (аналогично Level1)
// -------------------------------------------------------------------
void Level2::drawMap(SDL_Renderer* renderer, int camX, int camY) {
    SDL_Texture* tileset = TextureManager::getTexture("assets/map1/map1.png");
    if (!tileset) {
        int ox, oy;
        getMapOffset(ox, oy);
        ox -= camX; oy -= camY;
        SDL_SetRenderDrawColor(renderer, 40, 40, 50, 255);
        SDL_Rect bg = {ox, oy, WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE};
        SDL_RenderFillRect(renderer, &bg);
        return;
    }

    int ox, oy;
    getMapOffset(ox, oy);
    ox -= camX;
    oy -= camY;

    // Фоновый слой – случайные кирпичи (как в Level1, но генерируем на лету)
    static bool bgGenerated = false;
    static std::vector<std::vector<std::string>> bgLayer(HEIGHT, std::vector<std::string>(WIDTH, ""));
    if (!bgGenerated) {
        const std::string BG_POOL[] = {
            "mwb1000","mwb2000","mwb3000","mwb4000",
            "mwb5000","mwb6000","mwb7000","mwb8000","mwb9000"
        };
        constexpr int POOL_SIZE = 9;
        for (int row = 0; row < HEIGHT; ++row) {
            for (int col = 0; col < WIDTH; ++col) {
                if (solidLayer[row][col].empty() && decoLayer[row][col].empty()) {
                    bgLayer[row][col] = BG_POOL[rand() % POOL_SIZE];
                } else {
                    bgLayer[row][col] = "";
                }
            }
        }
        bgGenerated = true;
    }

    // Рисуем фон
    for (int row = 0; row < HEIGHT; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            if (!bgLayer[row][col].empty()) {
                drawTileByCode(renderer, tileset, bgLayer[row][col],
                               ox + col * TILE_SIZE, oy + row * TILE_SIZE);
            }
        }
    }

    // Рисуем твёрдый слой
    for (int row = 0; row < HEIGHT; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            if (!solidLayer[row][col].empty()) {
                drawTileByCode(renderer, tileset, solidLayer[row][col],
                               ox + col * TILE_SIZE, oy + row * TILE_SIZE);
            }
        }
    }

    // Рисуем декорации
    for (int row = 0; row < HEIGHT; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            if (!decoLayer[row][col].empty()) {
                drawTileByCode(renderer, tileset, decoLayer[row][col],
                               ox + col * TILE_SIZE, oy + row * TILE_SIZE);
            }
        }
    }
}

// -------------------------------------------------------------------
// Проверка коллизий (аналогично Level1)
// -------------------------------------------------------------------
bool Level2::isSolid(int pixelX, int pixelY) {
    int ox, oy;
    getMapOffset(ox, oy);
    int col = (pixelX - ox) / TILE_SIZE;
    int row = (pixelY - oy) / TILE_SIZE;
    if (col < 0 || col >= WIDTH || row < 0 || row >= HEIGHT) return true;

    const std::string& code = solidLayer[row][col];
    if (code.empty()) return false;
    if (code.size() >= 2 && code[0] == 's' && code[1] == 'p') return false; // платформы обрабатываются отдельно
    char shape = code[2];
    return (shape == 'w' || shape == 'f' || shape == 'c');
}

bool Level2::isPlatform(int pixelX, int pixelY) {
    int ox, oy;
    getMapOffset(ox, oy);
    int col = (pixelX - ox) / TILE_SIZE;
    int row = (pixelY - oy) / TILE_SIZE;
    if (col < 0 || col >= WIDTH || row < 0 || row >= HEIGHT) return false;
    const std::string& code = solidLayer[row][col];
    return (code.size() >= 2 && code[0] == 's' && code[1] == 'p');
}

void Level2::getMapOffset(int& outX, int& outY) {
    getMapOffsetForSize(WIDTH, HEIGHT, outX, outY);
}

std::pair<float, float> Level2::getPlayerSpawn() {
    int ox, oy;
    getMapOffset(ox, oy);
    return {
        ox + PLAYER_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f,
        oy + PLAYER_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f
    };
}

std::pair<float, float> Level2::getBossSpawn() {
    int ox, oy;
    getMapOffset(ox, oy);
    return {
        ox + BOSS_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f,
        oy + BOSS_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f
    };
}

std::unique_ptr<Character> Level2::createBoss(float x, float y, float attackSpeedMult) {
    // Пока используем Golem – позже заменим на BossNinja
    return std::make_unique<BossGolem>(x, y, attackSpeedMult);
}