#include "UI.h"
#include <imgui.h>

void UI::render(LuaEngine& lua) {
    editor.render();

    ImGui::Begin("Controls");

    if (ImGui::Button("Run")) {
        lua.runCode(editor.code);
    }

    if (ImGui::Button("Step")) {
        lua.step(editor.code);
    }

    if (ImGui::Button("Reset")) {
    }

    if (ImGui::Button("Load Script")) lua.loadCommands(editor.code);
    if (ImGui::Button("Step")) lua.step();
    if (ImGui::Button("Run")) while (!lua.commands.empty()) lua.step();

    ImGui::End();
}