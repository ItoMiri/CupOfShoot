#pragma once
#include <array>
#include "Vector2.h"

struct NormalVectorTerrain {
	Vector2 normalVector;
	std::array<Vector2, 2> linePoint;

	NormalVectorTerrain(Vector2 normalVector, std::array<Vector2, 2> linePoint)
		:normalVector(normalVector), linePoint(linePoint) {}
};