#include "SquareTerrain.h"

PolygonTerrain::PolygonTerrain(int maskNum)
	:TerrainUnit(maskNum),index(0)
{}

void PolygonTerrain::AddWeapon(Vector2 vec)
{
	this->vec.push_back(vec);
}

void PolygonTerrain::SetStartPosition(int index)
{
	this->index = index;
}

void PolygonTerrain::Update()
{
	// “–‚½‚è”»’è
}

void PolygonTerrain::Draw()
{
	/*DrawLineAA(vec[0].x, vec[0].y, vec[1].x, vec[1].y, GetColor(0, 255, 255), 3);
	DrawLineAA(vec[1].x, vec[1].y, vec[2].x, vec[2].y, GetColor(0, 255, 255), 3);
	DrawLineAA(vec[2].x, vec[2].y, vec[3].x, vec[3].y, GetColor(0, 255, 255), 3);
	DrawLineAA(vec[3].x, vec[3].y, vec[0].x, vec[0].y, GetColor(0, 255, 255), 3);*/

	int a = 0, b = 1;
	for (int i = 0; i < vec.size(); i ++, a++,b++) {
		if (b >= vec.size()) b = 0;
		DrawLineAA(vec[a].x, vec[a].y, vec[b].x, vec[b].y, GetColor(0, 255, 255), 3);
	}
}

void PolygonTerrain::DoShape()
{
	if (vec.size() < 3) return; // \’z•s‰Â
	end[0] = vec[0];
	end[1] = vec[2];
	for (auto vecs : vec) {
		if (end[0].x > vecs.x) end[0].x = vecs.x;
		if (end[1].x < vecs.x) end[1].x = vecs.x;
		if (end[0].y > vecs.y) end[0].y = vecs.y;
		if (end[1].y < vecs.y) end[1].y = vecs.y;
	}

	ShapeMask();
}

void PolygonTerrain::ShapeMask()
{
	SetDrawScreen(maskNum);
	int size = vec.size();
	int a = index, b = a+1, c = a+2;
	for (int i = 0; i < size - 2; i++, b++, c++) {
		if (b >= size) b -= size;
		if (c >= size) c -= size;
		DrawTriangleAA(vec[a].x, vec[a].y, vec[b].x, vec[b].y, vec[c].x, vec[c].y, GetColor(0, 0, 0), TRUE);
	}
}
