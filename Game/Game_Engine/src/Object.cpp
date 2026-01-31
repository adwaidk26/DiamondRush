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
    gameMapRef->setTile(xPosition,yPosition, this);
    gameMapRef->setTile(xPrev,yPrev, nullptr); 
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
    if(isMovable)
    {
        //LOG_INFO("Direction: %d", direction); fix required
        switch (direction)
        {
            case moveDirection::UP:
                if(gameMapRef->getTile(xPosition - 1, yPosition) != nullptr)
                {
                    if(gameMapRef->getTile(xPosition - 1, yPosition)->moveObject(direction, power-1))
                    {
                        LOG_INFO("Moving object Success");
                        changePosition(xPosition - 1, yPosition);
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
                    changePosition(xPosition - 1, yPosition);
                    return true;
                }
                LOG_ERROR("Not Returned");
                break;
            case moveDirection::DOWN:
                if(gameMapRef->getTile(xPosition + 1, yPosition) != nullptr)
                {
                    if(gameMapRef->getTile(xPosition + 1, yPosition)->moveObject(direction, power-1))
                    {
                        LOG_INFO("Moving object Success");
                        changePosition(xPosition + 1, yPosition);
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
                    changePosition(xPosition + 1, yPosition);
                    return true;
                }
                LOG_ERROR("Not Returned");
                break;
            case moveDirection::LEFT:
                if(gameMapRef->getTile(xPosition, yPosition - 1) != nullptr)
                {
                    if(gameMapRef->getTile(xPosition, yPosition - 1)->moveObject(direction, power-1))
                    {
                        LOG_INFO("Moving object Success");
                        changePosition(xPosition, yPosition - 1);
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
                    changePosition(xPosition, yPosition - 1);
                    return true;
                }
                LOG_ERROR("Not Returned");
                break;
            case moveDirection::RIGHT:
                if(gameMapRef->getTile(xPosition, yPosition + 1) != nullptr)
                {
                    if(gameMapRef->getTile(xPosition, yPosition + 1)->moveObject(direction, power-1))
                    {
                        LOG_INFO("Moving object Success");
                        changePosition(xPosition, yPosition + 1);
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
                    changePosition(xPosition, yPosition + 1);
                    return true;
                }
                LOG_ERROR("Not Returned");
                break;
        }            
    }
    return false;
}
