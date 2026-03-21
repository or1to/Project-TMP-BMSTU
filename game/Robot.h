#pragma once
#include "../game/Level.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Robot {
public:
    int x = 0;
    int y = 0;
    Direction dir = UP;

    void move(Level& level);
    void turnLeft();
    void turnRight();
    void reset();

    void update(float dt);

    float renderX = 0;
    float renderY = 0;
    float targetX = 0;
    float targetY = 0;
    bool isMoving = false;
};