#pragma once
#include "MChart.h"

class MChartFactory
{

private:
	GStyle style;

public:
	MChartFactory(GStyle _style) : style(_style) 
	{};

	MChart * CreateChart();
};

