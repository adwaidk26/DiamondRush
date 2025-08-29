#pragma once
#include "Utils.h"
#include "Menu.h"
#include "MainMenu.h" //for Main menu first

class StateManager
{
    public:
    static StateManager* getStateInstance();
    void SwitchState(GameStateIDs gameStateID);
    GameState* getCurrentState();
    GameStateIDs getCurrentStateID();
    void getCurrentStateHandler(GameState** currentStateHandlerPointer);
    void updateCurrentStateHandler();

    private:
        GameStateIDs currentGameStateID = MENU;
        GameState* currentGameState = new MainMenu();
        GameState** currentGameStateHandler;
        
};