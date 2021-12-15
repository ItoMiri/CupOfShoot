#include "FPSTimer.h"

LONGLONG FPSTimer::NowTime = 0;
LONGLONG FPSTimer::Time = 0;
float FPSTimer::DeltaTime = 0;
int FPSTimer::FPS = 0;
int FPSTimer::FPSCounter = 0;
LONGLONG FPSTimer::FPSCheckTime = 0;

FPSTimer::FPSTimer() {
	Time = GetNowHiPerformanceCount();

	// �ŏ��̌o�ߎ��Ԃ͉��� 0.000001f �b�ɂ��Ă���
	DeltaTime = 0.000001f;

	// FPS�v���֌W�̏�����
	FPSCheckTime = GetNowHiPerformanceCount();
	FPS = 0;
	FPSCounter = 0;
}

void FPSTimer::Update()
{
	// ���݂̃V�X�e�����Ԃ��擾
	NowTime = GetNowHiPerformanceCount();

	// �O��擾�������Ԃ���̌o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g
	// ( GetNowHiPerformanceCount �Ŏ擾�ł���l�̓}�C�N���b�P�ʂȂ̂� 1000000 �Ŋ��邱�Ƃŕb�P�ʂɂȂ� )
	DeltaTime = (NowTime - Time) / 1000000.0f;

	// ����擾�������Ԃ�ۑ�
	Time = NowTime;

	// FPS�֌W�̏���( 1�b�o�߂���ԂɎ��s���ꂽ���C�����[�v�̉񐔂� FPS �Ƃ��� )
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
