/**
 * @file main.cpp
 * @brief Точка входа — инициализация SDL, создание окна, игровой цикл
 * @author evol
 * @date 2026-02-20
 */
#include <SDL2/SDL.h>
#include "config/config.h"
#include "ui/ui.h"
#include "utils/scene_manager.h"
#include "utils/texture_manager.h"
#include "utils/input_manager.h"
#include "utils/sound_manager.h"
#include "config/common.h"
#include "utils/save_manager.h"

// Глобальный SoundManager — передаётся в сцены через getSoundManager()
SoundManager* g_soundMgr = nullptr;

// ============================================================
// ЗАГРУЗКА ЗВУКОВ (вынесено из main для читаемости)
// ============================================================

static void loadSounds(SoundManager& mgr) {
    // hover, click, slider — одна и та же кнопочная звуковая дорожка
    const char* btn = "assets/sound/button.mp3";
    mgr.loadSound("hover",         btn);
    mgr.loadSound("click",         btn);
    mgr.loadSound("slider",        btn);
    mgr.loadSound("attack_golem",  "assets/sound/attak_golem.mp3");
    mgr.loadSound("laser_attack",  "assets/sound/lazer_attak.mp3");
    mgr.loadSound("melee_attack",  "assets/sound/mellee_attak_player.mp3");
    // Файла ranged_attack_player.mp3 в проекте нет — бросок руки Голема был без звука
    mgr.loadSound("ranged_attack", "assets/sound/bomb_throw.wav");
    mgr.loadSound("golem_move",    "assets/sound/move_golem.mp3");
    mgr.loadSound("jump",        "assets/sound/jamp.wav");
    mgr.loadSound("land",        "assets/sound/isGrounded_true.wav");
    mgr.loadSound("magic_cast",  "assets/sound/magic.wav");
    mgr.loadSound("dash",        "assets/sound/dash.mp3");
    mgr.loadSound("shield",      "assets/sound/Shield.wav");
    mgr.loadSound("player_hurt", "assets/sound/damade_on_player.wav");
    mgr.loadSound("golem_block",    "assets/sound/BLOCK_BOSS_GOLEM.wav");
    mgr.loadSound("golem_slam",     "assets/sound/the-fall-of-a-huge-object-and-split-into-smithereens.wav");
    mgr.loadSound("golem_teleport", "assets/sound/krugovorot-vihr.mp3");
    mgr.loadSound("golem_death",    "assets/sound/the-sound-of-crumbling-rock.wav");
    mgr.loadSound("golem_revive",   "assets/sound/ec75ae3b628d993.mp3");
    mgr.loadSound("golem_dash",     "assets/sound/short-powerful-swing.wav");

    // Самурай
    mgr.loadSound("samurai_sword",  "assets/sound/samurai_sword.wav");
    mgr.loadSound("samurai_power",  "assets/sound/samurai_power.wav");
    mgr.loadSound("samurai_parry",  "assets/sound/samurai_parry.wav");
    mgr.loadSound("samurai_stance", "assets/sound/samurai_stance.wav");
    mgr.loadSound("samurai_death",  "assets/sound/samurai_death.wav");
    mgr.loadSound("bomb_throw",     "assets/sound/bomb_throw.wav");
    mgr.loadSound("bomb_explode",   "assets/sound/bomb_explode.wav");
    mgr.loadSound("boss_teleport",  "assets/sound/boss_teleport.wav");

    // Лучник
    mgr.loadSound("archer_sword",    "assets/sound/archer_sword.wav");
    mgr.loadSound("archer_bow",      "assets/sound/archer_bow.wav");
    mgr.loadSound("archer_teleport", "assets/sound/archer_teleport.wav");
    mgr.loadSound("archer_death",    "assets/sound/archer_death.wav");

    // Смерть Ночи и её миньоны
    mgr.loadSound("deadnight_fireball",         "assets/sound/deadnight_fireball.wav");
    mgr.loadSound("deadnight_fireball_explode", "assets/sound/deadnight_fireball_explode.wav");
    mgr.loadSound("deadnight_dash",             "assets/sound/deadnight_dash.wav");
    mgr.loadSound("deadnight_ascend",           "assets/sound/deadnight_ascend.wav");
    mgr.loadSound("deadnight_death",            "assets/sound/deadnight_death.wav");
    mgr.loadSound("minion_death",               "assets/sound/minion_death.wav");
}

// main.cpp
static void loadMusicTracks(SoundManager& mgr) {
    mgr.loadMusic("menu_music",   "assets/musik/Menu.wav");
    mgr.loadMusic("level3_music", "assets/musik/Boss_3_Theme.wav");

    mgr.loadMusic("level1_music",        "assets/musik/level1_music_face1.mp3"); // фаза 1
    mgr.loadMusic("level1_music_phase2", "assets/musik/level1_music_face2.mp3"); // фаза 2
    mgr.loadMusic("level2_music",        "assets/musik/level2_music.mp3");       // ayitsmatt — The Law of the Samurai
}

// ============================================================
// MAIN
// ============================================================

