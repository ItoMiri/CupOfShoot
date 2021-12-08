#pragma once
#include "CupUnit.h"

class NormalCup : public CupUnit
{
public:
	NormalCup(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life);

	void Update();
	void Draw();

private:
	int posMass[2];
};

