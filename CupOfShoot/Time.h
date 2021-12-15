#pragma once
#include "DxLib.h"
class Time
{
public:
	Time();
	static void Update();
	static float deltaTime;
private:
	static LONGLONG nowTime, time;
};

