#include<Object.h>
#include<GameMap.h>
#include <sstream>

gameObject::gameObject(int x, int y, gameMap* map)
    : xPosition(x), yPosition(y), gameMapRef(map)
{
    isBreakable = false;
    isMovable = false;
    isCollectable = false;
    isSquare = false;
}

gameObject::~gameObject()
{

}
void gameObject::changePosition(int xPos, int yPos)
{   
    xPrev = xPosition;
    yPrev = yPosition;
    xPosition = xPos;
    yPosition = yPos;
}
void gameObject::draw()
{
}

void gameObject::updateOnMap()
{
    
}

bool gameObject::moveObject(moveDirection direction, int power)
{
    if(power <= 0)
    {
        LOG_INFO("Power is less than or equal to 0");
        return false;
    }
    if (!isMovable)
    {
        return false;
    }

    int dx = 0;
    int dy = 0;

    switch (direction)
    {
        case moveDirection::UP:    dx = -1; break;
        case moveDirection::DOWN:  dx = 1;  break;
        case moveDirection::LEFT:  dy = -1; break;
        case moveDirection::RIGHT: dy = 1;  break;
    }

    int targetX = xPosition + dx;
    int targetY = yPosition + dy;
    gameObject* targetObject = gameMapRef->getTile(targetX, targetY);

    if (targetObject != nullptr)
    {
        if (targetObject->moveObject(direction, power - 1))
        {
            LOG_INFO("Moving object Success");
            gameMapRef->moveTile(xPosition, yPosition, targetX, targetY);
            return true;
        }
        else
        {
            LOG_ERROR("Moving object Failed");
            return false;
        }
    }
    else
    {
        LOG_INFO("No Object along the direction: Moving object Success");
        gameMapRef->moveTile(xPosition, yPosition, targetX, targetY);
        return true;
    }

    return false;
}
