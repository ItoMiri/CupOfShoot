#pragma once
#include "DxLib.h"
#include "Vector2.h"
class MobUnit
{
public:
	MobUnit(Vector2 vec, Vector2 sVec, int hp);
	~MobUnit();

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	Vector2 vec;
	Vector2 sVec;
	Vector2 sVecMax;
	int hp, hpMax;
};

