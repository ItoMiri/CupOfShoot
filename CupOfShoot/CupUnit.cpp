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

	cupHandle = 0; // �����ł̒�`��-1�����B�p����Ńn���h����������`

}

CupUnit::~CupUnit()
{
}
