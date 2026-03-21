#include "LuaEngine.h"
#include <iostream>

static Robot* g_robot = nullptr;
static Level* g_level = nullptr;

LuaEngine::LuaEngine(Robot& r, Level& l)
	: robot(r), level(l) {

	L = luaL_newstate();
	luaL_openlibs(L);

	g_robot = &robot;
	g_level = &level;

	blind();
}

LuaEngine::~LuaEngine() {
	lua_close(L);
}

void LuaEngine::bind() {
	lua_register(L, "move", l_move);
	lua_register(L, "left", l_left);
	lua_register(L, "right", l_right);
}

int LuaEngine::L_move(lua_State* L) {
	try {
		g_robot->move(*g_level);
	} catch (...) {
		luaL_error(L, "Столкновение!");
	}
	return 0;
}

int LuaEngine::l_left(lua_State* L) {
	g_robot->turnLeft();
	return 0;
}

int LuaEngine::l_right(lua_State* L) {
	g_robot->turnRight();
	return 0;
}

void LuaEngine::runCode(const std::string& code) {
	if (luaL_dostring(L, code.c_str())) {
		std::cout << "Lua error: " << lua_tostring(L, -1) << std::endl;
		robot.reset();
	}
}

void LuaEngine::step(const std::string& code) {
	static std::istringstream stream(code);
	std::string line;

	if (std::getline(stream, line)) {
		if (luaL_dostring(L, line.c_str())) {
			robot.reset();
		}
	}
}

void LuaEngine::loadCommands(const std::string& code) {
	std::istringstream ss(code);
	std::string line;

	while (std::getline(ss, line)) {
		commands.push(line);
	}
}

void LuaEngine::step() {
	if (commands.empty()) return;

	std::string cmd = commands.front();
	commands.pop();

	luaL_dostring(L, cmd.c_str());
}