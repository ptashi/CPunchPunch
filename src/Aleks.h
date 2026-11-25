#ifndef ALEKS_H
#define ALEKS_H

#include "Animation.h"
#include "Player.h"
#include "raylib.h"
#include <vector>

inline void aleks_sprite(Texture2D *sheet) {
    Image sprite_sheet = LoadImage("assets/sprites/aleks.png"); // load sprite sheet as 'sprite'
    *sheet = LoadTextureFromImage(sprite_sheet); // load sprite sheet as texture
    UnloadImage(sprite_sheet);
};

inline void aleks_init_animations(Player *self) {
    self->animations[ANIM_IDLE] = {
        .first = 0,
        .last = 2,
        .curr = 0,
        .dir = 1,
        .idling = true,
        .speed = 0.13,
        .duration_left = 0.1
    };

    self->animations[ANIM_WALK_BACK] = {
        .first = 8,
        .last = 11,
        .curr = 8,
        .dir = 1,
        .looping = true,
        .speed = 0.12,
        .duration_left = 0.1
    };

    self->animations[ANIM_WALK_FORWARD] = {
        .first = 4,
        .last = 7,
        .curr = 4,
        .dir = 1,
        .looping = true,
        .speed = 0.12,
        .duration_left = 0.1
    };

    self->animations[ANIM_LIGHT_PUNCH] = {
        .first = 12,
        .last = 14,
        .curr = 12,
        .dir = 1,
        .finished = false,
        .speed = 0.085,
        .duration_left = 0.1
    };
    
    self->animations[ANIM_HEAVY_PUNCH] = {
        .first = 16,
        .last = 19,
        .curr = 16,
        .dir = 1,
        .finished = false,
        .speed = 0.107,
        .duration_left = 0.1
    };

    self->animations[ANIM_LIGHT_KICK] = {
        .first = 20,
        .last = 22,
        .curr = 20,
        .dir = 1,
        .finished = false,
        .speed = 0.106,
        .duration_left = 0.1
    };

    self->animations[ANIM_HEAVY_KICK] = {
        .first = 24,
        .last = 27,
        .curr = 24,
        .dir = 1,
        .finished = false,
        .speed = 0.109,
        .duration_left = 0.1
    };

    self->animations[ANIM_CROUCH] = {
        .first = 29,
        .last = 29,
        .curr = 29,
        .dir = 1,
        .stall_last = true,
        .speed = 0.04,
        .duration_left = 0.1
    };

    self->animations[ANIM_CROUCH_LP] = {
        .first = 32,
        .last = 34,
        .curr = 32,
        .dir = 1,
        .finished = false,
        .speed = 0.085,
        .duration_left = 0.1
    };

    self->animations[ANIM_CROUCH_HP] = {
        .first = 36,
        .last = 38,
        .curr = 36,
        .dir = 1,
        .finished = false,
        .speed = .107,
        .duration_left = 0.1
    };

    self->animations[ANIM_CROUCH_LK] = {
        .first = 40,
        .last = 42,
        .curr = 40,
        .dir = 1,
        .finished = false,
        .speed = 0.1,
        .duration_left = 0.1
    };

    self->animations[ANIM_CROUCH_HK] = {
        .first = 44,
        .last = 47,
        .curr = 40,
        .dir = 1,
        .finished = false,
        .speed = 0.107,
        .duration_left = 0.1
    };

    self->animations[ANIM_JUMP] = {
        .first = 52,
        .last = 55,
        .curr = 52,
        .dir = 1,
        .finished = false,
        .speed = 0.05,
        .duration_left = 0.1
    };

    self->animations[ANIM_JUMP_LK] = {
        .first = 56,
        .last = 58,
        .curr = 56,
        .dir = 1,
        .finished = false,
        .speed = 0.1,
        .duration_left = 0.1
    };

    self->animations[ANIM_JUMP_HK] = {
        .first = 60,
        .last = 63,
        .curr = 60,
        .dir = 1,
        .finished = false,
        .speed = 0.095,
        .duration_left = 0.1
    };

    self->animations[ANIM_SPECIAL_1] = {
        .first = 64,
        .last = 68,
        .curr = 64,
        .dir = 1,
        .finished = false,
        .speed = 0.105,
        .duration_left = 0.1
    };

    self->animations[ANIM_SPECIAL_2] = {
        .first = 72,
        .last = 79,
        .curr = 72,
        .dir = 1,
        .finished = false,
        .speed = 0.075,
        .duration_left = 0.1
    };
}

