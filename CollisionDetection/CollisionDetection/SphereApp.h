#pragma once

#include <gl/glut.h>// OpenGL toolkit
#include "Application.h"
#include "Sphere.h"
#include <iostream>

class SphereApp : public Application
{
private:
	int sphereResolution;
	int numSpheres = 3;
	Sphere spheres[10];
	float g;
	float timeBetweenUpdates;

public:
	SphereApp();
	virtual void display();
	virtual void update();
};