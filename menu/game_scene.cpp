/**
 * @file game_scene.cpp
 * @brief Реализация игровой сцены
 * @author evol
 * @date 2026-02-20
 */

#include "game_scene.h"

// Глобальный указатель на текущий уровень — читается в CollisionSystem
extern ILevel* g_currentLevel;

// ============================================================
//  КОНСТРУКТОР
// ============================================================

GameScene::GameScene()
    : continueBtn(0, BTN_CONTINUE_Y,   BTN_W, BTN_H, "Продолжить"),
    saveBtn    (0, BTN_SAVE_Y,        BTN_W, BTN_H, "Сохранить"),
    exitBtn    (0, BTN_EXIT_PAUSE_Y,  BTN_W, BTN_H, "Выйти в меню"),
    nextBtn    (0, BTN_NEXT_Y,        BTN_W, BTN_H, "В меню уровней"),
    retryBtn   (0, BTN_RETRY_Y,       BTN_W, BTN_H, "Заново")
{
    soundMgr = getSoundManager();

    const int W = Config::getWindowWidth();
    continueBtn.centerX(W);
    saveBtn    .centerX(W);
    exitBtn    .centerX(W);
    nextBtn    .centerX(W);
    retryBtn   .centerX(W);

    currentLevel = Config::getSelectedLevel();
    loadFromSave = Config::getLoadFromSave();
    Config::setLoadFromSave(false);  // сбрасываем чтобы RESTART_GAME не грузил сохранение
    initPositions();
}

// ============================================================
//  ИНИЦИАЛИЗАЦИЯ ПОЗИЦИЙ
// ============================================================
void GameScene::initPositions() {
    level          = createLevel(currentLevel);
    g_currentLevel = level.get();

    auto [px, py] = level->getPlayerSpawn();
    auto [bx, by] = level->getBossSpawn();

    const Config::Difficulty& diff = Config::getDifficulties()[Config::getCurrentDifficulty()];
    livesLeft = diff.respawns;

    // Загружаем autosave ТОЛЬКО если флаг выставлен (пользователь выбрал "Загрузить")
    if (loadFromSave) {
        GameSaveState saved;
        const bool ok = SaveManager::get().loadAutosave(saved)
                        && saved.currentLevel == currentLevel;
        if (ok) {
            px = saved.player.x;
            py = saved.player.y;
            bx = saved.boss.x;
            by = saved.boss.y;
            livesLeft  = saved.livesLeft;
            levelTimer = saved.levelTimer;
            std::cout << "[GameScene] Загружено autosave\n";
        }
    }

    const int mapW = level->getMapWidth();
    const int mapH = level->getMapHeight();

    player = std::make_unique<Player>(px, py, diff.playerHP);
    player->setMapSize(mapW, mapH);

    boss = level->createBoss(bx, by, diff.projectileSpeed);
    if (auto* golem = dynamic_cast<BossGolem*>(boss.get()))
        golem->setMapSize(mapW, mapH);

    // Восстанавливаем HP только при загрузке
    if (loadFromSave) {
        GameSaveState saved;
        if (SaveManager::get().loadAutosave(saved)) {
            if (saved.player.hp > 0.0f) player->setHP(saved.player.hp);
            if (auto* golem = dynamic_cast<BossGolem*>(boss.get())) {
                if (saved.boss.hp > 0.0f) golem->setHP(saved.boss.hp);
                if (saved.bossPhase == 1) golem->forcePhase2();   // ← новый метод
            }

        }
    }

    gameStarted = true;
    camera   = std::make_unique<Camera>(mapW, mapH);
    g_camera = camera.get();
    g_camera->snapTo(px, py);

    // --- Враги уровня 3 (Смерть Ночи) ---
    groundMinions.clear();
    archers.clear();
    minionSpawnTimer = MINION_SPAWN_INTERVAL;

    if (auto* lv3 = dynamic_cast<Level3*>(level.get())) {
        for (int i = 0; i < lv3->getMinionCount(); i++) {
            auto [ax, ay] = lv3->getMinionSpawn(i);
            archers.push_back(std::make_unique<ArcherMinion>(ax, ay, 1));
        }
    }
}

