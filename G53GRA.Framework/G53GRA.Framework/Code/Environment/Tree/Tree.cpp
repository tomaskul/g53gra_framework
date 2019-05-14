//
// Created by Tomas on 03/05/19.
//

#include "Tree.h"
#include <math.h>

Tree::Tree(float xTranslate, float yTranslate, float zTranslate, GLuint trunkTexture)
    : m_xTranslate(xTranslate), m_yTranslate(yTranslate), m_zTranslate(zTranslate), m_TrunkTex(trunkTexture)
{
}

void Tree::Display() {
    this->DrawTrunk(m_xTranslate, m_yTranslate, m_zTranslate);
    this->DrawBranches(m_xTranslate, m_yTranslate, m_zTranslate);
}

void Tree::DrawTrunk(float xTranslate, float yTranslate, float zTranslate) {
    glPushMatrix();

    //glColor3f(0.525490196f, 0.349019608f, 0.176470588f); // brown.

    glScalef(1.75, 6, 1.75);

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
    glFrontFace(GL_CCW);

    glPopMatrix();
}

void Tree::DrawBranches(float xTranslate, float yTranslate, float zTranslate) {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glDisable(GL_LIGHTING);

        glScalef(1.75, 1.75, 1.75);
        glTranslatef(xTranslate, 7.5f + yTranslate, zTranslate);
        glColor3f(1, 0.278431373f, 0.101960784f); // orange.
        glutSolidSphere(5, 20, 15);
    }
    glPopAttrib();
    glPopMatrix();


    glEnable(GL_LIGHTING);

    static GLfloat ambient[] = { .5f, 0.1f, 0.1f, 1.0f };
    static GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    GLfloat lightpos[] = { xTranslate, 7.5f + yTranslate, zTranslate, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glEnable(GL_LIGHT0);
}
