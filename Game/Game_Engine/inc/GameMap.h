#pragma once
#include <vector>
#include <raylib.h>
#include "GameEngineUtils.h"
#include <Object.h>
#include <Objects.h>


class gameMap {
public:
    gameMap();

    void drawMap();
    void update();
    void addRow();
    void addColumn();
    void setTile(int x, int y, gameObject* object);
    gameObject* getTile(int x, int y);
    
private:
    std::vector<std::vector<gameObject*>> gameGrid;

};
