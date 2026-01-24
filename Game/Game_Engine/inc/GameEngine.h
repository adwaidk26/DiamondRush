#pragma once 
#include "GameState.h"
#include <GameMap.h>
#include <Player.h>
#include "GameEngineUtils.h"
#include "Logger.h"

class GameEngine:public GameState
{
public:
    GameEngine();
    ~GameEngine();
    void Draw() override;
    void HandleInput() override;
    void Update() override;
    void updateGravity();
    void applyGravity();

private:
    gameMap& gameMapData;
    playerObject player;
    float gravityTimer = 0.0f;
};