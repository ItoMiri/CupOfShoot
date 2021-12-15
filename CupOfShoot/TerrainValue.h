#pragma once
#include <vector>
#include <string>
#include "Vector2.h"

struct TerrainValue {
	std::string maskName;
	std::vector<Vector2> vec;
	int index;

	TerrainValue(std::string maskName, std::vector<Vector2> vec, int index = 0)
		:maskName(maskName), vec(vec), index(index) {}
};