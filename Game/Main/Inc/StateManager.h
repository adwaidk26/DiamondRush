#pragma once
#include "Utils.h"
#include "GameState.h"
#include <memory>

class StateManager
{
    public:
    ~StateManager();
    static StateManager* getStateInstance();
    
    void RequestStateChange(GameStateIDs newState);
    void ProcessStateChange();

    void HandleInput();
    void Update();
    void Draw();

    GameStateIDs getCurrentStateID();

    private:
        std::unique_ptr<GameState> currentState = nullptr;
        GameStateIDs currentGameStateID = STATE_NONE;
        GameStateIDs pendingStateID = STATE_NONE;
};