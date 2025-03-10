#pragma once
#include <raylib.h>

class gameObject
{
public:
    gameObject();
    virtual ~gameObject(); 
    virtual void draw(); 
    virtual void updateOnMap(); 
    virtual void moveObject(int direction);

protected:
    bool isBreakable;
    bool isMovable;
    bool isCollectable;
    bool isSquare;
    int xPosition;
    int yPosition; 
};



