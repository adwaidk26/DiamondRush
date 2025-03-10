#include<Objects.h>

boulder::boulder(int xPos, int yPos)
{
    isBreakable = false;
    isMovable = true;
    isCollectable = false;
    isSquare = false;
    xPosition = xPos;
    yPosition = yPos;
    xPrev = xPosition;
    yPrev = yPosition;
}

boulder::~boulder()
{
}

void boulder::draw()
{
    DrawCircle(xPosition * TILE_SIZE, yPosition * TILE_SIZE, TILE_SIZE, GRAY);
}

void boulder::updateOnMap()
{
    gameMap& gameMapData = gameMap::getInstance();
    gameMapData.setTile(xPrev, yPrev, nullptr);
    gameMapData.setTile(xPosition, yPosition, this);
}

void boulder::moveObject(int direction)
{
    // Custom moveObject implementation for boulder
}
