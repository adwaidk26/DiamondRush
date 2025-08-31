#include "MainMenu.h"
#include "StateManager.h"
#include <iostream>

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
    std::cout<<"Handle Input"<<std::endl;
    if (IsKeyPressed(KEY_SPACE))
    {
        std::cout<<"Space Pressed"<<std::endl;
        StateManager::getStateInstance()->RequestStateChange(GAME);
    }
}

void MainMenu::Update()
{
    
}