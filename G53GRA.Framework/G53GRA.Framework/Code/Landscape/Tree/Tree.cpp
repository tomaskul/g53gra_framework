//
// Created by ghost on 03/05/19.
//

#include "Tree.h"
#include <math.h>

#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))

Tree::Tree(float xTranslate, float yTranslate, float zTranslate)
    : m_xTranslate(xTranslate), m_yTranslate(yTranslate), m_zTranslate(zTranslate)
{
}

void Tree::Display() {
    this->DrawTrunk(m_xTranslate, m_yTranslate, m_zTranslate);
    this->DrawBranches(m_xTranslate, m_yTranslate, m_zTranslate);
}

void Tree::DrawTrunk(float xTranslate, float yTranslate, float zTranslate) {
    glPushMatrix();

    glColor3f(0.525490196f, 0.349019608f, 0.176470588f); // brown.

    glScalef(2.5, 7.5, 2.5);

    glTranslatef(xTranslate, yTranslate, zTranslate);

    glFrontFace(GL_CW);
    glBegin(GL_QUAD_STRIP);
    int degreesOfRotation = 10;
    for(int i = 0; i <= 360; i += degreesOfRotation){
        glVertex3f(Cos(i), +1, Sin(i));
        glVertex3f(Cos(i), -1, Sin(i));
    }
    glEnd();

    glPopMatrix();
}

void Tree::DrawBranches(float xTranslate, float yTranslate, float zTranslate) {
    glPushMatrix();

    glColor3f(0, 0.4, 0); // green.

    glScalef(2.5, 3, 2.5);

    glTranslatef(xTranslate, 9.5f + yTranslate, zTranslate);
    glutSolidSphere(7.5, 20, 15);

    glPopMatrix();
}
