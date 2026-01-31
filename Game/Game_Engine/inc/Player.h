#pragma once
#include<Object.h>
#include "GameEngineUtils.h"

class playerObject : public gameObject
{
public:
    playerObject(int xPos, int yPos, gameMap* map);
    ~playerObject() override;
    void draw() override;
    void updateOnMap();
    bool handleInput(moveDirection direction);
    bool collectDiamond(moveDirection direction);

private:
    int playerPower;
    int playerScore;
};