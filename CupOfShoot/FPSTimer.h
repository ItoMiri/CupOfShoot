#pragma once
#include "DxLib.h"
class FPSTimer
{
public:
	FPSTimer();
	static void Update();
	static int GetFPS();

private:
	static LONGLONG NowTime;
	static LONGLONG Time;
	static float DeltaTime;
	static int FPS;
	static int FPSCounter;
	static LONGLONG FPSCheckTime;
};

