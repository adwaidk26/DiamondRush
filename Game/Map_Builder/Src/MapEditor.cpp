#include "MapEditor.h"
#include "GameEngineUtils.h"
#include "Utils.h"
#include "StateManager.h"

MapEditor::MapEditor()
{
    mapWidth = SCREEN_WIDTH / TILE_SIZE;
    mapHeight = SCREEN_HEIGHT / TILE_SIZE;

    mapLayout.resize(mapHeight, std::vector<TileData>(mapWidth));
}

MapEditor::~MapEditor()
{
}

void MapEditor::Draw()
{
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            DrawTile(i, j, mapLayout[i][j].id);
        }
    }
}

void MapEditor::DrawTile(int row, int col, int id)
{
    int posX = col * TILE_SIZE;
    int posY = row * TILE_SIZE;

    // Draw a light grid to help with placement
    DrawRectangleLines(posX, posY, TILE_SIZE, TILE_SIZE, Fade(LIGHTGRAY, 0.5f));

    switch (id)
    {
    case BOULDER:
        DrawCircle(posX + CENTER_OFFSET, posY + CENTER_OFFSET, RADIUS_SIZE, GRAY);
        break;
    case DIAMOND:
        DrawCircle(posX + CENTER_OFFSET, posY + CENTER_OFFSET, RADIUS_SIZE, PINK);
        break;
    case PLAYER:
        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, BLUE);
        break;
    case BLOCK:
        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, BROWN);
        break;
    case BUSH:
        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, GREEN);
        break;
    case EXIT:
        DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, DARKGREEN);
        break;
    default:
        break;
    }
}

void MapEditor::HandleInput()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 mousePos = GetMousePosition();
        int col = (int)(mousePos.x / TILE_SIZE);
        int row = (int)(mousePos.y / TILE_SIZE);

        // Boundary check
        if (row >= 0 && row < mapHeight && col >= 0 && col < mapWidth)
        {
            // Currently hardcoded to place BOULDERs for testing
            mapLayout[row][col].id = BOULDER;
        }
    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        StateManager::getStateInstance()->RequestStateChange(MENU);
    }
}

void MapEditor::Update()
{
    // Update logic 
}