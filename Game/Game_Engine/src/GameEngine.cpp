#include "GameEngine.h"
#include <iostream>
#include "StateManager.h"

GameEngine::GameEngine()
    : gameMapData(std::make_unique<gameMap>()),
    player(3,3, gameMapData.get()) // Initialize gameMapData using initializer list
{
    gravityTimer = 0.0f;
}

GameEngine::~GameEngine()
{
    // Destructor body (empty in this case)
}

void GameEngine::Draw()
{
    gameMapData->drawMap(); // Use the member variable gameMapData
}

void GameEngine::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(keyPressed == KEY_UP)
    {
        LOG_INFO("KEY_UP");
        player.handleInput(moveDirection::UP);
    }
    else if(keyPressed == KEY_DOWN)
    {
        LOG_INFO("KEY_DOWN");
        player.handleInput(moveDirection::DOWN);
    }
    else if(keyPressed == KEY_LEFT)
    {
        LOG_INFO("KEY_LEFT");
        player.handleInput(moveDirection::LEFT);
    }
    else if(keyPressed == KEY_RIGHT)
    {
        LOG_INFO("KEY_RIGHT");
        player.handleInput(moveDirection::RIGHT);
    }
    else if(keyPressed == KEY_ESCAPE)
    {
        LOG_INFO("KEY_ESCAPE");
        StateManager::getStateInstance()->RequestStateChange(MENU);
    }
}

void GameEngine::Update()
{
    gravityTimer += GetFrameTime();
    if(gravityTimer >= GRAVITY_INTERVAL)
    {
        LOG_INFO("Applying Gravity");
        applyGravity();
        gravityTimer = 0;
    }
}

void GameEngine::applyGravity()
{
    for(int i = GRID_HEIGHT -2 ; i>=0; i--)
    {
        for(int j=0 ; j<GRID_WIDTH; j++)
        {
            if(gameMapData->getTile(i,j) != nullptr && gameMapData->getTile(i,j)->getIsGravityApplicable() && gameMapData->getTile(i+1,j) == nullptr)
            {
    
                gameMapData->getTile(i,j)->changePosition(i+1,j);
            }
        }
    }
}