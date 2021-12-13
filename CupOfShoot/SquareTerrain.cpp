#include "SquareTerrain.h"

SquareTerrain::SquareTerrain(int maskNum, Vector2 vec1, Vector2 vec2, Vector2 vec3, Vector2 vec4)
	:TerrainUnit(maskNum)
{
	vec.push_back(vec1);
	vec.push_back(vec2);
	vec.push_back(vec3);
	vec.push_back(vec4);

	end[0] = vec[0];
	end[1] = vec[2];
	for (auto vecs : vec) {
		if (end[0].x > vecs.x) end[0].x = vecs.x;
		if (end[1].x < vecs.x) end[1].x = vecs.x;
		if (end[0].y > vecs.y) end[0].y = vecs.y;
		if (end[1].y < vecs.y) end[1].y = vecs.y;
	}

	Draw();
}

void SquareTerrain::Update()
{

}

void SquareTerrain::Draw()
{
	SetDrawScreen(maskNum);
	//SetDrawArea(end[0].x, end[0].y, end[1].x, end[1].y);
	SetDrawArea(0,0,1920,1080);
	DrawTriangle(vec[0].x, vec[0].y, vec[1].x, vec[1].y, vec[3].x, vec[3].y, GetColor(0, 0, 0), TRUE);
	DrawTriangle(vec[1].x, vec[1].y, vec[2].x, vec[2].y, vec[3].x, vec[3].y, GetColor(0, 0, 0), TRUE);
	// OŠpŒ`‚Å2‰ñ•`‰æ
	// mask‰æ–Ê‚ğterrainStack‚ÅŠÇ—‚µ‚ÄC—\‚ßƒnƒ“ƒhƒ‹‚Ìƒ|ƒCƒ“ƒ^”z—ñ‚ğ“n‚·‚Ì‚à‚ ‚è
}
