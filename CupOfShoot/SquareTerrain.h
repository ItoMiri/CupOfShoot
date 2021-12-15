#pragma once
#include "TerrainUnit.h"
#include "Vector2.h"
#include <vector>
class PolygonTerrain :
    public TerrainUnit
{
public:
    PolygonTerrain(int maskNum);

    virtual void Update();
    virtual void Draw();
    virtual void DoShape();
    virtual void AddWeapon(Vector2 vec);
    virtual void SetStartPosition(int index = 0);

private:
    virtual void ShapeMask();

    int index;
    std::vector<Vector2> vec;
    Vector2 end[2];
};

