#include "Level.h"
#include "../utils/Json.h"
#include <fstream>

Level:Level() {
	grid.resize(height, std::vector<Cell>(width, EMPTY));
}

bool Level::isWalkable(int x, int y) {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return false;

	return grid[y][x] != WALL;
}

void saveLevel(Level& level, const std::string& path) {
	json j;

	j["width"] = level.width;
	j["height"] = level.height;
	j["grid"] = level.grid;

	std::ofstream f(path);
	f << j.dump(4);
}

void loadLevel(Level& level, const std::string& path) {
	std::ifstream f(path);
	json j;
	f >> j;

	level.width = j["width"];
	level.height = j["height"];
	level.grid = j["grid"].get<std::vector<std::vector<Cell>>>();
}