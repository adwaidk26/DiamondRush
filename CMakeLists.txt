cmake_minimum_required(VERSION 3.31.5)
project (Game)

include(FetchContent)

set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(raylib)

set(IMAGE_FOLDER "Game/Data/Images")

add_definitions(-DIMAGE_FOLDER="${IMAGE_FOLDER}")

include_directories(
	${PROJECT_SOURCE_DIR}/Game/Main/Inc
	${PROJECT_SOURCE_DIR}/Game/Game_Engine/inc
	${PROJECT_SOURCE_DIR}/Game/Map_Builder/Inc
	${PROJECT_SOURCE_DIR}/Game/Game_Menu/Inc
	${PROJECT_SOURCE_DIR}/Game/Utils/Inc
	)

file(GLOB SOURCES 
	${PROJECT_SOURCE_DIR}/Game/Main/Src/*.cpp
	${PROJECT_SOURCE_DIR}/Game/Game_Engine/src/*.cpp
	${PROJECT_SOURCE_DIR}/Game/Map_Builder/Src/*.cpp
	${PROJECT_SOURCE_DIR}/Game/Game_Menu/Src/*.cpp
	${PROJECT_SOURCE_DIR}/Game/Utils/Src/*.cpp
	)

add_executable(Game ${SOURCES})

target_link_libraries(Game PRIVATE raylib)
