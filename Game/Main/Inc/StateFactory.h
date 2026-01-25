#pragma once

#include "GameState.h"
#include <memory>

class StateFactory {
public:
    static std::unique_ptr<GameState> CreateState(GameStateIDs stateID);
};
