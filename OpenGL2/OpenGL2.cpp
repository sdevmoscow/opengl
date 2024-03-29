// OpenGL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "MClock.h"
#include "GCommon.h"
#include "GShape.h"
#include "GStyle.h"
#include "GShapeFactory.h"
#include "MClockFactory.h"
#include "MChartFactory.h"

// коллекция моделей
static vector<MBase*> models;

static void DrawPolygons()
{
	// фабрики графических примитивов
	GStyle style;
	style.color = GColor(0.5f, 0.75f, 1.0f);
	style.lineWidth = 1.0f;
	style.filled = true;
	GShapeFactory blueFactory(style);

	style.color = GColor(1.0f, 1.0f, 0.2f);
	style.filled = false;
	GShapeFactory yellowFactory(style);

	// отрисовка тестовых полигонов
	float px = -0.75f;
	float py = 0.80f;
	float radius = 0.15f;
	for (int i = 3; i < 9; i++)
	{
		if (i == 7) continue;

		GShapeFactory *factory = i < 6 ? &blueFactory : &yellowFactory;

		float dy = i == 3 ? -0.04f : 0.0f;
		GPolygon *poly = factory->CreatePolygon();
		float step = float(2 * M_PI / (float)i);
		for (float angle = 0; angle < float(2 * M_PI); angle += step)
		{
			float y = py + radius * cosf(angle) + dy;
			float x = px + radius * sinf(angle);
			poly->AddPoint(x, y);
		}
		px += 0.37f;
		poly->Draw();
		delete poly;
	}

}

static void DisplayFunc(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

	// отрисовка тестовых полигонов
	DrawPolygons();

	// отрисовка моделей
	for (auto model : models)
	{
		model->Draw();
	}

	glFlush();

}

static void Key(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
	}
}

static void SpecialKey(int key, int x, int y)
{
	switch (key) {
	case 101:
		break;
	case 103:
		break;
	}
}

static void myMouseMove(int x, int y)
{
	//CenterX += 0.01;
	//glutPostRedisplay();
}

void TimerFunction(int value) 
{
	for (auto model : models)
	{
		model->Life(0.01);
	}

	glutPostRedisplay();
	glutTimerFunc(10, TimerFunction, value++);
}

int main(int argc, char** argv)
{
	std::srand(unsigned(std::time(NULL)));

	// создание общего стиля
	GStyle style;
	style.color = GColor(0.5f, 0.75f, 1.0f);
	style.filled = false;;
	style.lineWidth = 1.0f;
	style.textSize = 15;

	// фабрика часов
	MClockFactory clocksFactory(style, 0.25f);
	
	// создание часов
	float clock_y = -0.4f;
	MClock *clockMoscow = clocksFactory.CreateClock(3, "Moscow");
	clockMoscow->Position(-0.67f, clock_y);
	models.insert(models.end(), clockMoscow);

	MClock *clockLondon = clocksFactory.CreateClock(0, "London");
	clockLondon->Position(0.0f, clock_y);
	models.insert(models.end(), clockLondon);

	MClock *clockTokyo = clocksFactory.CreateClock(9, "Tokyo");
	clockTokyo->Position(0.67f, clock_y);
	models.insert(models.end(), clockTokyo);

	// фабрика диаграмм
	MChartFactory chartsFactory(style);

	// создание диаграмм
	clock_y = 0.05f;
	MChart *chart1 = chartsFactory.CreateChart();
	chart1->Position(-0.9f, clock_y);
	chart1->Size(0.8f, 0.5f);
	models.insert(models.end(), chart1);

	MChart *chart2 = chartsFactory.CreateChart();
	chart2->Color(0.0f, 0.7f, 0.2f);
	chart2->Position(0.1f, clock_y);
	chart2->Size(0.8f, 0.5f);
	chart2->LineColor(1.0f, 1.0f, 0.0f);
	models.insert(models.end(), chart2);

	// инициализация OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(768, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Demo");
	glutDisplayFunc(DisplayFunc);
	glutKeyboardFunc(Key);
	glutSpecialFunc(SpecialKey);
	glutTimerFunc(10, TimerFunction, 1);
	glutMainLoop();

	return 0;
}