#pragma once

#include "GStyle.h"
#include "MBase.h"
#include "MClock.h"

class MClockFactory
{

private:
	GStyle style;
	float radius;

public:
	MClockFactory(GStyle _style, float _radius) : style(_style), radius(_radius)
	{};

	MClock * CreateClock(int timeZone, string place);
};

