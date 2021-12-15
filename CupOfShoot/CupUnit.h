#pragma once
#include "DxLib.h"
#include "Vector2.h"
class CupUnit
{
public: // コンストラクタでCupの画像を読み込む 画像はハンドルで格納
	CupUnit(Vector2 vec, Vector2 sVec, float sizeX, float sizeY, bool beLiving, int life);
	~CupUnit();

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	bool beLiving; // 生存判定
	int life; // 環境ギミック対策
	int lifeMax;
	Vector2 vec;
	Vector2 sVec;
	float sizeX, sizeY;
	int cupHandle; // 辞書参照の代入用変数

};
