#pragma once
#include "DxLib.h"
class ImageResize
{
public:
	ImageResize();
	~ImageResize();

	static int Resize(int handle, int sizeX, int sizeY);

private:
	static int tempHandle;
};
