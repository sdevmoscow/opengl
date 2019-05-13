#pragma once
#include "GShape.h"
class GTriangle : public GShape
{
private:

	vector<Point2D> vertices;

protected:

	GTriangle()
	{
		this->option = G_POLYGON;
	}

public:

	friend class GShapeFactory;
	virtual void Draw();
	GTriangle * AddPoint(Point2D point);
};
