#include <SDL3/SDL.h>
#include "engine/Renderer.h"
#include "game/Level.h"
#include "game/Robot.h"
#include "scripting/ScriptEngine.h"
#include "ui/UI.h"

int main() {
    Renderer renderer;
    renderer.Init();

    Level level;
    level.Load("data/levels/level1.json");

    Robot robot(&level);
    ScriptEngine script(&robot);

    UI ui;

    SDL_StartTextInput();

    SDL_Event e;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT)
                running = false;

            ui.Handle(e);
        }

        if (ui.run) {
            script.Run(ui.code);
            ui.run = false;

            if (level.IsCompleted(robot.GetX(), robot.GetY()))
                SDL_ShowSimpleMessageBox(0, "WIN", "Level complete!", NULL);
        }

        renderer.Clear();

        level.Render(renderer.Get(), 50);
        robot.Render(renderer.Get(), 50);
        ui.Render(renderer.Get());

        renderer.Present();
    }

    return 0;
}