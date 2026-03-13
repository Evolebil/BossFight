#pragma once
#include "../config/common.h"


// Менеджер текстур - загрузка и хранение PNG файлов
class TextureManager {
private:
    static std::map<std::string, SDL_Texture*> textures;
    static SDL_Renderer* renderer;
    
public:
    // Инициализация (устанавливает рендерер)
    static void init(SDL_Renderer* rend);
    
    // Загрузка текстуры из файла
    static SDL_Texture* loadTexture(const std::string& path);
    
    // Получение текстуры по имени (загружает если нет)
    static SDL_Texture* getTexture(const std::string& path);
    
    // Отрисовка текстуры
    static void draw(SDL_Texture* texture, int x, int y);
    static void draw(SDL_Texture* texture, int x, int y, int w, int h);
    static void draw(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect);
    
    // Очистка всех текстур
    static void cleanup();
};
