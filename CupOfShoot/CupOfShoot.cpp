#include "DxLib.h"
#include "NormalCup.h"
#include "FPSTimer.h"
#include "PlayerMob.h"
#include "KeyboardInput.h"
#include "CupStack.h"

#pragma warning(push)
#pragma warning(disable:28251)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawArea(0, 0, 1920, 1080); // �Ƃ肠������ʕ`��̈�͍ő�ŃX�^�[�g�B��������p���邱�ƂŃ}�X�N���\
	SetGraphMode(1920, 1080, 32); // ����͕`��T�C�Y ��{�ς�邱�Ƃ͂Ȃ����낤
	SetWindowSize(1920 / 2, 1080 / 2); // �Q�[�����σE�C���h�E�ɂ���Ȃ�ŏ���3/4�T�C�Y�̃E�C���h�E�ŋN�����Ă�������������Ȃ�
	SetMouseDispFlag(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);// �E�C���h�E���ςɂ��邩TRUE�ŉ�
	ChangeWindowMode(TRUE);

	//NormalCup cup(0, 0, 0, 0, 1000, 1000, TRUE, 10);
	CupStack cStack(1);
	PlayerMob player(200, 200, 0, 0, 10, cStack);

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()) {
		SetDrawScreen(DX_SCREEN_BACK);
		KeyboardInput::Update();
		//if (KeyboardInput::GetKey(KEY_INPUT_LCONTROL) >= 1) DrawBoxAA(300, 300, 100, 100, GetColor(255, 0, 255), TRUE);
		cStack.Update();
		player.Update();
		cStack.Draw();
		player.Draw();
		//FPSTimer::Update(); // fps�v�Z
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break; // ESC�ŒE�o
		// printf("%d\n",FPSTimer::GetFPS());
		// SetDrawArea(0, 0, FPSTimer::GetFPS()*20, FPSTimer::GetFPS()*20); // fps��`��̈�ŉ���
	}// �L�[���͑҂�

	DxLib_End();			// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

#pragma warning(pop)