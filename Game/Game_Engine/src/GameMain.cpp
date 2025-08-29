#include <raylib.h>
#include <GameMap.h>
#include "GameEngineUtils.h"
#include <Game.h>
#include <dbg.h>

// main()
// {
//     InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diamond Rush");
//     SetTargetFPS(60);
//     Game diamondRush;

//     while(!WindowShouldClose())
//     {
//         diamondRush.updateGravity();
//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//         diamondRush.draw();
//         DrawText("Diamond Rush", 10, 10, 20, DARKGRAY);
//         EndDrawing();
//         diamondRush.handleInput();
//     }
//     CloseWindow();
//     return 0;
// }