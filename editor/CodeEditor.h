#pragma once
#include <string>

class CodeEditor {
public:
    std::string code =
        "-- Lua script\n"
        "for i = 1,5 do\n"
        "  move()\n"
        "end\n";

    void render();
};