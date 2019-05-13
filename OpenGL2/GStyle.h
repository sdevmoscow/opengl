#pragma once
#include "Interface.h"

class GStyle
{
public:
	GColor color;
	bool   filled;
	float  lineWidth;
	int    lineDashed;
	int    textSize;

	GStyle() : 
		color(GColor(1.0f, 1.0f, 1.0f)),
		lineWidth(1.0f),
		lineDashed(0),
		textSize(15),
		filled(false)
	{}
};
