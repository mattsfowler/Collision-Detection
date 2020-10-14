#include "MyDemoApp.h"

//extern Application* getApplication(); 
extern void runGLApp(Application* application, int argc, char* argv[]);

int main(int argc, char* argv[])
{
	Application* app = new MyDemoApp();
	runGLApp(app, argc, argv);
	delete app;
	return 0;
}