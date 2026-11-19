#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Animation.h"
#include "Player.h"
#include "raylib.h"
#include <vector>

struct Stage
{
    int posX = 0;
    int posY = 600;
    int width = 1500;
    int height = 100;
};

class Gameplay
{
public:
    void Load();
    void Unload();
    void Update();
    void Draw();

private:
    Texture2D character_sheet;
    Player player1;
    Player player2;
    Stage stage;

    // test animations
    // Animation animations[ANIM_COUNT];
    // AnimState state = ANIM_IDLE;
};

#endif