cmake_minimum_required(VERSION 3.10)
project(BotCodingLevels)

set(CMAKE_CXX_STANDARD 17)

set(SDL3_INCLUDE_DIR "D:/libs/SDL3/include")
set(SDL3_LIB_DIR "D:/libs/SDL3/lib/x64")
include_directories(${SDL3_INCLUDE_DIR})
link_directories(${SDL3_LIB_DIR})

set(LUA_SRC_DIR "D:/libs/lua/src")
file(GLOB LUA_SOURCES "${LUA_SRC_DIR}/*.c")
include_directories(${LUA_SRC_DIR})

include_directories(imgui imgui/backends)

include_directories(utils/thirdparty)

file(GLOB SOURCES
    game/*.cpp
    scripting/*.cpp
    editor/*.cpp
    ui/*.cpp
    imgui/*.cpp
    imgui/backends/imgui_impl_sdl2.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

add_executable(BotCodingLevels ${SOURCES} ${LUA_SOURCES})

target_link_libraries(BotCodingLevels SDL3 SDL3main opengl32)