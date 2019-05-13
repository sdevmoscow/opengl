#pragma once
#include "GShape.h"

class GPolygon : public GShape
{
private:

	vector<Point2D> vertices;

protected:

	GPolygon()
	{
		this->option = G_POLYGON;
	}

public:

	friend class GShapeFactory;
	virtual void Draw();
	GPolygon * AddPoint(float x, float y);
};

