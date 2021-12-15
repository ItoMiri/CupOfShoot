#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2() :x(0), y(0) {};
	Vector2(float value) :x(value), y(value) {};
	Vector2(float x, float y) :x(x), y(y) {};
};
