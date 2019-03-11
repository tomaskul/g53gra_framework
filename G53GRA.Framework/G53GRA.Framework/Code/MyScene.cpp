#include "MyScene.h"


MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	torso *c = new torso();
	AddObjectToScene(c);

	//Cube *mycube = new Cube();
	//AddObjectToScene(mycube);

}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
