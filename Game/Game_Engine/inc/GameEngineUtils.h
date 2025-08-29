#pragma once
#include <utility>

constexpr int GRID_WIDTH = 10;
constexpr int GRID_HEIGHT = 10;

constexpr int CENTER_OFFSET = 50;

constexpr int TILE_SIZE = 100;
constexpr int RADIUS_SIZE = 50;
constexpr float GRAVITY_INTERVAL = 0.5f;


enum moveDirection
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum gameState
{
    START,
    PLAYING,
    PAUSED,
    GAMEOVER
};

enum gameObjectType
{
    PLAYER,
    BOULDER,
    DIAMOND,
    BLOCK,
    BUSH,
    EXIT
};

constexpr std::pair<int, int> moveOffsets[] = {
    { -1, 0 }, // UP
    { 1, 0 },  // DOWN
    { 0, -1 }, // LEFT
    { 0, 1 }   // RIGHT
};