#include "DxLib.h"
#include "NormalCup.h"
#include "FPSTimer.h"

#pragma warning(push)
#pragma warning(disable:28251)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawArea(0, 0, 1920, 1080); // とりあえず画面描画領域は最大でスタート。これを活用することでマスクが可能
	SetGraphMode(1920, 1080, 32); // これは描画サイズ 基本変わることはないだろう
	SetWindowSize(1920 / 2, 1080 / 2); // ゲームを可変ウインドウにするなら最初は3/4サイズのウインドウで起動してもいいかもしれない
	SetMouseDispFlag(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);// ウインドウを可変にするかTRUEで可変
	ChangeWindowMode(TRUE);

	NormalCup cup(0, 0, 0, 0, 1000, 1000, TRUE, 10);

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		cup.Update();
		cup.Draw();
		FPSTimer::Update(); // fps計算
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break; // ESCで脱出
		printf("%d\n",FPSTimer::GetFPS());
		SetDrawArea(0, 0, FPSTimer::GetFPS()*20, FPSTimer::GetFPS()*20); // fpsを描画領域で可視化
	}// キー入力待ち

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

#pragma warning(pop)