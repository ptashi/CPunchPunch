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
    Texture2D p1_character_sheet;
    Texture2D p2_character_sheet;
    Player player1;
    Player player2;
    Stage stage;

    // test animations
    // Animation animations[ANIM_COUNT];
    // AnimState state = ANIM_IDLE;
};

inline void input_buffer_1(Player *self) {
    if (self->input_step_1 > 0) {
        self->input_timer_1 -= GetFrameTime();
        if (self->input_timer_1 <= 0) {
            self->input_step_1 = 0;
        }
    }
};

inline void input_buffer_2(Player *self) {
    if (self->input_step_2 > 0) {
        self->input_timer_2 -= GetFrameTime();
        if (self->input_timer_2 <= 0) {
            self->input_step_2 = 0;
        }
    }
};

#endif