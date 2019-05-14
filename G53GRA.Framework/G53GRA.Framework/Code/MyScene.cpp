#include <Environment/Tree/Tree.h>
#include <World/Skybox.h>
#include <Environment/Comet/Comet.h>
#include <Spaceship/Spaceship.h>
#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
}

void MyScene::Initialise()
{
	const std::string textureDirectory = "";

	auto *skybox = new Skybox(textureDirectory + "skybox/");
	AddObjectToScene(skybox);

	auto *spaceship = new Spaceship();
	AddObjectToScene(spaceship);


	GLuint trunk = Scene::GetTexture(textureDirectory + "TexturesCom_BarkDecidious0026_S.bmp");
	Tree *tree = new Tree(0, 0, 0, trunk);
	AddObjectToScene(tree);

	auto *comet = new Comet(5, 2, 15);
	AddObjectToScene(comet);

	glClearColor(.0f, .0f, .0f, 0.5f);
    //glClearColor(1.0f, 0.5f, 0.25f, 1.0f);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
