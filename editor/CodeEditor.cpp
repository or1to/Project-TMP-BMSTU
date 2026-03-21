#include "CodeEditor.h"
#include <imgui.h>
#include <sstream>
#include <vector>

static ImVec4 colorKeyword = ImVec4(0.4f, 0.7f, 1.0f, 1.0f);
static ImVec4 colorNumber = ImVec4(1.0f, 0.8f, 0.4f, 1.0f);
static ImVec4 colorDefault = ImVec4(1, 1, 1, 1);

bool isKeyword(const std::string& word) {
    return word == "for" || word == "while" || word == "if" ||
        word == "do" || word == "end";
}

void CodeEditor::render() {
    ImGui::Begin("Code Editor");

    std::istringstream stream(code);
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream words(line);
        std::string word;

        while (words >> word) {
            ImVec4 color = ImVec4(1, 1, 1, 1);

            if (word == "for" || word == "while" || word == "if" || word == "do" || word == "end")
                color = ImVec4(0.4f, 0.7f, 1.0f, 1.0f); 
            else if (isdigit(word[0]))
                color = ImVec4(1, 0.8f, 0, 1.0f);

            ImGui::SameLine(0, 0);
            ImGui::TextColored(color, "%s ", word.c_str());
        }
        ImGui::NewLine();
    }

    ImGui::End();
}