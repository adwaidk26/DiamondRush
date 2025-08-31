#include <iostream>
#include <raylib.h>
#include <Utils.h>
#include <StateManager.h>


main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diamond Rush");
    SetTargetFPS(60);
    GameState* CurrentState = new MainMenu();
    StateManager* stateManager = StateManager::getStateInstance();
    StateManager::getStateInstance()->getCurrentStateHandler(&CurrentState);
    while(!WindowShouldClose())
    {
        CurrentState->HandleInput();
        CurrentState->Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        CurrentState->Draw();
        EndDrawing();
        stateManager->ProcessStateChange();
    }
    CloseWindow();
    return 0;
}