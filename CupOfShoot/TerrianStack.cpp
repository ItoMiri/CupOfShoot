#include "TerrianStack.h"

TerrianStack::TerrianStack()
{
	TerrainUnit* t = new SquareTerrain(0, Vector2(50, 300), Vector2(400, 300), Vector2(400, 500), Vector2(100, 500));
	ter.push_back(t);
}

void TerrianStack::Update()
{
	for (auto& ters : ter) {
		ters->Update();
	}
}

void TerrianStack::Draw()
{
	for (auto& ters : ter) {
		ters->Draw();
	}
}
