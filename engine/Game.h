#pragma once
#include <SDL2/SDL.h>

#include "../game/Level.h"
#include "../game/Robot.h"
#include "../scripting/LuaEngine.h"
#include "../editor/LevelEditor.h"
#include "../ui/UI.h"

class Game {
public:
    void run();

private:
    SDL_Window* window = nullptr;
    SDL_GLContext glContext;

    bool running = true;

    Level level;
    Robot robot;

    LuaEngine* luaEngine = nullptr;
    LevelEditor editor;
    UI ui;

    void init();
    void loop();
    void render();
    void handleInput();
    void cleanup();
};