#include "NormalCup.h"

NormalCup::NormalCup(float x, float y, float sx, float sy, float sizeX, float sizeY, bool beLiving, int life)
	:CupUnit(x, y, sx, sy, sizeX, sizeY, beLiving, life) {

	posMass[0] = 0; // ここは計算必要　外部クラスで計算させる
	posMass[1] = 0;

	cupHandle = LoadGraph("./Contents/CupNormal.png"); // ここで外部mapより取得
}

void NormalCup::Update() { // 重力判定等記述
	x += sx;
	y += sy;

	// 重力計算(gはstatic 構造体で渡すつもり
}

void NormalCup::Draw() {
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 200);
	DrawGraph(x, y, cupHandle, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}