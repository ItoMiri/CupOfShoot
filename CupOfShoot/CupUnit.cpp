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

	cupHandle = 0; // �����ł̒�`��-1�����B�p����Ńn���h����������`

}

CupUnit::~CupUnit()
{
}
