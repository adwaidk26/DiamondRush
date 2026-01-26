#pragma once
#include <vector>
#include <raylib.h>
#include "AppState.h"
#include "Object.h"

struct TileData {
    int id = -1; // Defaults to -1 (Empty), matches gameObjectType enum
    bool isBreakable = false;
    bool isMovable = false;
    bool isCollectable = false;
    int points = 0;
    int gravityApplicable = 0;
};

class MapEditor: public AppState
{
public:
    MapEditor();
    ~MapEditor();
    void Draw() override;
    void HandleInput() override;
    void Update() override;
private:
    int mapWidth;
    int mapHeight;
    std::vector<std::vector<TileData>> mapLayout;
    void DrawTile(int row, int col, int id);
};