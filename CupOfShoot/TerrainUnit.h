#pragma once
#include "DxLib.h"
class TerrainUnit
{
public:
	TerrainUnit(int maskNum) {
		this->maskNum = maskNum;
	};

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	int maskNum; // �}�X�N�X�N���[���𕡐��z�u���C�}�X�N�Ɍʂő��d�`�悵�����̂�\(�Q�[���n���h��)�ɕ`��

};

