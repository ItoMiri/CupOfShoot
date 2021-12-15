#include "FPSTimer.h"

LONGLONG FPSTimer::NowTime = 0;
LONGLONG FPSTimer::Time = 0;
float FPSTimer::DeltaTime = 0;
int FPSTimer::FPS = 0;
int FPSTimer::FPSCounter = 0;
LONGLONG FPSTimer::FPSCheckTime = 0;

FPSTimer::FPSTimer() {
	Time = GetNowHiPerformanceCount();

	// 最初の経過時間は仮に 0.000001f 秒にしておく
	DeltaTime = 0.000001f;

	// FPS計測関係の初期化
	FPSCheckTime = GetNowHiPerformanceCount();
	FPS = 0;
	FPSCounter = 0;
}

void FPSTimer::Update()
{
	// 現在のシステム時間を取得
	NowTime = GetNowHiPerformanceCount();

	// 前回取得した時間からの経過時間を秒に変換してセット
	// ( GetNowHiPerformanceCount で取得できる値はマイクロ秒単位なので 1000000 で割ることで秒単位になる )
	DeltaTime = (NowTime - Time) / 1000000.0f;

	// 今回取得した時間を保存
	Time = NowTime;

	// FPS関係の処理( 1秒経過する間に実行されたメインループの回数を FPS とする )
	FPSCounter++;
	if (NowTime - FPSCheckTime > 1000000)
	{
		FPS = FPSCounter;
		FPSCounter = 0;
		FPSCheckTime = NowTime;
	}
}

int FPSTimer::GetFPS()
{
	return FPS;
}
