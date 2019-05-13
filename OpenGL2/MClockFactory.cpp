#include "pch.h"
#include "MClockFactory.h"


MClock * MClockFactory::CreateClock(int timeZone, string place)
{
	MClock *clock = new MClock(timeZone, place);
	clock->style = this->style;
	clock->radius = this->radius;
	return clock;
}
