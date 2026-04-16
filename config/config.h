/**
 * @file config.h
 * @brief Настройки игры — окно, звук, управление, прогресс
 * @author evol
 * @date 2026-02-20
 */
#pragma once
#include "../config/common.h"

struct SaveData {
    int levelStars[3];
    int selectedLevel;
    int currentDifficulty;
};

class Config {
private:
    static int windowWidth;
    static int windowHeight;

    static float brightness;
    static float soundVolume;
    static float musicVolume;
    static float sensitivity;

    static bool  isFullscreen;
    static float scaleX;
    static float scaleY;

    static int currentDifficulty;
    static int levelStars[3];

    static TTF_Font* font;
    static TTF_Font* titleFont;

    static int selectedLevel;

public:
    static bool init();
    static void cleanup();

    static int   getWindowWidth()  { return windowWidth; }
    static int   getWindowHeight() { return windowHeight; }

    static float getBrightness()  { return brightness; }
    static float getSoundVolume() { return soundVolume; }
    static float getMusicVolume() { return musicVolume; }
    static float getSensitivity() { return sensitivity; }

    static void setBrightness(float val);
    static void setSoundVolume(float val);
    static void setMusicVolume(float val);
    static void setSensitivity(float val);

    // --- Fullscreen ---
    static void toggleFullscreen(SDL_Window* window);
    static void updateScale(SDL_Window* window);
    static bool getIsFullscreen() { return isFullscreen; }
    static float getScaleX()      { return scaleX; }
    static float getScaleY()      { return scaleY; }

    static int getCurrentDifficulty()      { return currentDifficulty; }
    static int getLevelStars(int level)    { return levelStars[level]; }

    static void setCurrentDifficulty(int diff);
    static void setLevelStars(int level, int stars);
    static void resetProgress();



    static TTF_Font* getFont()      { return font; }
    static TTF_Font* getTitleFont() { return titleFont; }

    struct Difficulty {
        std::string name;
        float projectileSpeed;
        float damage;
        float playerHP;
        int   respawns;
        int   projectileCount;
    };

    static const Difficulty* getDifficulties();
    static int getDifficultyCount() { return 6; }

    // Управление — добавлены дэш, щит и магия
    struct Controls {
        SDL_Scancode attack;        // ближняя атака (клавиша)
        SDL_Scancode shoot;         // дальняя атака (клавиша, не используется)
        SDL_Scancode jump;
        SDL_Scancode left;
        SDL_Scancode right;
        SDL_Scancode crouch;
        SDL_Scancode interact;
        SDL_Scancode dash;          // рывок
        SDL_Scancode shield;        // щит
        int attackMouseButton;      // ближняя атака (мышь) — ЛКМ = 1
        int magicMouseButton;       // магия (мышь) — ПКМ = 3
    };

    static Controls& getControls();

    static void setSelectedLevel(int level);
    static int  getSelectedLevel();

    static bool saveProgress();
    static bool loadProgress();
};