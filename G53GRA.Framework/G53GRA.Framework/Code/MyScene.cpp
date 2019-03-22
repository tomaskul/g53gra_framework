#include <Arm/FullArm.h>
#include <torso.h>
#include <Leg/Leg.h>
#include "MyScene.h"
#include "Floor.h"


MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glEnable(GL_NORMALIZE);
	setLighting();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Robot.
	FullArm *leftArm = new FullArm(0.75, true);
	FullArm *rightArm = new FullArm(0.75, false);
	AddObjectToScene(leftArm);
	AddObjectToScene(rightArm);
  
	glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
	torso *c = new torso();
	AddObjectToScene(c);

	Leg *leftLeg = new Leg(0.75, true);
	Leg *rightLeg = new Leg(0.75, false);
	AddObjectToScene(leftLeg);
	AddObjectToScene(rightLeg);

	// Lighting
	Floor *flooring = new Floor();
	flooring->size(5.0f);
	AddObjectToScene(flooring);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}

void MyScene::setLighting()
{
	/*
	float redAmbient[] = {0.4f,0.f,0.f,1.f};
	float redDiffuse[] = { 1.f,0.f,0.f,1.f };
	float redSpecular[] = { 1.f,0.f,0.f,1.f };

	float blueAmbient[] = { 0.f,0.f,0.4f,1.f };
	float blueDiffuse[] = { 0.f,0.f,1.f,1.f };
	float blueSpecular[] = { 0.f,0.f,1.f,1.f };

	//last value w is 1 as the light is positional. 
	float redLightPosition[] = {-15.f,0.f,0.f,1.f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, redAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, redDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, redSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, redLightPosition);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);

	//last value w is 1 as the light is positional. 
	float blueLightPosition[] = { 15.f,0.f,0.f,1.f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, blueAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blueDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, blueSpecular);
	glLightfv(GL_LIGHT1, GL_POSITION, blueLightPosition);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5f);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
*/

}
