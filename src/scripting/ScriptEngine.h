#pragma once
#include <string>
#include "../game/Robot.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class ScriptEngine {
public:
    ScriptEngine(Robot* r);
    bool Run(const std::string& code);

private:
    lua_State* L;
    Robot* robot;

    static ScriptEngine* instance;

    static int Move(lua_State*);
    static int TurnLeft(lua_State*);
    static int TurnRight(lua_State*);
    static int Pickup(lua_State*);
};