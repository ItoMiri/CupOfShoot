#include "NormalCup.h"

NormalCup::NormalCup(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life)
	:CupUnit(x, y, sx, sy, sizeX, sizeY, beLiving, life) {

	posMass[0] = 0; // �����͌v�Z�K�v �O���N���X�Ōv�Z������
	posMass[1] = 0;
	cupHandle = LoadGraph("./Contents/CupNormal.png"); // �����ŊO��map���擾
	cupHandle = ImageResize::Resize(cupHandle, (int)sizeX, (int)sizeY);

	beBreaking = FALSE;
	breakTimeMax = 0.5f;
	breakTime = breakTimeMax;
}

void NormalCup::ToggleOnBreak(int brakeMode)
{
	if (beBreaking) return;
	beBreaking = TRUE;
	breakTime = breakTimeMax;
}

bool NormalCup::GetBreaking()
{
	return beBreaking;
}

bool NormalCup::GetLiving()
{
	return beLiving;
}

void NormalCup::Update() { // �d�͔��蓙�L�q

	if (beBreaking) {
		breakTime -= Time::deltaTime; // ���Ԃɂ���ăn���h����؂�ւ���������͗��̉�ʂŃ^�C�����ׂč��W�w��
		if (breakTime <= 0.00f) {
			beLiving = FALSE;
		}
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", breakTime);
		return;
	}
	sx += 0.0f;
	sy += Physics::phyG * Time::deltaTime;
	x += sx;
	y += sy;

	/*if (GetNowCount() % 60 == 0) {
		
	}*/
}

void NormalCup::Draw() {
	if (!beLiving) return;
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 200);
	DrawGraph((int)x, (int)y, cupHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
}