#include "pch.h"
#include "MChart.h"

const int num_x = 10.0f;
const int num_y = 5.0f;

void MChart::Life(float dt)
{
	time += dt;

	// имитация входного сигнала
	float d = 5.0f * (float)std::rand() / (float)RAND_MAX;
	if (values.size() == 0)
	{
		value = d;
	}
	else
	{
		// сглаживание
		value = 0.96*value + 0.04*d;
	}

	values.push_front(value);

	// удаляем старые элементы
	while (values.size() > 1000)
	{
		values.pop_back();
	}
}

void MChart::Draw()
{
	int t = (int)time;

	float scale_x = width / (float)num_x;
	float scale_y = height / (float)num_y;
	float delt = scale_x * (time - (float)t);

	GShapeFactory factory(this->style);

	// граница
	GPolygon *poly = factory.CreatePolygon();
	poly->AddPoint(pos_x, pos_y);
	poly->AddPoint(pos_x + width, pos_y);
	poly->AddPoint(pos_x + width, pos_y + height);
	poly->AddPoint(pos_x, pos_y + height);
	poly->Draw();
	delete poly;

	// сетка - вертикальные линии
	for (int i = 1; i <= num_x; i++)
	{
		float x = pos_x + scale_x * (float)i - delt;
		GLine *line = factory.CreateLine(Point2D(x, pos_y), Point2D(x, pos_y + height));
		line->AddColor(style.color);
		line->AddLineDashed(3);
		line->Draw();
		delete line;

		// подписи по оси x
		int val = t - num_x + i;
		if (val >= 0)
		{
			float _dx = val > 9 ? -0.01f : 0.0f;
			GText *text = factory.CreateText(Point2D(x - 0.008f + _dx, pos_y - 0.035f), std::to_string(val));
			text->AddTextSize(13);
			text->Draw();
			delete text;
		}
	}

	// сетка - горизонтальные линии
	for (int i = 0; i <= num_y; i++)
	{
		float y = pos_y + scale_y * (float)i;
		if (i < num_y)
		{
			GLine *line = factory.CreateLine(Point2D(pos_x, y), Point2D(pos_x + width, y));
			line->AddColor(style.color);
			line->AddLineDashed(3);
			line->Draw();
			delete line;
		}

		GText *text = factory.CreateText(Point2D(pos_x - 0.03f, y-0.006f), std::to_string(i));
		text->AddTextSize(13);
		text->Draw();
		delete text;
	}

	// линия данных
	int n = 0;
	float py = pos_y + scale_y * values.front();
	float px = pos_x + width;
	for (deque<float>::iterator it = values.begin(); it != values.end(); ++it, ++n)
	{
		float y = pos_y + scale_y * (*it);
		float x = pos_x + width - scale_x * 0.01f*(float)n;
		GLine *line = factory.CreateLine(Point2D(x, y), Point2D(px, py));
		line->AddColor(color);
		line->Draw();
		delete line;
		py = y;
		px = x;
	}

}
