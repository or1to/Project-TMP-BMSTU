#pragma once
#include <vector>
#include <string>
#include <SDL3/SDL.h>

struct Vec2 { int x, y; };

class Level {
public:
    bool Load(const std::string& path);

    bool IsWall(int x, int y);
    void CollectCoin(int x, int y);
    bool IsCompleted(int x, int y);

    void Render(SDL_Renderer* r, int cell);

    int width, height;
    Vec2 robotStart;
    Vec2 exit;

private:
    std::vector<Vec2> walls;
    std::vector<Vec2> coins;
};