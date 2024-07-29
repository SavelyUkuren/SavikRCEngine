cmake_minimum_required(VERSION 3.28)
project(SavikRCEngine)

set(CMAKE_CXX_STANDARD 17)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)

set(SOURCE_DIR src)
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h")

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

add_executable(SavikRCEngine ${SOURCES}
        src/testGame/TestScene.cpp
        src/testGame/TestScene.h
        src/engine/math/point.h
        src/engine/math/vector.h
        src/engine/math/line.h
        src/engine/components/object.cpp
        src/engine/components/object.h
        src/engine/character.cpp
        src/engine/character.h
        src/engine/rc_render.cpp
        src/engine/rc_render.h
        src/engine/math/se_math.cpp
        src/engine/math/se_math.h
)

target_link_libraries(SavikRCEngine PRIVATE SDL3::SDL3)