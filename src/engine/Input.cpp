#include "Input.h"

void Input::Update(SDL_Event& e) {
    if (e.type == SDL_EVENT_QUIT)
        quit = true;
}