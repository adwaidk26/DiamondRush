#pragma once
#include<Object.h>
#include "GameEngineUtils.h"
#include<GameMap.h>

class playerObject : public gameObject
{
public:
    playerObject(int xPos, int yPos);
    ~playerObject() override;
    void draw() override;
    void updateOnMap();
    bool handleInput(moveDirection direction);
    bool collectDiamond(moveDirection direction);

private:
    int playerPower;
    int playerScore;
};