#include "HomePage.h"
#include "raymath.h"

void HomePage::Load()
{
    titleFont = LoadFontEx("assets/fonts/retroFont/PressStart2P-Regular.ttf", 80, 0, 0);
}
void HomePage::Unload()
{
    UnloadFont(titleFont);
}

void HomePage::Draw()
{
    // DrawText(text, posX, posY, fontSize, color)
    DrawText("Team10 Presents", (GetScreenWidth() - MeasureText("Team10 Presents", 25)) / 2, (GetScreenHeight() / 6), 25, WHITE);

    // DRAWING THE TITLE
    const char *title = "CPunchPunch";
    float fontSize = 85;
    float spacing = 2;

    Vector2 textSize = MeasureTextEx(titleFont, title, fontSize, spacing);

    Vector2 position = {(GetScreenWidth() - textSize.x) / 2, (GetScreenHeight() - textSize.y) / 2};

    // Black shadow behind the title
    DrawTextEx(titleFont, title, {position.x + 5, position.y + 5}, fontSize, spacing, BLACK);

    // Yellow arcade title
    DrawTextEx(titleFont, title, position, fontSize, spacing, ORANGE);

    startButton.x = (GetScreenWidth() - startButton.width) / 2;
    startButton.y = GetScreenHeight() * 2 / 3;

    bool isHovered = CheckCollisionPointRec(GetMousePosition(), startButton);

    if (isHovered)
    {
        hoverDuration += GetFrameTime() * 5.0f;
    }
    else
    {
        hoverDuration -= GetFrameTime() * 5.0f;
    }

    hoverDuration = Clamp(hoverDuration, 0.0f, 1.0f);

    // Transition from white to gold
    Color textColor = ColorLerp(WHITE, RED, hoverDuration);

    // Draw only the text, no rectangle
    DrawText("START GAME", (GetScreenWidth() - MeasureText("START GAME", 30)) / 2, startButton.y + (startButton.height - 20) / 2, 30, textColor);
}

bool HomePage::StartClicked()
{
    // CheckCollisionPointRec check if ur mouse pos is inside the bounds of startButton and left mouse button was pressed
    bool startCheck = CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    return startCheck;
}
