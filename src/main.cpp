// initiliaze the game play + window
#include "raylib.h"
#include "HomePage.h"
#include "GameState.h"
#include "Gameplay.h"

int main()
{
    InitWindow(1000, 600, "CPunchPunch");
    SetTargetFPS(60);

    HomePage homePage; // create our HomePage object
    Gameplay game; // create Gameplay object
    homePage.Load();
    game.Load();
    bool gameStarted = false; // false means we on homescreen, true means we started game

    while (!WindowShouldClose())
    {
        if (!gameStarted && homePage.StartClicked())
        {
            gameStarted = true;
        }

        BeginDrawing();            // telling Raylib we are going to draw a new frame
        ClearBackground(DARKBLUE); // this clears the window, removing any drawings

        if (!gameStarted)
        {
            homePage.Draw();
        }
        else
        {
            game.Update();
            game.Draw();
        }

        EndDrawing();
    }

    homePage.Unload();
    game.Unload();
    CloseWindow();
    return 0;
}
