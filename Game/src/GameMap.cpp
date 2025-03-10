#include <GameMap.h>

gameMap::gameMap()
{

}
void gameMap::drawMap()
{
    for(int i = 0; i < gameGrid.size(); i++)
    {
        for(int j = 0; j < gameGrid[i].size(); j++)
        {
            if(gameGrid[i][j] != nullptr)
            {
                gameGrid[i][j]->draw();
            }
        }
    }
}

void gameMap::update()
{
    
}

void gameMap::setTile(int x, int y, gameObject *object)
{
    gameGrid[y][x] = object;
}
