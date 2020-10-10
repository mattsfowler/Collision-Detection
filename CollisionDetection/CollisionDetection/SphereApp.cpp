#include "SphereApp.h"


SphereApp::SphereApp()
{
	numSpheres = NUM_SPHERES;
	sphereResolution = 30;
	g = Vector2(0.0f, -9.81);

	//automatically generate a number of spheres
	width = 100;
	height = 100;
	int minRad = 2;
	int maxRad = 5;
	int minVel = 0;
	int maxVel = 10;
	for (int s = 0; s < numSpheres; s++)
	{
		int radius = rand() % (maxRad - minRad) + minRad;
		int posX = rand() % (width * 2) - width;
		int posY = rand() % (height * 2) - height;
		int velX = rand() % (maxVel - minVel) + minVel;
		int velY = rand() % (maxVel - minVel) + minVel;
		int r = rand() % 255;
		int g = rand() % 255;
		int b = rand() % 255;
		float mass = M_PI * powf(radius, 2.0f);
		spheres[s] = Sphere(radius);
		spheres[s].position = Vector2(posX, posY);
		spheres[s].velocity = Vector2(velX, velY);
		spheres[s].setColour(r, g, b);
		spheres[s].setMass(mass);
		spheres[s].dampening = 0.8f;
	}
}


void SphereApp::display(void)
{
	Application::display();

	for (int s = 0; s < numSpheres; s++)
	{
		glPushMatrix();
		glTranslatef(spheres[s].position.x, spheres[s].position.y, 0);
		glColor3ub(spheres[s].getColour('r'), spheres[s].getColour('g'), spheres[s].getColour('b'));
		glutSolidSphere(spheres[s].getRadius(), sphereResolution, sphereResolution);
		glPopMatrix();
	}

	glutSwapBuffers();
}

void SphereApp::update()
{
	for (int s = 0; s < numSpheres; s++)
	{
		spheres[s].addForce(g * spheres[s].getMass());
		spheres[s].update(Application::timeInterval / 1000.0f); //TODO: why the div by 1000?
		borderCollisionResolve(&spheres[s]);
		outOfBoundsResolve(&spheres[s]);
	}
	
	Application::update();
}

void SphereApp::borderCollisionResolve(Sphere* s)
{
	float radius = s->getRadius();
	if (s->position.x > (width - radius) || s->position.x < (-width + radius))
		s->velocity.x = -s->velocity.x;
	if (s->position.y > (height - radius) || s->position.y < (-height + radius))
		s->velocity.y = -s->velocity.y;
}

void SphereApp::outOfBoundsResolve(Sphere* s)
{
	float radius = s->getRadius();
	if (s->position.x > (width - radius))
		s->position.x = width - radius;
	else if (s->position.x < (-width + radius))
		s->position.x = -width + radius;

	if (s->position.y > (height - radius))
		s->position.y = height - radius;
	else if (s->position.y < (-height + radius))
		s->position.y = -height + radius;
}

/*
Application* getApplication()
{
	return new SphereApp();
}
*/