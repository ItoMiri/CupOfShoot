#pragma once
#include "DxLib.h"
class MobUnit
{
public:
	MobUnit(float x, float y, float sx, float sy, int hp);
	~MobUnit();

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	float x, y;
	float sx, sy;
	int hp, hpMax;
};

