#pragma once
#include "DxLib.h"
constexpr int KB_PRESS_NONE = 0;
constexpr int KB_PRESS_FIRST = 1;
constexpr int KB_PRESS_PRESSING = 2;

constexpr int KB_MAX = 256;

class KeyboardInput
{
public:
	KeyboardInput();
	~KeyboardInput();
	static void Update();
	static int GetKey(int key);

private:
	static int key[];
};

