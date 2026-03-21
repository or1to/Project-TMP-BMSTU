#include "Robot.h"

Robot::Robot(Level* lvl) {
    level = lvl;
    x = startX = lvl->robotStart.x;
    y = startY = lvl->robotStart.y;
    dir = 0;
}

void Robot::Move() {
    int nx = x, ny = y;
    if (dir == 0) nx++;
    if (dir == 1) ny++;
    if (dir == 2) nx--;
    if (dir == 3) ny--;

    if (level->IsWall(nx, ny)) return;

    x = nx; y = ny;
}

void Robot::TurnLeft() { dir = (dir + 3) % 4; }
void Robot::TurnRight() { dir = (dir + 1) % 4; }

void Robot::Pickup() {
    level->CollectCoin(x, y);
}

void Robot::Reset() {
    x = startX; y = startY;
}

void Robot::Render(SDL_Renderer* r, int cell) {
    SDL_SetRenderDrawColor(r, 50, 150, 255, 255);
    SDL_Rect rect = { x * cell,y * cell,cell,cell };
    SDL_RenderFillRect(r, &rect);
}

int Robot::GetX() { return x; }
int Robot::GetY() { return y; }