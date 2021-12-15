#pragma once
#include <map>
#include <string>
#include "DxLib.h"

using namespace std;
class TerrainContainer
{
public:
	TerrainContainer();
	~TerrainContainer();

	TerrainContainer(const TerrainContainer&) = delete;
	TerrainContainer& operator=(const TerrainContainer&) = delete; // コピー禁止

	void Add(string TerrainName);
	int GetTerrainHandle(string TerrainName);

	void DeleteAll();

	void SetGraphic(int width, int height);

private:
	int width, height;
	map<string, int> Terrain;
};

/*
*
* 地形コンテナ―
*
* 動的にステージ読み込みをした際に，ステージデータファイルから
* ステージと地形チップを読み込み，その地形のstringと一致するものをここで関数により
* 追加する。
* ステージ終了時に全開放
*
* 辞書がstring形な理由：数が増えた時に対処しやすい
* 
* 呼び出し元でClearDrawScreen()と地形描画，画像のパターン描画する
*
*/

