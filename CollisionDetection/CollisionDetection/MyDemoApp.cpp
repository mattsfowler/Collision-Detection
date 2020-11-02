#include "MyDemoApp.h"


MyDemoApp::MyDemoApp()
{
	numSpheres = NUM_SPHERES;
	sphereResolution = 30;

	width = 80;
	height = 80;

	
	int minRad = 2;
	int maxRad = 5;
	int minVel = -4;
	int maxVel = 4;
	
	for (int s = 0; s < numSpheres; s++)
	{
		Circle sphere = generateRandomSphere(minRad, maxRad, minVel, maxVel);
		spheres[s] = CirclePhysics(sphere);
	}
}

Circle MyDemoApp::generateRandomSphere(int minRad, int maxRad, int minVel, int maxVel)
{
	Circle randomSphere = Circle();

	randomSphere.radius = rand() % (maxRad - minRad) + minRad;
	randomSphere.position.x = rand() % (width * 2) - width;
	randomSphere.position.y = rand() % (height * 2) - height;
	randomSphere.velocity.x = rand() % (maxVel - minVel) + minVel;
	randomSphere.velocity.y = rand() % (maxVel - minVel) + minVel;
	randomSphere.colour[0] = rand() % 255;
	randomSphere.colour[1] = rand() % 255;
	randomSphere.colour[2] = rand() % 255;
	randomSphere.mass = M_PI * powf(randomSphere.radius, 2.0f);
	randomSphere.dampening = 0.8f;

	return randomSphere;
}


void MyDemoApp::display(void)
{
	Application::display();

	for (int s = 0; s < numSpheres; s++)
	{
		glPushMatrix();
		glTranslatef(spheres[s].position().x, spheres[s].position().y, 0);
		glColor3ub(spheres[s].colour('r'), spheres[s].colour('g'), spheres[s].colour('b'));
		glutSolidSphere(spheres[s].radius(), sphereResolution, sphereResolution);
		glPopMatrix();
	}

	glutSwapBuffers();
}

void MyDemoApp::update()
{
	Vector2 g = Vector2(0.0f, -9.81);
	float restitution = 0.9f;
	float duration = Application::timeInterval / 1000.0f;

	for (int s = 0; s < numSpheres; s++)
	{
		spheres[s].addForce(g * spheres[s].mass());

		for (int s2 = s+1; s2 < numSpheres; s2++)
		{
			if (CircleCollisionResolver::isCollision(spheres[s], spheres[s2]))
				CircleCollisionResolver::resolve(&spheres[s], &spheres[s2], duration, restitution);
		}

		spheres[s].update(duration);
		spheres[s].resolveBorder(width, height);
	}
	
	Application::update();
}
