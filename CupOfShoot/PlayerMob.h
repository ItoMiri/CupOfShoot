#pragma once
#include "KeyboardInput.h"
#include "MobUnit.h"
#include "CupStack.h"
class PlayerMob :
    public MobUnit
{
public:
    PlayerMob(float x, float y, float sx, float sy, int hp, CupStack& cStack);
    ~PlayerMob();

    void Update();
    void Draw();

private:
    CupStack* cStack{};
};

