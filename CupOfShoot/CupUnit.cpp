#include "CupUnit.h"

CupUnit::CupUnit(Vector2 vec, Vector2 sVec, float sizeX, float sizeY, bool beLiving, int life)
{
	this->vec = vec;
	this->sVec = sVec;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->beLiving = beLiving;
	this->life = life;
	lifeMax = this->life;

	cupHandle = 0; // ここでの定義は-1を代入。継承先でハンドルを代入する形

}

CupUnit::~CupUnit()
{
}
