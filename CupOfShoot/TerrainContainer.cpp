#include "TerrainContainer.h"

TerrainContainer::TerrainContainer()
    :width(0), height(0)
{
    CreateMaskScreen();
}

TerrainContainer::~TerrainContainer()
{
    DeleteMaskScreen();
}

void TerrainContainer::Add(string TerrainName)
{
    Terrain[TerrainName] = MakeScreen(width, height, TRUE);
    //SetMaskScreenGraph(Terrain[TerrainName]);
}

int TerrainContainer::GetTerrainHandle(string TerrainName)
{
    auto itr = Terrain.find(TerrainName);
    if (itr != Terrain.end()) {
        return Terrain[TerrainName];
    }
    else {
        return -1;
    }
}

void TerrainContainer::DeleteAll()
{
}

void TerrainContainer::SetGraphic(int width, int height)
{
    this->width = width;
    this->height = height;
}
