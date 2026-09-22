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

# ───────────────────────────────────────────────
# Исходники — только .cpp/.h, по одному файлу на строку.
# Ассеты (PNG/WAV/MP3) сюда НЕ добавляются — их копирует
# copy_directory ниже, а не этот список.
# ───────────────────────────────────────────────
add_executable(BossFight
    main.cpp

    # --- utils ---
    utils/animation.cpp
    utils/animation.h
    utils/camera.cpp
    utils/camera.h
    utils/collision_system.cpp
    utils/collision_system.h
    utils/input_manager.cpp
    utils/input_manager.h
    utils/save_manager.cpp
    utils/save_manager.h
    utils/scene_manager.cpp
    utils/scene_manager.h
    utils/sound_manager.cpp
    utils/sound_manager.h
    utils/texture_manager.cpp
    utils/texture_manager.h

    # --- backgrounds ---
    backgrounds/forest_bg.cpp
    backgrounds/forest_bg.h

    # --- characters ---
    characters/archer_minion.cpp
    characters/archer_minion.h
    characters/boss.cpp
    characters/boss.h
    characters/boss_archer.cpp
    characters/boss_archer.h
    characters/boss_deadnight.cpp
    characters/boss_deadnight.h
    characters/boss_golem.cpp
    characters/boss_golem.h
    characters/boss_samurai.cpp
    characters/boss_samurai.h
    characters/character.cpp
    characters/character.h
    characters/ground_minion.cpp
    characters/ground_minion.h
    characters/player.cpp
    characters/player.h

    # --- config ---
    config/common.h
    config/config.cpp
    config/config.h

    # --- levels ---
    levels/ilevel.cpp
    levels/ilevel.h
    levels/level1.h
    levels/level1_assets.cpp
    levels/level1_assets.h
    levels/level2.cpp
    levels/level2.h
    levels/level3.cpp
    levels/level3.h

    # --- menu ---
    menu/credits_scene.cpp
    menu/credits_scene.h
    menu/game_scene.cpp
    menu/game_scene.h
    menu/level_select_scene.cpp
    menu/level_select_scene.h
    menu/main_menu_scene.cpp
    menu/main_menu_scene.h
    menu/saves_scene.cpp
    menu/saves_scene.h
    menu/settings_scene.cpp
    menu/settings_scene.h
    menu/splash_scene.cpp
    menu/splash_scene.h

    # --- ui ---
    ui/ui.cpp
    ui/ui.h

    # --- прочее ---
    toolchain-mingw64.cmake
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

# На Linux часто нужен pthread
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
    file(GLOB SDL2_DLLS "*.dll")
    foreach(dll IN LISTS SDL2_DLLS)
        add_custom_command(TARGET BossFight POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_SOURCE_DIR}/${dll}"
            "$<TARGET_FILE_DIR:BossFight>/${dll}"
        )
    endforeach()
endif()