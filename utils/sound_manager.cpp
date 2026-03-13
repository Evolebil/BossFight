#include "sound_manager.h"
#include "../config/common.h"

static SoundManager* g_soundManager = nullptr;

SoundManager::SoundManager() 
    : soundVolume(0.5f), musicVolume(0.5f) {
    g_soundManager = this;
}

SoundManager::~SoundManager() {
    cleanup();
}

bool SoundManager::init() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer ошибка: " << Mix_GetError() << std::endl;
        return false;
    }
    
    Mix_AllocateChannels(16);
    
    int flags = Mix_Init(MIX_INIT_MP3);
    if (flags & MIX_INIT_MP3) {
    } else {
        std::cout << "✗ MP3 НЕ ПОДДЕРЖИВАЕТСЯ" << std::endl;
    }
    
    // БЕЗ СИНТЕЗА - убираем весь блок с generateTone
    
    return true;
}

bool SoundManager::loadSound(const std::string& name, const std::string& path) {
    Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
    if (!sound) {
        std::cout << "Ошибка загрузки звука " << path << ": " << Mix_GetError() << std::endl;
        return false;
    }
    sounds[name] = sound;
    return true;
}

bool SoundManager::loadMusic(const std::string& name, const std::string& path) {
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    if (!music) {
        std::cout << "Ошибка загрузки музыки " << path << ": " << Mix_GetError() << std::endl;
        return false;
    }
    this->music[name] = music;
    return true;
}

void SoundManager::playSound(const std::string& name) {
    auto it = sounds.find(name);
    if (it != sounds.end()) {
        Mix_VolumeChunk(it->second, (int)(MIX_MAX_VOLUME * soundVolume));
        int channel = Mix_PlayChannel(-1, it->second, 0);
        
        if (channel == -1) {
            std::cout << "✗ Ошибка воспроизведения '" << name << "': " << Mix_GetError() << std::endl;
        } else {
        }
    } else {
        std::cout << "✗ Звук '" << name << "' не найден" << std::endl;
    }
}

void SoundManager::playMusic(const std::string& name) {
    auto it = music.find(name);
    if (it != music.end()) {
        Mix_VolumeMusic((int)(MIX_MAX_VOLUME * musicVolume));
        Mix_PlayMusic(it->second, -1); // -1 = бесконечный повтор
    }
}

void SoundManager::stopMusic() {
    Mix_HaltMusic();
}

void SoundManager::playHover() {
    playSound("hover");
}

void SoundManager::playClick() {
    playSound("click");
}

void SoundManager::playSliderMove() {
    playSound("slider");
}

void SoundManager::cleanup() {
    for (auto& pair : sounds) {
        if (pair.second) Mix_FreeChunk(pair.second);
    }
    sounds.clear();
    
    for (auto& pair : music) {
        if (pair.second) Mix_FreeMusic(pair.second);
    }
    music.clear();
    
    Mix_CloseAudio();
}

SoundManager* getSoundManager() {
    return g_soundManager;
}
