#pragma once

#include <gl/glut.h>// OpenGL toolkit
#include "Application.h"
#include "Platform.h"
#include "CirclePhysics.h"
#include "CircleCollisionResolver.h"
#include <iostream>

#define NUM_CIRCLES 20
#define M_PI 3.14159265358979323846  /* pi */


class MyDemoApp : public Application
{
private:
	CirclePhysics circles[NUM_CIRCLES];
	int numCircles;
	int circleResolution;

	Circle generateRandomCircle(int minRad, int maxRad, int minVel, int maxVel);

public:
	MyDemoApp();
	void display();
	void update();
};