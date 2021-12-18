#pragma once
#include <array>
#include "Vector2.h"

struct NormalVectorTerrain {
	Vector2 normalVector;
	std::array<Vector2, 2> linePoint;
	Vector2 pointThird;

	NormalVectorTerrain(Vector2 normalVector, std::array<Vector2, 2> linePoint, Vector2 pointThird)
		:normalVector(normalVector), linePoint(linePoint), pointThird(pointThird) {}
};