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

add_executable(BossFight main.cpp
    assets/boss1/arm.png
    assets/boss1/Character.png
    assets/boss1/Laser.png
    assets/map1/map1.png
    assets/player/player.png
    assets/sound/attak_golem.mp3
    assets/sound/button.mp3
    assets/sound/gomage_to_golem.mp3
    assets/sound/lazer-attak.mp3
    assets/sound/lazer_attak.mp3
    assets/sound/mellee_attak_player.mp3
    assets/sound/move_golem.mp3
    assets/sound/ranged_attack_player.mp3
    backgrounds/forest_bg.cpp
    backgrounds/forest_bg.h
    characters/boss_golem.cpp
    characters/boss_golem.h
    characters/player.cpp
    characters/player.h
    config/common.h
    config/config.cpp
    config/config.h
    levels/level1_assets.cpp
    levels/level1_assets.h
    menu/credits_scene.cpp
    menu/credits_scene.h
    menu/game_scene.cpp
    menu/game_scene.h
    menu/level_select_scene.cpp
    menu/level_select_scene.h
    menu/main_menu_scene.cpp
    menu/main_menu_scene.h
    menu/settings_scene.cpp
    menu/settings_scene.h
    menu/splash_scene.cpp
    menu/splash_scene.h ui/ui.cpp
    ui/ui.h utils/animation.h
    utils/input_manager.cpp
    utils/input_manager.h
    utils/scene_manager.cpp
    utils/scene_manager.h
    utils/sound_manager.cpp
    utils/sound_manager.h
    utils/texture_manager.cpp
    utils/texture_manager.h
    utils/collision_system.h
    utils/collision_system.cpp
    characters/character.h
    characters/character.cpp
    assets/player/ATTACK_1.png
    assets/player/ATTACK_2.png
    assets/player/ATTACK_3.png
    assets/player/DEATH.png
    assets/player/DEFEND.png
    assets/player/HURT.png
    assets/player/IDLE.png
    assets/player/JUMP.png
    assets/player/RUN.png
    assets/player/WALK.png
    assets/magic/01.png
    utils/animation.cpp
    levels/ilevel.h
    levels/ilevel.cpp
    levels/level1.h
    utils/camera.h
    utils/camera.cpp
    levels/level2.h
    levels/level2.cpp

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