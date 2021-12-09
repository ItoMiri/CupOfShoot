#include "PlayerMob.h"

typedef KeyboardInput KB;

PlayerMob::PlayerMob(float x, float y, float sx, float sy, int hp, CupStack& cStack)
	:MobUnit(x, y, sx, sy, hp)
{
	this->cStack = &cStack;
}

PlayerMob::~PlayerMob()
{
}

void PlayerMob::Update()
{
	x += sx;
	y += sy;
	if (KB::GetKey(KEY_INPUT_LCONTROL) == KB_PRESS_FIRST) {
		(*cStack).IncreaseCup(x,y+30);
	}
	
}

void PlayerMob::Draw()
{
	DrawBoxAA(x, y, 100, 100, GetColor(255, 0, 255), TRUE);
}
