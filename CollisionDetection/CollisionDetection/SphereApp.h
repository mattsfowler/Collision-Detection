#pragma once

#include <gl/glut.h>// OpenGL toolkit
#include "Application.h"
#include "Sphere.h"
#include <iostream>

#define NUM_SPHERES 100
#define M_PI 3.14159265358979323846  /* pi */


class SphereApp : public Application
{
private:
	int sphereResolution;
	int numSpheres;
	Sphere spheres[NUM_SPHERES];
	Vector2 g;

public:
	SphereApp();
	void display();
	void update();

	void borderCollisionResolve(Sphere* s);
	void outOfBoundsResolve(Sphere* s);
};