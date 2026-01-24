#pragma once
#include <raylib.h>
#include "GameEngineUtils.h"
#include "Logger.h"

class gameObject
{
public:
    gameObject();
    virtual ~gameObject(); 
    virtual void draw(); 
    void updateOnMap(); 
    void changePosition(int xPos, int yPos);
    virtual bool moveObject(moveDirection direction, int power = 1);
    bool isItemCollectable() const { return isCollectable; }
    int getScore() const { return score; }
    int getIsMovable() const { return isMovable; }
    int getIsGravityApplicable() const { return gravityApplicable; }

protected:
    bool isBreakable;
    bool isMovable;
    bool isCollectable;
    bool isSquare;
    int score;
    int xPosition;
    int yPosition;
    int xPrev;
    int yPrev;
    int gravityApplicable;
};



