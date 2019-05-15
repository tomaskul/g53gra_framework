#include <World/Skybox.h>
#include <Environment/Comet/Comet.h>
#include <Environment/Spaceship/Spaceship.h>
#include <Environment/Star/Star.h>
#include <Environment/Spaceship/Spaceship.h>
#include <Environment/Robot/Robot.h>
#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
}

void MyScene::Initialise()
{
	const std::string textureDirectory = "";

	// Initialise objects.
	auto *skybox = new Skybox(textureDirectory + "skybox/");
	auto *spaceship = new Spaceship();
	auto *star = new Star(0, 0, 0);
	auto *comet = new Comet(5, 2, 15);
	auto *robot = new Robot(20.0f);

	// Add to scene.
	AddObjectToScene(skybox);
	AddObjectToScene(spaceship);
	AddObjectToScene(star);
    AddObjectToScene(robot);
	AddObjectToScene(comet);

	glClearColor(.0f, .0f, .0f, 0.5f);

    //glClearColor(1.0f, 0.5f, 0.25f, 1.0f);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
