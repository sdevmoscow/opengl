#include "pch.h"
#include "MChartFactory.h"

MChart * MChartFactory::CreateChart()
{
	MChart *chart = new MChart();
	chart->style = this->style;
	return chart;
}
