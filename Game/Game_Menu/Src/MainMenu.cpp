#include "MainMenu.h"
#include "StateManager.h"
#include <iostream>
#include "Logger.h"

MainMenu::MainMenu()
{}

MainMenu::~MainMenu()
{}

void MainMenu::Draw()
{
    ClearBackground(BLACK);
    DrawText("Welcome to Boulder Dash!", 100, 100, 24, WHITE);
    DrawText("Press SPACE to start", 100, 200, 24, WHITE);
}

void MainMenu::HandleInput()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        LOG_INFO("Key Space Pressed");
        StateManager::getStateInstance()->RequestStateChange(GAME);
    }
    else if(IsKeyPressed(KEY_E))
    {
        LOG_INFO("Key E Pressed");
        StateManager::getStateInstance()->RequestStateChange(MAP_EDITOR);
    }
}

void MainMenu::Update()
{
    
}