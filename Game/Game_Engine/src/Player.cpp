#include <Player.h>
#include <GameMap.h>

playerObject::playerObject(int xPos, int yPos, gameMap* map) : gameObject(xPos, yPos, map)
{
    isBreakable = false;
    isMovable = true;
    isCollectable = false;
    isSquare = true;
    xPosition = xPos;
    yPosition = yPos;
    xPrev = xPosition;
    yPrev = yPosition;
    playerPower = 3;
    playerScore = 0;
    gravityApplicable = 0;
    this->gameMapRef->setTile(xPosition, yPosition, this);
}

playerObject::~playerObject()
{
}

void playerObject::draw()
{
    DrawRectangle(yPosition * TILE_SIZE, xPosition * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
}

bool playerObject::collectDiamond(moveDirection direction)
{
    int xOffset = moveOffsets[direction].first;
    int yOffset = moveOffsets[direction].second;
    int targetX = xPosition + xOffset;
    int targetY = yPosition + yOffset;
    gameObject* targetObj = gameMapRef->getTile(targetX, targetY);

    if (targetObj != nullptr)
    {
        if (targetObj->isItemCollectable())
        {
            playerScore += targetObj->getScore();
            delete targetObj;
            gameMapRef->setTile(targetX, targetY, nullptr); // Clear the slot so we can move into it
            gameMapRef->moveTile(xPosition, yPosition, targetX, targetY);
            LOG_INFO("Player collected diamond: %d", playerScore);
            return true;
        }
    }
    return false;
}


bool playerObject::handleInput(moveDirection direction)
{
    LOG_INFO("Player handleInput: %d", direction);
    if (direction == moveDirection::UP)
    {
        if (collectDiamond(moveDirection::UP))
        {
            return true;
        }
        return moveObject(moveDirection::UP, playerPower);
    }
    else if (direction == moveDirection::DOWN)
    {
        if (collectDiamond(moveDirection::DOWN))
        {
            return true;
        }
        return moveObject(moveDirection::DOWN, playerPower);
    }
    else if (direction == moveDirection::LEFT)
    {
        if (collectDiamond(moveDirection::LEFT))
        {
            return true;
        }
        return moveObject(moveDirection::LEFT, playerPower);
    }
    else if (direction == moveDirection::RIGHT)
    {
        if (collectDiamond(moveDirection::RIGHT))
        {
            return true;
        }
        return moveObject(moveDirection::RIGHT, playerPower);
    }
    return false;
}
