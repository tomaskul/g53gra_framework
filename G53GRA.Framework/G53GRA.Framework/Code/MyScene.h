#pragma once

#include "../Framework/Engine/Scene.h"
#include "torso.h"
#include "Animation.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};
	void setLighting();

private:
	void Initialise();
	void Projection();
	

};