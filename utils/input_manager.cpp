#include "input_manager.h"
#include "../config/common.h"

std::array<Uint8, SDL_NUM_SCANCODES> InputManager::currentKeys;
std::array<Uint8, SDL_NUM_SCANCODES> InputManager::previousKeys;
std::array<bool, 5> InputManager::currentMouse;
std::array<bool, 5> InputManager::previousMouse;
int InputManager::mouseX = 0;
int InputManager::mouseY = 0;

void InputManager::update() {
    previousKeys = currentKeys;
    std::copy(currentMouse.begin(), currentMouse.end(), previousMouse.begin());
    
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        currentKeys[i] = keys[i];
    }
    
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    for (int i = 0; i < 5; ++i) {
        currentMouse[i] = (mouseState & SDL_BUTTON(i + 1)) != 0;
    }
}

bool InputManager::isKeyDown(SDL_Scancode key) {
    return currentKeys[key] != 0;
}

bool InputManager::isKeyPressed(SDL_Scancode key) {
    return currentKeys[key] != 0 && previousKeys[key] == 0;
}

bool InputManager::isKeyReleased(SDL_Scancode key) {
    return currentKeys[key] == 0 && previousKeys[key] != 0;
}

bool InputManager::isMouseDown(int button) {
    if (button < 1 || button > 5) return false;
    return currentMouse[button - 1];
}

bool InputManager::isMousePressed(int button) {
    if (button < 1 || button > 5) return false;
    return currentMouse[button - 1] && !previousMouse[button - 1];
}

bool InputManager::isMouseReleased(int button) {
    if (button < 1 || button > 5) return false;
    return !currentMouse[button - 1] && previousMouse[button - 1];
}

void InputManager::getMousePos(int& x, int& y) {
    x = mouseX;
    y = mouseY;
}
