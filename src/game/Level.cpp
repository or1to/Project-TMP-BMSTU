#include "Level.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool Level::Load(const std::string& path) {
    std::ifstream f(path);
    json j; f >> j;

    width = j["width"];
    height = j["height"];

    robotStart = { j["robot_start"][0],j["robot_start"][1] };
    exit = { j["exit"][0],j["exit"][1] };

    for (auto& w : j["walls"])
        walls.push_back({ w[0],w[1] });

    for (auto& c : j["coins"])
        coins.push_back({ c[0],c[1] });

    return true;
}

bool Level::IsWall(int x, int y) {
    for (auto& w : walls)
        if (w.x == x && w.y == y) return true;
    return false;
}

void Level::CollectCoin(int x, int y) {
    for (int i = 0;i < coins.size();i++)
        if (coins[i].x == x && coins[i].y == y) {
            coins.erase(coins.begin() + i);
            break;
        }
}

bool Level::IsCompleted(int x, int y) {
    return coins.empty() && x == exit.x && y == exit.y;
}

void Level::Render(SDL_Renderer* r, int cell) {
    SDL_SetRenderDrawColor(r, 200, 50, 50, 255);
    for (auto& w : walls) {
        SDL_Rect rect = { w.x * cell,w.y * cell,cell,cell };
        SDL_RenderFillRect(r, &rect);
    }

    SDL_SetRenderDrawColor(r, 255, 215, 0, 255);
    for (auto& c : coins) {
        SDL_Rect rect = { c.x * cell,c.y * cell,cell,cell };
        SDL_RenderFillRect(r, &rect);
    }

    SDL_SetRenderDrawColor(r, 50, 200, 50, 255);
    SDL_Rect e = { exit.x * cell,exit.y * cell,cell,cell };
    SDL_RenderFillRect(r, &e);
}