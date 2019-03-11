#include <Arm/FullArm.h>
#include <torso.h>
#include "MyScene.h"


MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	FullArm *fullArm = new FullArm(0.75, 7.5);
	AddObjectToScene(fullArm);
  
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	torso *c = new torso();
	AddObjectToScene(c);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
