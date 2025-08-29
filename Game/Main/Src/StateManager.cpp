#include "StateManager.h"
#include "GameState.h"
#include "MapEditor.h"
#include "GameEngine.h"

StateManager* StateManager::getStateInstance() {
    static StateManager instance;
    return &instance;
}

void StateManager::SwitchState(GameStateIDs gameStateID)
{
    currentGameStateID = gameStateID;
    delete currentGameState;
    switch (currentGameStateID)
    {
        
    case MENU:
        currentGameState = new MainMenu();
        updateCurrentStateHandler();
        break;
    
    case GAME:
        currentGameState = new GameEngine();
        updateCurrentStateHandler();
        break;

    // case MAP_EDITOR:
    //     currentGameState = new MapEditor();
    //     break;
    // default:
    //     break;
    }
}

GameState* StateManager::getCurrentState()
{
    return currentGameState;
}

GameStateIDs StateManager::getCurrentStateID()
{
    return currentGameStateID;
}

void StateManager::getCurrentStateHandler(GameState** currentStateHandlerPointer)
{
    currentGameStateHandler = currentStateHandlerPointer;
}

void StateManager::updateCurrentStateHandler()
{
    *currentGameStateHandler = currentGameState;
}