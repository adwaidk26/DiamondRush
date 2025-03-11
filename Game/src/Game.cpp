#include <Game.h>

Game::Game()
{
    gameMap& gameMapData = gameMap::getInstance();
}

Game::~Game()
{
}

void Game::draw()
{
    gameMap& gameMapData = gameMap::getInstance();
    gameMapData.drawMap();
}