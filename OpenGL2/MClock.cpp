#include "pch.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include "MClock.h"

static string IntToString(int value)
{
	string s = std::to_string(value);
	return value < 10 ? "0" + s : s;
}

void MClock::Life(float t)
{
	char time[26];
	auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	ctime_s(time, sizeof time, &timenow);

	struct tm timeinfo;
	gmtime_s(&timeinfo, &timenow);

	this->day = timeinfo.tm_mday;
	this->month = timeinfo.tm_mon + 1;
	this->year = timeinfo.tm_year + 1900;
	this->hour = timeinfo.tm_hour + this->timeZone;
	this->minute = timeinfo.tm_min;
	this->second = timeinfo.tm_sec;

	int hour = timeinfo.tm_hour + this->timeZone;
	while (hour < 0 ) hour += 24;
	while (hour > 23) hour -= 24;

	this->date_s =
		IntToString(timeinfo.tm_mday) + "." +
		IntToString(timeinfo.tm_mon + 1) + "." +
		IntToString(timeinfo.tm_year + 1900);

	this->time_s =
		IntToString(hour) + ":" +
		IntToString(timeinfo.tm_min) + ":" +
		IntToString(timeinfo.tm_sec);
}

void MClock::Draw()
{
	GShapeFactory factory(this->style);

	GEllipse *circle = 
		factory.CreateEllipse(
			Point2D(this->pos_x, this->pos_y),
			this->radius,
			this->radius);

	circle->Draw();
	delete circle;

	const float step = float(2 * M_PI / 12);
	const float L1 = 0.9f;
	const float L2 = 0.8f;
	const float L4 = 0.6f;
	const float DX = -0.010f;
	const float DY = -0.013f;
	const double TO_DEG = 180.0 / 3.141592653589793238463;

	GColor arrowColor(0.8f, 0.8f, 1.0f);

	// круг
	GEllipse *ellipse = 
		factory.CreateEllipse(
			Point2D(this->pos_x, this->pos_y), 
			this->radius, 
			this->radius);

	ellipse->AddColor(GColor(0.1f, 0.1f, 0.2f));
	ellipse->AddFilled(true);
	ellipse->Draw();

	// граница
	ellipse->AddColor(this->style.color);
	ellipse->AddFilled(false);
	ellipse->Draw();

	// центральный кружок
	ellipse = 
		factory.CreateEllipse(
			Point2D(this->pos_x, this->pos_y), 
			0.01f, 
			0.01f);

	ellipse->AddColor(arrowColor);
	ellipse->AddFilled(false);
	ellipse->Draw();
	delete ellipse;

	int n = 0;
	for (float angle = 0; angle < float(2 * M_PI); angle += step, n++)
	{
		const float y1 = this->pos_y + this->radius * L1 * cosf(angle);
		const float y2 = this->pos_y + this->radius * L2 * cosf(angle);
		const float x1 = this->pos_x + this->radius * L1 * sinf(angle);
		const float x2 = this->pos_x + this->radius * L2 * sinf(angle);

		if (n != 0)
		{
			float _dx = n > 9 ? -0.01f : 0.0f;
			GText *text = factory.CreateText(Point2D(x2+DX+_dx,y2+DY), std::to_string(n));
			text->Draw();
			delete text;
		}
	}

	float hour = this->hour > 12 ? this->hour-12 : this->hour;
	float minutes = hour*60.0f + (float)this->minute;

	float angleHours = - float(2 * M_PI) * minutes / (12.0f*60.0f) * TO_DEG;
	float angleMinutes = -float(2 * M_PI) * ((float)this->minute) / 60.0f * TO_DEG;
	float angleSeconds = -float(2 * M_PI) * ((float)this->second) / 60.0f * TO_DEG;

	Arrow(&factory, angleHours, L4*radius, 0.004f, arrowColor);
	Arrow(&factory, angleMinutes, L2*radius, 0.002f, arrowColor);
	ThinArrow(&factory, angleSeconds, L2*radius, arrowColor);

	GText *text = factory.CreateText(Point2D(this->pos_x-0.06f, this->pos_y - this->radius* L1 * 1.6f), this->place);
	text->AddColor(arrowColor);
	text->Draw();
	delete text;

	text = factory.CreateText(Point2D(this->pos_x - 0.21f, this->pos_y - this->radius* L1 * 1.9f), this->date_s);
	text->AddColor(arrowColor);
	text->AddTextSize(13);
	text->Draw();
	delete text;

	text = factory.CreateText(Point2D(this->pos_x + 0.03f, this->pos_y - this->radius* L1 * 1.9f), this->time_s);
	text->AddColor(arrowColor);
	text->AddTextSize(11);
	text->Draw();
	delete text;

}

void MClock::Arrow(GShapeFactory *factory, float angle, float length, float width, GColor color)
{
	glPushMatrix();

	GPolygon *poly = factory->CreatePolygon();

	glTranslatef(this->pos_x, this->pos_y, 0);
	glRotatef(angle, 0, 0, 1);

	poly->AddPoint(-width / 2, 0.01f);
	poly->AddPoint(-width / 2, length);
	poly->AddPoint( width / 2, length);
	poly->AddPoint( width / 2, 0.01f);
	poly->AddFilled(true);
	poly->AddColor(color);
	poly->Draw();

	poly->AddFilled(false);
	poly->Draw();
	delete poly;

	glPopMatrix();
}

void MClock::ThinArrow(GShapeFactory *factory, float angle, float length, GColor color)
{
	glPushMatrix();

	GLine *line = factory->CreateLine(Point2D(0, 0.01f), Point2D(0, length));

	glTranslatef(this->pos_x, this->pos_y, 0);
	glRotatef(angle, 0, 0, 1);

	line->AddColor(color);
	line->Draw();
	delete line;

	glPopMatrix();
}

