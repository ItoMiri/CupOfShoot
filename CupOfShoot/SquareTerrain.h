#pragma once
#include "TerrainUnit.h"
#include "Vector2.h"
#include <vector>
class SquareTerrain :
    public TerrainUnit
{
public:
    SquareTerrain(int maskNum, Vector2 vec1, Vector2 vec2, Vector2 vec3, Vector2 vec4);

    virtual void Update();
    virtual void Draw();

private:
    std::vector<Vector2> vec;
};

