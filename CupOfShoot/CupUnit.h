#pragma once
#include "DxLib.h"
#include "Vector2.h"
class CupUnit
{
public: // �R���X�g���N�^��Cup�̉摜��ǂݍ��� �摜�̓n���h���Ŋi�[
	CupUnit(Vector2 vec, Vector2 sVec, float sizeX, float sizeY, bool beLiving, int life);
	~CupUnit();

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	bool beLiving; // ��������
	int life; // ���M�~�b�N�΍�
	int lifeMax;
	Vector2 vec;
	Vector2 sVec;
	float sizeX, sizeY;
	int cupHandle; // �����Q�Ƃ̑���p�ϐ�

};
