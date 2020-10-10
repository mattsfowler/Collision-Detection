#include <gl/glut.h>
#include "Application.h"


// Global variables ew yuck: any alternatives?
Application* app;
GLfloat timeInterval = 1000.0f / 60.0f;   // 60fps


void display(void)
{
	app->display();
}

void createWindow(const char* title)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow(title);
}

void update(int value)
{
	app->update();
	glutTimerFunc(timeInterval, update, 1);
}

void resize(int width, int height)
{
	app->resize(width, height);
}

void runGLApp(Application* application, int argc, char* argv[])
{
	glutInit(&argc, argv);
	app = application;
	createWindow("Sphere");
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	app->initGraphics();
	app->setTimeInterval(timeInterval);
	glutTimerFunc(timeInterval, update, 1);
	glutMainLoop();
}

