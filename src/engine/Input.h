#pragma once
#include <SDL3/SDL.h>

class Input {
public:
    void Update(SDL_Event& e);
    bool quit = false;
};