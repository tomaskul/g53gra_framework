//
// Created by Tomas on 14/05/19.
//

#include "Comet.h"

Comet::Comet(float size, float speed, float tailLength) : m_cometSize(size), m_cometSpeed(speed), m_tailLength(tailLength)
{
    m_tail.reserve(tailLength + 1);
    for (auto i = 1; i < tailLength; i++){
        m_tail.push_back(new CometTail(static_cast<float>((1 * size) / i / 1.2), static_cast<float>((1 / size) * i*5)));
    }
}

void Comet::Display() {
    glPushMatrix();

    // Scale the matrix to give comet elongated look.
    glScalef(0.25, 0.125, 0.125);

    glRotatef(30.f, 0, 1, 0);

    glTranslatef(m_xTranslate, m_yTranslate, m_zTranslate);

    // Colour comet grey.
    glColor3f(0.701960784f, 0.701960784f, 0.701960784f);

    // Draw misshapen sphere to act as the comets body.
    glutSolidSphere(m_cometSize, static_cast<GLint>(m_cometSize), static_cast<GLint>(m_cometSize));


    // Draw the tail.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    for (auto &i : m_tail) {
        glTranslatef(-i->Size, i->Size, 0);
        i->Display();
    }

    glDisable(GL_BLEND);
    glPopMatrix();
}

void Comet::Update(const double &deltaTime) {
    auto distance = m_cometSpeed * static_cast<float>(deltaTime);
    m_xTranslate += distance;
    m_yTranslate -= distance;
}
