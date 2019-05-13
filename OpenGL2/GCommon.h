#pragma once

#include <string>
#include <queue>

#include "glut.h"

using std::string;
using std::queue;

class Point2D {
public:
	Point2D()
	{}

	Point2D(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	float x, y;
};

