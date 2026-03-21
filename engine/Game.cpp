#include "Game.h"

#include <GL/gl.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_opengl3.h>

void Game::init() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("BotCodingLevels",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 700,
        SDL_WINDOW_OPENGL);

    glContext = SDL_GL_CreateContext(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    ImGui_ImplOpenGL3_Init("#version 130");

    luaEngine = new LuaEngine(robot, level);
}

void Game::run() {
    init();
    loop();
    cleanup();
}

void Game::loop() {
    Uint32 last = SDL_GetTicks(); 

    while (running) {
        Uint32 now = SDL_GetTicks();
        float dt = (now - last) / 1000.0f;
        last = now;

        handleInput();

        robot.update(dt);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        render();

        ImGui::Render();
        glViewport(0, 0, 1000, 700);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
}

void Game::handleInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {

        ImGui_ImplSDL2_ProcessEvent(&e);

        if (e.type == SDL_QUIT)
            running = false;

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x = e.button.x / 40;
            int y = e.button.y / 40;
            editor.place(level, x, y);
        }
    }
}

void Game::render() {
    ImGui::Begin("Level");

    for (int y = 0; y < level.height; y++) {
        for (int x = 0; x < level.width; x++) {

            ImVec4 color;

            switch (level.grid[y][x]) {
            case EMPTY: color = { 0.2f,0.2f,0.2f,1 }; break;
            case WALL:  color = { 0.5f,0.5f,0.5f,1 }; break;
            case COIN:  color = { 1,0.8f,0,1 }; break;
            case EXIT:  color = { 0,1,0,1 }; break;
            }

            ImGui::PushStyleColor(ImGuiCol_Button, color);

            if (ImGui::Button("##cell", ImVec2(30, 30))) {
                editor.place(level, x, y);
            }

            ImGui::PopStyleColor();

            if (x < level.width - 1)
                ImGui::SameLine();
        }
    }

    ImGui::SetCursorScreenPos(ImVec2(robot.renderX, robot.renderY));
    ImGui::Button("R", ImVec2(30, 30));

    ImGui::End();

    ui.render(*luaEngine);
}

void Game::cleanup() {
    delete luaEngine;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}