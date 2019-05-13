#include "pch.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "GEllipse.h"

void GEllipse::Draw()
{
	const float step = float(2 * M_PI / 72);

	glLineWidth(this->style.lineWidth);

	if (this->style.filled)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glColor3f(
			this->style.color.r,
			this->style.color.g,
			this->style.color.b);

		int n = 0;
		float px, py;
		for (float angle = 0; angle < float(2 * M_PI); angle += step)
		{
			const float dx = this->rx * cosf(angle);
			const float dy = this->ry * sinf(angle);

			if (n++ > 0)
			{
				glBegin(GL_POLYGON);
				glVertex3f(this->center.x, this->center.y, 0.0);
				glVertex3f(dx + this->center.x, dy + this->center.y, 0.0);
				glVertex3f(px, py, 0.0);
				glEnd();
			}
			px = dx + this->center.x;
			py = dy + this->center.y;
		}

	}
	else
	{
		glBegin(GL_LINE_STRIP);

		glColor3f(
			this->style.color.r,
			this->style.color.g,
			this->style.color.b);

		for (float angle = 0; angle < float(2 * M_PI); angle += step)
		{
			const float dx = this->rx * cosf(angle);
			const float dy = this->ry * sinf(angle);
			glVertex2f(dx + this->center.x, dy + this->center.y);
		}

		glEnd();
	}

}
