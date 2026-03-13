#pragma once
#include "../config/common.h"


class SoundManager {
private:
    std::map<std::string, Mix_Chunk*> sounds;
    std::map<std::string, Mix_Music*> music;
    
public:
    float soundVolume;
    float musicVolume;
    
    SoundManager();
    ~SoundManager();
    
    bool init();
    
    // Загрузка звуков
    bool loadSound(const std::string& name, const std::string& path);
    bool loadMusic(const std::string& name, const std::string& path);
    
    // Воспроизведение
    void playSound(const std::string& name);
    void playMusic(const std::string& name);
    void stopMusic();
    
    // UI звуки (временные, пока не загружены файлы)
    void playHover();
    void playClick();
    void playSliderMove();
    
    // Очистка
    void cleanup();
};
SoundManager* getSoundManager();
