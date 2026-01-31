#pragma once 
#include "AppState.h"
#include <memory>
#include <GameMap.h>
#include <Player.h>
#include "GameEngineUtils.h"
#include "Logger.h"

class GameEngine:public AppState
{
public:
    GameEngine();
    ~GameEngine();
    void Draw() override;
    void HandleInput() override;
    void Update() override;

private:
    void applyGravity();
    std::unique_ptr<gameMap> gameMapData;
    playerObject player;
    float gravityTimer = 0.0f;
};