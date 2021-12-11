#include "DxLib.h"
#include "NormalCup.h"
#include "FPSTimer.h"
#include "KeyboardInput.h"
#include "GameValue.h"
#include "MainGame.h"

#pragma warning(push)
#pragma warning(disable:28251)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GameValue gValue;
	gValue.graphWidth = 1920;
	gValue.graphHeight = 1080;
	SetDrawArea(0, 0, 1920, 1080); // とりあえず画面描画領域は最大でスタート。これを活用することで簡単なマスクが可能
	SetGraphMode(gValue.graphWidth, gValue.graphHeight, 32); // これは描画サイズ 基本変わることはないだろう
	SetWindowSize(1920 / 2, 1080 / 2); // ゲームを可変ウインドウにするなら最初は3/4サイズのウインドウで起動してもいいかもしれない
	SetMouseDispFlag(TRUE);
	SetWindowStyleMode(7);
	SetWindowSizeChangeEnableFlag(TRUE);// ウインドウを可変にするかTRUEで可変

	gValue.fullWindow = FALSE;
	ChangeWindowMode(!gValue.fullWindow);

	if (DxLib_Init() == -1)	return -1;

	MainGame mainGame(gValue);

	gValue.gameDrawHandle = MakeScreen(1920, 1080);
	RECT rect, nowRect, monRec;
	GetClientRect(GetMainWindowHandle(), &rect);
	gValue.windowWidth = rect.right;
	gValue.windowHeight = rect.bottom;
	GetWindowRect(GetDesktopWindow(), &monRec);
	gValue.monitorWidth = monRec.right;
	gValue.monitorHeight = monRec.bottom;

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		GetClientRect(GetMainWindowHandle(), &nowRect);
		if (rect.right != nowRect.right || rect.bottom != nowRect.bottom) {
			gValue.windowWidth = rect.right;
			gValue.windowHeight = rect.bottom;
		}
		rect = nowRect;

		Time::Update(); // システムアップデート
		KeyboardInput::Update();

		mainGame.Update(); // SceneManagerが将来的に欲しい
		mainGame.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break; // ESCで脱出
		if (KeyboardInput::GetKey(KEY_INPUT_F11) == KB_PRESS_FIRST) {
			if (gValue.fullWindow) {
				gValue.fullWindow = FALSE;
				SetWindowStyleMode(7);
				SetWindowSize(monRec.right * 3 / 4, monRec.bottom * 3 / 4);
			}
			else {
				gValue.fullWindow = TRUE;
				SetWindowStyleMode(2);
				SetWindowSize(monRec.right, monRec.bottom);
			}
		}
	}

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

#pragma warning(pop)