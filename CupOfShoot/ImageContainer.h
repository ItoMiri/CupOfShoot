#pragma once
#include <map>
#include <string>
#include "DxLib.h"
using namespace std;

class ImageContainer
{
public:

	ImageContainer();
	~ImageContainer();

	ImageContainer(const ImageContainer&) = delete;
	ImageContainer& operator=(const ImageContainer&) = delete; // ÉRÉsÅ[ã÷é~

	void Add(string mapName, string imagePath);
	int GetImageHandle(string mapName);

	void DeleteAll();

private:
	map<string, int> image;
};

