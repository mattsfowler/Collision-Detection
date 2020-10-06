#include "SphereApp.h"


SphereApp::SphereApp()
{
	sphereResolution = 30;
	g = 9.81f;
	timeBetweenUpdates = 0.5f;

	// manually position spheres
	spheres[0] = Sphere(10.0f);
	spheres[0].setMass(2.0f);
	spheres[0].position = Vector2(30.0f, 30.0f);
	spheres[0].dampening = 1.0f;

	spheres[1] = Sphere(7.0f);
	spheres[1].setMass(1.0f);
	spheres[1].position  = Vector2(0.0f, 30.0f);
	spheres[1].dampening = 1.0f;
	
	spheres[2] = Sphere(20.0f);
	spheres[2].setMass(4.0f);
	spheres[2].position = Vector2(-30.0f, 30.0f);
	spheres[2].dampening = 1.0f;
}


void SphereApp::display(void)
{
	Application::display();

	for (int s = 0; s < numSpheres; s++)
	{
		glLoadIdentity();
		glTranslatef(spheres[s].position.x, spheres[s].position.y, 0);
		glColor3ub(255, 0, 0);
		glutSolidSphere(spheres[s].getRadius(), sphereResolution, sphereResolution);
	}

	glutSwapBuffers();
}

void SphereApp::update()
{
	system("CLS");

	for (int s = 0; s < numSpheres; s++)
	{
		spheres[s].addForce(Vector2(0, -g * spheres[s].getMass()));
		spheres[s].update(timeBetweenUpdates);
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