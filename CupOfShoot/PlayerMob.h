#pragma once
#include "KeyboardInput.h"
#include "MobUnit.h"
#include "CupStack.h"
#include "Time.h"
class PlayerMob :
    public MobUnit
{
public:
    PlayerMob(Vector2 vec, Vector2 sVec, int hp, CupStack& cStack);
    ~PlayerMob();

    void Update();
    void Draw();

private:
    CupStack* cStack{};
    int direction;
};

