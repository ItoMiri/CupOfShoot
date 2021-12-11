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
	SetDrawArea(0, 0, 1920, 1080); // �Ƃ肠������ʕ`��̈�͍ő�ŃX�^�[�g�B��������p���邱�ƂŊȒP�ȃ}�X�N���\
	SetGraphMode(gValue.graphWidth, gValue.graphHeight, 32); // ����͕`��T�C�Y ��{�ς�邱�Ƃ͂Ȃ����낤
	SetWindowSize(1920 / 2, 1080 / 2); // �Q�[�����σE�C���h�E�ɂ���Ȃ�ŏ���3/4�T�C�Y�̃E�C���h�E�ŋN�����Ă�������������Ȃ�
	SetMouseDispFlag(TRUE);
	SetWindowStyleMode(7);
	SetWindowSizeChangeEnableFlag(TRUE);// �E�C���h�E���ςɂ��邩TRUE�ŉ�

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

		Time::Update(); // �V�X�e���A�b�v�f�[�g
		KeyboardInput::Update();

		mainGame.Update(); // SceneManager�������I�ɗ~����
		mainGame.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break; // ESC�ŒE�o
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

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

#pragma warning(pop)