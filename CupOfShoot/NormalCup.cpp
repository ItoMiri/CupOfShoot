#include "NormalCup.h"

NormalCup::NormalCup(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life)
	:CupUnit(x, y, sx, sy, sizeX, sizeY, beLiving, life) {

	posMass[0] = 0; // �����͌v�Z�K�v�@�O���N���X�Ōv�Z������
	posMass[1] = 0;

	cupHandle = LoadGraph("./Contents/CupNormal.png"); // �����ŊO��map���擾
}

void NormalCup::Update() { // �d�͔��蓙�L�q
	x += sx;
	y += sy;

	// �d�͌v�Z(g��static �\���̂œn������
}

void NormalCup::Draw() {
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 200);
	DrawGraph(x, y, cupHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}