#include "SquareTerrain.h"

PolygonTerrain::PolygonTerrain(int maskNum, PlayerMob &playerMob)
	:TerrainUnit(maskNum), index(0)
{
	this->playerMob = &playerMob;
}

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
	// 当たり判定
	Collide();
}

void PolygonTerrain::Collide()
{
	for (const auto& nvts : nvt) {
		
	}
}


void PolygonTerrain::Draw()
{
	/*DrawLineAA(vec[0].x, vec[0].y, vec[1].x, vec[1].y, GetColor(0, 255, 255), 3);
	DrawLineAA(vec[1].x, vec[1].y, vec[2].x, vec[2].y, GetColor(0, 255, 255), 3);
	DrawLineAA(vec[2].x, vec[2].y, vec[3].x, vec[3].y, GetColor(0, 255, 255), 3);
	DrawLineAA(vec[3].x, vec[3].y, vec[0].x, vec[0].y, GetColor(0, 255, 255), 3);*/

	int a = 0, b = 1;
	for (int i = 0; i < vec.size(); i++, a++, b++) {
		if (b >= vec.size()) b = 0;
		DrawLineAA(vec[a].x, vec[a].y, vec[b].x, vec[b].y, GetColor(0, 255, 255), 3);
	}
}

void PolygonTerrain::DoShape()
{
	if (vec.size() < 3) return; // 構築不可
	end[0] = vec[0];
	end[1] = vec[2];
	for (auto vecs : vec) {
		if (end[0].x > vecs.x) end[0].x = vecs.x;
		if (end[1].x < vecs.x) end[1].x = vecs.x;
		if (end[0].y > vecs.y) end[0].y = vecs.y;
		if (end[1].y < vecs.y) end[1].y = vecs.y;
	}

	int size = vec.size();
	int i1 = 0, i2 = i1 + 1;
	for (int i = 0; i < size; i++, i2++) {
		if (i2 >= size) i2 -= size;
		std::array<Vector2, 2> point = { vec[i1],vec[i2] };
		float a = (vec[i2].y - vec[i1].y) / (vec[i2].x - vec[i1].x); // y = ax + b
		//float b = vec[i1].y - a * vec[i1].x;
		Vector2 nVec(-a, 1.0f);
		Vector2 normalizeNVec(nVec.x / std::sqrt(std::powf(nVec.x, 2) + std::powf(nVec.y, 2)), nVec.y / std::sqrt(std::powf(nVec.x, 2) + std::powf(nVec.y, 2)));
		nvt.push_back(NormalVectorTerrain(normalizeNVec, point)); // 法線ベクトル
	}

	ShapeMask();
}

void PolygonTerrain::ShapeMask()
{
	SetDrawScreen(maskNum);
	int size = vec.size();
	int a = index, b = a + 1, c = a + 2;
	for (int i = 0; i < size - 2; i++, b++, c++) {
		if (b >= size) b -= size;
		if (c >= size) c -= size;
		DrawTriangleAA(vec[a].x, vec[a].y, vec[b].x, vec[b].y, vec[c].x, vec[c].y, GetColor(0, 0, 0), TRUE);
	}
}

