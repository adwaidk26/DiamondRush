#include <Player.h>

playerObject::playerObject(int xPos, int yPos)
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
    gameMap& gameMapData = gameMap::getInstance();
    gameMapData.setTile(xPosition, yPosition, this);
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
    gameMap& gameMapData = gameMap::getInstance();
    int xOffset = moveOffsets[direction].first;
    int yOffset = moveOffsets[direction].second;
    if (gameMapData.getTile(xPosition + xOffset, yPosition + yOffset) != nullptr)
    {
        if (gameMapData.getTile(xPosition + xOffset, yPosition + yOffset)->isItemCollectable())
        {
            playerScore += gameMapData.getTile(xPosition + xOffset, yPosition + yOffset)->getScore();
            delete gameMapData.getTile(xPosition + xOffset, yPosition + yOffset);
            gameMapData.setTile(xPosition + xOffset, yPosition + yOffset, this);
            gameMapData.setTile(xPosition, yPosition, nullptr);
            changePosition(xPosition + xOffset, yPosition + yOffset);
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
