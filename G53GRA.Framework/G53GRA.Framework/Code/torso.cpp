#include "torso.h"


torso::torso()
{
}


torso::~torso()
{
}

void torso::Display()
{
	glPushMatrix();                                         // save transformation state
	glPushAttrib(GL_ALL_ATTRIB_BITS);                   // save style attributes (and more)
	glColor3f(0.5f, 0.5f, 0.5f);                        // colour horse grey

	// Project from Object Space to World Space
	glTranslatef(pos[0], pos[1], pos[2]);               // Position
	glScalef(scale[0], scale[1], scale[2]);             // Scale
	glRotatef(rotation[1], 0.f, 1.f, 0.f);              // Set orientation (Y)
	glRotatef(rotation[2], 0.f, 0.f, 1.f);              // Set orientation (Z)
	glRotatef(rotation[0], 1.f, 0.f, 0.f);              // Set orientation (X)

	drawRobot();                                        // draw Robot

	glPopAttrib();                                      // restore style attributes
	glPopMatrix();
}

void torso::drawRobot()
{
	glTranslatef(0.f, 20.f, 0.f);
	glPushMatrix();
	drawTorso();
	glPushMatrix();
	glTranslatef(0.f, 15.f, 0.f);	//move to top of torso
	drawNeck();
	glPushMatrix();
	glTranslatef(0.f, 5.f, 0.f);
	drawHead(8.0f, 8.0f, 8.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}

void torso::drawTorso()
{
	box(10.0f, 20.0f, 10.0f);
}

void torso::box(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);
	glutSolidCube(1.f);
	glPopMatrix();
}

void torso::drawNeck()
{
	box(5.0f, 10.f, 5.f);
}

void torso::drawHead(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);
	glutSolidSphere(1.f, 10, 10);
	glPopMatrix();
}
