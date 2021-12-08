#include "DxLib.h"
#include "NormalCup.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawArea(0, 0, 1920, 1080);
	SetGraphMode(1920, 1080, 32);
	SetMouseDispFlag(TRUE);

	NormalCup cup = NormalCup(0, 0, 0, 0, 100, 100, TRUE, 10);

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		cup.Update();
		cup.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break;
	}// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}