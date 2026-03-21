#include "Robot.h"
#include "Level.h"
#include <stdexcept>

void Robot::move(Level& level) {
    int nx = x, ny = y;

    if (dir == UP) ny--;
    if (dir == DOWN) ny++;
    if (dir == LEFT) nx--;
    if (dir == RIGHT) nx++;

    if (!level.isWalkable(nx, ny))
        throw std::runtime_error("Стена!");

    // логическая позиция
    x = nx;
    y = ny;

    // анимация
    targetX = x * 40;
    targetY = y * 40;
    isMoving = true;
}

void Robot::turnLeft() {
	dir = (Direction)((dir + 3) % 4);
}

void Robot::turnRight() {
	dir = (Direction)((dir + 1) % 4);
}

void Robot::reset() {
	x = 0;
	y = 0;
	dir = RIGHT;
}

void Robot::update(float dt) {
    float speed = 200.0f;

    if (isMoving) {
        float dx = targetX - renderX;
        float dy = targetY - renderY;

        float dist = sqrt(dx * dx + dy * dy);

        if (dist < 1.0f) {
            renderX = targetX;
            renderY = targetY;
            isMoving = false;
        }
        else {
            renderX += dx * dt * speed / dist;
            renderY += dy * dt * speed / dist;
        }
    }
}