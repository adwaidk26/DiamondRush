#include <iostream>
#include <raylib.h>
#include <Utils.h>
#include <StateManager.h>


int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diamond Rush");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL); // Disable default ESC behavior (closing the window)
    
    StateManager* stateManager = StateManager::getStateInstance();
    stateManager->RequestStateChange(MENU);

    while(!WindowShouldClose())
    {
        stateManager->ProcessStateChange();
        stateManager->HandleInput();
        stateManager->Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        stateManager->Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}