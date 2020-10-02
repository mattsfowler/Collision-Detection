// sphereJK_OO.cpp
// draw a single sphere in the middle of the screen
// OO basic

#include "SphereApp.h"


SphereApp::SphereApp()
{
	sphereResolution = 30;

	// manually position spheres
	spheres[0] = Sphere(10.0f);
	spheres[0].setPosition(vector2d(30.0f, 30.0f));
	spheres[0].setMass(2);
	spheres[0].setDrag(0.5);

	spheres[1] = Sphere(7.0f);
	spheres[1].setPosition(vector2d(0.0f, 30.0f));
	spheres[1].setMass(1);
	spheres[1].setDrag(0.5);

	spheres[2] = Sphere(20.0f);
	spheres[2].setPosition(vector2d(-30.0f, 30.0f));
	spheres[2].setMass(4);
	spheres[2].setDrag(0.5);
}


void SphereApp::display(void)
{
	Application::display();

	int x;
	int y;
	int rad;
	for (int s = 0; s < numSpheres; s++)
	{
		x = spheres[s].getPosition().x;
		y = spheres[s].getPosition().y;
		rad = spheres[s].getRadius();
		glLoadIdentity();
		glTranslatef(x, y, 0);
		glColor3ub(255, 0, 0);
		glutSolidSphere(rad, sphereResolution, sphereResolution);
	}

	glutSwapBuffers();
}

void SphereApp::update()
{
	system("CLS");
	for (int s = 0; s < numSpheres; s++)
	{
		float duration = 0.1;
		float g = spheres[s].getMass() * 9.81f;
		spheres[s].addForce(vector2d(0, -g));
		spheres[s].update(duration);
	}
	
	std::cout << std::endl;
	Application::update();
}

/*
Application* getApplication()
{
	return new SphereApp();
}
*/