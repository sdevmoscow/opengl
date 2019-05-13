#pragma once
#include "GShape.h"

class GLine : public GShape
{
private:
	
	Point2D from, to;
	GLine();

protected:
	
	GLine(Point2D _from, Point2D _to);

public:
	
	friend class GShapeFactory;
	virtual void Draw();

};



