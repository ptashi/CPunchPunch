#include "Gameplay.h"
#include "Animation.h"
#include "raylib.h"
#include "Aleks.h"

void Gameplay::Load()
{
    aleks_sprite(&p1_character_sheet);
    aleks_init_animations(&player1);
}

void Gameplay::Unload()
{
    UnloadTexture(p1_character_sheet);
}

void Gameplay::Update()
{   
    aleks_animate(&player1);
}

void Gameplay::Draw()
{
    Rectangle source = animation_frame(&player1.animations[player1.state], 4, p1_character_sheet);
    Rectangle dimensions = {150+player1.posX, player1.posY - player1.jump_height, source.width*2, source.height*2};
    DrawTexturePro(p1_character_sheet, source, dimensions, {0, 0}, 0.0f, WHITE);
}
