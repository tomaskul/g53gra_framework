//
// Created by Tomas on 14/05/19.
//

#include <cmath>
#include <iostream>
#include "Robot.h"

Robot::Robot(float spaceshipSpeed) : m_spaceshipSpeed(spaceshipSpeed) {
}

void Robot::Display() {
    if (!m_drawAstraunaut) { return; }

    glPushMatrix();

    glScalef(.1f, .1f, .1f);
    glRotatef(m_spaceshipRotationAngle, .0f, 10.0f, .0f);
    glTranslatef(m_xTranslate, m_yTranslate, m_zTranslate);

    auto size = 15.0f;
    auto fourth = size / 4;

    glColor4f(1.0, 1.0, 1.0, 1.0);

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
    m_totalRotationAngle += change;

    if (m_spaceshipRotationAngle >= 360.0f){
        m_spaceshipRotationAngle = m_spaceshipRotationAngle - 360.0f;
    }

    if (m_totalRotationAngle >= 230.0f && m_totalRotationAngle <= 231.0f){
        m_drawAstraunaut = true;
        m_stage = 1;
    }

    if (m_totalRotationAngle >= 596.0f && m_totalRotationAngle <= 597.0f){
        //Descend.
        m_stage = 2;
    }

    if (m_totalRotationAngle >= 610.0f && m_totalRotationAngle <= 611.0f){
        // Return.
        m_stage = 3;
    }

    if (m_totalRotationAngle >= 963.0f && m_totalRotationAngle <= 964.0f){
        // Sucked into the star
        m_stage = 4;
    }

    if (m_totalRotationAngle >= 1890.0f && m_totalRotationAngle <= 1891.0f){
        m_drawAstraunaut = false;
    }

    if (m_stage == 0){
        m_spaceshipRotationAngle += change;
        return;
    } else if (m_stage == 1){
        // Robot leaves spaceship.

        m_xTranslate -= change * 0.2;
        m_yTranslate -= change * 0.15;
        m_zTranslate -= change * 0.15;
        return;

    } else if (m_stage == 2){
        // Robot leaves comets tail.
        m_xTranslate += change * 0.25;
        m_yTranslate += change * 0.2;
        m_zTranslate += change * 0.2;
        return;

    } else if (m_stage == 3){
        // Move up into catchment area.
        m_yTranslate += change * 0.15;

        return;
    } else if (m_stage == 4){
        // Sucked into the star.

        m_zTranslate += change * 0.5;
    }
}