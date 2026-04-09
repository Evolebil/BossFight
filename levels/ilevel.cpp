/**
 * @file ilevel.cpp
 * @brief Фабрика уровней
 * @author evol
 * @date 2026-04-06
 */
#include "ilevel.h"
#include "level1.h"
#include "level2.h"
// #include "level3.h"

// Глобальный указатель на текущий уровень — используется CollisionSystem
ILevel* g_currentLevel = nullptr;

std::unique_ptr<ILevel> createLevel(int index) {
    switch (index) {
    case 0:  return std::make_unique<Level1>();
    case 1:  return std::make_unique<Level2>();
    // case 2:  return std::make_unique<Level3>();
    default: return std::make_unique<Level1>();
    }
}