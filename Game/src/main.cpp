#include <raylib.h>
#include <GameMap.h>
#include <Utils.h>
#include <Game.h>

main()
{
    InitWindow(SCREEN_HEIGHT,SCREEN_WIDTH,"Diamond Rush");
    SetTargetFPS(60);
    Game diamondRush = Game();
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        diamondRush.draw();
        DrawText("Diamond Rush", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
}