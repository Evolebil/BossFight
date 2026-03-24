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
    /**
     * @brief Разрешает коллизии по оси X.
     *
     * Вызывать ПОСЛЕ x += velocityX * dt, ПЕРЕД resolveY.
     *
     * @param x         Позиция центра персонажа по X (изменяется при коллизии)
     * @param velocityX Скорость по X (обнуляется при коллизии)
     * @param width     Ширина хитбокса
     * @param height    Высота хитбокса
     */
    static void resolveX(float& x, float y, float& velocityX, float width, float height);

    /**
     * @brief Разрешает коллизии по оси Y.
     *
     * Вызывать ПОСЛЕ y += velocityY * dt и ПОСЛЕ resolveX.
     *
     * @param x          Позиция центра по X (только чтение)
     * @param y          Позиция центра по Y (изменяется при коллизии)
     * @param velocityY  Скорость по Y (обнуляется при коллизии)
     * @param width      Ширина хитбокса
     * @param height     Высота хитбокса
     * @param isGrounded Флаг "на земле" (выставляется этим методом)
     */
    static void resolveY(float x, float& y, float& velocityY,
                         float width, float height, bool& isGrounded);

private:
    // Конструктор закрыт — класс полностью статический, создавать объекты не нужно
    CollisionSystem() = delete;
};
#endif // COLLISION_SYSTEM_H
