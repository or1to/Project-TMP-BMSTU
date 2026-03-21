#pragma once
#include <lua.hpp>
#include "../game/Robot.h"
#include "../game/Level.h"
#include <string>

class LuaEngine {
public:
	LuaEngine(Robot& r, Level& l);
	~LuaEngine();

	void runCode(const std::string& code);

private:
	lua_State* L;
	Robot& robot;
	Level& level;

	static int l_move(lua_State* L);
	static int l_left(lua_State* L);
	static int l_right(lua_State* L);

	void blind();
};