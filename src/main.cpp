// initiliaze the game play + window
#include "raylib.h"
#include "HomePage.h"
#include "GameState.h"
#include "Gameplay.h"

int main()
{
    InitWindow(1280, 720, "CPunchPunch");
    SetTargetFPS(60);

    // Load background image as Texture2D
    Texture2D background = LoadTexture("assets/backgrounds/sun-background.png");
    // Create a rectangle with source image dimensions ()
    Rectangle source = {0, 0, 1920, 1280};
    // Create a rectangle with target window dimensions
    Rectangle target_dimensions = {0, 0, 1280, 720};

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
        // Draw Texture2D background and scale it from source dimensions to target dimensions
        // DrawTexturePro(background, source, target_dimensions, {0,0}, 0.0f, WHITE);
        ClearBackground(BLUE);

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
