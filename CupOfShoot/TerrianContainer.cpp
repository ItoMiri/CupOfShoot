#include "TerrianContainer.h"

TerrianContainer::TerrianContainer()
    :width(0), height(0)
{
    CreateMaskScreen();
}

TerrianContainer::~TerrianContainer()
{
    DeleteMaskScreen();
}

void TerrianContainer::Add(string terrianName)
{
    terrian[terrianName] = MakeScreen(width, height, TRUE);
    //SetMaskScreenGraph(terrian[terrianName]);
}

int TerrianContainer::GetTerrianHandle(string terrianName)
{
    auto itr = terrian.find(terrianName);
    if (itr != terrian.end()) {
        return terrian[terrianName];
    }
    else {
        return -1;
    }
}

void TerrianContainer::DeleteAll()
{
}

void TerrianContainer::SetGraphic(int width, int height)
{
    this->width = width;
    this->height = height;
}
