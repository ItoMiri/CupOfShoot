#pragma once
class CupUnit
{
public: // コンストラクタでCupの画像を読み込む 画像はハンドルで格納
	CupUnit();
	~CupUnit();

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	bool beLiving; // 生存判定
	int life; // 環境ギミック対策
	int lifeMax;
	float x, y;
	float sx, sy;
	float sizeX, sizeY;
	int cupHandle; // 辞書参照の代入用変数
	
}; // コメント
