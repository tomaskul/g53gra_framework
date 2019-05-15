//
// Created by Tomas on 14/05/19.
//

#include "Star.h"

Star::Star(float xTranslate, float yTranslate, float zTranslate) : m_xTranslate(xTranslate), m_yTranslate(yTranslate),
    m_zTranslate(zTranslate)
{
}

void Star::Display() {
    glPushMatrix();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);

    glScalef(1.75, 1.75, 1.75);
    glTranslatef(m_xTranslate, m_yTranslate, m_zTranslate);
    glColor3f(1, 0.278431373f, 0.101960784f); // orange.
    glutSolidSphere(5, 20, 15);

    glPopAttrib();
    glPopMatrix();

    glEnable(GL_LIGHTING);
    static GLfloat ambient[] = { .5f, 0.1f, 0.1f, 1.0f };
    static GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    GLfloat lightpos[] = { m_xTranslate, m_yTranslate, m_zTranslate, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glEnable(GL_LIGHT0);
}
