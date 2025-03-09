#pragma once
#include <vector>
#include <raylib.h>
#include <Utils.h>


class GameMap {
public:
    static GameMap& getInstance() {
        static GameMap instance;
        return instance;
    }

    GameMap(GameMap const&) = delete;
    void operator=(GameMap const&) = delete;

    void drawMap();
    void update();
    void addRow();
    void addColumn();

private:
    GameMap();
    std::vector<std::vector<int>> gameMap;

};