cmake_minimum_required(VERSION 3.28)
project(SavikRCEngine)

set(CMAKE_CXX_STANDARD 17)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)

set(SOURCE_DIR src)
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h")

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

add_executable(SavikRCEngine ${SOURCES})

target_link_libraries(SavikRCEngine PRIVATE SDL3::SDL3)