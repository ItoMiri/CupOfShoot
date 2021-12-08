#pragma once
#include "DxLib.h"
class CupUnit
{
public: // �R���X�g���N�^��Cup�̉摜��ǂݍ��� �摜�̓n���h���Ŋi�[
	CupUnit(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life);
	~CupUnit();

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	bool beLiving; // ��������
	int life; // ���M�~�b�N�΍�
	int lifeMax;
	float x, y;
	float sx, sy;
	float sizeX, sizeY;
	int cupHandle; // �����Q�Ƃ̑���p�ϐ�
	
};
