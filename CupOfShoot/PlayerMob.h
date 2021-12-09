#pragma once
#include "MobUnit.h"
#include "CupStack.h"
class PlayerMob :
    public MobUnit
{
public:
    PlayerMob(float x, float y, float sx, float sy, int hp);
    ~PlayerMob();

    void Update();
    void Draw();

private:
    CupStack cStack;
};

