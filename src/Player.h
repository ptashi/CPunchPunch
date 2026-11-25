#ifndef PLAYER_H
#define PLAYER_H

#include "Animation.h"
#include "raylib.h"
#include <vector>

struct Player
{
    float width;
    float height;
    float velocity = 0;
    float posY = 300;
    float posX = 0;

    bool locked;
    bool grounded;
    bool crouching;
    int move_state;

    bool special2 = false;

    Animation animations[ANIM_COUNT];
    AnimState state = ANIM_IDLE;
    AnimState next = ANIM_IDLE;

    float jump_height = 0;
    float jump_velocity = 0;
    int jump_dir = 0;

    int input_step_1 = 0;
    int input_step_2 = 0;
    float input_timer_1 = 0;
    float input_timer_2 = 0;
    float timer = 0;
};

#endif