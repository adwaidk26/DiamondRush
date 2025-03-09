cmake_minimum_required(VERSION 3.11)
project (Game)

include(FetchContent)

set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(raylib)

include_directories(${PROJECT_SOURCE_DIR}/Game/inc)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/Game/src/*.cpp)

add_executable(Game ${SOURCES})

target_link_libraries(Game PRIVATE raylib)
