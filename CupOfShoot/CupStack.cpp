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
	cupMax = num;
}

void CupStack::IncreaseCup(int x, int y)
{
	size_t size = cup.size();
	if (size >= cupMax) DestroyCup();
	cup.push_back(NormalCup(x, y, 0, 0, 75, 75, TRUE, 10));
}

void CupStack::Update()
{
	for (auto& cups : cup) {
		cups.Update();
	}
}

void CupStack::Draw()
{
	for (auto& cups : cup) {
		cups.Draw();
	}
}

void CupStack::DestroyCup()
{
	// ここにカップの破壊メンバを呼び出す
}
