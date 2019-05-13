#pragma once
#include "GShape.h"
class GText : public GShape
{
private:

	Point2D basePoint;
	string text;
	GText();

protected:

	GText(Point2D _basePoint, string _text) : basePoint(_basePoint), text(_text)
	{
		this->option = G_TEXT;
	}

public:

	friend class GShapeFactory;
	virtual void Draw();

};

