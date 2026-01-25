#include "StateFactory.h"
#include "MainMenu.h"
#include "GameEngine.h"
#include "MapEditor.h"
#include "GameState.h"

std::unique_ptr<GameState> StateFactory::CreateState(GameStateIDs stateID) {
    switch (stateID) {
        case MENU:
            return std::make_unique<MainMenu>();
        case GAME:
            return std::make_unique<GameEngine>();
        //case MAP_EDITOR:
        //    return std::make_unique<MapEditor>();
        default:
            return nullptr;
    }
}
