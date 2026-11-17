#ifndef PLAYER_H
#define PLAYER_H

#include "Animation.h"
#include "raylib.h"
#include <vector>

struct Player
{
    float width;
    float height;
    int velocity = 0;
    float posY = 0;
    float posX = 0;

    int jumpVelocity = 600;
    int health = 100;
    int punchCount = 0;
    int hitCount = 0;
    int knockCount = 0;
    int totalHitCount = 0;
    int clashCount = 0;

    double stunTime = 0;
    double punchCooldown = 0;
    double punchResetCount = 0;
    double hitResetCount = 0;
    double airCooldown = 0;
    double crouchCooldown = 0;
    double blockCooldown = 0;
    double roundTimer = 0;
    double time = 0;

    bool isGrounded = true;   
    bool isBlocking = false;
    bool isCrouching = false;
    bool isStunned = false;
    bool isFacingRight = false;
    bool isBlockBroken = false;
    bool isAttacking = false;
    bool roundTwo = false;
    bool isClashing = false;

    Animation animations[ANIM_COUNT];
    AnimState state = ANIM_IDLE;
    AnimState next = ANIM_IDLE;

    inline void Load() {
    Image sprite_sheet = LoadImage("assets/sprites/mario2.png"); // load sprite sheet as 'sprite'
    ImageColorReplace(&sprite_sheet, WHITE, BLANK); // remove magenta background from sprite sheet
    character_sheet = LoadTextureFromImage(sprite_sheet); // load sprite sheet as texture
    UnloadImage(sprite_sheet);
};
}
#endif