#include <gl/glut.h>
#include "Application.h"


// Global variables ew yuck: any alternatives?
Application* app;
GLfloat timeInterval = 100.0f;


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

void timerFunc(int value)
{
	app->update();
	glutTimerFunc(timeInterval, timerFunc, 1);
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
	glutTimerFunc(timeInterval, timerFunc, 1);
	app->initGraphics();
	glutMainLoop();
}

