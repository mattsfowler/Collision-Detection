#include <gl/glut.h>
#include "Application.h"


void Application::initGraphics()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void Application::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void Application::update()
{
    glutPostRedisplay();
}


void Application::resize(int width, int height)
{
    GLfloat viewportRange = 100.0;
    GLfloat top = viewportRange;
    GLfloat right = viewportRange;

    // Stop deformation - stretch to fit to shortest window axis, then expand other axis to fill window
    if (width > height) right = right * ((GLfloat)width / height);
    else if (height > width) top = top * ((GLfloat)height / width);
    GLfloat bottom = -top;
    GLfloat left = -right;

    Application::width = right;
    Application::height = top;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, -viewportRange, viewportRange); //clipping range
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}