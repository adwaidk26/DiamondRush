#include <Game.h>

Game::Game()
    : gameMapData(gameMap::getInstance()),
    player(3,3) // Initialize gameMapData using initializer list
{
    gravityTimer = 0.0f;
}

Game::~Game()
{
    // Destructor body (empty in this case)
}

void Game::draw()
{
    gameMapData.drawMap(); // Use the member variable gameMapData
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    if(keyPressed == KEY_UP)
    {
        player.handleInput(moveDirection::UP);
    }
    else if(keyPressed == KEY_DOWN)
    {
        player.handleInput(moveDirection::DOWN);
    }
    else if(keyPressed == KEY_LEFT)
    {
        player.handleInput(moveDirection::LEFT);
    }
    else if(keyPressed == KEY_RIGHT)
    {
        player.handleInput(moveDirection::RIGHT);
    }
}

void Game::updateGravity()
{
    gravityTimer += GetFrameTime();
    if(gravityTimer >= GRAVITY_INTERVAL)
    {
        TraceLog(LOG_INFO, "Applying gravity");
        applyGravity();
        gravityTimer = 0;
    }
}

void Game::applyGravity()
{
    
    for(int i = GRID_HEIGHT -2 ; i>=0; i--)
    {
        for(int j=0 ; j<GRID_WIDTH; j++)
        {
            if(gameMapData.getTile(i,j) != nullptr && gameMapData.getTile(i,j)->getIsGravityApplicable() && gameMapData.getTile(i+1,j) == nullptr)
            {
    
                gameMapData.getTile(i,j)->changePosition(i+1,j);
            }
        }
    }
}