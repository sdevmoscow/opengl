#include "pch.h"
#include "GLine.h"

GLine::GLine(Point2D _from, Point2D _to) : from(_from), to(_to)
{
	this->option = G_LINE;
}

void GLine::Draw()
{
	
	glLineWidth(this->style.lineWidth);
	
	switch (this->style.lineDashed)
	{
	case 1:
		glPushAttrib(GL_ENABLE_BIT);
		glLineStipple(1, 0xFF00);
		glEnable(GL_LINE_STIPPLE);
		break;
	case 2:
		glPushAttrib(GL_ENABLE_BIT);
		glLineStipple(1, 0xA0A0);
		glEnable(GL_LINE_STIPPLE);
		break;
	case 3:
		glPushAttrib(GL_ENABLE_BIT);
		glLineStipple(1, 0xAAAA);
		glEnable(GL_LINE_STIPPLE);
		break;
	}

	glBegin(GL_LINES);

	glColor3f(
		this->style.color.r,
		this->style.color.g,
		this->style.color.b);

	glVertex2f(from.x, from.y);
	glVertex2f(to.x, to.y);
	glEnd();

	if (this->style.lineDashed > 0)
	{
		glPopAttrib();
	}

}

