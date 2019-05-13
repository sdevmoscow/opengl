#pragma once

#include <chrono>
#include <ctime> 
#include "MBase.h"
#include "GShape.h"
#include "GEllipse.h"
#include "GShapeFactory.h"

class MClock : public MBase
{

private:
	int timeZone;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	string place;
	string date_s;
	string time_s;
	float pos_x;
	float pos_y;
	float radius;
	GStyle style;

private:
	MClock();
	MClock(int _tzone, string _place) : timeZone(_tzone), place(_place)
	{};
	void Arrow(GShapeFactory *factory, float angle, float length, float width, GColor color);
	void ThinArrow(GShapeFactory *factory, float angle, float length, GColor color);

public:
	friend class MClockFactory;

	void Position(float posx, float posy)
	{
		this->pos_x = posx;
		this->pos_y = posy;
	}

	void Size(float _radius)
	{
		this->radius = _radius;
	}

	virtual void Life(float t);
	virtual void Draw();

};

