#pragma once
#include <vector>
#include "TerrainUnit.h"
#include "SquareTerrain.h"
#include "TerrainContainer.h"
#include "ImageContainer.h"
#include "TerrainValue.h"
#include "PlayerMob.h"
class TerrainStack
{
public:
	//TerrainStack(const TerrainStack&) = delete;
	//TerrainStack& operator=(const TerrainStack&) = delete; // �R�s�[�֎~
	TerrainStack(PlayerMob &playerMob);

	void Update();
	void Draw();

private:
	void Shape();

	std::vector<TerrainUnit*> ter;

	std::vector<TerrainValue> tv; // �O�������͂��K�v�CmaskNum�ɑΉ�����terName�������ok

	std::vector<string> terName;
	std::vector<int> maskHandle;
	TerrainContainer tContainer;
	ImageContainer iContainer;
	PlayerMob* playerMob{};

	int gameWin;
	
};

