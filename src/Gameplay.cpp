#include "Gameplay.h"
//#include "Characters.h"
#include "Animation.h"
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

void Gameplay::Load()
{
    Image sprite_sheet = LoadImage("assets/sprites/mario2.png"); // load sprite sheet as 'sprite'
    ImageColorReplace(&sprite_sheet, WHITE, BLANK); // remove magenta background from sprite sheet
    character_sheet = LoadTextureFromImage(sprite_sheet); // load sprite sheet as texture
    UnloadImage(sprite_sheet);
    // player1.Load(); 

    player1.animations[ANIM_IDLE] = {
        .first = 0,
        .last = 3,
        .curr = 0,
        .dir = 1,
        .idling = true,
        .speed = 0.12,
        .duration_left = 0.1
    };

    player1.animations[ANIM_WALK_BACK] = {
        .first = 4,
        .last = 7,
        .curr = 4,
        .dir = 1,
        .looping = true,
        .speed = 0.12,
        .duration_left = 0.1
    };
    
    // player1.animations[ANIM_WALK_BACK] = {
    //     .first = 8,
    //     .last = 11,
    //     .curr = 8,
    //     .dir = 1,
    //     .looping = true,
    //     .speed = 0.12,
    //     .duration_left = 0.1
    // };

    player1.animations[ANIM_WALK_FORWARD] = {
        .first = 8,
        .last = 11,
        .curr = 8,
        .dir = 1,
        .looping = true,
        .speed = 0.12,
        .duration_left = 0.1
    };

    player1.animations[ANIM_LIGHT_PUNCH] = {
        .first = 12,
        .last = 13,
        .curr = 12,
        .dir = 1,
        .finished = false,
        .speed = 0.07,
        .duration_left = 0.1
    };
    
    player1.animations[ANIM_HEAVY_PUNCH] = {
        .first = 16,
        .last = 17,
        .curr = 16,
        .dir = 1,
        .finished = false,
        .speed = 0.13,
        .duration_left = 0.1
    };

}

void Gameplay::Unload()
{
    UnloadTexture(character_sheet);
}

void Gameplay::Update()
{   
    // TraceLog(LOG_INFO, "pos: %.0f, %.0f  screen: %d x %d",
    //          player1.posX, player1.posY, GetScreenWidth(), GetScreenHeight());
    // If enum value of state is greather than or equal to light punch and animation is not finished, locked is set to true and player is not actionable
    // until action and animation finish.
    bool p1_locked = player1.state >= ANIM_LIGHT_PUNCH && !player1.animations[player1.state].finished;

    if (!p1_locked) {
        player1.next = ANIM_IDLE;

        if (IsKeyPressed(KEY_S)) {
            player1.next = ANIM_LIGHT_PUNCH;
        } else if (IsKeyPressed(KEY_D)) {
            player1.next = ANIM_HEAVY_PUNCH;
        } else {
            int move_state = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);

            if (move_state == 1) {
                player1.next = ANIM_WALK_FORWARD;
                if (player1.posX <= (screenWidth+20)) {
                    player1.posX += 5;
                }
            } else if (move_state == -1) {
                player1.next = ANIM_WALK_BACK;
                if (player1.posX >= -80) {
                    player1.posX -= 5;
                }
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
    Rectangle dimensions = {(screenWidth*0)+player1.posX, (screenHeight/2)+player1.posY, source.width*2.2f, source.height*2.2f};
    // TraceLog(LOG_INFO, "tex id=%u size=%dx%d | src=%.0f,%.0f,%.0f,%.0f | dest=%.0f,%.0f,%.0f,%.0f | window=%dx%d",
    //      character_sheet.id, character_sheet.width, character_sheet.height,
    //      source.x, source.y, source.width, source.height,
    //      dimensions.x, dimensions.y, dimensions.width, dimensions.height,
    //      GetScreenWidth(), GetScreenHeight());

    DrawRectangleLinesEx(dimensions, 2, RED); 
    DrawTexturePro(character_sheet, source, dimensions, {0, 0}, 0.0f, WHITE);
}
