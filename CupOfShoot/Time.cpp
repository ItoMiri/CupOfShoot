#include "Time.h"

LONGLONG Time::nowTime = 0;
LONGLONG Time::time = GetNowHiPerformanceCount();
float Time::deltaTime = 0.000001f;

Time::Time()
{
}

void Time::Update()
{
	nowTime = GetNowHiPerformanceCount();
	deltaTime = (nowTime - time) / 1000000.0f;
	time = nowTime;
}
