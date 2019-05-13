#pragma once
#include <queue>
#include <vector>
#include "GCommon.h"
#include "GStyle.h"
#include "Interface.h"

using std::queue;
using std::vector;

enum GShapeOption
{
	G_NONE = 0,
	G_POINT = 1,
	G_LINE = 2,
	G_TRIANGLE = 3,
	G_POLYGON = 4,
	G_ELLIPSE = 5,
	G_TEXT = 6,
	G_DISTANCE = 7,
	G_COURSE = 8,
	G_PITCH = 9,
	G_PLANE = 10,
	G_CROSS = 11
};

class GShape : IShape
{

protected: 

	GShapeOption option;
	GStyle style;

public:

	GShape()
	{
		option = G_NONE;
		style.color = GColor(0.0f, 0.0f, 0.0f);
		style.filled = false;
		style.lineWidth = 1.0f;
		style.textSize = 15;
	}

	virtual void AddStyle(GStyle _style)
	{
		style = _style;
	}

	virtual void AddColor(GColor _color)
	{
		style.color = _color;
	}

	virtual void AddColor(float r, float g, float b)
	{
		style.color = GColor(r, g, b);
	}

	virtual void AddFilled(bool _filled)
	{
		style.filled = _filled;
	}

	void AddLineWidth(float _width)
	{
		if (_width > 0.0f)
		{
			style.lineWidth = _width;
		}
	}

	void AddLineDashed(int _dashed)
	{
		style.lineDashed = _dashed;
	}

	virtual void AddTextSize(int _size)
	{
		style.textSize = _size;
	}

	virtual void Draw() = 0;

};
