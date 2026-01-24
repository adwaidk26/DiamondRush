#include <iostream>
#include <raylib.h>
#include <Utils.h>
#include <StateManager.h>


int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diamond Rush");
    SetTargetFPS(60);
    
    StateManager* stateManager = StateManager::getStateInstance();
    stateManager->RequestStateChange(MENU);

    while(!WindowShouldClose())
    {
        // First, process any pending state change.
        // This ensures the new state is active before we operate on it.
        stateManager->ProcessStateChange();

        // Delegate all frame logic to the state manager
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