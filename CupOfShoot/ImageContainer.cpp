#include "ImageContainer.h"

ImageContainer::ImageContainer()
{
}

ImageContainer::~ImageContainer()
{
}

void ImageContainer::Add(string mapName, string imagePath)
{
	image[mapName] = LoadGraph(imagePath.c_str());
}

int ImageContainer::GetImageHandle(string mapName)
{
	auto itr = image.find(mapName);
	if (itr != image.end()) {
		return image[mapName];
	}
	else {
		return -1;
	}
}

void ImageContainer::DeleteAll()
{
}
