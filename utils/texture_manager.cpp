#include "texture_manager.h"
#include "../config/common.h"


// Инициализация статических переменных
std::map<std::string, SDL_Texture*> TextureManager::textures;
SDL_Renderer* TextureManager::renderer = nullptr;

void TextureManager::init(SDL_Renderer* rend) {
    renderer = rend;
    
    // Инициализация SDL_image (поддержка PNG)
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "SDL_image ошибка: " << IMG_GetError() << std::endl;
    }
}

SDL_Texture* TextureManager::loadTexture(const std::string& path) {
    // Проверяем, не загружена ли уже
    if (textures.find(path) != textures.end()) {
        return textures[path];
    }
    
    // Загружаем поверхность
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cout << "Ошибка загрузки изображения " << path << ": " << IMG_GetError() << std::endl;
        return nullptr;
    }
    
    // Создаём текстуру
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    if (!texture) {
        std::cout << "Ошибка создания текстуры из " << path << ": " << SDL_GetError() << std::endl;
        return nullptr;
    }
    
    // Сохраняем в кэш
    textures[path] = texture;
    
    return texture;
}

SDL_Texture* TextureManager::getTexture(const std::string& path) {
    return loadTexture(path);
}

void TextureManager::draw(SDL_Texture* texture, int x, int y) {
    if (!texture) return;
    
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dstRect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}

void TextureManager::draw(SDL_Texture* texture, int x, int y, int w, int h) {
    if (!texture) return;
    
    SDL_Rect dstRect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect) {
    if (!texture) return;
    SDL_RenderCopy(renderer, texture, srcRect, dstRect);
}

void TextureManager::cleanup() {
    for (auto& pair : textures) {
        SDL_DestroyTexture(pair.second);
    }
    textures.clear();
    IMG_Quit();
}
