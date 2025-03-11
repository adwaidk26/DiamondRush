#include<Objects.h>

// ############################################################################################################
// gameObject boulder
// ############################################################################################################
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
    DrawCircle(xPosition * TILE_SIZE + CENTER_OFFSET, yPosition * TILE_SIZE +CENTER_OFFSET, RADIUS_SIZE, GRAY);
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


// ############################################################################################################
// gameObject Diamond
// ############################################################################################################

diamond::diamond(int xPos, int yPos)
{
    isBreakable = false;
    isMovable = false;
    isCollectable = true;
    isSquare = false;
    xPosition = xPos;
    yPosition = yPos;
}

diamond::~diamond()
{
}

void diamond::draw()
{
    DrawCircle(xPosition * TILE_SIZE + CENTER_OFFSET, yPosition * TILE_SIZE + CENTER_OFFSET, RADIUS_SIZE, PINK);
}

void diamond::updateOnMap()
{
    gameMap& gameMapData = gameMap::getInstance();
    gameMapData.setTile(xPosition, yPosition, this);
}


// ############################################################################################################
// gameObject Block
// ############################################################################################################

block::block(int xPos, int yPos)
{
    isBreakable = false;
    isCollectable = false;
    isMovable = false;
    isSquare = true;
    xPosition = xPos;
    yPosition = yPos;
}

block::~block()
{
}

void block::draw()
{
    DrawRectangle(xPosition * TILE_SIZE, yPosition * TILE_SIZE, TILE_SIZE, TILE_SIZE, BROWN);
}

