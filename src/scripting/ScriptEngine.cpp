#include "ScriptEngine.h"

ScriptEngine* ScriptEngine::instance = nullptr;

ScriptEngine::ScriptEngine(Robot* r) {
    robot = r;
    instance = this;

    L = luaL_newstate();
    luaL_openlibs(L);

    lua_register(L, "move", Move);
    lua_register(L, "turnLeft", TurnLeft);
    lua_register(L, "turnRight", TurnRight);
    lua_register(L, "pickup", Pickup);
}

bool ScriptEngine::Run(const std::string& code) {
    if (luaL_dostring(L, code.c_str()) != LUA_OK) {
        robot->Reset();
        return false;
    }
    return true;
}

int ScriptEngine::Move(lua_State*) {
    instance->robot->Move(); return 0;
}
int ScriptEngine::TurnLeft(lua_State*) {
    instance->robot->TurnLeft(); return 0;
}
int ScriptEngine::TurnRight(lua_State*) {
    instance->robot->TurnRight(); return 0;
}
int ScriptEngine::Pickup(lua_State*) {
    instance->robot->Pickup(); return 0;
}