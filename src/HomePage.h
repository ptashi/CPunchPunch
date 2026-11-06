// This files defines what our HomeScreen class can do

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "raylib.h"

class HomePage
{
private:
    // Rectangle name = {x, y, width, height};
    Rectangle startButton = {0, 0, 200, 60}; // keep it 0 for now so i can adjust the screenwidth
    float hoverDuration = 0.0f;
    Font titleFont = {};

public:
    void Draw();         // this is to display the home screen
    bool StartClicked(); // this is a check for the start game button
    void Load();
    void Unload();
};

#endif
