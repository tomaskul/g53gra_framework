#include "MyScene.h"

#include <Demos/Triangle/Triangle.h>
#include <Demos/Triforce/Triforce.h>

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Demos

	/* Triangle
	Triangle *t = new Triangle();
	AddObjectToScene(t);
    */

	/* Triforce
	Triforce *triforce = new Triforce();
	AddObjectToScene(triforce);
	*/
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
