#pragma once
#include "Menu.h"

class MainMenu : public GameMenu
{
public:
    MainMenu();
    ~MainMenu();
    void Draw() override;
    void HandleInput() override;
    void Update() override;
};