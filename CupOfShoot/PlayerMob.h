#pragma once
#include "KeyboardInput.h"
#include "MobUnit.h"
#include "CupStack.h"
#include "Vector2.h"
#include "Time.h"

constexpr int PLAYER_UPPER_LEFT = 0;
constexpr int PLAYER_UPPER_RIGHT = 1;
constexpr int PLAYER_LOWER_RIGHT = 2;
constexpr int PLAYER_LOWER_LEFT = 3;

class PlayerMob :
    public MobUnit
{
public:
    PlayerMob(Vector2 vec, Vector2 sVec, int hp, CupStack& cStack);
    ~PlayerMob();

    void Update();
    void Draw();

    Vector2 GetPlayerSpeedVector();
    Vector2 GetPlayerPosition(int position);

    void SetPlayerSpeedVector(Vector2 sVec);

private:
    CupStack* cStack{};
    int direction;
};

