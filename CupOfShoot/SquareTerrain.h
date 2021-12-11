#pragma once
#include "TerrainUnit.h"
class SquareTerrain :
    public TerrainUnit
{
public:
    SquareTerrain(int maskNum, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

    void Update();
    void Draw();

private:
    
};

