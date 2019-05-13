#include "pch.h"
#include "GTriangle.h"

GTriangle * GTriangle::AddPoint(Point2D point)
{
	if (vertices.size() < 3)
	{
		vertices.insert(vertices.end(), point);
	}
	return this;
}

void GTriangle::Draw()
{
	glLineWidth(this->style.lineWidth);

	glBegin(GL_TRIANGLES);

	glColor3f(
		this->style.color.r,
		this->style.color.g,
		this->style.color.b);

	if (vertices.size() == 3)
		for (auto point : vertices)
		{
			glVertex3f(point.x, point.y, 0.0);
		}

	glEnd();
}