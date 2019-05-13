#pragma once
#include "GShape.h"
class GEllipse : public GShape
{
private:

	Point2D center;
	float rx;
	float ry;
	GEllipse();

protected:

	GEllipse(Point2D _center, float _rx, float _ry) : center(_center), rx(_rx), ry(_ry)
	{
		this->option = G_ELLIPSE;
	};

public:

	friend class GShapeFactory;
	virtual void Draw();

};