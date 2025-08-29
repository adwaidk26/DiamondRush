#pragma once
#include "raylib.h"
#include "GameState.h"

class GameMenu : public GameState
{
public:
    GameMenu();
    ~GameMenu();
    virtual void Draw() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
};