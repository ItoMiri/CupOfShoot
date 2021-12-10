#include "NormalCup.h"

NormalCup::NormalCup(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life)
	:CupUnit(x, y, sx, sy, sizeX, sizeY, beLiving, life) {

	posMass[0] = 0; // ここは計算必要 外部クラスで計算させる
	posMass[1] = 0;

	cupHandle = LoadGraph("./Contents/CupNormal.png"); // ここで外部mapより取得
	cupHandle = ImageResize::Resize(cupHandle, (int)sizeX, (int)sizeY);
}

void NormalCup::Update() { // 重力判定等記述
	sx += 0.0f;
	sy += Physics::phyG;
	x += sx;
	y += sy;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", (int)y);

	/*if (GetNowCount() % 60 == 0) {
		
	}*/

	// 重力計算(gはstatic 構造体で渡すつもり
}

void NormalCup::Draw() {
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 200);
	DrawGraph((int)x, (int)y, cupHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
}