/**
 * @file config.cpp
 * @brief Реализация Config
 * @author evol
 * @date 2026-02-20
 */
#include "config.h"
#include "../config/common.h"

int Config::windowWidth  = 1280;
int Config::windowHeight = 720;

float Config::brightness  = 1.0f;
float Config::soundVolume = 0.5f;
float Config::musicVolume = 0.5f;
float Config::sensitivity = 1.0f;

bool  Config::isFullscreen = false;
float Config::scaleX       = 1.0f;
float Config::scaleY       = 1.0f;
bool  Config::loadFromSave = false;

int Config::currentDifficulty = 2;
int Config::levelStars[3]     = {0, 0, 0};
int Config::selectedLevel     = 0;

TTF_Font* Config::font      = nullptr;
TTF_Font* Config::titleFont = nullptr;

static Config::Difficulty difficulties[] = {
    {"Нуб",        0.25f, 0.25f, 4.0f,  -1, 1},
    {"Легко",      0.50f, 0.50f, 2.0f,  10, 1},
    {"Нормально",  1.0f,  1.0f,  1.0f,   5, 1},
    {"Сложно",     1.25f, 1.25f, 0.75f,  3, 1},
    {"Мастер",     2.0f,  2.0f,  0.50f,  2, 1},
    {"ХАРДКОР!!!", 3.0f,  2.0f,  0.50f,  0, 2}
};

// Управление по умолчанию
// SDL мышь: 1=ЛКМ, 2=СКМ, 3=ПКМ
static Config::Controls controls = {
    SDL_SCANCODE_RSHIFT,   // attack (клавиша — не используется, атака через мышь)
    SDL_SCANCODE_Q,        // shoot  (не используется)
    SDL_SCANCODE_SPACE,    // jump
    SDL_SCANCODE_A,        // left
    SDL_SCANCODE_D,        // right
    SDL_SCANCODE_S,        // crouch
    SDL_SCANCODE_E,        // interact
    SDL_SCANCODE_LSHIFT,   // dash — рывок
    SDL_SCANCODE_F,        // shield — щит
    1,                     // attackMouseButton — ЛКМ
    3                      // magicMouseButton  — ПКМ
};

bool Config::init() {
    if (TTF_Init() < 0) {
        std::cout << "SDL_ttf ошибка: " << TTF_GetError() << std::endl;
        return false;
    }

    font      = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans.ttf", 24);
    titleFont = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans-Bold.ttf", 48);

    if (!font || !titleFont) {
        std::cout << "Ошибка загрузки шрифтов: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void Config::cleanup() {
    if (font)      TTF_CloseFont(font);
    if (titleFont) TTF_CloseFont(titleFont);
    TTF_Quit();
}

void Config::setBrightness(float val)  { brightness  = std::clamp(val, 0.0f, 1.0f); }
void Config::setSoundVolume(float val) { soundVolume = std::clamp(val, 0.0f, 1.0f); }
void Config::setMusicVolume(float val) { musicVolume = std::clamp(val, 0.0f, 1.0f); }
void Config::setSensitivity(float val) { sensitivity = std::clamp(val, 0.5f, 2.0f); }

void Config::setCurrentDifficulty(int diff) {
    currentDifficulty = std::clamp(diff, 0, 5);
}

void Config::setLevelStars(int level, int stars) {
    if (level >= 0 && level < 3)
        levelStars[level] = std::clamp(stars, 0, 3);
}

void Config::resetProgress() {
    for (int i = 0; i < 3; i++) levelStars[i] = 0;
}

const Config::Difficulty* Config::getDifficulties() { return difficulties; }
Config::Controls&         Config::getControls()     { return controls; }

void Config::setSelectedLevel(int level) {
    selectedLevel = std::clamp(level, 0, 2);
}

int Config::getSelectedLevel() { return selectedLevel; }

void Config::toggleFullscreen(SDL_Window* window) {
    isFullscreen = !isFullscreen;
    SDL_SetWindowFullscreen(window,
                            isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    updateScale(window);
}

void Config::updateScale(SDL_Window* window) {
    int realW, realH;
    SDL_GetWindowSize(window, &realW, &realH);
    scaleX = (float)realW  / (float)windowWidth;
    scaleY = (float)realH / (float)windowHeight;
}

bool Config::saveProgress() {
    SaveData data;
    for (int i = 0; i < 3; ++i)
        data.levelStars[i] = levelStars[i];
    data.selectedLevel = selectedLevel;
    data.currentDifficulty = currentDifficulty;

    std::ofstream ofs("save.bin", std::ios::binary);
    if (!ofs.is_open()) return false;
    ofs.write(reinterpret_cast<const char*>(&data), sizeof(SaveData));
    return true;
}

bool Config::loadProgress() {
    std::ifstream ifs("save.bin", std::ios::binary);
    if (!ifs.is_open()) return false;
    SaveData data;
    ifs.read(reinterpret_cast<char*>(&data), sizeof(SaveData));
    if (!ifs) return false;
    for (int i = 0; i < 3; ++i)
        levelStars[i] = data.levelStars[i];
    selectedLevel = data.selectedLevel;
    currentDifficulty = data.currentDifficulty;
    // валидация
    selectedLevel = std::clamp(selectedLevel, 0, 2);
    currentDifficulty = std::clamp(currentDifficulty, 0, 5);
    return true;
}