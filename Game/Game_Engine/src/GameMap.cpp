#include <GameMap.h>

gameMap::gameMap()
{
    gameGrid = std::vector<std::vector<gameObject*>>(10, std::vector<gameObject*>(10, nullptr));

    // Visual representation of the map (10x10)
    // # = Block, O = Boulder, D = Diamond, B = Bush, . = Empty
    const char* mapLayout[10] = {
        "##########",
        "#OO......#",
        "#.......D#",
        "#.......D#",
        "#O.......#",
        "#O.......#",
        "#O.......#",
        "# B......#",
        "#........#",
        "##########"
    };

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            char tileType = mapLayout[row][col];
            switch (tileType) {
                case '#':
                    gameGrid[row][col] = new block(row, col, this);
                    break;
                case 'O':
                    gameGrid[row][col] = new boulder(row, col, this);
                    break;
                case 'D':
                    gameGrid[row][col] = new diamond(row, col, this);
                    break;
                case 'B':
                    gameGrid[row][col] = new bush(row, col, this);
                    break;
                default:
                    gameGrid[row][col] = nullptr;
                    break;
            }
        }
    }
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
    //TraceLog(LOG_INFO, "setTile: x: %d, y: %d", x, y);
    gameGrid[x][y] = object;
}

gameObject* gameMap::getTile(int x, int y)
{
    //TraceLog(LOG_INFO, "getTile: x: %d, y: %d", x, y);
    return gameGrid[x][y];
}

void gameMap::moveTile(int fromX, int fromY, int toX, int toY)
{
    gameObject* obj = getTile(fromX, fromY);
    if(obj)
    {
        setTile(toX, toY, obj);
        setTile(fromX, fromY, nullptr);
        obj->changePosition(toX, toY);
    }
}