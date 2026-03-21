#pragma once
#include <lua.hpp>
#include <queue>
#include <string>
#include "../game/Robot.h"
#include "../game/Level.h"

class LuaEngine {
public:
    LuaEngine(Robot& robot, Level& level);
    ~LuaEngine();

    void runCode(const std::string& code);

    void loadCommands(const std::string& code);
    void step();

private:
    lua_State* L;
    Robot& robot;
    Level& level;

    std::queue<std::string> commands;
};