// ============================================================
//  ВЫЧИСЛЕНИЕ ПОЗИЦИИ СПАВНА ИГРОКА (для респавна)
// ============================================================

std::pair<float, float> GameScene::getPlayerSpawnPos() {
    if (level) return level->getPlayerSpawn();
    return {0.0f, 0.0f};
}

// ============================================================
//  ВВОД
// ============================================================
void GameScene::handleInput(SDL_Event& event, int mx, int my,
                            bool clicked, bool /*mouseDown*/) {
    if (resultState == ResultState::PLAYING) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                isPaused = !isPaused;
                if (soundMgr) soundMgr->playClick();
                break;
            case SDL_SCANCODE_H:
                if (player && boss) {
                    bool next = !player->showHitboxes;
                    player->showHitboxes = next;
                    if (auto* golem = dynamic_cast<BossGolem*>(boss.get()))
                        golem->showHitboxes = next;
                    if (auto* samurai = dynamic_cast<BossSamurai*>(boss.get()))
                        samurai->showHitboxes = next;
                    if (auto* archer = dynamic_cast<BossArcher*>(boss.get()))
                        archer->showHitboxes = next;
                    if (auto* deadnight = dynamic_cast<BossDeadNight*>(boss.get()))
                        deadnight->showHitboxes = next;
                }
                break;
            // Консольная команда — набираем текст в любой момент игры
            case SDL_SCANCODE_K:
                if (boss && resultState == ResultState::PLAYING) {
                    boss->takeDamage(9999999.0f);
                    std::cout << "[DEBUG] /kill_boss\n";
                }
                break;
            default:
                break;
            }
        }
    }

    if (event.type == SDL_TEXTINPUT && resultState == ResultState::PLAYING && !isPaused) {
        consoleInput += event.text.text;
        if (consoleInput.size() > 20) consoleInput.clear(); // защита от мусора
    }

    if (isPaused && resultState == ResultState::PLAYING) {
        if (updateButton(continueBtn, mx, my, clicked, soundMgr)) isPaused = false;
        if (updateButton(saveBtn,     mx, my, clicked, soundMgr)) saveGame();
        if (updateButton(exitBtn,     mx, my, clicked, soundMgr)) {
            SaveManager::get().saveOnExit(buildSaveState());
            nextScene = SceneType::LEVEL_SELECT;
        }
        return;
    }

    // ПОБЕДА — убрали условие PLAYING (оно блокировало кнопку)
    if (resultState == ResultState::VICTORY && starsRevealed >= earnedStars) {
        if (updateButton(nextBtn, mx, my, clicked, soundMgr))
            nextScene = SceneType::LEVEL_SELECT;
    }

    // ПОРАЖЕНИЕ — аналогично
    if (resultState == ResultState::DEFEAT) {
        if (updateButton(retryBtn, mx, my, clicked, soundMgr))
            nextScene = SceneType::RESTART_GAME;
        if (updateButton(exitBtn,  mx, my, clicked, soundMgr))
            nextScene = SceneType::LEVEL_SELECT;
    }
}

// ============================================================
//  UPDATE
// ============================================================

