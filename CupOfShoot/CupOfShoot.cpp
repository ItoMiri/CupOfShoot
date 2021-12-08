#include "DxLib.h"
#include "NormalCup.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawArea(0, 0, 1920, 1080);
	SetGraphMode(1920, 1080, 32);
	SetMouseDispFlag(TRUE);

	NormalCup cup = NormalCup(0, 0, 0, 0, 100, 100, TRUE, 10);

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		cup.Update();
		cup.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) break;
	}// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}