#pragma once

#include <gl/glut.h>// OpenGL toolkit
#include "Application.h"
#include "PlatformPhysics.h"
#include "CirclePhysics.h"
#include "ContactGenerator.h"
#include "CircleCollisionResolver.h"
#include "Contact.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define NUM_CIRCLES 2
#define NUM_PLATFORMS 6
#define MAX_CONTACTS 20
#define M_PI 3.14159265358979323846  /* pi */


class MyDemoApp : public Application
{
private:
	PlatformPhysics platforms[NUM_PLATFORMS];
	CirclePhysics circles[NUM_CIRCLES];
	int numCircles;
	int circleResolution;
	Contact* contacts[MAX_CONTACTS];
	unsigned usedContacts;

	Circle generateRandomCircle(int minRad, int maxRad, int minVel, int maxVel);
	Platform generateRandomPlatform();

public:
	MyDemoApp();
	~MyDemoApp();
	void display();
	void update();
	void generateContacts();
	void drawCircle(CirclePhysics c);
	void drawPlatform(PlatformPhysics p);
};