void GameScene::update(float deltaTime) {
    if (isPaused) return;

    // --- АВТОСОХРАНЕНИЕ (только во время игры) ---
    if (resultState == ResultState::PLAYING && gameStarted) {
        SaveManager::get().tickAutosave(deltaTime, buildSaveState());
    }

    if (resultState == ResultState::VICTORY && starsRevealed < earnedStars) {
        starRevealTimer += deltaTime;
        if (starRevealTimer >= STAR_REVEAL_DELAY) {
            starRevealTimer = 0.0f;
            starsRevealed++;
        }
    }

    if (resultState != ResultState::PLAYING) return;

    levelTimer += deltaTime;

    if (player) player->update(deltaTime);

    // Обновляем камеру по позиции игрока
    if (camera && player)
        camera->update(player->getX(), player->getY());

    if (boss && player) {
        // Вызываем update через интерфейс Character
        // Для боссов с расширенным update (BossGolem) используем dynamic_cast
        if (auto* golem = dynamic_cast<BossGolem*>(boss.get()))
            golem->update(deltaTime, player->getX(), player->getY());
        else if (auto* samurai = dynamic_cast<BossSamurai*>(boss.get())) {
            samurai->update(deltaTime, player->getX(), player->getY(), player->getFacingRight());
        } else if (auto* deadnight = dynamic_cast<BossDeadNight*>(boss.get())) {
            deadnight->update(deltaTime, player->getX(), player->getY(), player->getFacingRight());
        } else {
            boss->update(deltaTime);
        }
        SDL_Rect pb = player->getHitbox();

        const float dmgMult = Config::getDifficulties()[Config::getCurrentDifficulty()].damage;

        // Урон по игроку от босса
        if (auto* golem = dynamic_cast<BossGolem*>(boss.get())) {
            float dmgToPlayer = golem->checkPlayerDamage(pb, deltaTime) * dmgMult;
            if (dmgToPlayer > 0.0f) {
                player->takeDamage(dmgToPlayer);
                playerTookDamage = true;
            }
        }

        if (auto* samurai = dynamic_cast<BossSamurai*>(boss.get())) {
            float dmgToPlayer = samurai->checkPlayerDamage(pb, deltaTime) * dmgMult;
            if (dmgToPlayer > 0.0f) {
                player->takeDamage(dmgToPlayer);
                playerTookDamage = true;
            }
        }

        if (auto* archer = dynamic_cast<BossArcher*>(boss.get())) {
            archer->update(deltaTime, player->getX(), player->getY());
            float dmg = archer->checkPlayerDamage(pb, deltaTime) * dmgMult;
            if (dmg > 0.0f) {
                player->takeDamage(dmg);
                playerTookDamage = true;
            }
        }

        auto* deadnight = dynamic_cast<BossDeadNight*>(boss.get());
        if (deadnight) {
            float dmg = deadnight->checkPlayerDamage(pb, deltaTime) * dmgMult;
            if (dmg > 0.0f) {
                player->takeDamage(dmg);
                playerTookDamage = true;
            }
        }

        // Лучники и наземные миньоны уровня 3 — только пока жив BossDeadNight
        if (deadnight) {
            for (auto& archerMinion : archers) {
                archerMinion->setPhase(deadnight->getPhaseNumber());
                archerMinion->update(deltaTime, player->getX(), player->getY());
                float dmg = archerMinion->checkPlayerDamage(pb) * dmgMult;
                if (dmg > 0.0f) {
                    player->takeDamage(dmg);
                    playerTookDamage = true;
                }
            }

            for (auto& m : groundMinions) {
                float dmg = m->checkPlayerDamage(pb) * dmgMult;
                if (dmg > 0.0f) {
                    player->takeDamage(dmg);
                    playerTookDamage = true;
                }
            }

            updateGroundMinions(deltaTime);
        }

        // Урон от шипов уровня 2 (Level2::isSpike)
        if (auto* lv2 = dynamic_cast<Level2*>(level.get())) {
            bool onSpike =
                lv2->isSpike(pb.x,          pb.y + pb.h - 1) ||
                lv2->isSpike(pb.x + pb.w-1, pb.y + pb.h - 1) ||
                lv2->isSpike(pb.x,          pb.y) ||
                lv2->isSpike(pb.x + pb.w-1, pb.y);

            if (onSpike)
                player->takeDamage(Level2::SPIKE_DAMAGE_PER_SEC * deltaTime);
        }

        // Урон по боссу от игрока
        float dmgToBoss = player->consumeAttackDamage();
        if (dmgToBoss > 0.0f) {
            SDL_Rect atk = player->getAttackHitbox();
            if (auto* golem = dynamic_cast<BossGolem*>(boss.get())) {
                if (rectsOverlap(atk, golem->getHitbox()))
                    golem->takeDamage(dmgToBoss);
            } else if (auto* samurai = dynamic_cast<BossSamurai*>(boss.get())) {
                if (rectsOverlap(atk, samurai->getHitbox())) {
                    if (samurai->checkParry()) {
                        // Парирование — стан игрока
                        player->applyStun(PLAYER_STUN_DURATION);
                    } else {
                        samurai->takeDamage(dmgToBoss);
                    }
                }
            } else if (auto* archer = dynamic_cast<BossArcher*>(boss.get())) {
                if (rectsOverlap(atk, archer->getHitbox()))
                    archer->takeDamage(dmgToBoss);
            } else if (deadnight) {
                if (rectsOverlap(atk, deadnight->getHitbox()))
                    deadnight->takeDamage(dmgToBoss);
            }

            // Тот же замах может задеть наземного миньона.
            // Засчитывание убийства (ровно один раз) — в updateGroundMinions().
            for (auto& m : groundMinions) {
                if (!m->isDead() && rectsOverlap(atk, m->getHitbox()))
                    m->takeDamage(dmgToBoss);
            }
        }
    }

    // Магические снаряды
    if (player && boss) {
        for (auto& proj : player->getMagicProjectiles()) {
            if (!proj.active) continue;
            SDL_Rect projBox = {
                (int)(proj.x - MagicProjectile::SIZE / 2),
                (int)(proj.y - MagicProjectile::SIZE / 2),
                (int)MagicProjectile::SIZE,
                (int)MagicProjectile::SIZE
            };

            SDL_Rect bossHb = boss->getHitbox();
            if (rectsOverlap(projBox, bossHb)) {
                boss->takeDamage(MagicProjectile::DAMAGE);
                proj.active = false;
                continue;
            }

            // Тот же снаряд может задеть наземного миньона
            for (auto& m : groundMinions) {
                if (!m->isDead() && rectsOverlap(projBox, m->getHitbox())) {
                    m->takeDamage(MagicProjectile::DAMAGE);
                    proj.active = false;
                    break;
                }
            }
        }
    }
    // Победа / смена боссов
    if (boss && !boss->isAlive() && !bossDefeated) {
        bool finalDead = false;

        if (auto* golem = dynamic_cast<BossGolem*>(boss.get())) {
            // Голем — победа только во второй фазе
            finalDead = (golem->getPhase() == BossPhase::PHASE_2);

        } else if (auto* samurai = dynamic_cast<BossSamurai*>(boss.get())) {
            // Самурай — после смерти спавним лучника, победы НЕТ
            if (samurai->isDeathAnimFinished() && !samuraiDefeated) {
                samuraiDefeated = true;
                auto [bx, by]   = level->getBossSpawn();
                const Config::Difficulty& diff =
                    Config::getDifficulties()[Config::getCurrentDifficulty()];
                boss = std::make_unique<BossArcher>(bx, by, diff.projectileSpeed);
            }

        } else if (auto* archer = dynamic_cast<BossArcher*>(boss.get())) {
            // Лучник — настоящая победа
            finalDead = archer->isDeathAnimFinished();

        } else if (auto* deadnight2 = dynamic_cast<BossDeadNight*>(boss.get())) {
            // Смерть Ночи — финальный босс, победа сразу по смерти
            // TODO: заменить на !isDeathAnimFinished когда будет анимация смерти + взрывы
            finalDead = true;
        }
        if (finalDead) {
            bossDefeated = true;
            calculateAndSaveStars();
            resultState = ResultState::VICTORY;
        }
    }

    // Поражение
    if (player && !player->isAlive() && resultState == ResultState::PLAYING) {
        if (livesLeft == -1) {
            respawnPlayer();
        } else if (livesLeft > 0) {
            livesLeft--;
            respawnPlayer();
        } else {
            resultState = ResultState::DEFEAT;
        }
    }
}

