#include "TerrianStack.h"

TerrianStack::TerrianStack()
	:tContainer(), iContainer()
{
	// �����Ńt�@�C���̓��o�͂�����K�v��
	terName.push_back("StageTile1");
	Shape();
}

void TerrianStack::Update()
{
	for (auto& ters : ter) {
		ters->Update();
	}
}

void TerrianStack::Draw()
{
	SetDrawArea(0, 0, 1920, 1080);
	for (auto names : terName) {
		SetMaskScreenGraph(tContainer.GetTerrianHandle(names));
		SetUseMaskScreenFlag(TRUE);
		DrawGraph(0, 0, iContainer.GetImageHandle(names), TRUE);
		SetUseMaskScreenFlag(FALSE);
		SetMaskScreenGraph(-1);
	}
}

void TerrianStack::Shape()
{
	int bScreen = GetDrawScreen();
	tContainer.SetGraphic(1920, 1080);
	for (auto names : terName) {
		tContainer.Add(names);
		SetDrawScreen(tContainer.GetTerrianHandle(names));
		ClearDrawScreen();
		//DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), TRUE);
		if (1) {
			ter.push_back(new SquareTerrain(tContainer.GetTerrianHandle(names), Vector2(50, 300), Vector2(400, 300), Vector2(400, 500), Vector2(100, 500))); // debug �����ɔC�ӂ̒l��ǉ�
			LoadGraphScreen(0, 0, ".\\Contents\\TileSam.bmp", TRUE);
		}
		string path = ".\\Contents\\" + names;
		iContainer.Add(names, path);
	}
	SetDrawScreen(bScreen);
}
