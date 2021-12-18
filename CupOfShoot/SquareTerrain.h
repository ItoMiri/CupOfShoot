#pragma once
#include "TerrainUnit.h"
#include "Vector2.h"
#include "NormalVectorTerrain.h"
#include "PlayerMob.h"
#include <vector>
#include <array>
#include <cmath>

class PolygonTerrain :
	public TerrainUnit
{
public:
	PolygonTerrain(int maskNum, PlayerMob &playerMob);

	virtual void Update();
	virtual void Draw();
	virtual void DoShape();
	virtual void AddWeapon(Vector2 vec);
	virtual void SetStartPosition(int index = 0);

private:
	virtual void ShapeMask();
	virtual void Collide();

	PlayerMob* playerMob{};

	int index;
	std::vector<Vector2> vec;
	std::vector<NormalVectorTerrain> nvt;
	Vector2 end[2];
};

