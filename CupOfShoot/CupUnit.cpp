#include "CupUnit.h"

CupUnit::CupUnit(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life)
{
	this->x = x;
	this->y = y;
	this->sx = sx;
	this->sy = sy;
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
