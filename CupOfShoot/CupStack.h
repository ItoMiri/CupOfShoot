#pragma once
#include <vector>
#include "NormalCup.h"
class CupStack
{
public:
	CupStack(int initialNum);
	
	void SetCupMax(int num); // �ő�l��w��
	void SetCupQuantity(int num); // ���B�p

	void IncreaseCup(int x, int y); // �J�b�v��1���� ���񋟕K�v

	void Update();
	void Draw();
private:
	void DestroyCup();

	Vector2 sAtSummoning;
	int cupMax;
	int cupSize;
	std::vector<NormalCup> cup;
};
