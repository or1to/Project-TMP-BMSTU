#pragma once
#include "Level.h"
#include <SDL3/SDL.h>

class Robot {
public:
    Robot(Level* level);

    void Move();
    void TurnLeft();
    void TurnRight();
    void Pickup();
    void Reset();

    void Render(SDL_Renderer* r, int cell);

    int GetX();
    int GetY();

private:
    int x, y, startX, startY, dir;
    Level* level;
};