#include <GameMap.h>

gameMap::gameMap()
{
    gameGrid = std::vector<std::vector<gameObject*>>(10, std::vector<gameObject*>(10, nullptr));
    gameGrid[0][0] = new block(0,0);
    gameGrid[0][1] = new block(0,1);
    gameGrid[0][2] = new block(0,2);
    gameGrid[0][3] = new block(0,3);
    gameGrid[0][4] = new block(0,4);
    gameGrid[0][5] = new block(0,5);
    gameGrid[0][6] = new block(0,6);
    gameGrid[0][7] = new block(0,7);
    gameGrid[0][8] = new block(0,8);
    gameGrid[0][9] = new block(0,9);
    gameGrid[1][0] = new block(1,0);
    gameGrid[2][0] = new block(2,0);
    gameGrid[3][0] = new block(3,0);
    gameGrid[4][0] = new block(4,0);
    gameGrid[5][0] = new block(5,0);
    gameGrid[6][0] = new block(6,0);
    gameGrid[7][0] = new block(7,0);
    gameGrid[8][0] = new block(8,0);
    gameGrid[9][0] = new block(9,0);
    gameGrid[9][1] = new block(9,1);
    gameGrid[9][2] = new block(9,2);
    gameGrid[9][3] = new block(9,3);
    gameGrid[9][4] = new block(9,4);
    gameGrid[9][5] = new block(9,5);
    gameGrid[9][6] = new block(9,6);
    gameGrid[9][7] = new block(9,7);
    gameGrid[9][8] = new block(9,8);
    gameGrid[9][9] = new block(9,9);
    gameGrid[8][9] = new block(8,9);
    gameGrid[7][9] = new block(7,9);
    gameGrid[6][9] = new block(6,9);
    gameGrid[5][9] = new block(5,9);
    gameGrid[4][9] = new block(4,9);
    gameGrid[3][9] = new block(3,9);
    gameGrid[2][9] = new block(2,9);
    gameGrid[1][9] = new block(1,9);
    gameGrid[1][1] = new boulder(1,1);
    gameGrid[1][8] = new diamond(1,8);
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

void gameMap::addColumn()
{
    for(int i = 0; i<gameGrid.size(); i++)
    {
        gameGrid[i].push_back(nullptr);
    }
}

void gameMap::addRow()
{
    std::vector<gameObject*> row(gameGrid[0].size(), nullptr);
    gameGrid.push_back(row);
}

void gameMap::update()
{
    
}

void gameMap::setTile(int x, int y, gameObject *object)
{
    gameGrid[y][x] = object;
}
