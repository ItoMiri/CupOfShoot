#include "SquareTerrain.h"

SquareTerrain::SquareTerrain(int maskNum, Vector2 vec1, Vector2 vec2, Vector2 vec3, Vector2 vec4)
	:TerrainUnit(maskNum)
{
	vec.push_back(vec1);
	vec.push_back(vec2);
	vec.push_back(vec3);
	vec.push_back(vec4);
}

void SquareTerrain::Update()
{

}

void SquareTerrain::Draw()
{
	SetDrawArea(0, 0, 1920, 1080);
	DrawTriangle(vec[0].x, vec[0].y, vec[1].x, vec[1].y, vec[3].x, vec[3].y, GetColor(255, 255, 255), TRUE);
	DrawTriangle(vec[1].x, vec[1].y, vec[2].x, vec[2].y, vec[3].x, vec[3].y, GetColor(255, 255, 255), TRUE);
	// 三角形で2回描画
	// mask画面をterrainStackで管理して，予めハンドルのポインタ配列を渡すのもあり
}
