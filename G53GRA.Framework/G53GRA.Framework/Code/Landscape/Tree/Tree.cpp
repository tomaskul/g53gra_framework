//
// Created by ghost on 03/05/19.
//

#include "Tree.h"
#include <math.h>

#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))

Tree::Tree() {
}

void Tree::Display() {
    this->DrawTrunk();
    //this->DrawTrunk(5);
    //this->DrawTrunk(10, 0, 5);
    this->DrawBranches();
}

void Tree::DrawTrunk(float xTranslate, float yTranslate, float zTranslate) {
    glPushMatrix();

    // Colour if brown.
    glColor3f(0.525490196, 0.349019608, 0.176470588);

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

void Tree::DrawBranches() {
    glPushMatrix();

    // Green leaves.
    glColor3f(0, 0.4, 0);

    glTranslatef(0, 22, 0);
    glScalef(5, 3, 5);
    glutSolidSphere(5, 15, 15);

    glPopMatrix();
}