// ============================================================
//  НАЗЕМНЫЕ МИНЬОНЫ (Уровень 3)
// ============================================================

void GameScene::updateGroundMinions(float deltaTime) {
    auto* lv3       = dynamic_cast<Level3*>(level.get());
    auto* deadnight = dynamic_cast<BossDeadNight*>(boss.get());
    if (!lv3 || !deadnight) return;

    int ox, oy;
    lv3->getMapOffset(ox, oy);

    // Спавн — только после 30 сек выживания и пока не набрано 5/5
    if (deadnight->getSurvivalPassed() &&
        deadnight->getMinionsKilled() < deadnight->getMinionsRequired()) {
        minionSpawnTimer -= deltaTime;
        if (minionSpawnTimer <= 0.0f) {
            minionSpawnTimer = MINION_SPAWN_INTERVAL;

            const float spawnX = ox + Level3::MINION_SPAWN_COL * TILE_SIZE + TILE_SIZE / 2.0f;
            const float spawnY = oy + Level3::MINION_SPAWN_ROW * TILE_SIZE + TILE_SIZE / 2.0f;
            const float doorX  = ox + Level3::DOOR_COL * TILE_SIZE + TILE_SIZE / 2.0f;

            groundMinions.push_back(std::make_unique<GroundMinion>(
                spawnX, spawnY, doorX, deadnight->getPhaseNumber()));
        }
    }

    for (auto& m : groundMinions) {
        m->update(deltaTime);

        // Ровно одно засчитывание убийства за реальную смерть от урона
        if (m->consumeKillEvent())
            deadnight->registerMinionKilled();
    }

    groundMinions.erase(
        std::remove_if(groundMinions.begin(), groundMinions.end(),
                       [](const std::unique_ptr<GroundMinion>& m) { return m->shouldRemove(); }),
        groundMinions.end());
}

