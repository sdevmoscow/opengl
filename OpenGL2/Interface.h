#pragma once
#include "GCommon.h"

class GColor
{
private:
	float r, g, b;

public:

	friend class GShape;
	friend class GLine;
	friend class GEllipse;
	friend class GPolygon;
	friend class GTriangle;
	friend class GText;
	friend class GCourse;
	friend class GCross;
	friend class GDistance;
	friend class GPitch;
	friend class GPlane;

	GColor()
	{
		r = g = b = 0;
	};
	GColor(float _r, float _g, float _b) : r(_r), g(_g), b(_b)
	{};
};

class IShape {

public:

	virtual void Draw() = 0;

};

class IModel {

public:

	virtual void Life(float t) = 0;
	virtual void Draw() = 0;

};
