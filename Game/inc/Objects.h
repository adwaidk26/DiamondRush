#pragma once
#include<Object.h>
#include<Utils.h>
#include<GameMap.h>

class boulder : public gameObject
{
public:
    boulder(int xPos, int yPos);
    ~boulder() override;
    void draw() override;
    void updateOnMap() override;
    void moveObject(int direction) override;

private:
    int xPrev;
    int yPrev;
};