void GameScene::renderGroundMinions(SDL_Renderer* renderer) {
    for (auto& m : groundMinions) m->render(renderer);
}

void GameScene::renderArchers(SDL_Renderer* renderer) {
    for (auto& a : archers) a->render(renderer);
}

// ============================================================
//  РЕСПАВН
// ============================================================

void GameScene::respawnPlayer() {
    auto [px, py] = getPlayerSpawnPos();
    const Config::Difficulty& diff = Config::getDifficulties()[Config::getCurrentDifficulty()];
    player = std::make_unique<Player>(px, py, diff.playerHP);
    // Сохраняем флаг хитбоксов при респавне
    if (auto* golem = dynamic_cast<BossGolem*>(boss.get()))
        player->showHitboxes = golem->showHitboxes;
    playerTookDamage = true;
}

// ============================================================
//  ПОДСЧЁТ ЗВЁЗД
// ============================================================

void GameScene::calculateAndSaveStars() {
    earnedStars = 1;
    if (!playerTookDamage)                earnedStars++;
    if (levelTimer <= TIME_LIMIT_SECONDS) earnedStars++;

    int prev = Config::getLevelStars(currentLevel);
    if (earnedStars > prev)
        Config::setLevelStars(currentLevel, earnedStars);
}

// ============================================================
//  РЕНДЕР
// ============================================================

void GameScene::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, BG_R, BG_G, BG_B, 255);
    SDL_Rect bg = {0, 0, Config::getWindowWidth(), Config::getWindowHeight()};
    SDL_RenderFillRect(renderer, &bg);

    // Рисуем карту текущего уровня через интерфейс
    if (level) {
        int camX = camera ? (int)camera->getOffsetX() : 0;
        int camY = camera ? (int)camera->getOffsetY() : 0;
        level->drawMap(renderer, camX, camY);
    }

    if (player) player->render(renderer);
    if (boss)   boss->render(renderer);
    renderArchers(renderer);
    renderGroundMinions(renderer);
    drawHealthBars(renderer);

    // Пауза
    if (isPaused && resultState == ResultState::PLAYING) {
        drawUIOverlay(renderer, OVERLAY_ALPHA);
        drawText(renderer, Config::getFont(), "ПАУЗА",
                 0, PAUSE_TITLE_Y, {255, 255, 100, 255}, true, Config::getTitleFont());
        drawButton(renderer, Config::getFont(), continueBtn);
        drawButton(renderer, Config::getFont(), saveBtn);
        drawButton(renderer, Config::getFont(), exitBtn);
        drawText(renderer, Config::getFont(), "ESC - продолжить",
                 0, Config::getWindowHeight() - PAUSE_HINT_Y, {200, 200, 200, 255}, true);
        return;
    }

    if (resultState == ResultState::VICTORY) { renderVictoryScreen(renderer); return; }
    if (resultState == ResultState::DEFEAT)  { renderDefeatScreen(renderer); }
}

