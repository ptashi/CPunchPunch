
#include "raylib.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "CPunchPunch");
    SetTargetFPS(60);

    float playerX = 400;
    float playerY = 300;
    float speed = 300;

    while (!WindowShouldClose())
    {

        float dt = GetFrameTime();

        // Movement
        if (IsKeyDown(KEY_RIGHT))
            playerX += speed * dt;
        if (IsKeyDown(KEY_LEFT))
            playerX -= speed * dt;
        if (IsKeyDown(KEY_UP))
            playerY -= speed * dt;
        if (IsKeyDown(KEY_DOWN))
            playerY += speed * dt;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("CPunchPunch", 20, 20, 30, BLACK);
        DrawText("Use arrow keys to move!", 20, 60, 20, DARKGRAY);

        // Temporary player
        DrawRectangle((int)playerX, (int)playerY, 50, 70, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
