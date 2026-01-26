#include "StateFactory.h"
#include "MainMenu.h"
#include "GameEngine.h"
#include "MapEditor.h"
#include "AppState.h"

std::unique_ptr<AppState> StateFactory::CreateState(AppStateIDs stateID) {
    LOG_INFO("Creating State");
    switch (stateID) {
        case MENU:
            return std::make_unique<MainMenu>();
        case GAME:
            return std::make_unique<GameEngine>();
        case MAP_EDITOR:
            return std::make_unique<MapEditor>();
        default:
            return nullptr;
    }
}
