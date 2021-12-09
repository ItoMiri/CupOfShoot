#include "CupStack.h"

CupStack::CupStack()
{
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
