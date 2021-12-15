#include "CupStack.h"

CupStack::CupStack(int initialNum)
{
	cupMax = initialNum;
	cupSize = 50;
	sAtSummoning = Vector2(0.0f, 5.0f);

	normalCupHundle = LoadGraph("./Contents/CupNormal");
	normalCupHundle = ImageResize::Resize(normalCupHundle, cupSize, cupSize);
}

void CupStack::SetCupMax(int num)
{
	cupMax = num;
}

void CupStack::SetCupQuantity(int num) // for Debug
{
	size_t size = cup.size();
	if (size < num) {
		for (int i = 0; i < num - size; i++)
			cup.push_back(NormalCup(Vector2(0), Vector2(0), (int)cupSize, (int)cupSize, TRUE, 10, normalCupHundle));
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
	cup.push_back(NormalCup(Vector2(x,y), sAtSummoning, (int)cupSize, (int)cupSize, TRUE, 10, normalCupHundle));
}

void CupStack::Update()
{
	for (auto it = cup.begin(), e = cup.end(); it != e; ++it) {
		(*it).Update();
		if ((*it).GetBreaking() && !(*it).GetLiving()) {
			cup.erase(it);
			break;
		}
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
	for (auto& cups : cup) {
		if (cups.GetBreaking()) continue;
		cups.ToggleOnBreak();
		break;
	}
}
