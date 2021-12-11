#pragma once
#include <vector>
#include "TerrainUnit.h"
#include "SquareTerrain.h"
class TerrianStack
{
public:
	TerrianStack(const TerrianStack&) = delete;
	TerrianStack& operator=(const TerrianStack&) = delete;
	TerrianStack();

	void Update();
	void Draw();

private:
	std::vector<TerrainUnit*> ter;
};