// ============================================================
//  ЭКРАН ПОБЕДЫ
// ============================================================

void GameScene::renderVictoryScreen(SDL_Renderer* renderer) {
    const int W = Config::getWindowWidth();
    drawUIOverlay(renderer, RESULT_OVERLAY_ALPHA);
    drawText(renderer, Config::getFont(), "ПОБЕДА!",
             0, VICTORY_TITLE_Y, {255, 215, 0, 255}, true, Config::getTitleFont());

    int mins = (int)levelTimer / 60;
    int secs = (int)levelTimer % 60;
    char timeBuf[32];
    std::snprintf(timeBuf, sizeof(timeBuf), "Время: %d:%02d", mins, secs);
    drawText(renderer, Config::getFont(), timeBuf,
             0, VICTORY_TIME_Y, {200, 200, 200, 255}, true);

    const int totalW = 3 * (VICTORY_STAR_SIZE * 2) + 2 * VICTORY_STAR_GAP;
    const int startX = (W - totalW) / 2 + VICTORY_STAR_SIZE;

    const char* labels[3] = {"Убить", "3 минуты", "Без урона"};
    for (int i = 0; i < 3; i++) {
        int cx = startX + i * (VICTORY_STAR_SIZE * 2 + VICTORY_STAR_GAP);
        drawStar(renderer, cx, VICTORY_STAR_Y, VICTORY_STAR_SIZE,
                 (i < starsRevealed) && (i < earnedStars));
        SDL_Color c = (i < earnedStars)
                          ? SDL_Color{255, 215, 0, 255}
                          : SDL_Color{120, 120, 120, 255};
        drawText(renderer, Config::getFont(), labels[i],
                 cx - VICTORY_STAR_SIZE,
                 VICTORY_STAR_Y + VICTORY_STAR_SIZE + VICTORY_STAR_LABEL_DY, c);
    }

    if (starsRevealed >= earnedStars)
        drawButton(renderer, Config::getFont(), nextBtn);
}

// ============================================================
//  ЭКРАН ПОРАЖЕНИЯ
// ============================================================

void GameScene::renderDefeatScreen(SDL_Renderer* renderer) {
    drawUIOverlay(renderer, RESULT_OVERLAY_ALPHA);
    drawText(renderer, Config::getFont(), "ПОРАЖЕНИЕ",
             0, DEFEAT_TITLE_Y, {220, 50, 50, 255}, true, Config::getTitleFont());

    int mins = (int)levelTimer / 60;
    int secs = (int)levelTimer % 60;
    char timeBuf[32];
    std::snprintf(timeBuf, sizeof(timeBuf), "Прожил: %d:%02d", mins, secs);
    drawText(renderer, Config::getFont(), timeBuf,
             0, DEFEAT_TIME_Y, {200, 200, 200, 255}, true);

    drawButton(renderer, Config::getFont(), retryBtn);
    drawButton(renderer, Config::getFont(), exitBtn);
}

// ============================================================
//  ЗВЕЗДА
// ============================================================

void GameScene::drawStar(SDL_Renderer* renderer, int cx, int cy, int size, bool filled) {
    // Рамка звезды
    SDL_SetRenderDrawColor(renderer, 180, 150, 0, 255);
    SDL_Rect outline = {cx - size, cy - size, size * 2, size * 2};
    SDL_RenderDrawRect(renderer, &outline);

    // Заливка (золото если заработана, тёмная если нет)
    SDL_SetRenderDrawColor(renderer,
                           filled ? 255 : 55,
                           filled ? 215 : 55,
                           filled ?   0 : 55,
                           255);
    SDL_Rect inner = {
        cx - size + STAR_BORDER,
        cy - size + STAR_BORDER,
        size * 2  - STAR_BORDER * 2,
        size * 2  - STAR_BORDER * 2
    };
    SDL_RenderFillRect(renderer, &inner);
}

