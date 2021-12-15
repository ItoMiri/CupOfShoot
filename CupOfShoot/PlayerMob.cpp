#include "PlayerMob.h"

typedef KeyboardInput KB;

PlayerMob::PlayerMob(Vector2 vec, Vector2 sVec, int hp, CupStack& cStack)
	:MobUnit(vec, sVec, hp)
{
	this->cStack = &cStack;
	direction = 1; // -1 left 0 : front(?) 1 : right
	sVecMax = Vector2(10.0f, 10.0f);
}

PlayerMob::~PlayerMob()
{
}

void PlayerMob::Update()
{
	if (KB::GetKey(KEY_INPUT_LCONTROL) == KB_PRESS_FIRST) {
		(*cStack).IncreaseCup((int)vec.x, (int)vec.y + 55);
	}
	if (KB::GetKey(KEY_INPUT_D) >= KB_PRESS_FIRST) {
		sVec.x += 10 * Time::deltaTime;
		direction = 1;
	}
	else if (KB::GetKey(KEY_INPUT_A) >= KB_PRESS_FIRST) {
		sVec.x -= 10 * Time::deltaTime;
		direction = -1;
	}
	bool sxPlus = sVec.x > 0;
	if (!sxPlus) sVec.x = -sVec.x;
	if (sVec.x > sVecMax.x) sVec.x = sVecMax.x;
	sVec.x -= 5 * Time::deltaTime;
	if (sVec.x < 0) sVec.x = 0;
	if (!sxPlus) sVec.x = -sVec.x;

	if (sVec.y > sVecMax.y) sVec.y = sVecMax.y;
	
	
	/*if (direction == 1 && sVec.x <= 0.0f) {
		sVec.x = 0;
	}
	else if (direction == -1 && sVec.x >= 0.0f) {
		sVec.x = 0;
	}*/

	vec.x += sVec.x;
	vec.y += sVec.y;

	if (vec.x < 0 - 25) vec.x = 1920 + 25;
	if (vec.x > 1920+ 25) vec.x = -25;
}

void PlayerMob::Draw()
{
	//DrawBox(0, 0, 500, 500, GetColor(255, 255, 255), TRUE);
	//SetDrawArea(vec.x - 25, vec.y - 25, vec.x + 25, vec.y + 25);
	DrawBoxAA(vec.x-25, vec.y-25, vec.x+25, vec.y+25, GetColor(255, 0, 255), TRUE);
}
