#include<Object.h>
#include<GameMap.h>

gameObject::gameObject()
{
    isBreakable = false;
    isMovable = false;
    isCollectable = false;
    isSquare = false;
    xPosition = 0;
    yPosition = 0;
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
    gameMap::getInstance().setTile(xPosition,yPosition, this);
    gameMap::getInstance().setTile(xPrev,yPrev, nullptr); 
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
        TraceLog(LOG_ERROR, "Power is less than or equal to 0");
        return false;
    }
    if(isMovable)
    {
        TraceLog(LOG_INFO, "Movable: Moving object in direction: %d", direction);
        gameMap& gameMapData = gameMap::getInstance();
        switch (direction)
        {
            case moveDirection::UP:
                if(gameMapData.getTile(xPosition - 1, yPosition) != nullptr)
                {
                    if(gameMapData.getTile(xPosition - 1, yPosition)->moveObject(direction, power-1))
                    {
                        TraceLog(LOG_INFO, "Moving object Success");
                        changePosition(xPosition - 1, yPosition);
                        return true;
                    }
                    else
                    {
                        TraceLog(LOG_ERROR, "Moving object Failed");
                        return false;
                    }
                }
                else
                {
                    TraceLog(LOG_INFO, "No Object along the direction: Moving object Success");
                    changePosition(xPosition - 1, yPosition);
                    return true;
                }
                TraceLog(LOG_ERROR, "Not Returned");
                break;
            case moveDirection::DOWN:
                if(gameMapData.getTile(xPosition + 1, yPosition) != nullptr)
                {
                    if(gameMapData.getTile(xPosition + 1, yPosition)->moveObject(direction, power-1))
                    {
                        TraceLog(LOG_INFO, "Moving object Success");
                        changePosition(xPosition + 1, yPosition);
                        return true;
                    }
                    else
                    {
                        TraceLog(LOG_ERROR, "Moving object Failed");
                        return false;
                    }
                }
                else
                {
                    TraceLog(LOG_INFO, "No Object along the direction: Moving object Success");
                    changePosition(xPosition + 1, yPosition);
                    return true;
                }
                TraceLog(LOG_ERROR, "Not Returned");
                break;
            case moveDirection::LEFT:
                if(gameMapData.getTile(xPosition, yPosition - 1) != nullptr)
                {
                    if(gameMapData.getTile(xPosition, yPosition - 1)->moveObject(direction, power-1))
                    {
                        TraceLog(LOG_INFO, "Moving object Success");
                        changePosition(xPosition, yPosition - 1);
                        return true;
                    }
                    else
                    {
                        TraceLog(LOG_ERROR, "Moving object Failed");
                        return false;
                    }
                }
                else
                {
                    TraceLog(LOG_INFO, "No Object along the direction: Moving object Success");
                    changePosition(xPosition, yPosition - 1);
                    return true;
                }
                TraceLog(LOG_ERROR, "Not Returned");
                break;
            case moveDirection::RIGHT:
                if(gameMapData.getTile(xPosition, yPosition + 1) != nullptr)
                {
                    if(gameMapData.getTile(xPosition, yPosition + 1)->moveObject(direction, power-1))
                    {
                        TraceLog(LOG_INFO, "Moving object Success");
                        changePosition(xPosition, yPosition + 1);
                        return true;
                    }
                    else
                    {
                        TraceLog(LOG_ERROR, "Moving object Failed");
                        return false;
                    }
                }
                else
                {
                    TraceLog(LOG_INFO, "No Object along the direction: Moving object Success");
                    changePosition(xPosition, yPosition + 1);
                    return true;
                }
                TraceLog(LOG_ERROR, "Not Returned");
                break;
        }            
    }
    return false;
}



