#pragma once
#include <vector>
#include "NormalCup.h"
class CupStack
{
public:
	CupStack();
	
	void SetCupQuantity(int num);

	void Update();
	void Draw();
private:
	std::vector<NormalCup> cup;
};
