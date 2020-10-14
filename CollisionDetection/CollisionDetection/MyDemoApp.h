#pragma once

#include <gl/glut.h>// OpenGL toolkit
#include "Application.h"
#include "Platform.h"
#include "SphereGeometry.h"
#include "SphereCollisionResolver.h"
#include <iostream>

#define NUM_SPHERES 20
#define M_PI 3.14159265358979323846  /* pi */


class MyDemoApp : public Application
{
private:
	SphereGeometry spheres[NUM_SPHERES];
	int numSpheres;
	int sphereResolution;

	Sphere generateRandomSphere(int minRad, int maxRad, int minVel, int maxVel);

public:
	MyDemoApp();
	void display();
	void update();
};