#include "MyDemoApp.h"


MyDemoApp::MyDemoApp()
{
	numCircles = NUM_CIRCLES;
	circleResolution = 30;

	width = 80;
	height = 80;

	
	int minRad = 2;
	int maxRad = 5;
	int minVel = -4;
	int maxVel = 4;
	
	for (int s = 0; s < numCircles; s++)
	{
		Circle circle = generateRandomCircle(minRad, maxRad, minVel, maxVel);
		circles[s] = CirclePhysics(circle);
	}
}

Circle MyDemoApp::generateRandomCircle(int minRad, int maxRad, int minVel, int maxVel)
{
	Circle randomCircle = Circle();

	randomCircle.radius = rand() % (maxRad - minRad) + minRad;
	randomCircle.position.x = rand() % (width * 2) - width;
	randomCircle.position.y = rand() % (height * 2) - height;
	randomCircle.velocity.x = rand() % (maxVel - minVel) + minVel;
	randomCircle.velocity.y = rand() % (maxVel - minVel) + minVel;
	randomCircle.colour[0] = rand() % 255;
	randomCircle.colour[1] = rand() % 255;
	randomCircle.colour[2] = rand() % 255;
	randomCircle.mass = M_PI * powf(randomCircle.radius, 2.0f);
	randomCircle.dampening = 0.8f;

	return randomCircle;
}


void MyDemoApp::display(void)
{
	Application::display();

	for (int s = 0; s < numCircles; s++)
	{
		glPushMatrix();
		glTranslatef(circles[s].position().x, circles[s].position().y, 0);
		glColor3ub(circles[s].colour('r'), circles[s].colour('g'), circles[s].colour('b'));
		glutSolidSphere(circles[s].radius(), circleResolution, circleResolution);
		glPopMatrix();
	}

	glutSwapBuffers();
}

void MyDemoApp::update()
{
	Vector2 g = Vector2(0.0f, -9.81);
	float restitution = 0.9f;
	float duration = Application::timeInterval / 1000.0f;

	for (int s = 0; s < numCircles; s++)
	{
		circles[s].addForce(g * circles[s].mass());

		for (int s2 = s+1; s2 < numCircles; s2++)
		{
			if (CircleCollisionResolver::isCollision(circles[s], circles[s2]))
				CircleCollisionResolver::resolve(&circles[s], &circles[s2], duration, restitution);
		}

		circles[s].update(duration);
		circles[s].resolveBorder(width, height);
	}
	
	Application::update();
}
