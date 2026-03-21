#pragma once
#include <SDL3/SDL.h>
#include <string>

class UI {
public:
    void Handle(SDL_Event& e);
    void Render(SDL_Renderer* r);

    bool run = false;
    std::string code = "move()\\n";
};