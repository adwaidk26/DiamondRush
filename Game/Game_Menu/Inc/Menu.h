#pragma once
#include "raylib.h"
#include "AppState.h"

class GameMenu : public AppState
{
public:
    GameMenu();
    ~GameMenu();
    virtual void Draw() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
};