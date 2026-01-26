#include "StateManager.h"
#include "StateFactory.h"
#include <iostream>

StateManager* StateManager::getStateInstance() {
    static StateManager instance;
    return &instance;
}

StateManager::~StateManager() {
    // No need to delete currentState, std::unique_ptr handles it.
}

void StateManager::ProcessStateChange()
{
    if(pendingStateID != STATE_NONE)
    {
        currentState = StateFactory::CreateState(pendingStateID);
        currentAppStateID = pendingStateID;
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

AppStateIDs StateManager::getCurrentStateID()
{
    return currentAppStateID;
}

void StateManager::RequestStateChange(AppStateIDs newState) 
{
    pendingStateID = newState;
}