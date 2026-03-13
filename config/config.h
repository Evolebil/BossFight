#pragma once
#include "../config/common.h"
// Класс для управления всеми настройками игры
class Config {
private:
    // Размеры окна
    static int windowWidth;
    static int windowHeight;
    
    // Настройки графики и звука
    static float brightness;
    static float soundVolume;
    static float musicVolume;
    static float sensitivity;
    
    // Прогресс игры
    static int currentDifficulty;
    static int levelStars[3];
    
    // Шрифты
    static TTF_Font* font;
    static TTF_Font* titleFont;

    static int selectedLevel;  // Добавляем выбранный уровень
    
public:
    // Инициализация и очистка
    static bool init();
    static void cleanup();
    
    // Геттеры для размеров окна
    static int getWindowWidth() { return windowWidth; }
    static int getWindowHeight() { return windowHeight; }
    
    // Геттеры для настроек
    static float getBrightness() { return brightness; }
    static float getSoundVolume() { return soundVolume; }
    static float getMusicVolume() { return musicVolume; }
    static float getSensitivity() { return sensitivity; }
    
    // Сеттеры для настроек (с валидацией)
    static void setBrightness(float val);
    static void setSoundVolume(float val);
    static void setMusicVolume(float val);
    static void setSensitivity(float val);
    
    // Геттеры для прогресса
    static int getCurrentDifficulty() { return currentDifficulty; }
    static int getLevelStars(int level) { return levelStars[level]; }
    
    // Сеттеры для прогресса
    static void setCurrentDifficulty(int diff);
    static void setLevelStars(int level, int stars);
    static void resetProgress();
    
    // Геттеры для шрифтов
    static TTF_Font* getFont() { return font; }
    static TTF_Font* getTitleFont() { return titleFont; }
    
    // Структура сложности
    struct Difficulty {
        std::string name;
        float projectileSpeed;
        float damage;
        float playerHP;
        int respawns;
        int projectileCount;
    };
    
    static const Difficulty* getDifficulties();
    static int getDifficultyCount() { return 6; }
    
    // Структура управления
    struct Controls {
        SDL_Scancode attack;
        SDL_Scancode shoot;
        SDL_Scancode jump;
        SDL_Scancode left;
        SDL_Scancode right;
        SDL_Scancode crouch;
        SDL_Scancode interact;
        int attackMouseButton;
        int shootMouseButton;
    };
    
    static Controls& getControls();
    
    static void setSelectedLevel(int level);
    static int getSelectedLevel();
};
