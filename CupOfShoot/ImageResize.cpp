#include "ImageResize.h"

int ImageResize::tempHandle = 0;

ImageResize::ImageResize() {
}

ImageResize::~ImageResize() {
}

int ImageResize::Resize(int handle, int sizeX, int sizeY) {

	if (handle != -1) {//�摜�̃��[�h�ɐ��������ꍇ
		int Nowscreen = GetDrawScreen();//���݂̕`��Ώۉ�ʂ��ꎞ�ۑ�
		int miniHandle = MakeScreen(sizeX, sizeY, TRUE);//1/10�T�C�Y�̃O���t�B�b�N�n���h�����쐬
		if (miniHandle == -1) {//�n���h���쐬�Ɏ��s�����ꍇ
			return handle;
		}
		SetDrawScreen(miniHandle);//�`��Ώۉ�ʂ��قǍ����1/10�T�C�Y�̃O���t�B�b�N�n���h���ɕύX
		DrawExtendGraph(0, 0, sizeX, sizeY, handle, TRUE);//���[�h�����摜��1/10�T�C�Y�ŕ`��
		DeleteGraph(handle);//�s�v�ɂȂ����{���̃T�C�Y�̃O���t�B�b�N�n���h�����폜
		SetDrawScreen(Nowscreen);//���݂̕`��Ώۉ�ʂ����̉�ʂɖ߂�
		return miniHandle;//�k�߂��摜�̃O���t�B�b�N�n���h����Ԃ�
	}
	else {//�摜�̃��[�h�Ɏ��s�����ꍇ
		return -1;//�G���[����������-1��Ԃ�
	}
}
