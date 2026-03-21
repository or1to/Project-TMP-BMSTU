#include "UI.h"

void UI::Handle(SDL_Event& e) {
    if (e.type == SDL_EVENT_KEY_DOWN) {
        if (e.key.keysym.sym == SDLK_RETURN) run = true;
    }

    if (e.type == SDL_EVENT_TEXT_INPUT) {
        code += e.text.text;
    }
}

void UI::Render(SDL_Renderer* r) {
    SDL_SetRenderDrawColor(r, 100, 200, 100, 255);
    SDL_Rect btn = { 600,50,150,50 };
    SDL_RenderFillRect(r, &btn);
}