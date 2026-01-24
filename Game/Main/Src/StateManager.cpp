#include "StateManager.h"
#include "MapEditor.h"
#include "GameEngine.h"
#include "MainMenu.h"
#include <iostream>

StateManager* StateManager::getStateInstance() {
    static StateManager instance;
    return &instance;
}

StateManager::~StateManager() {
    delete currentState;
}

void StateManager::ProcessStateChange()
{
    if(pendingStateID != STATE_NONE)
    {
        delete currentState; // Delete the old state, if any.
        
        switch (pendingStateID)
        {  
        case MENU:
            currentState = new MainMenu();
            break;
        
        case GAME:
            currentState = new GameEngine();
            break;

        // case MAP_EDITOR:
        //     *currentGameStateHandler = new MapEditor();
        //     break;
        default:
            currentState = nullptr;
            break;
        }
        currentGameStateID = pendingStateID;
        pendingStateID = STATE_NONE;
    }
}

void StateManager::HandleInput() {
    if (currentState) {
        currentState->HandleInput();
    }
}

void StateManager::Update() {
    if (currentState) {
        currentState->Update();
    }
}

void StateManager::Draw() {
    if (currentState) {
        currentState->Draw();
    }
}

GameStateIDs StateManager::getCurrentStateID()
{
    return currentGameStateID;
}

void StateManager::RequestStateChange(GameStateIDs newState) 
{
    pendingStateID = newState;
}