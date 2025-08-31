#include "StateManager.h"
#include "GameState.h"
#include "MapEditor.h"
#include "GameEngine.h"
#include <iostream>

StateManager* StateManager::getStateInstance() {
    static StateManager instance;
    return &instance;
}

void StateManager::ProcessStateChange()
{
    if(pendingStateID != STATE_NONE)
    {
        
        currentGameStateID = pendingStateID;
        delete *currentGameStateHandler;
        switch (currentGameStateID)
        {  
        case MENU:
            *currentGameStateHandler = new MainMenu();
            break;
        
        case GAME:
            *currentGameStateHandler = new GameEngine();
            break;

        // case MAP_EDITOR:
        //     *currentGameStateHandler = new MapEditor();
        //     break;
        // default:
        //     break;
        }
        pendingStateID = STATE_NONE;
    }
}


GameStateIDs StateManager::getCurrentStateID()
{
    return currentGameStateID;
}

void StateManager::getCurrentStateHandler(GameState** currentStateHandlerPointer)
{
    currentGameStateHandler = currentStateHandlerPointer;
}

void StateManager::RequestStateChange(GameStateIDs newState) 
{
    pendingStateID = newState;
}