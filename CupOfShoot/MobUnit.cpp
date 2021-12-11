#include "MobUnit.h"

MobUnit::MobUnit(Vector2 vec, Vector2 sVec, int hp)
{
	this->vec = vec;
	this->sVec = sVec;
	this->hp = hp;
	hpMax = this->hp;
	sVecMax = Vector2();
}

MobUnit::~MobUnit()
{
}
