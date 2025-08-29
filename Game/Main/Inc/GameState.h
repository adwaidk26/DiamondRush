#pragma once

enum GameStateIDs
{
    MENU = 0,
    GAME = 1,
    MAP_EDITOR = 2
};

class GameState
{
    public:
    GameState() {};
    virtual ~GameState() {};
    virtual void Draw() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    
    private:
};