// ============================================================
//  HP БАРЫ + ЖИЗНИ
// ============================================================

void GameScene::drawHealthBars(SDL_Renderer* renderer) {
    const int W = Config::getWindowWidth();

    if (player) {
        float pct = player->getHP() / player->getMaxHP();
        drawText(renderer, Config::getFont(), "Игрок",
                 HUD_BAR_X, HUD_LABEL_Y, {200, 200, 200, 255});

        // HP бар игрока
        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
        SDL_Rect bg  = {HUD_BAR_X, HUD_BAR_Y, HUD_BAR_W, HUD_BAR_H};
        SDL_RenderFillRect(renderer, &bg);
        SDL_SetRenderDrawColor(renderer, 60, 200, 60, 255);
        SDL_Rect bar = {HUD_BAR_X, HUD_BAR_Y, (int)(HUD_BAR_W * pct), HUD_BAR_H};
        SDL_RenderFillRect(renderer, &bar);
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderDrawRect(renderer, &bg);

        // Жизни
        if (livesLeft == -1) {
            drawText(renderer, Config::getFont(), "∞",
                     HUD_BAR_X, HUD_LIVES_Y, {100, 200, 255, 255});
        } else {
            const int total = std::min(livesLeft, HUD_MAX_LIVES);
            for (int i = 0; i < total; i++) {
                SDL_SetRenderDrawColor(renderer, 60, 160, 255, 255);
                SDL_Rect cell = {
                    HUD_BAR_X + i * (HUD_LIFE_W + HUD_LIFE_GAP),
                    HUD_LIVES_Y,
                    HUD_LIFE_W, HUD_LIFE_H
                };
                SDL_RenderFillRect(renderer, &cell);
                SDL_SetRenderDrawColor(renderer, 120, 200, 255, 200);
                SDL_RenderDrawRect(renderer, &cell);
            }
        }

        // Мана
        float manaPct = player->getMana() / player->getMaxMana();
        drawText(renderer, Config::getFont(), "Мана",
                 HUD_BAR_X, HUD_MANA_LBL_Y, {150, 150, 255, 255});

        SDL_SetRenderDrawColor(renderer, 20, 20, 60, 220);
        SDL_Rect manaBg  = {HUD_BAR_X, HUD_MANA_Y, HUD_BAR_W, HUD_MANA_H};
        SDL_RenderFillRect(renderer, &manaBg);
        SDL_SetRenderDrawColor(renderer, 80, 160, 255, 255);
        SDL_Rect manaBar = {HUD_BAR_X, HUD_MANA_Y, (int)(HUD_BAR_W * manaPct), HUD_MANA_H};
        SDL_RenderFillRect(renderer, &manaBar);
        SDL_SetRenderDrawColor(renderer, 120, 120, 200, 255);
        SDL_RenderDrawRect(renderer, &manaBg);

        char manaBuf[16];
        std::snprintf(manaBuf, sizeof(manaBuf), "%.0f/%.0f",
                      player->getMana(), player->getMaxMana());
        drawText(renderer, Config::getFont(), manaBuf,
                 HUD_MANA_VAL_X, HUD_MANA_VAL_Y, {150, 200, 255, 255});
    }

    // Подсказки внизу экрана
    {
        bool hbOn  = (player && player->showHitboxes);
        SDL_Color c = hbOn
                          ? SDL_Color{100, 255, 100, 255}
                          : SDL_Color{150, 150, 150, 180};
        drawText(renderer, Config::getFont(),
                 hbOn ? "[H] Хитбоксы: ВКЛ" : "[H] Хитбоксы: ВЫКЛ",
                 0, Config::getWindowHeight() - HUD_HINT_HB_Y, c, true);
    }
    drawText(renderer, Config::getFont(), "ESC - пауза",
             0, Config::getWindowHeight() - HUD_HINT_ESC_Y, {150, 150, 150, 180}, true);

    // Таймер по центру
    if (resultState == ResultState::PLAYING) {
        int remaining = std::max(0, (int)(TIME_LIMIT_SECONDS - levelTimer));
        char buf[16];
        std::snprintf(buf, sizeof(buf), "%d:%02d", remaining / 60, remaining % 60);
        drawText(renderer, Config::getFont(), buf,
                 0, HUD_LABEL_Y, {255, 255, 255, 255}, true);
    }

    // HP босса (справа)
    if (boss) {
        float pct = boss->getHP() / boss->getMaxHP();
        drawText(renderer, Config::getFont(), "Босс",
                 W - HUD_BOSS_X_OFF, HUD_LABEL_Y, {200, 200, 200, 255});

        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
        SDL_Rect bg  = {W - HUD_BOSS_X_OFF, HUD_BAR_Y, HUD_BAR_W, HUD_BAR_H};
        SDL_RenderFillRect(renderer, &bg);
        SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
        SDL_Rect bar = {W - HUD_BOSS_X_OFF, HUD_BAR_Y, (int)(HUD_BAR_W * pct), HUD_BAR_H};
        SDL_RenderFillRect(renderer, &bar);
        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderDrawRect(renderer, &bg);

        // Фиолетовая полоса — прогресс убийства миньонов (только у Смерти Ночи)
        if (auto* deadnight = dynamic_cast<BossDeadNight*>(boss.get())) {
            const int killed   = deadnight->getMinionsKilled();
            const int required = deadnight->getMinionsRequired();
            const float mpct   = required > 0 ? (float)killed / (float)required : 0.0f;
            const int purpleY  = HUD_BAR_Y + HUD_BAR_H + HUD_MINION_BAR_GAP_Y;

            drawText(renderer, Config::getFont(), "Миньоны",
                     W - HUD_BOSS_X_OFF, purpleY - 20, {200, 200, 200, 255});

            SDL_SetRenderDrawColor(renderer, 40, 40, 40, 220);
            SDL_Rect pbg = {W - HUD_BOSS_X_OFF, purpleY, HUD_BAR_W, HUD_BAR_H};
            SDL_RenderFillRect(renderer, &pbg);
            SDL_SetRenderDrawColor(renderer, 160, 60, 220, 255);
            SDL_Rect pbar = {W - HUD_BOSS_X_OFF, purpleY, (int)(HUD_BAR_W * mpct), HUD_BAR_H};
            SDL_RenderFillRect(renderer, &pbar);
            SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
            SDL_RenderDrawRect(renderer, &pbg);

            char buf[16];
            std::snprintf(buf, sizeof(buf), "%d/%d", killed, required);
            drawText(renderer, Config::getFont(), buf,
                     W - HUD_BOSS_X_OFF + HUD_BAR_W + 10, purpleY, {220, 180, 255, 255});
        }
    }
}

