#pragma once

#include "GShape.h"
#include "GStyle.h"
#include "GLine.h"
#include "GEllipse.h"
#include "GPolygon.h"
#include "GTriangle.h"
#include "GText.h"

class GShapeFactory
{

private: 
	GStyle style;

public:
	GShapeFactory(GStyle _style) : style(_style)
	{};

	GLine     * CreateLine(Point2D from, Point2D to);
	GEllipse  * CreateEllipse(Point2D center, float rx, float ry);
	GText	  * CreateText(Point2D basePoint, string text);
	GPolygon  * CreatePolygon();
	GTriangle * CreateTriangle();
};

