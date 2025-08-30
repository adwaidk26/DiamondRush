#pragma once

enum GameStateIDs
{
    STATE_NONE = 0,
    MENU = 1,
    GAME = 2,
    MAP_EDITOR = 3
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