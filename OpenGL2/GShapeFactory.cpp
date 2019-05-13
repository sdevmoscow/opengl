#include "pch.h"
#include "GShapeFactory.h"

GLine * GShapeFactory::CreateLine(Point2D from, Point2D to)
{
	GLine *line = new GLine(from, to);
	line->AddStyle(this->style);
	return line;
}

GEllipse * GShapeFactory::CreateEllipse(Point2D center, float rx, float ry)
{
	GEllipse *ellipse = new GEllipse(center, rx, ry);
	ellipse->AddStyle(this->style);
	return ellipse;
}

GPolygon * GShapeFactory::CreatePolygon()
{
	GPolygon *poly = new GPolygon();
	poly->AddStyle(this->style);
	return poly;
}

 GTriangle * GShapeFactory::CreateTriangle()
{
	 GTriangle *triangle = new GTriangle();
	triangle->AddStyle(this->style);
	return triangle;
}

GText * GShapeFactory::CreateText(Point2D basePoint, string text)
{
	GText *gtext = new GText(basePoint, text);
	gtext->AddStyle(this->style);
	return gtext;
}