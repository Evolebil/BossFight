#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H
/**
 * @file collision_system.h
 * @brief Система коллизий — AABB проверки для всех персонажей
 * @author evol
 * @date 2026-02-20
 *
 * Использование:
 *   CollisionSystem::resolveX(x, velocityX, width, height);
 *   CollisionSystem::resolveY(y, velocityY, width, height, isGrounded);
 *
 * Вызывай resolveX ДО resolveY — по одной оси за раз.
 */

#pragma once
#include "../config/common.h"

/**
 * @class CollisionSystem
 * @brief Статический класс для разрешения коллизий с тайлами карты.
 *
 * Не хранит никакого состояния — только статические методы.
 * Работает с любым персонажем: Player, Boss, и будущими.
 */
class CollisionSystem {
public:
    static void resolveX(float& x, float y, float& velocityX, float width, float height);

    static void resolveY(float x, float& y, float& velocityY,
                         float width, float height, bool& isGrounded,
                         bool ignorePlatforms = false);

    /**
     * @brief Останавливает движение по X о хитбокс другого персонажа —
     *        та же логика, что и resolveX с тайлами. Если velocityX == 0 —
     *        объект не двигается, ничего не делаем (не толкаем того, кто
     *        просто стоит). Если объект реально едет в сторону otherBox —
     *        гасим его движение на границе. otherBox никогда не трогаем.
     */
    static void resolveEntityX(float& x, float y, float& velocityX,
                               float width, float height, const SDL_Rect& otherBox);

private:
    CollisionSystem() = delete;
};
#endif // COLLISION_SYSTEM_H