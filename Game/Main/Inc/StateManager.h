#pragma once
#include "Utils.h"
#include "AppState.h"
#include <memory>

class StateManager
{
    public:
    ~StateManager();
    static StateManager* getStateInstance();
    
    void RequestStateChange(AppStateIDs newState);
    void ProcessStateChange();

    void HandleInput();
    void Update();
    void Draw();

    AppStateIDs getCurrentStateID();

    private:
        std::unique_ptr<AppState> currentState = nullptr;
        AppStateIDs currentAppStateID = STATE_NONE;
        AppStateIDs pendingStateID = STATE_NONE;
};