#include "RoundHud.h"
#include "raylib.h"

#include <cmath>

void DrawRoundHud(const Round& round)
{
    const int center = GetScreenWidth() / 2;
    const int barWidth = center - 95;
    for (int index = 0; index < 2; ++index)
    {
        const auto& fighter = round.GetFighter(index);
        const int barX = index == 0 ? 28 : GetScreenWidth() - 28 - barWidth;
        const int healthWidth = fighter.health * barWidth / Round::MaxHealth;
        const Color healthColor = fighter.health <= 25 ? RED : LIME;
        DrawText(TextFormat("P%d   %d HP", index + 1, fighter.health), barX, 22, 20, RAYWHITE);
        DrawRectangle(barX, 50, barWidth, 20, Color{9, 19, 36, 255});
        const int fillX = index == 0 ? barX : barX + barWidth - healthWidth;
        DrawRectangle(fillX, 50, healthWidth, 20, healthColor);
        DrawRectangleLines(barX, 50, barWidth, 20, RAYWHITE);
        DrawText(TextFormat("Score %d", fighter.score), barX, 81, 20, RAYWHITE);
        if (fighter.combo > 1)
            DrawText(TextFormat("%d-hit combo", fighter.combo), barX, 109, 20, GOLD);
    }

    const char* timer = TextFormat("%02d", static_cast<int>(std::ceil(round.TimeLeft())));
    DrawText(timer, center - MeasureText(timer, 40) / 2, 35, 40, round.TimeLeft() <= 10 ? ORANGE : RAYWHITE);
}
