#include "SquareTerrain.h"

PolygonTerrain::PolygonTerrain(int maskNum, PlayerMob& playerMob)
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
	Vector2 playerUL = (*playerMob).GetPlayerPosition(PLAYER_UPPER_LEFT),
		playerUR = (*playerMob).GetPlayerPosition(PLAYER_UPPER_RIGHT),
		playerLR = (*playerMob).GetPlayerPosition(PLAYER_LOWER_RIGHT),
		playerLL = (*playerMob).GetPlayerPosition(PLAYER_LOWER_LEFT);
	Vector2 polygon0, polygon1, polygon2;
	for (const auto& nvts : nvt) {
		polygon0 = nvts.linePoint[0];
		polygon1 = nvts.linePoint[1];
		polygon2 = nvts.pointThird;

		if (HitCheck_Triangle_Triangle_2D(VGet(playerUL.x, playerUL.y, 0), VGet(playerUR.x, playerUR.y, 0), VGet(playerLL.x, playerLL.y, 0),
			VGet(polygon0.x, polygon0.y, 0), VGet(polygon1.x, polygon1.y, 0), VGet(polygon2.x, polygon2.y, 0)) ||
			HitCheck_Triangle_Triangle_2D(VGet(playerUR.x, playerUR.y, 0), VGet(playerLR.x, playerLR.y, 0), VGet(playerLL.x, playerLL.y, 0),
				VGet(polygon0.x, polygon0.y, 0), VGet(polygon1.x, polygon1.y, 0), VGet(polygon2.x, polygon2.y, 0)))
		{
			Vector2 newPlayerSpeedVector;
			newPlayerSpeedVector.x = (*playerMob).GetPlayerSpeedVector().x; //　ここに内積x正規化済n
			// 接触時
		}
	}
}

bool PolygonTerrain::CompareVector2(struct Vector2* a, struct Vector2* b)
{
	return a->x == b->x &&
		a->y == b->y;
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
		Vector2 thirdPos;
		if (!CompareVector2(&vec[index], &point[0]) && !CompareVector2(&vec[index], &point[1]))
			thirdPos = vec[index];
		else {
			int i = index + 1;
			if (i >= size) i -= size;
			while (CompareVector2(&vec[i], &point[0]) || CompareVector2(&vec[i], &point[1])) {
				i++;
				if (i >= size) i -= size;
			}
			thirdPos = vec[i];
		}

		float a = (vec[i2].y - vec[i1].y) / (vec[i2].x - vec[i1].x); // y = ax + b
		//float b = vec[i1].y - a * vec[i1].x;
		Vector2 nVec(-a, 1.0f);
		Vector2 normalizeNVec(nVec.x / std::sqrt(std::powf(nVec.x, 2) + std::powf(nVec.y, 2)), nVec.y / std::sqrt(std::powf(nVec.x, 2) + std::powf(nVec.y, 2)));
		nvt.push_back(NormalVectorTerrain(normalizeNVec, point, thirdPos)); // 法線ベクトル
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

