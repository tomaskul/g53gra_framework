#ifndef ___Horse__
#define ___Horse__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"

class torso:
	public DisplayableObject
{
public:
	torso();
	~torso();
	void Display();
private:
	void drawRobot();
	void drawTorso();
	void box(float sx, float sy, float sz); // draw a scaled glutSolidCube (forms components of body)
	void drawNeck();
	void drawHead(float sx, float sy, float sz);
};

#endif