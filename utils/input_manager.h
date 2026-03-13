#pragma once
#include "../config/common.h"

class InputManager {
private:
    static std::array<Uint8, SDL_NUM_SCANCODES> currentKeys;
    static std::array<Uint8, SDL_NUM_SCANCODES> previousKeys;
    static std::array<bool, 5> currentMouse;
    static std::array<bool, 5> previousMouse;
    static int mouseX, mouseY;
    
public:
    static void update();
    
     // Клавиша НАЖАТА в этом кадре (только первый кадр)
    static bool isKeyPressed(SDL_Scancode key);
    
    // Клавиша УДЕРЖИВАЕТСЯ (любое количество кадров)
    static bool isKeyDown(SDL_Scancode key);
    
    // Клавиша ОТПУЩЕНА в этом кадре
    static bool isKeyReleased(SDL_Scancode key);
    
    static bool isMouseDown(int button);
    static bool isMousePressed(int button);
    static bool isMouseReleased(int button);
    static void getMousePos(int& x, int& y);
};
