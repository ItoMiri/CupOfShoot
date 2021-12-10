#pragma once
#include <vector>
#include "NormalCup.h"
class CupStack
{
public:
	CupStack(int initialNum);
	
	void SetCupMax(int num); // 最大値を背定
	void SetCupQuantity(int num); // 増殖用

	void IncreaseCup(int x, int y); // カップを1個召還 情報提供必要

	void Update();
	void Draw();
private:
	void DestroyCup();

	int cupMax;
	std::vector<NormalCup> cup;
};
