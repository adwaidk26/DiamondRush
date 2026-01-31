#pragma once
#include<Object.h>
#include "GameEngineUtils.h"

class boulder : public gameObject
{
public:
    boulder(int xPos, int yPos, gameMap* map);
    ~boulder() override;
    void draw() override;
    void updateOnMap();

private:
    int xPrev;
    int yPrev;
};

class diamond : public gameObject
{
public:
    diamond(int xPos, int yPos, gameMap* map);
    ~diamond() override;
    void draw() override;
    void updateOnMap();

};

class block : public gameObject
{
public:
    block(int xPos, int yPos, gameMap* map);
    ~block() override;
    void draw() override;
};

class bush : public gameObject
{
public:
    bush(int xPos, int yPos, gameMap* map);
    ~bush() override;
    void draw() override;
};
