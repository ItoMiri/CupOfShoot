#include "DxLib.h"
#include "NormalCup.h"
#include "FPSTimer.h"
#include "PlayerMob.h"
#include "KeyboardInput.h"
#include "CupStack.h"
#include "GameValue.h"

#pragma warning(push)
#pragma warning(disable:28251)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GameValue gValue;
	gValue.graphWidth = 1920;
	gValue.graphHeight = 1080;
	SetDrawArea(0, 0, 1920, 1080); // �Ƃ肠������ʕ`��̈�͍ő�ŃX�^�[�g�B��������p���邱�ƂŊȒP�ȃ}�X�N���\
	SetGraphMode(gValue.graphWidth, gValue.graphHeight, 32); // ����͕`��T�C�Y ��{�ς�邱�Ƃ͂Ȃ����낤
	SetWindowSize(1920/2, 1080/2); // �Q�[�����σE�C���h�E�ɂ���Ȃ�ŏ���3/4�T�C�Y�̃E�C���h�E�ŋN�����Ă�������������Ȃ�
	SetMouseDispFlag(TRUE);
	SetWindowStyleMode(7);
	SetWindowSizeChangeEnableFlag(TRUE);// �E�C���h�E���ςɂ��邩TRUE�ŉ�

	gValue.fullWindow = FALSE;
	ChangeWindowMode(!gValue.fullWindow);

	if (DxLib_Init() == -1)	return -1;
	gValue.gameDrawHandle = MakeScreen(1920, 1080);
	CupStack cStack(1);
	PlayerMob player(Vector2(100, 100), Vector2(0), 10, cStack);
	RECT rect, nowRect;
	GetClientRect(GetMainWindowHandle(), &rect);
	gValue.windowWidth = rect.right;
	gValue.windowHeight = rect.bottom;
	RECT monRec;
	GetWindowRect(GetDesktopWindow(), &monRec);

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		GetClientRect(GetMainWindowHandle(), &nowRect);
		if (rect.right != nowRect.right || rect.bottom != nowRect.bottom) {
			gValue.windowWidth = rect.right;
			gValue.windowHeight = rect.bottom;
		}
		rect = nowRect;
		Time::Update();
		KeyboardInput::Update();
		//if (KeyboardInput::GetKey(KEY_INPUT_LCONTROL) >= 1) DrawBoxAA(300, 300, 100, 100, GetColor(255, 0, 255), TRUE);
		cStack.Update();
		player.Update();
		SetDrawScreen(gValue.gameDrawHandle);
		ClearDrawScreen();
		SetDrawArea(0, 0, 1920, 1080);
		DrawBox(0, 0, 1920, 1080, GetColor(200, 40, 50), TRUE);
		SetDrawArea(0, 0, 0, 0);
		cStack.Draw();
		player.Draw();
		SetDrawScreen(DX_SCREEN_BACK);

		int x, y, sizeX, sizeY;
		if (gValue.graphHeight / 9 < gValue.graphWidth / 16) {
			sizeY = gValue.graphHeight;
			sizeX = sizeY * 16 / 9;
			y = 0;
			x = (gValue.graphWidth - sizeX) / 2;
		}
		else {
			sizeX = gValue.graphWidth;
			sizeY = sizeX * 9 / 16;
			x = 0;
			y = (gValue.graphHeight - sizeY) / 2;
		}
		DrawExtendGraph(x, y, sizeX - 1, sizeY - 1, gValue.gameDrawHandle, TRUE);

		DrawFormatString(500, 500, GetColor(255, 255, 255), "%d", gValue.windowWidth);
		//FPSTimer::Update(); // fps�v�Z
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break; // ESC�ŒE�o
		if (KeyboardInput::GetKey(KEY_INPUT_F11) == KB_PRESS_FIRST) {
			if (gValue.fullWindow) {
				gValue.fullWindow = FALSE;
				SetWindowStyleMode(7);
				SetWindowSize(monRec.right*3/4, monRec.bottom*3/4);
			}
			else {
				gValue.fullWindow = TRUE;
				SetWindowStyleMode(2);
				SetWindowSize(monRec.right, monRec.bottom);
			}
		}
	}

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

#pragma warning(pop)