#include "pch.h"
#include "GText.h"

void GText::Draw()
{
	glColor3f(
		this->style.color.r,
		this->style.color.g,
		this->style.color.b);

	void *size = this->style.textSize >= 15 ? GLUT_BITMAP_9_BY_15 : GLUT_BITMAP_8_BY_13;
	char *c;
	glRasterPos3f(this->basePoint.x, this->basePoint.y, 0.0f);
	for (c = (char*)this->text.c_str(); *c != '\0'; c++) 
	{
		glutBitmapCharacter(size, *c);
	}
}