int main(int /*argc*/, char* /*argv*/[]) {
#ifndef _WIN32
    // На некоторых Linux-системах SDL по умолчанию пытается выбрать pulse/pipewire
    // драйвер и молча остаётся без звука, даже если аудиосистема в порядке.
    // ALSA работает предсказуемо почти везде на Linux (pulse/pipewire и сами
    // обычно работают поверх неё) — форсируем её как дефолт, но только если
    // пользователь явно не задал свой драйвер через SDL_AUDIODRIVER
    // (overrideExisting=0 это гарантирует). На Windows такого драйвера нет
    // вообще, поэтому здесь ничего не форсируем — пусть SDL выбирает сам.
    SDL_setenv("SDL_AUDIODRIVER", "alsa", 0);
#endif

    // === ИНИЦИАЛИЗАЦИЯ SDL ===
    // Видео и аудио инициализируем раздельно: без окна игра бессмысленна,
    // но без звука она всё ещё может работать (просто тихо). Раньше здесь
    // была одна общая проверка — падение аудио (недоступная ALSA, отсутствие
    // звуковой карты и т.д.) гасило игру целиком, даже не открыв окно.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL ошибка: " << SDL_GetError() << "\n";
        return 1;
    }
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
        std::cerr << "WARNING: аудиоподсистема SDL не инициализирована: "
                  << SDL_GetError() << " — игра продолжит работу без звука\n";
    }

    // === ИНИЦИАЛИЗАЦИЯ CONFIG (шрифты) ===
    if (!Config::init()) {
        std::cerr << "Ошибка инициализации Config\n";
        SDL_Quit();
        return 1;
    }

    Config::loadProgress();   // загружаем сохранённый прогресс при запуске
    SaveManager::get().loadIndex();  // загружаем индекс сохранений при старте

    // === ОКНО И РЕНДЕРЕР ===
    SDL_Window* window = SDL_CreateWindow(
        "Boss Fight",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Config::getWindowWidth(), Config::getWindowHeight(),
        SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Ошибка создания окна: " << SDL_GetError() << "\n";
        Config::cleanup();
        SDL_Quit();
        return 1;
    }

    g_gameWindow = window;  // нужно Settings-сцене для fullscreen/смены разрешения

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Ошибка создания рендерера: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        Config::cleanup();
        SDL_Quit();
        return 1;
    }

    // Виртуальное разрешение — SDL сам масштабирует на реальный экран
    SDL_RenderSetLogicalSize(renderer,
                             Config::getWindowWidth(),
                             Config::getWindowHeight());

    // === ЗВУК ===
    // unique_ptr — автоматически удалится при выходе из main
    auto soundMgrPtr = std::make_unique<SoundManager>();
    g_soundMgr = soundMgrPtr.get();

    if (!g_soundMgr->init()) {
        std::cerr << "WARNING: звуковая система не инициализирована\n";
    }
    loadSounds(*g_soundMgr);
    loadMusicTracks(*g_soundMgr);
    g_soundMgr->soundVolume = Config::getSoundVolume();
    g_soundMgr->musicVolume = Config::getMusicVolume();

    // === ТЕКСТУРЫ ===
    TextureManager::init(renderer);

    // === МЕНЕДЖЕР СЦЕН ===
    SceneManager sceneManager(renderer);
    sceneManager.loadScene(SceneType::SPLASH);

    // === ИГРОВОЙ ЦИКЛ ===
    bool      running  = true;
    SDL_Event event;
    int       mouseX   = 0, mouseY = 0;
    bool      mouseClicked = false;
    bool      mouseDown    = false;

    Uint32 lastTime = SDL_GetTicks();

    while (running && !sceneManager.shouldQuit()) {
        const Uint32 frameStart = SDL_GetTicks();

        // Deltatime — время прошедшее с прошлого кадра
        float deltaTime = (frameStart - lastTime) / 1000.0f;
        lastTime = frameStart;

        // Сбрасываем одноразовый клик
        mouseClicked = false;

        // === СОБЫТИЯ ===
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;

            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_F11) {
                Config::toggleFullscreen(window);
            }

            if (event.type == SDL_MOUSEMOTION) {
                mouseX = event.motion.x;
                mouseY = event.motion.y;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                mouseClicked = true;
                mouseDown    = true;
            }
            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                mouseDown = false;
            }

            sceneManager.handleInput(event, mouseX, mouseY, mouseClicked, mouseDown);
        }

        // === ОБНОВЛЕНИЕ ===
        InputManager::update();
        sceneManager.update(deltaTime);

        // === РЕНДЕРИНГ ===
        SDL_RenderClear(renderer);
        sceneManager.render();
        SDL_RenderPresent(renderer);

        // Ограничение FPS: ждём остаток от 16ms (≈62 FPS максимум)
        const Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 16) SDL_Delay(16 - frameTime);
    }

    // === ОЧИСТКА ===
    TextureManager::cleanup();
    // g_soundMgr удаляется автоматически (unique_ptr)
    Config::cleanup();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}