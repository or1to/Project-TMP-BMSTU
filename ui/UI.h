#pragma once
#include "../editor/CodeEditor.h"
#include "../scripting/LuaEngine.h"

class UI {
public:
	CodeEditor editor;

	void render(LuaEngine& lua);
};