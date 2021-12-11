#include "MainGame.h"

MainGame::MainGame(GameValue& gValue)
	:cStack(3), player(Vector2(100, 100), Vector2(0), 10, cStack), tStack()
{
	this->gValue = &gValue;
}

void MainGame::Update()
{
	cStack.Update();
	tStack.Update();
	player.Update();
}

void MainGame::Draw()
{
	SetDrawScreen((*gValue).gameDrawHandle);
	ClearDrawScreen();
	SetDrawArea(0, 0, 1920, 1080);
	DrawBox(0, 0, 1920, 1080, GetColor(200, 40, 50), TRUE);
	SetDrawArea(0, 0, 0, 0);
	cStack.Draw();
	tStack.Draw();
	player.Draw();
	SetDrawScreen(DX_SCREEN_BACK);

	int x, y, sizeX, sizeY;
	if ((*gValue).graphHeight / 9 < (*gValue).graphWidth / 16) {
		sizeY = (*gValue).graphHeight;
		sizeX = sizeY * 16 / 9;
		y = 0;
		x = ((*gValue).graphWidth - sizeX) / 2;
	}
	else {
		sizeX = (*gValue).graphWidth;
		sizeY = sizeX * 9 / 16;
		x = 0;
		y = ((*gValue).graphHeight - sizeY) / 2;
	}
	DrawExtendGraph(x, y, sizeX - 1, sizeY - 1, (*gValue).gameDrawHandle, TRUE);
}
