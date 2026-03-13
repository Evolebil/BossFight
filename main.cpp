#include <SDL2/SDL.h>
#include "config/config.h"
#include "ui/ui.h"
#include "utils/scene_manager.h"
#include "utils/texture_manager.h"
#include "utils/input_manager.h"
#include "utils/sound_manager.h"
#include "config/common.h"
// Глобальный SoundManager (чтобы передавать в сцены)
SoundManager* g_soundMgr = nullptr;

// Функция для получения глобального SoundManager (объявляем здесь)

int main(int argc, char* argv[]) {
    // === ИНИЦИАЛИЗАЦИЯ SDL ===
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL ошибка: " << SDL_GetError() << std::endl;
        return 1;
    }

    // === ИНИЦИАЛИЗАЦИЯ CONFIG ===
    if (!Config::init()) {
        std::cout << "Ошибка инициализации Config" << std::endl;
        SDL_Quit();
        return 1;
    }

    // === СОЗДАНИЕ ОКНА ===
    SDL_Window* window = SDL_CreateWindow(
        "Boss Fight",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        Config::getWindowWidth(),
        Config::getWindowHeight(),
        SDL_WINDOW_SHOWN
        );

    if (!window) {
        std::cout << "Ошибка создания окна: " << SDL_GetError() << std::endl;
        Config::cleanup();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Ошибка создания рендерера: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        Config::cleanup();
        SDL_Quit();
        return 1;
    }

    // === ИНИЦИАЛИЗАЦИЯ ЗВУКОВ ===
    g_soundMgr = new SoundManager();

    // 1. СНАЧАЛА ИНИЦИАЛИЗИРУЕМ (открываем аудио-устройство)
    if (!g_soundMgr->init()) {
        std::cerr << "WARNING: Sound system not initialized" << std::endl;
    }

    // 2. ПОТОМ ЗАГРУЖАЕМ ФАЙЛЫ
    g_soundMgr->loadSound("hover", "assets/sound/button.mp3");
    g_soundMgr->loadSound("click", "assets/sound/button.mp3");
    g_soundMgr->loadSound("slider", "assets/sound/button.mp3");
    g_soundMgr->loadSound("attack_golem", "assets/sound/attak_golem.mp3");
    g_soundMgr->loadSound("laser_attack", "assets/sound/lazer_attak.mp3");
    g_soundMgr->loadSound("melee_attack", "assets/sound/mellee_attak_player.mp3");
    g_soundMgr->loadSound("ranged_attack", "assets/sound/ranged_attack_player.mp3");
    g_soundMgr->loadSound("golem_move", "assets/sound/move_golem.mp3");

    // 3. НАСТРАИВАЕМ ГРОМКОСТЬ
    g_soundMgr->soundVolume = Config::getSoundVolume();
    g_soundMgr->musicVolume = Config::getMusicVolume();

    // === ИНИЦИАЛИЗАЦИЯ ТЕКСТУР ===
    TextureManager::init(renderer);

    // === МЕНЕДЖЕР СЦЕН ===
    SceneManager sceneManager(renderer);
    sceneManager.loadScene(SceneType::SPLASH);

    // === ИГРОВОЙ ЦИКЛ ===
    bool running = true;
    SDL_Event event;

    int mouseX = 0, mouseY = 0;
    bool mouseClicked = false;
    bool mouseDown = false;

    Uint32 lastTime = SDL_GetTicks();

    while (running && !sceneManager.shouldQuit()) {
        // 1. Расчёт deltaTime
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        // 2. Сбрасываем флаг клика
        mouseClicked = false;

        // === ОБРАБОТКА СОБЫТИЙ ===
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            // Координаты мыши
            if (event.type == SDL_MOUSEMOTION) {
                mouseX = event.motion.x;
                mouseY = event.motion.y;
            }

            // Клики мыши
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                mouseClicked = true;
                mouseDown = true;
            }

            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                mouseDown = false;
            }

            // Передаём событие текущей сцене
            sceneManager.handleInput(event, mouseX, mouseY, mouseClicked, mouseDown);
        }

        // 3. Обновляем InputManager ПОСЛЕ обработки событий
        InputManager::update();

        // 4. Обновление сцены
        sceneManager.update(deltaTime);

        // 5. Рендеринг
        SDL_RenderClear(renderer);
        sceneManager.render();
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    // === ОЧИСТКА РЕСУРСОВ ===
    TextureManager::cleanup();
    delete g_soundMgr;
    Config::cleanup();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
