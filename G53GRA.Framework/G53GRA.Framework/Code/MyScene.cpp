#include <Train/Locomotive.h>
#include <Landscape/Tree/Tree.h>
#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Locomotive *locomotive = new Locomotive();
	AddObjectToScene(locomotive);

	//Tree *tree = new Tree();
	//AddObjectToScene(tree);

	glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
