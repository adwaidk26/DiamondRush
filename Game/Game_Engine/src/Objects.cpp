#include<Objects.h>
#include<GameMap.h>

// ############################################################################################################
// gameObject boulder
// ############################################################################################################
boulder::boulder(int xPos, int yPos, gameMap* map) : gameObject(xPos, yPos, map)
{
    isBreakable = false;
    isMovable = true;
    isCollectable = false;
    isSquare = false;
    xPrev = xPosition;
    yPrev = yPosition;
    gravityApplicable = 1;
}

boulder::~boulder()
{
    gameMapRef->setTile(xPosition, yPosition, nullptr);
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

diamond::diamond(int xPos, int yPos, gameMap* map) : gameObject(xPos, yPos, map)
{
    isBreakable = false;
    isMovable = false;
    isCollectable = true;
    isSquare = false;
    score = 10;
    xPrev = xPosition;
    yPrev = yPosition;
    gravityApplicable = 1;
}

diamond::~diamond()
{
    gameMapRef->setTile(xPosition, yPosition, nullptr);
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

block::block(int xPos, int yPos, gameMap* map) : gameObject(xPos, yPos, map)
{
    isBreakable = false;
    isCollectable = false;
    isMovable = false;
    isSquare = true;
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

bush::bush(int xPos, int yPos, gameMap* map) : gameObject(xPos, yPos, map)
{
    isBreakable = true;
    isCollectable = true;
    isMovable = false;
    isSquare = true;
    gravityApplicable = 0;
}

bush::~bush()
{
}

void bush::draw()
{
    DrawRectangle(yPosition * TILE_SIZE, xPosition * TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
}
