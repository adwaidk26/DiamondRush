#pragma once
#include "Utils.h"
#include "Menu.h"
#include "MainMenu.h" //for Main menu first

class StateManager
{
    public:
    static StateManager* getStateInstance();
    void ProcessStateChange();
    GameStateIDs getCurrentStateID();
    void getCurrentStateHandler(GameState** currentStateHandlerPointer);
    void RequestStateChange(GameStateIDs newState);

    private:
        GameStateIDs currentGameStateID = MENU;
        GameState** currentGameStateHandler;
        GameStateIDs pendingStateID = STATE_NONE;
};