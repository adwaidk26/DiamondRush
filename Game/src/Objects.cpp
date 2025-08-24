#include<Objects.h>
#include<GameMap.h>

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
    gravityApplicable = 1;
}

boulder::~boulder()
{
    gameMap& gameMapData = gameMap::getInstance();
    gameMapData.setTile(xPosition, yPosition, nullptr);
}

void boulder::draw()
{
    DrawCircle(yPosition * TILE_SIZE + CENTER_OFFSET, xPosition * TILE_SIZE + CENTER_OFFSET, RADIUS_SIZE, GRAY);
}

void boulder::updateOnMap()
{

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
    score = 10;
    xPosition = xPos;
    yPosition = yPos;
    xPrev = xPosition;
    yPrev = yPosition;
    gravityApplicable = 1;
}

diamond::~diamond()
{
    gameMap& gameMapData = gameMap::getInstance();
    gameMapData.setTile(xPosition, yPosition, nullptr);
}

void diamond::draw()
{
    DrawCircle(yPosition * TILE_SIZE + CENTER_OFFSET, xPosition * TILE_SIZE + CENTER_OFFSET, RADIUS_SIZE, PINK);
}

void diamond::updateOnMap()
{
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
    gravityApplicable = 0;
}

block::~block()
{
}

void block::draw()
{
    DrawRectangle(yPosition * TILE_SIZE, xPosition * TILE_SIZE, TILE_SIZE, TILE_SIZE, BROWN);
}


// ############################################################################################################
// gameObject Bush
// ############################################################################################################

bush::bush(int xPos, int yPos)
{
    isBreakable = true;
    isCollectable = true;
    isMovable = false;
    isSquare = true;
    xPosition = xPos;
    yPosition = yPos;
    gravityApplicable = 0;
}

bush::~bush()
{
}

void bush::draw()
{
    DrawRectangle(yPosition * TILE_SIZE, xPosition * TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
}
