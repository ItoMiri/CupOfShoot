#pragma once
#include <vector>
#include "TerrainUnit.h"
#include "SquareTerrain.h"
#include "TerrainContainer.h"
#include "ImageContainer.h"
#include "TerrainValue.h"
class TerrainStack
{
public:
	TerrainStack(const TerrainStack&) = delete;
	TerrainStack& operator=(const TerrainStack&) = delete; // コピー禁止
	TerrainStack();

	void Update();
	void Draw();

private:
	void Shape();

	std::vector<TerrainUnit*> ter;
	//std::vector<vector<Vector2>> vec;

	std::vector<TerrainValue> tv; // 外部より入力が必要，maskNumに対応したterNameもあればok

	std::vector<string> terName;
	std::vector<int> maskHandle;
	TerrainContainer tContainer;
	ImageContainer iContainer;

	int gameWin;
	
};

