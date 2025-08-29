#include <iostream>
#include <raylib.h>
#include <Utils.h>
#include <StateManager.h>


main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diamond Rush");
    SetTargetFPS(60);
    GameState* CurrentState = new MainMenu();
    StateManager::getStateInstance()->getCurrentStateHandler(&CurrentState);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        CurrentState->HandleInput();
        CurrentState->Update();
        CurrentState->Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}