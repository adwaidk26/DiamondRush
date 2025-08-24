#pragma once
#include<raylib.h>
#include <GameMap.h>
#include <Player.h>
#include <Utils.h>


class Game
{
public:
    Game();
    ~Game();
    void update();
    void draw();
    void handleInput();
    void updateGravity();
    void applyGravity();

private:
    gameMap& gameMapData;
    playerObject player;
    float gravityTimer = 0.0f;
};


