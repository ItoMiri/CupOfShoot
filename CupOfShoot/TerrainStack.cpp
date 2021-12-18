#include "TerrainStack.h"

TerrainStack::TerrainStack()
	:tContainer(), iContainer()
{
	// ここでファイルの入出力をする必要性
	terName.push_back("StageTile1");
	//vec.push_back({ Vector2(50, 300), Vector2(400, 300), Vector2(400, 500), Vector2(100, 500) });
	vector<Vector2> v{ Vector2(50, 300), Vector2(400, 300), Vector2(400, 500), Vector2(100, 500) };
	tv.push_back(TerrainValue("StageTile1", v));
	vector<Vector2> vc{ Vector2(650, 500), Vector2(800, 650), Vector2(850, 800), Vector2(900, 650),Vector2(1200, 500),Vector2(1200, 200),Vector2(650, 200) };
	tv.push_back(TerrainValue("StageTile1", vc, 1));

	Shape();
}

void TerrainStack::Update()
{
	for (auto& ters : ter) {
		ters->Update();
	}
}

void TerrainStack::Draw()
{
	//SetDrawArea(0, 0, 1920, 1080);
	for (auto names : terName) {
		SetMaskScreenGraph(tContainer.GetTerrainHandle(names));
		SetUseMaskScreenFlag(TRUE);
		SetMaskReverseEffectFlag(TRUE);
		DrawGraph(0, 0, iContainer.GetImageHandle(names), TRUE);
		SetUseMaskScreenFlag(FALSE);
		SetMaskReverseEffectFlag(FALSE);
		SetMaskScreenGraph(-1);
	}

	for (auto& ters : ter) {
		ters->Draw();
	}

}

void TerrainStack::Shape()
{
	int bScreen = GetDrawScreen();
	tContainer.SetGraphic(1920, 1080);
	for (auto names : terName) {
		tContainer.Add(names);
		SetDrawScreen(tContainer.GetTerrainHandle(names));
		ClearDrawScreen();

		if (1) { // ここは，多角形以外のオブジェクトがあるときに使用

			for (auto tvs : tv) {
				if (tvs.maskName != names) continue;
				auto* t = new PolygonTerrain(tContainer.GetTerrainHandle(names));
				ter.push_back(t); // 地形生成
				for (auto vecs : tvs.vec) {
					t->AddWeapon(vecs);
				}
				t->SetStartPosition(tvs.index);
				t->DoShape();
			}

			//DrawTriangle(0,0,200,200,0,200, GetColor(0, 0, 0), TRUE);
			//LoadGraphScreen(0, 0, ".\\Contents\\TileSam.bmp", TRUE);
		}
		string path = ".\\Contents\\" + names;
		iContainer.Add(names, path);
	}
	SetDrawScreen(bScreen);
}
