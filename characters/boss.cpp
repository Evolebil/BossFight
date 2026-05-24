/**
 * @file boss.cpp
 * @brief Реализация базового класса Boss
 * @author evol
 * @date 2026-05-20
 */
#include "boss.h"

// ============================================================
// КОНСТРУКТОР
// ============================================================

Boss::Boss(float spawnX, float spawnY, float w, float h, float health,
           float attackSpeedMult)
    : Character(spawnX, spawnY, w, h, health)
{
    // Поля зависящие от параметров — нельзя задать дефолтом в .h
    this->attackSpeedMult = attackSpeedMult;
    this->lastPlayerX     = spawnX;   // при старте считаем что игрок рядом со спавном
    this->lastPlayerY     = spawnY;
    this->mapW            = Config::getWindowWidth();
    this->mapH            = Config::getWindowHeight();
}

// ============================================================
// ПОЛУЧЕНИЕ УРОНА
// ============================================================

/**
 * Урон уменьшается на (defense * 100)%.
 * defense = 0.0 → полный урон
 * defense = 0.5 → половина урона (блок голема)
 * defense = 1.0 → полный иммунитет
 */
void Boss::takeDamage(float damage) {
    hp -= damage * (1.0f - defense);
    hp = std::clamp(hp, 0.0f, maxHP);
}