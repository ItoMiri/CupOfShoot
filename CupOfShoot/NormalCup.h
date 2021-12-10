#pragma once
#include "CupUnit.h"
#include "ImageResize.h"
#include "PhysicsData.h"
#include "Time.h"

constexpr int CBRAKE_DISAPPEAR = 0;

class NormalCup : public CupUnit
{
public:
	NormalCup(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life);

	void ToggleOnBreak(int brakeMode = 0);

	bool GetBreaking();
	bool GetLiving();

	void Update();
	void Draw();

private:
	bool beBreaking;
	float breakTime, breakTimeMax;
	int posMass[2];
};

