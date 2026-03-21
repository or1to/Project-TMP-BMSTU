#include "Renderer.h"

bool Renderer::Init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("BotCodingLevels", 800, 600, 0);
    renderer = SDL_CreateRenderer(window, NULL);
    return true;
}

void Renderer::Clear() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
}

void Renderer::Present() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::Get() {
    return renderer;
}