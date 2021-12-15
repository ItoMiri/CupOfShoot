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
	TerrainStack& operator=(const TerrainStack&) = delete; // �R�s�[�֎~
	TerrainStack();

	void Update();
	void Draw();

private:
	void Shape();

	std::vector<TerrainUnit*> ter;
	//std::vector<vector<Vector2>> vec;

	std::vector<TerrainValue> tv; // �O�������͂��K�v�CmaskNum�ɑΉ�����terName�������ok

	std::vector<string> terName;
	std::vector<int> maskHandle;
	TerrainContainer tContainer;
	ImageContainer iContainer;

	int gameWin;
	
};

