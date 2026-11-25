#ifndef ANIMATION_H
#define ANIMATION_H

#include "raylib.h"
#include <vector>

struct Animation
{
    int first; // first frame of animation
    int last; // last frame of animation
    int curr; // current frame
    int dir; // forward looping or backwards looping

    bool looping = false;
    bool idling = false;
    bool finished = true;
    bool stall_last = false;

    float speed;
    float duration_left;
};

enum AnimState
{
    ANIM_IDLE,
    ANIM_CROUCH,
    ANIM_JUMP,
    ANIM_WALK_BACK,
    ANIM_WALK_FORWARD,
    ANIM_LIGHT_PUNCH,
    ANIM_HEAVY_PUNCH,
    ANIM_LIGHT_KICK,
    ANIM_HEAVY_KICK,
    ANIM_CROUCH_LP,
    ANIM_CROUCH_HP,
    ANIM_CROUCH_LK,
    ANIM_CROUCH_HK,
    ANIM_JUMP_LP,
    ANIM_JUMP_HP,
    ANIM_JUMP_LK,
    ANIM_JUMP_HK,
    ANIM_SPECIAL_1,
    ANIM_SPECIAL_2,
    ANIM_COUNT
};

// When we include Animation.h in Gameplay.h for the Animation struct, a double declaration of these functions occurs
// inline makes it so the compiler ignores these duplicates.
inline void animation_update(Animation *self) {
    float dt = GetFrameTime();
    self->duration_left -= dt;

        if (self->duration_left <= 0) {
            self->duration_left = self->speed;
            self->curr += self->dir;

            if (self->curr > self->last) {
                //repeating
                if (self->idling == true) {
                    self->curr = self->last - 1;
                    self->dir = -1;
                }
                else if (self->looping == true) {
                    self->curr = self->first;
                }
                else if (self->stall_last == true) {
                    self->curr = self->last;
                }
                else {
                    self->curr = self->last;
                    self->finished = true;
                }
            }
        }

        if (self->curr < self->first) {
            self->curr = self->first + 1;
            self->dir = 1;
        }
};

inline Rectangle animation_frame(Animation *self, int num_frames_per_row, Texture2D image) {
    int x = (self->curr % num_frames_per_row) * (image.width/4);
    int y = (self->curr / num_frames_per_row) * (image.height/20);

    return (Rectangle) {
        .x = (float)x,
        .y = (float)y,
        .width = (float)image.width/4,
        .height = (float)image.height/20
    };
};
// resets an animation to first frame after it is finished or if it gets canceled by another animation
inline void animation_reset(Animation *self) {
    self->curr = self->first;
    self->dir = 1;
    self->duration_left = self->speed;
    self->finished = false;
};

#endif