inline void aleks_animate(Player *self) {
    // If enum value of state is greather than or equal to light punch and animation is not finished, locked is set to true and player is not actionable
    // until action and animation finish.
    self->locked = self->state >= ANIM_LIGHT_PUNCH && !self->animations[self->state].finished;
    // No input = 0, right arrow key = 1, left arrow key = -1
    self->move_state = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
    // Self explanatory
    self->grounded = self->jump_height <= 0;
    self->crouching = IsKeyDown(KEY_DOWN) && self->grounded;

    input_buffer_1(self);
    input_buffer_2(self);

    // Command check for Special 1
    if (self->input_step_1 == 0) {
        if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT)) {
            self->input_step_1 = 1;
            self->input_timer_1 = 0.4f;
        }
    } else if (self->input_step_1 == 1) {
        if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))  {
            self->input_step_1 = 2;
            self->input_timer_1 = 0.4f;
        }
    } else if (self->input_step_1 == 2) {
        if (!IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
            self->input_step_1 = 3;
            self->input_timer_1 = 0.4f;
        }
    }
    // Command check for Special 2
    if (self->input_step_2 == 0) {
        if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_DOWN)) {
            self->input_step_2 = 1;
            self->input_timer_2 = 0.4f;
        }
    } else if (self->input_step_2 == 1) {
        if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN))  {
            self->input_step_2 = 2;
            self->input_timer_2 = 0.4f;
        }
    } else if (self->input_step_2 == 2) {
        if (!IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN)) {
            self->input_step_2 = 3;
            self->input_timer_2 = 0.4f;
        }
    }

    if (!self->locked) {
        // jump and jump attacks   
        if (!self->grounded) {
            self->next = ANIM_JUMP;
            if (IsKeyPressed(KEY_X)) {
                self->next = ANIM_JUMP_LK;
            } else if (self->input_step_2 == 3 && IsKeyPressed(KEY_C)) {
                // self->animations[ANIM_SPECIAL_2].curr = self->animations[ANIM_SPECIAL_2].first + 3;
                // self->animations[ANIM_SPECIAL_2].duration_left = self->animations[ANIM_SPECIAL_2].speed;
                self->next = ANIM_SPECIAL_2;
                self->input_step_2 = 0;
            } else if (IsKeyPressed(KEY_C)) {
                self->next = ANIM_JUMP_HK;
            }
        } else if (IsKeyPressed(KEY_UP)) {
            self->next = ANIM_JUMP;
        } 
        // special 1
        else if (self->input_step_1 == 3 && IsKeyPressed(KEY_C)) {
            self->next = ANIM_SPECIAL_1;
            self->input_step_1 = 0;
        } else if (self->input_step_2 == 3 && IsKeyPressed(KEY_C)) {
            self->next = ANIM_SPECIAL_2;
            self->input_step_2 = 0;
        }
        // crouch and crouch attacks
        else if (self->crouching) {
            self->next = ANIM_CROUCH;
            if (IsKeyPressed(KEY_S)) {
                self->next = ANIM_CROUCH_LP;
            } else if (IsKeyPressed(KEY_D)) {
                self->next = ANIM_CROUCH_HP;
            } else if (IsKeyPressed(KEY_X)) {
                self->next = ANIM_CROUCH_LK;
            } else if (IsKeyPressed(KEY_C)) {
                self->next = ANIM_CROUCH_HK;
            }
        } 
        // standing attacks
        else {
            self->next = ANIM_IDLE;
            if (IsKeyPressed(KEY_S)) {
                self->next = ANIM_LIGHT_PUNCH;
            } else if (IsKeyPressed(KEY_D)) {
                self->next = ANIM_HEAVY_PUNCH;
            } else if (IsKeyPressed(KEY_X)) {
                self->next = ANIM_LIGHT_KICK;
            } else if (IsKeyPressed(KEY_C)) {
                self->next = ANIM_HEAVY_KICK;
            } else {
                if (self->move_state == 1) { // movement
                    self->next = ANIM_WALK_FORWARD;
                    if (self->posX <= 974) {
                        self->posX += 5.5;
                    }
                } else if (self->move_state == -1) {
                    self->next = ANIM_WALK_BACK;
                    if (self->posX >= -204) {
                        self->posX -= 5.5;
                    }
                }
            }
        }
        // reset animations to first frame
        if (self->next != self->state || self->next >= ANIM_LIGHT_PUNCH) {
            self->state = self->next;
            animation_reset(&self->animations[self->state]);

            if (self->state == ANIM_JUMP) { // init jump physics
                if (self->grounded) {
                    self->jump_velocity = 1250.0f;
                    self->jump_dir = self->move_state;
                } else {
                    self->animations[ANIM_JUMP].curr = self->animations[ANIM_JUMP].last; // hold last frame of jump animation while in air
                }
            }
            if (self->state == ANIM_SPECIAL_2 && !self->grounded) {
                self->animations[ANIM_SPECIAL_2].curr = self->animations[ANIM_SPECIAL_2].first + 4;
                self->animations[ANIM_SPECIAL_2].duration_left = self->animations[ANIM_SPECIAL_2].speed;
            }
        }
    }

    if (self->state == ANIM_SPECIAL_2) {
        self->jump_velocity = 350.0f;
        self->velocity = 350.0f;
        self->special2 = true;
    }

    if (self->special2 && !self->animations[ANIM_SPECIAL_2].finished) {
        float dt = GetFrameTime();
        int frame = self->animations[ANIM_SPECIAL_2].curr - self->animations[ANIM_SPECIAL_2].first;

        if (frame <= 4) {
            self->jump_velocity += 2500.0f * dt;
            self->jump_height += self->jump_velocity * dt;
            self->posX += self->velocity * dt;
        } else {
            if (self->jump_velocity > 0) self->jump_velocity = -1500.0f;
            self->jump_velocity -= 3200.0f * dt;
            self->jump_height += self->jump_velocity * dt;
        }

        if (self->jump_height <= 0 && frame > 5) {
            self->special2 = false;
            self->velocity = 0;
            self->jump_height = 0;
            self->jump_velocity = 0;
        }
    }
    // handle jump physics
    else if (self->jump_height > 0 || self->jump_velocity > 0) {
        float dt = GetFrameTime();

        self->jump_velocity -= 3200.0f * dt;
        self->jump_height += self->jump_velocity * dt;

        // directional jump
        float nextX = self->posX + self->jump_dir * 6.5f;
        if (nextX >= -204 && nextX <= 974) {
            self->posX = nextX;
        }

        // land and cancel any attack animations
        if (self->jump_height <= 0) {
            self->jump_height = 0;
            self->jump_velocity = 0;
            self->animations[ANIM_JUMP].finished = true;
            self->animations[ANIM_JUMP_HK].finished = true;
            self->animations[ANIM_JUMP_LK].finished = true;
            self->animations[ANIM_JUMP_LP].finished = true;
            self->animations[ANIM_JUMP_HP].finished = true;
        }
    }
    animation_update(&self->animations[self->state]);
}

#endif