//
// Created by ghost on 03/05/19.
//

#include "Tree.h"
#include <math.h>

Tree::Tree(float xTranslate, float yTranslate, float zTranslate, GLuint trunkTexture, GLuint leavesTexture)
    : m_xTranslate(xTranslate), m_yTranslate(yTranslate), m_zTranslate(zTranslate), m_TrunkTex(trunkTexture),
    m_LeavesTex(leavesTexture)
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
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_TrunkTex);
    glBegin(GL_QUAD_STRIP);
    int degreesOfRotation = 10;
    float textureCoordIncrement = 1.0 / static_cast<float>(360/degreesOfRotation);
    for(int i = 0; i <= 360; i += degreesOfRotation){
        auto c = static_cast<float>(cos(degreesOfRotation * i));
        auto s = static_cast<float>(sin(degreesOfRotation * i));

        glTexCoord2f(textureCoordIncrement * i, 0);
        glVertex3f(c, -1, s);
        glTexCoord2f(textureCoordIncrement * i, 1.0);
        glVertex3f(c, 1, s);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void Tree::DrawBranches(float xTranslate, float yTranslate, float zTranslate) {
    glPushMatrix();

    glColor3f(0, 0.4, 0); // green.

    glScalef(2.5, 3, 2.5);

    glTranslatef(xTranslate, 9.5f + yTranslate, zTranslate);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_LeavesTex);
    glutSolidSphere(7.5, 20, 15);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}
