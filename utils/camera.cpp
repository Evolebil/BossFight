/**
 * @file camera.cpp
 * @brief Реализация камеры с dead zone
 * @author evol
 * @date 2026-04-07
 */
#include "camera.h"
#include "../config/config.h"

Camera* g_camera = nullptr;

Camera::Camera(int mapWidthPx, int mapHeightPx)
    : offsetX(0.0f), offsetY(0.0f),
    mapWidth(mapWidthPx), mapHeight(mapHeightPx) {

    viewWidth  = Config::getWindowWidth();
    viewHeight = Config::getWindowHeight();

    // Dead zone — прямоугольник 40% ширины и 40% высоты экрана по центру
    deadZoneX = viewWidth  * 0.20f;  // отступ от края зоны по X
    deadZoneY = viewHeight * 0.20f;  // отступ от края зоны по Y
}

void Camera::update(float playerX, float playerY) {
    // Центр dead zone в экранных координатах
    float screenX = playerX - offsetX;
    float screenY = playerY - offsetY;

    // Левая/правая граница dead zone
    float zoneLeft   = viewWidth  * 0.5f - deadZoneX;
    float zoneRight  = viewWidth  * 0.5f + deadZoneX;
    float zoneTop    = viewHeight * 0.5f - deadZoneY;
    float zoneBottom = viewHeight * 0.5f + deadZoneY;

    // Двигаем камеру только если игрок вышел за зону
    if (screenX < zoneLeft)   offsetX -= (zoneLeft   - screenX);
    if (screenX > zoneRight)  offsetX += (screenX - zoneRight);
    if (screenY < zoneTop)    offsetY -= (zoneTop    - screenY);
    if (screenY > zoneBottom) offsetY += (screenY - zoneBottom);

    // Clamp — камера не выходит за границы карты
    // Если карта меньше экрана — камера не двигается по этой оси
    float maxOffsetX = std::max(0.0f, (float)(mapWidth  - viewWidth));
    float maxOffsetY = std::max(0.0f, (float)(mapHeight - viewHeight));
    offsetX = std::clamp(offsetX, 0.0f, maxOffsetX);
    offsetY = std::clamp(offsetY, 0.0f, maxOffsetY);
}
// После метода update() добавь:
void Camera::snapTo(float playerX, float playerY) {
    offsetX = playerX - viewWidth  * 0.5f;
    offsetY = playerY - viewHeight * 0.5f;
    float maxOffX = std::max(0.0f, (float)(mapWidth  - viewWidth));
    float maxOffY = std::max(0.0f, (float)(mapHeight - viewHeight));
    offsetX = std::clamp(offsetX, 0.0f, maxOffX);
    offsetY = std::clamp(offsetY, 0.0f, maxOffY);
}