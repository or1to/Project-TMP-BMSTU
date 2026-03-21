#pragma once
#include <vector>

enum Cell { EMPTY, WALL, COIN, EXIT };

class Level {
public:
	int width = 20;
	int height = 15;

	std::vector<std::vector<Cell>> grid;

	Level();

	bool isWalkable(int x, int y);
};