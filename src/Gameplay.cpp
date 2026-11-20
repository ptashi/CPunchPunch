#include "Gameplay.h"
//#include "Characters.h"
#include "Animation.h"
#include "raylib.h"

void Gameplay::Load()
{
    Image sprite_sheet = LoadImage("assets/sprites/aleks.png"); // load sprite sheet as 'sprite'
    ImageColorReplace(&sprite_sheet, WHITE, BLANK); // remove magenta background from sprite sheet
    character_sheet = LoadTextureFromImage(sprite_sheet); // load sprite sheet as texture
    UnloadImage(sprite_sheet);

    player1.animations[ANIM_IDLE] = {
        .first = 0,
        .last = 2,
        .curr = 0,
        .dir = 1,
        .idling = true,
        .speed = 0.13,
        .duration_left = 0.1
    };

    player1.animations[ANIM_WALK_BACK] = {
        .first = 8,
        .last = 11,
        .curr = 8,
        .dir = 1,
        .looping = true,
        .speed = 0.12,
        .duration_left = 0.1
    };

    player1.animations[ANIM_WALK_FORWARD] = {
        .first = 4,
        .last = 7,
        .curr = 4,
        .dir = 1,
        .looping = true,
        .speed = 0.12,
        .duration_left = 0.1
    };

    player1.animations[ANIM_LIGHT_PUNCH] = {
        .first = 12,
        .last = 14,
        .curr = 12,
        .dir = 1,
        .finished = false,
        .speed = 0.06,
        .duration_left = 0.1
    };
    
    player1.animations[ANIM_HEAVY_PUNCH] = {
        .first = 16,
        .last = 19,
        .curr = 16,
        .dir = 1,
        .finished = false,
        .speed = 0.082,
        .duration_left = 0.1
    };

    player1.animations[ANIM_LIGHT_KICK] = {
        .first = 20,
        .last = 22,
        .curr = 20,
        .dir = 1,
        .finished = false,
        .speed = 0.081,
        .duration_left = 0.1
    };

    player1.animations[ANIM_HEAVY_KICK] = {
        .first = 24,
        .last = 27,
        .curr = 24,
        .dir = 1,
        .finished = false,
        .speed = 0.084,
        .duration_left = 0.1
    };

    player1.animations[ANIM_CROUCH] = {
        .first = 29,
        .last = 29,
        .curr = 29,
        .dir = 1,
        .crouching = true,
        .speed = 0.04,
        .duration_left = 0.1
    };

    player1.animations[ANIM_CROUCH_LP] = {
        .first = 32,
        .last = 34,
        .curr = 32,
        .dir = 1,
        .finished = false,
        .speed = 0.06,
        .duration_left = 0.1
    };

    player1.animations[ANIM_CROUCH_HP] = {
        .first = 36,
        .last = 38,
        .curr = 36,
        .dir = 1,
        .finished = false,
        .speed = .08,
        .duration_left = 0.1
    };

}

void Gameplay::Unload()
{
    UnloadTexture(character_sheet);
}

void Gameplay::Update()
{   
    // If enum value of state is greather than or equal to light punch and animation is not finished, locked is set to true and player is not actionable
    // until action and animation finish.
    bool p1_locked = player1.state >= ANIM_LIGHT_PUNCH && !player1.animations[player1.state].finished;
    bool is_crouching = IsKeyDown(KEY_DOWN);
    int move_state = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);

    if (!p1_locked) {
        if (is_crouching) {
            player1.next = ANIM_CROUCH;
        } else {
            player1.next = ANIM_IDLE;
        }
        
        if (!is_crouching) {
            if (IsKeyPressed(KEY_S)) {
                player1.next = ANIM_LIGHT_PUNCH;
            } else if (IsKeyPressed(KEY_D)) {
                player1.next = ANIM_HEAVY_PUNCH;
            } else if (IsKeyPressed(KEY_X)) {
                player1.next = ANIM_LIGHT_KICK;
            } else if (IsKeyPressed(KEY_C)) {
                player1.next = ANIM_HEAVY_KICK;
            } else {
                if (move_state == 1) {
                    player1.next = ANIM_WALK_FORWARD;
                    if (player1.posX <= 974) {
                        player1.posX += 5.5;
                    }
                } else if (move_state == -1) {
                    player1.next = ANIM_WALK_BACK;
                    if (player1.posX >= -204) {
                        player1.posX -= 5.5;
                    }
                }
            }
        } else if (is_crouching) {
            if (IsKeyPressed(KEY_S)) {
                player1.next = ANIM_CROUCH_LP;
            } else if (IsKeyPressed(KEY_D)) {
                player1.next = ANIM_CROUCH_HP;
            }
        }
        
        if (player1.next != player1.state || player1.next >= ANIM_LIGHT_PUNCH) {
            player1.state = player1.next;
            animation_reset(&player1.animations[player1.state]);
        }
    }

    animation_update(&player1.animations[player1.state]);
}

void Gameplay::Draw()
{
    // if (IsKeyDown(KEY_RIGHT)) {
    //     DrawTexturePro(character_sheet, {animation_frame(&walk_forwards, 4, character_sheet)}, {10, 10, (float)character_sheet.width/4, (float)character_sheet.height/3}, {0,0}, 0.0f, WHITE);
    // } else if (IsKeyDown(KEY_LEFT)) {
    //     DrawTexturePro(character_sheet, {animation_frame(&walk_backwards, 4, character_sheet)}, {10, 10, (float)character_sheet.width/4, (float)character_sheet.height/3}, {0,0}, 0.0f, WHITE);
    // } else {
    //     DrawTexturePro(character_sheet, {animation_frame(&idle_animation, 4, character_sheet)}, {10, 10, (float)character_sheet.width/4, (float)character_sheet.height/3}, {0,0}, 0.0f, WHITE);
    // }
    Rectangle source = animation_frame(&player1.animations[player1.state], 4, character_sheet);
    Rectangle dimensions = {150+player1.posX, 300, source.width*2, source.height*2};
    DrawTexturePro(character_sheet, source, dimensions, {0, 0}, 0.0f, WHITE);
}
