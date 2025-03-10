#include <raylib.h>
#include <GameMap.h>
#include <Utils.h>

main()
{
    InitWindow(SCREEN_HEIGHT,SCREEN_WIDTH,"Diamond Rush");
    SetTargetFPS(60);
    gameMap& gameMapData = gameMap::getInstance();
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        gameMapData.drawMap();
        DrawText("Diamond Rush", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
}