void GameScene::saveGame() {}

SceneType GameScene::getNextScene() {
    return nextScene;
}

GameSaveState GameScene::buildSaveState() const {
    GameSaveState s;

    // Позиции и HP игрока
    if (player) {
        s.player.x           = player->getX();
        s.player.y           = player->getY();
        s.player.hp          = player->getHP();
        s.player.facingRight = player->getFacingRight();
    }

    // Позиции и HP босса
    if (boss) {
        s.boss.x           = boss->getX();
        s.boss.y           = boss->getY();
        s.boss.hp          = boss->getHP();
        s.boss.facingRight = boss->getFacingRight();
    }

    if (auto* golem = dynamic_cast<BossGolem*>(boss.get())) {
        // Сохраняем фазу — только 1 или 2, переходные состояния округляем до ближайшей
        BossPhase phase = golem->getPhase();
        s.bossPhase = (phase == BossPhase::PHASE_2) ? 1 : 0;
    }


    // Прогресс
    s.levelTimer   = levelTimer;
    s.currentLevel = currentLevel;
    s.livesLeft    = livesLeft;
    s.difficulty   = Config::getCurrentDifficulty();

    // Лучшие звёзды
    for (int i = 0; i < 3; i++)
        s.bestStars[i] = Config::getLevelStars(i);

    // Управление
    SaveManager::fillControlsFromConfig(s);

    return s;
}