/**
 * @file camera.h
 * @brief Камера с dead zone — следит за игроком с опозданием
 * @author evol
 * @date 2026-04-07
 */
#pragma once
#include "../config/common.h"
#include "../characters/boss_golem.h"
#include "../levels/level1_assets.h"
#include "../characters/player.h"

class Camera {
private:
    float offsetX, offsetY;       // текущее смещение камеры
    float deadZoneX, deadZoneY;   // размер зоны где камера не двигается
    int   mapWidth, mapHeight;    // границы карты в пикселях
    int   viewWidth, viewHeight;  // размер экрана (1280x720)

public:
    Camera(int mapWidthPx, int mapHeightPx);

    // Обновляет позицию камеры по позиции игрока
    void update(float playerX, float playerY);
    void snapTo(float playerX, float playerY);

    // Перевод мировых координат в экранные
    [[nodiscard]] float worldToScreenX(float worldX) const { return worldX - offsetX; }
    [[nodiscard]] float worldToScreenY(float worldY) const { return worldY - offsetY; }

    [[nodiscard]] float getOffsetX() const { return offsetX; }
    [[nodiscard]] float getOffsetY() const { return offsetY; }
};

// Глобальная камера — читается в render() персонажей
extern Camera* g_camera;