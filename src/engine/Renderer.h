#pragma once
#include <SDL3/SDL.h>

class Renderer {
public:
    bool Init();
    void Clear();
    void Present();
    SDL_Renderer* Get();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};