#pragma once
class TerrainUnit
{
public:
	TerrainUnit(int maskNum) {
		this->maskNum = maskNum;
	};

	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	int maskNum; // マスクスクリーンを複数配置し，マスクに個別で多重描画したものを表(ゲームハンドル)に描画

};

