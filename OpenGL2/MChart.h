#pragma once
#include <chrono>
#include <ctime> 
#include <deque> 
#include "MBase.h"
#include "GShape.h"
#include "GEllipse.h"
#include "GShapeFactory.h"

using std::deque;

class MChart : public MBase
{
private:
	float pos_x;
	float pos_y;
	float width;
	float height;
	float time;
	float value;
	deque<float> values;
	GStyle style;
	GColor color;

	MChart() : time(0)
	{
		color = GColor(0.0f, 1.0f, 0.25f);
	};

public:
	friend class MChartFactory;

	void Position(float posx, float posy)
	{
		this->pos_x = posx;
		this->pos_y = posy;
	}

	void Size(float _width, float _height)
	{
		this->width = _width;
		this->height = _height;
	}

	void Color(float _r, float _g, float _b)
	{
		this->style.color = GColor(_r, _g, _b);
	}

	void LineColor(float _r, float _g, float _b)
	{
		this->color = GColor(_r, _g, _b);
	}

	virtual void Life(float dt);
	virtual void Draw();

};

