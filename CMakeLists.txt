cmake_minimum_required(VERSION 3.16)

project(BossFight LANGUAGES CXX)

# ───────────────────────────────────────────────
# Находим pkg-config и модули через него
# ───────────────────────────────────────────────
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2     REQUIRED sdl2)
pkg_check_modules(SDL2IMG  REQUIRED SDL2_image)
pkg_check_modules(SDL2TTF  REQUIRED SDL2_ttf)
pkg_check_modules(SDL2MIX  REQUIRED SDL2_mixer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# На Windows используем MinGW Makefiles
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

add_executable(BossFight
    main.cpp
    utils/animation.cpp
    utils/camera.cpp
    utils/collision_system.cpp
    utils/input_manager.cpp
    utils/save_manager.cpp
    utils/scene_manager.cpp
    utils/sound_manager.cpp
    utils/texture_manager.cpp
    backgrounds/forest_bg.cpp
    characters/archer_minion.cpp
    characters/boss.cpp
    characters/boss_archer.cpp
    characters/boss_deadnight.cpp
    characters/boss_golem.cpp
    characters/boss_samurai.cpp
    characters/character.cpp
    characters/ground_minion.cpp
    characters/player.cpp
    config/config.cpp
    levels/ilevel.cpp
    levels/level1_assets.cpp
    levels/level2.cpp
    levels/level3.cpp
    menu/credits_scene.cpp
    menu/game_scene.cpp
    menu/level_select_scene.cpp
    menu/main_menu_scene.cpp
    menu/saves_scene.cpp
    menu/settings_scene.cpp
    menu/splash_scene.cpp
    ui/ui.cpp
    toolchain-mingw64.cmake
    backgrounds/forest_bg.cpp backgrounds/forest_bg.h bin/assets/bomb/bomb.png bin/assets/bomb/Explosion_bomb.png bin/assets/boss1/arm.png bin/assets/boss1/Character.png bin/assets/boss1/Laser.png bin/assets/boss_3/attacking.png bin/assets/boss_3/death.png bin/assets/boss_3/idle.png bin/assets/boss_3/idle2.png bin/assets/boss_3/projectile.png bin/assets/boss_3/skill1.png bin/assets/boss_3/summon.png bin/assets/boss_3/summonAppear.png bin/assets/boss_3/summonDeath.png bin/assets/boss_3/summonIdle.png bin/assets/fonts/DejaVuSans-Bold.ttf bin/assets/fonts/DejaVuSans.ttf bin/assets/magic/01.png bin/assets/magic/02.png bin/assets/magic/03.png bin/assets/magic/04.png bin/assets/magic/05.png bin/assets/magic/06.png bin/assets/magic/07.png bin/assets/magic/08.png bin/assets/magic/09.png bin/assets/magic/10.png bin/assets/magic/11.png bin/assets/magic/12.png bin/assets/magic/13.png bin/assets/magic/14.png bin/assets/magic/15.png bin/assets/magic/16.png bin/assets/magic/17.png bin/assets/magic/18.png bin/assets/magic/19.png bin/assets/magic/20.png bin/assets/magic/21.png bin/assets/magic/22.png bin/assets/magic/23.png bin/assets/magic/24.png bin/assets/magic/25.png bin/assets/magic/26.png bin/assets/magic/27.png bin/assets/magic/28.png bin/assets/magic/29.png bin/assets/magic/30.png bin/assets/magic/31.png bin/assets/magic/32.png bin/assets/magic/33.png bin/assets/magic/34.png bin/assets/magic/35.png bin/assets/magic/36.png bin/assets/magic/37.png bin/assets/magic/38.png bin/assets/magic/39.png bin/assets/magic/40.png bin/assets/magic/41.png bin/assets/magic/42.png bin/assets/magic/43.png bin/assets/magic/44.png bin/assets/magic/45.png bin/assets/magic/46.png bin/assets/magic/47.png bin/assets/magic/48.png bin/assets/magic/49.png bin/assets/magic/50.png bin/assets/magic/51.png bin/assets/magic/52.png bin/assets/magic/53.png bin/assets/magic/54.png bin/assets/magic/55.png bin/assets/magic/56.png bin/assets/magic/57.png bin/assets/magic/58.png bin/assets/magic/59.png bin/assets/magic/60.png bin/assets/magic/61.png bin/assets/magic/62.png bin/assets/magic/63.png bin/assets/magic/64.png bin/assets/magic/65.png bin/assets/magic/66.png bin/assets/map1/map1.png bin/assets/player/ATTACK_1.png bin/assets/player/ATTACK_2.png bin/assets/player/ATTACK_3.png bin/assets/player/DEATH.png bin/assets/player/DEFEND.png bin/assets/player/HURT.png bin/assets/player/IDLE.png bin/assets/player/JUMP.png bin/assets/player/RUN.png bin/assets/player/WALK.png bin/assets/Samurai/Attack_1.png bin/assets/Samurai/Attack_2.png bin/assets/Samurai/Attack_3.png bin/assets/Samurai/Dead.png bin/assets/Samurai/Hurt.png bin/assets/Samurai/Idle.png bin/assets/Samurai/Jump.png bin/assets/Samurai/Protection.png bin/assets/Samurai/Run.png bin/assets/Samurai/Walk.png bin/assets/Samurai_Archer/Arrow.png bin/assets/Samurai_Archer/Attack_1.png bin/assets/Samurai_Archer/Attack_2.png bin/assets/Samurai_Archer/Attack_3.png bin/assets/Samurai_Archer/Dead.png bin/assets/Samurai_Archer/Hurt.png bin/assets/Samurai_Archer/Idle.png bin/assets/Samurai_Archer/Jump.png bin/assets/Samurai_Archer/Run.png bin/assets/Samurai_Archer/Shot.png bin/assets/Samurai_Archer/Walk.png bin/assets/sound/attak_golem.mp3 bin/assets/sound/button.mp3 bin/assets/sound/gomage_to_golem.mp3 bin/assets/sound/lazer-attak.mp3 bin/assets/sound/lazer_attak.mp3 bin/assets/sound/mellee_attak_player.mp3 bin/assets/sound/move_golem.mp3 bin/assets/sound/ranged_attack_player.mp3 bin/BossFight bin/BossFight.exe bin/libsharpyuv.dll bin/libssp-0.dll bin/libwebp.dll bin/libwebpdemux.dll bin/libwinpthread-1.dll bin/SDL2.dll bin/SDL2_image.dll bin/SDL2_mixer.dll bin/SDL2_ttf.dll characters/archer_minion.cpp characters/archer_minion.h characters/boss.cpp characters/boss.h characters/boss_archer.cpp characters/boss_archer.h characters/boss_deadnight.cpp characters/boss_deadnight.h characters/boss_golem.cpp characters/boss_golem.h characters/boss_samurai.cpp characters/boss_samurai.h characters/character.cpp characters/character.h characters/ground_minion.cpp characters/ground_minion.h characters/player.cpp characters/player.h config/common.h config/config.cpp config/config.h levels/ilevel.cpp levels/ilevel.h levels/level1.h levels/level1_assets.cpp levels/level1_assets.h levels/level2.cpp levels/level2.h levels/level3.cpp levels/level3.h menu/credits_scene.cpp menu/credits_scene.h menu/game_scene.cpp menu/game_scene.h menu/level_select_scene.cpp menu/level_select_scene.h menu/main_menu_scene.cpp menu/main_menu_scene.h menu/saves_scene.cpp menu/saves_scene.h menu/settings_scene.cpp menu/settings_scene.h menu/splash_scene.cpp menu/splash_scene.h ui/ui.cpp ui/ui.h utils/animation.cpp utils/animation.h utils/camera.cpp utils/camera.h utils/collision_system.cpp utils/collision_system.h utils/input_manager.cpp utils/input_manager.h utils/save_manager.cpp utils/save_manager.h utils/scene_manager.cpp utils/scene_manager.h utils/sound_manager.cpp utils/sound_manager.h utils/texture_manager.cpp utils/texture_manager.h
)

# ───────────────────────────────────────────────
# Include-директории
# ───────────────────────────────────────────────
target_include_directories(BossFight PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMG_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    ${SDL2MIX_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# ───────────────────────────────────────────────
# Линкуем ВСЕ библиотеки (самое важное!)
# ───────────────────────────────────────────────
target_link_libraries(BossFight PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2IMG_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    ${SDL2MIX_LIBRARIES}
)

# На Linux часто нужно pthread
find_package(Threads REQUIRED)
target_link_libraries(BossFight PRIVATE Threads::Threads)

# Уменьшаем число нужных DLL на Windows — статически линкуем рантайм компилятора
if (MINGW)
    target_link_options(BossFight PRIVATE -static-libgcc -static-libstdc++)
endif()

# ───────────────────────────────────────────────
# Копируем assets/ в папку с exe после сборки
# ───────────────────────────────────────────────
add_custom_command(TARGET BossFight POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:BossFight>/assets
)

include(GNUInstallDirs)
install(TARGETS BossFight
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
# Выходной путь для экзешника
set_target_properties(BossFight PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Копируем ассеты туда же
add_custom_command(TARGET BossFight POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_SOURCE_DIR}/bin/assets
)

# ───────────────────────────────────────────────
# Windows: копируем DLL зависимостей
# ───────────────────────────────────────────────
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Копируем все DLL в папку с exe
    file(GLOB SDL2_DLLS "*.dll")
    foreach(dll IN LISTS SDL2_DLLS)
        add_custom_command(TARGET BossFight POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_SOURCE_DIR}/${dll}"
            "$<TARGET_FILE_DIR:BossFight>/${dll}"
        )
    endforeach()
endif()