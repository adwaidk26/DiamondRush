#pragma once

#include "AppState.h"
#include <memory>

class StateFactory {
public:
    static std::unique_ptr<AppState> CreateState(AppStateIDs stateID);
};
