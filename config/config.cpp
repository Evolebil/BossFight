#include "config.h"
#include "../config/common.h"

// Инициализация статических переменных
int Config::windowWidth = 1280;
int Config::windowHeight = 720;

float Config::brightness = 1.0f;
float Config::soundVolume = 0.5f;
float Config::musicVolume = 0.5f;
float Config::sensitivity = 1.0f;

int Config::currentDifficulty = 2;  // Нормально
int Config::levelStars[3] = {0, 0, 0};

int Config::selectedLevel = 0;  // Инициализация


TTF_Font* Config::font = nullptr;
TTF_Font* Config::titleFont = nullptr;

// Массив сложностей
static Config::Difficulty difficulties[] = {
    {"Нуб", 0.25f, 0.25f, 4.0f, -1, 1},
    {"Легко", 0.50f, 0.50f, 2.0f, 10, 1},
    {"Нормально", 1.0f, 1.0f, 1.0f, 5, 1},
    {"Сложно", 1.25f, 1.25f, 0.75f, 3, 1},
    {"Мастер", 2.0f, 2.0f, 0.50f, 2, 1},
    {"ХАРДКОР!!!", 3.0f, 2.0f, 0.50f, 0, 2}
};

// Управление (по умолчанию)
static Config::Controls controls = {
    SDL_SCANCODE_RSHIFT,  // attack
    SDL_SCANCODE_LSHIFT,  // shoot
    SDL_SCANCODE_SPACE,   // jump
    SDL_SCANCODE_A,       // left
    SDL_SCANCODE_D,       // right
    SDL_SCANCODE_S,       // crouch
    SDL_SCANCODE_E,       // interact
    2,                    // attackMouseButton (ПКМ)
    1                     // shootMouseButton (ЛКМ)
};

bool Config::init() {
    // Инициализация SDL_ttf
    if (TTF_Init() < 0) {
        std::cout << "SDL_ttf ошибка: " << TTF_GetError() << std::endl;
        return false;
    }
    
    // Загрузка шрифтов
    font = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans.ttf", 24);
    titleFont = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans-Bold.ttf", 48);
    
    if (!font || !titleFont) {
        std::cout << "Ошибка загрузки шрифтов: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void Config::cleanup() {
    if (font) TTF_CloseFont(font);
    if (titleFont) TTF_CloseFont(titleFont);
    TTF_Quit();
}

// Сеттеры с валидацией
void Config::setBrightness(float val) {
    brightness = std::clamp(val, 0.0f, 1.0f);
}

void Config::setSoundVolume(float val) {
    soundVolume = std::clamp(val, 0.0f, 1.0f);
}

void Config::setMusicVolume(float val) {
    musicVolume = std::clamp(val, 0.0f, 1.0f);
}

void Config::setSensitivity(float val) {
    sensitivity = std::clamp(val, 0.5f, 2.0f);
}

void Config::setCurrentDifficulty(int diff) {
    currentDifficulty = std::clamp(diff, 0, 5);
}

void Config::setLevelStars(int level, int stars) {
    if (level >= 0 && level < 3) {
        levelStars[level] = std::clamp(stars, 0, 3);
    }
}

void Config::resetProgress() {
    for (int i = 0; i < 3; i++) {
        levelStars[i] = 0;
    }
}

const Config::Difficulty* Config::getDifficulties() {
    return difficulties;
}

Config::Controls& Config::getControls() {
    return controls;
}

void Config::setSelectedLevel(int level) {
    selectedLevel = std::clamp(level, 0, 2);  // У нас 3 уровня
}

int Config::getSelectedLevel() {
    return selectedLevel;
}
