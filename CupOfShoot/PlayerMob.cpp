#include "PlayerMob.h"
PlayerMob::PlayerMob(float x, float y, float sx, float sy, int hp)
	:MobUnit(x, y, sx, sy, hp) {
	cStack = CupStack();
}


PlayerMob::~PlayerMob()
{
}

void PlayerMob::Update()
{
	x += sx;
	y += sy;
}

void PlayerMob::Draw()
{
	// debug
	DrawBoxAA(x, y, 100, 100, GetColor(255, 0, 255), TRUE);
}
