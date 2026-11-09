// initiliaze the game play + window
#include "raylib.h"
#include "HomePage.h"

int main()
{
    InitWindow(1000, 600, "CPunchPunch");
    SetTargetFPS(60);

    HomePage homePage; // create our HomePage object
    homePage.Load();
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
            DrawText("Game Started!", 350, 250, 40, BLACK);
        }

        EndDrawing();
    }

    homePage.Unload();
    CloseWindow();
    return 0;
}
