#include "MobUnit.h"

MobUnit::MobUnit(float x, float y, float sx, float sy, int hp)
{
	this->x = x;
	this->y = y;
	this->sx = sx;
	this->sy = sy;
	this->hp = hp;
	hpMax = this->hp;
}

MobUnit::~MobUnit()
{
}
