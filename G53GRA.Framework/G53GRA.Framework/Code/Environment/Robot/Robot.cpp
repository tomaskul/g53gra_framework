//
// Created by Tomas on 14/05/19.
//

#include <cmath>
#include "Robot.h"

Robot::Robot(float spaceshipSpeed) : m_spaceshipSpeed(spaceshipSpeed) {
}

void Robot::Display() {
    //if (!m_drawAstraunaut) { return; }

    glPushMatrix();

    glScalef(.1f, .1f, .1f);
    glRotatef(m_spaceshipRotationAngle, .0f, 10.0f, .0f);
    glTranslatef(.0f, -10.0f, -500.0f);

    auto size = 15.0f;
    auto fourth = size / 4;

    // Head.
    glutSolidCube(fourth);

    glScalef(.125f, .15f, .125f);
    glTranslatef(0, -(size - fourth - (fourth/.15)), 0);

    // Main body.
    glutSolidCube(size);

    glPopMatrix();
}

void Robot::Update(const double &deltaTime) {
    auto change = m_spaceshipSpeed * static_cast<float>(deltaTime);

    m_spaceshipRotationAngle += change;
    m_totalRotationAngle += change;

    if (m_spaceshipRotationAngle >= 360.0f){
        m_spaceshipRotationAngle = m_spaceshipRotationAngle - 360.0f;
    }

    if (m_totalRotationAngle >= 236.0f || m_totalRotationAngle <= 237.0f){
        m_drawAstraunaut = true;

        // Robot leaves spaceship.
        // TODO: Adjust translation.
    }

    if (m_totalRotationAngle >= 596.0f || m_totalRotationAngle <= 597.0f){
        m_drawAstraunaut = true;

        // Robot leaves comet.
        // TODO: Adjust translation.
    }
}