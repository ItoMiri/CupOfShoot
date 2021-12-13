#pragma once
#include <vector>
#include "TerrainUnit.h"
#include "SquareTerrain.h"
#include "TerrianContainer.h"
#include "ImageContainer.h"
class TerrianStack
{
public:
	TerrianStack(const TerrianStack&) = delete;
	TerrianStack& operator=(const TerrianStack&) = delete; // �R�s�[�֎~
	TerrianStack();

	void Update();
	void Draw();

private:
	void Shape();

	std::vector<TerrainUnit*> ter;
	std::vector<string> terName;
	std::vector<int> maskHandle;
	TerrianContainer tContainer;
	ImageContainer iContainer;
	
};

