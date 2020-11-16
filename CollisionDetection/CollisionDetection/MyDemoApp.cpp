#include "MyDemoApp.h"


MyDemoApp::MyDemoApp()
{
	numCircles = NUM_CIRCLES;
	circleResolution = 30;

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		contacts[i] = new Contact();
	}
	usedContacts = 0;

	width = 95;
	height = 95;

	/*
	srand(time(NULL));
	int minRad = 4;
	int maxRad = 9;
	int minVel = -1;
	int maxVel = 1;
	
	// Generate each circle randomly
	for (int i = 0; i < numCircles; i++)
	{
		Circle circle = generateRandomCircle(minRad, maxRad, minVel, maxVel);
		circles[i] = CirclePhysics(circle);
	}
	*/

	Circle c1 = Circle();
	c1.colour[0] = 255; c1.colour[1] = 0; c1.colour[2] = 0;
	c1.mass = 500;
	c1.position = Vector2(-50, 0);
	c1.velocity = Vector2(2, 0);
	c1.radius = 10;
	circles[0] = CirclePhysics(c1);

	Circle c2 = Circle();
	c2.colour[0] = 0; c2.colour[1] = 255; c2.colour[2] = 0;
	c2.mass = 1;
	c2.position = Vector2(50, 0);
	c2.velocity = Vector2(-2, 0);
	c2.radius = 10;
	circles[1] = CirclePhysics(c2);

	// Platforms...
	unsigned usedPlatforms = 0;

	// Generate a platform for each border
	Vector2 corners[5] = { Vector2(-width, height), Vector2(width, height), Vector2(width, -height), Vector2(-width, -height), Vector2(-width, height) };
	for (int corner = 0; corner < 4; corner++)
	{
		Platform borderPlatform = Platform();
		borderPlatform.start = corners[corner];
		borderPlatform.end = corners[corner + 1];
		borderPlatform.colour[0] = 255;
		borderPlatform.colour[1] = 0;
		borderPlatform.colour[2] = 0;
		platforms[usedPlatforms] = PlatformPhysics(borderPlatform);
		usedPlatforms++;
	}

	/*
	// Generate remaining platforms randomly
	for (usedPlatforms; usedPlatforms < NUM_PLATFORMS; usedPlatforms++)
	{
		Platform platform = generateRandomPlatform();
		platforms[usedPlatforms] = platform;
	}
	*/
}

MyDemoApp::~MyDemoApp()
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		delete contacts[i];
	}
}

Circle MyDemoApp::generateRandomCircle(int minRad, int maxRad, int minVel, int maxVel)
{
	Circle randomCircle = Circle();
	int trueWidth = width - maxRad;
	int trueHeight = height - maxRad;

	randomCircle.radius = rand() % (maxRad - minRad) + minRad;
	randomCircle.position.x = rand() % (trueWidth * 2) - trueWidth;
	randomCircle.position.y = rand() % (trueHeight * 2) - trueHeight;
	randomCircle.velocity.x = rand() % (maxVel - minVel) + minVel;
	randomCircle.velocity.y = rand() % (maxVel - minVel) + minVel;
	randomCircle.colour[0] = rand() % 255;
	randomCircle.colour[1] = rand() % 255;
	randomCircle.colour[2] = rand() % 255;
	randomCircle.mass = M_PI * powf(randomCircle.radius, 2.0f);

	return randomCircle;
}

Platform MyDemoApp::generateRandomPlatform()
{
	Platform randomPlatform = Platform();

	randomPlatform.start.x = rand() % (width * 2) - width;
	randomPlatform.start.y = rand() % (height * 2) - height;
	randomPlatform.end.x = rand() % (width * 2) - width;
	randomPlatform.end.y = rand() % (height * 2) - height;
	randomPlatform.colour[0] = rand() % 255;
	randomPlatform.colour[1] = rand() % 255;
	randomPlatform.colour[2] = rand() % 255;

	return randomPlatform;
}


void MyDemoApp::display(void)
{
	Application::display();

	for (int i = 0; i < NUM_CIRCLES; i++)
		drawCircle(circles[i]);
	
	for (int i = 0; i < NUM_PLATFORMS; i++)
		drawPlatform(platforms[i]);

	glutSwapBuffers();
}

void MyDemoApp::update()
{
	Vector2 g = Vector2(0.0f, -9.81);
	float restitution = 0.9f;
	float duration = Application::timeInterval / 1000.0f;

	generateContacts();

	// Resolve contacts
	for (int c = 0; c < usedContacts; c++)
	{
		CircleCollisionResolver::resolve(contacts[c], duration, restitution);
	}

	// Apply additional forces
	for (int s = 0; s < NUM_CIRCLES; s++)
	{
		//circles[s].addForce(g * circles[s].mass()); //gravity
		circles[s].update(duration);
		//circles[s].resolveBorder(width, height);
	}
	
	Application::update();
}

void MyDemoApp::generateContacts()
{
	usedContacts = 0;

	for (int c = 0; c < NUM_CIRCLES; c++)
	{
		// circle-circle collisions
		for (int c2 = c + 1; c2 < NUM_CIRCLES; c2++)
		{
			if (usedContacts >= MAX_CONTACTS)
				return;

			Contact cContact = ContactGenerator::generate(&circles[c], &circles[c2]);
			if (cContact.separation < 0.0f)
			{
				*contacts[usedContacts] = cContact;
				usedContacts++;
			}
		}

		// circle-platform collisions
		for (int p = 0; p < NUM_PLATFORMS; p++)
		{
			if (usedContacts >= MAX_CONTACTS)
				return;

			Contact cContact = ContactGenerator::generate(&circles[c], &platforms[p]);
			if (cContact.separation < 0.0f)
			{
				*contacts[usedContacts] = cContact;
				usedContacts++;
			}
		}
	}
}

void MyDemoApp::drawCircle(CirclePhysics c)
{
	glPushMatrix();
	glTranslatef(c.position().x, c.position().y, 0);
	glColor3ub(c.colour('r'), c.colour('g'), c.colour('b'));
	glutSolidSphere(c.radius(), circleResolution, circleResolution);
	glPopMatrix();
}

void MyDemoApp::drawPlatform(PlatformPhysics p)
{
	glBegin(GL_LINES);
	glColor3ub(p.colour('r'), p.colour('g'), p.colour('b'));
	glVertex2f(p.start().x, p.start().y);
	glVertex2f(p.end().x, p.end().y);
	glEnd();
}
