#include "CupStack.h"

CupStack::CupStack(int initialNum)
{
	cupMax = initialNum;
}

void CupStack::SetCupMax(int num)
{
	cupMax = num;
}

void CupStack::SetCupQuantity(int num)
{
	size_t size = cup.size();
	if (size < num) {
		for (int i = 0; i < num - size; i++)
			cup.push_back(NormalCup(0, 0, 0, 0, 1000, 1000, TRUE, 10));
	}
	else if (size > num) {
		for (int i = 0; i < size - num; i++) {
			if (cup.empty()) break;
			cup.pop_back();
		}
	}
}

void CupStack::IncreaseCup(int x, int y)
{
	// カップの個数が一定以上なら，0番目を破壊してから描画させる→配列を一定量とってもいいかもしれない
	cup.push_back(NormalCup(0, 0, 0, 0, 1000, 1000, TRUE, 10));
}

void CupStack::Update()
{
	for (auto cups : cup) {
		cups.Update();
	}
}

void CupStack::Draw()
{
	for (auto cups : cup) {
		cups.Draw();
	}
}
