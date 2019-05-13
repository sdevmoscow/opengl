#include "pch.h"
#include "GPolygon.h"

GPolygon * GPolygon::AddPoint(float x, float y)
{
	vertices.insert(vertices.end(), Point2D(x,y));
	return this;
}

void GPolygon::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, 
		this->style.filled ? GL_FILL : GL_LINE);

	glLineWidth(this->style.lineWidth);

	glBegin(GL_POLYGON);

	glColor3f(
		this->style.color.r,
		this->style.color.g,
		this->style.color.b);

	for (auto point : vertices)
	{
		glVertex3f(point.x, point.y, 0.0);
	}

	glEnd();

}