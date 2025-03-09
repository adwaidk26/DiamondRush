#include <GameMap.h>

GameMap::GameMap()
{
    gameMap = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
}
void GameMap::drawMap()
{
    for(int i = 0; i < gameMap.size(); i++)
    {
        for(int j = 0; j < gameMap[i].size(); j++)
        {
            if(gameMap[i][j] == 1)
            {
                DrawRectangle(j*TILE_SIZE, i*TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
            }
        }
    }
}

void GameMap::update()
{

}
