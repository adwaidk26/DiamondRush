#pragma once
#include <vector>
#include <raylib.h>
#include <Utils.h>
#include <Object.h>


class gameMap {
public:
    static gameMap& getInstance() {
        static gameMap instance;
        return instance;
    }

    gameMap(gameMap const&) = delete;
    void operator=(gameMap const&) = delete;

    void drawMap();
    void update();
    void addRow();
    void addColumn();
    void setTile(int x, int y, gameObject* object);
    gameObject* getTile(int x, int y);

private:
    gameMap();
    std::vector<std::vector<gameObject*>> gameGrid;

};