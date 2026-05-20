/**
 * @file boss.cpp
 * @brief Реализация базового класса Boss
 * @author evol
 * @date 2026-05-20
 */
#include "boss.h"

Boss::Boss(float spawnX, float spawnY, float w, float h, float health,
           float attackSpeedMult)
    : Character(spawnX, spawnY, w, h, health)
{
    this->attackSpeedMult = attackSpeedMult;
    this->lastPlayerX     = spawnX;
    this->lastPlayerY     = spawnY;
    this->mapW            = Config::getWindowWidth();
    this->mapH            = Config::getWindowHeight();
}

void Boss::takeDamage(float damage) {
    hp -= damage * (1.0f - defense);
    hp = std::clamp(hp, 0.0f, maxHP);
}