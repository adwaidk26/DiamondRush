#include <raylib.h>
#include <Utils.h>
#include <StateManager.h>
#include "Logger.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_FULLSCREEN_MODE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Diamond Rush");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL); // Disable default ESC behavior (closing the window)
    
    StateManager* stateManager = StateManager::getStateInstance();
    stateManager->RequestStateChange(MENU);

    while(!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
        {
            LOG_INFO("Toggling fullscreen");
            ToggleFullscreen();
        }

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