//
// Created by ghost on 22/03/19.
//

#include "Leg.h"

Leg::Leg(double legGirth, bool isLeft)
        : m_leg_girth(legGirth),
          m_is_left(isLeft) {
}

void Leg::Display() {
    glPushMatrix();

    DrawFullLeg();

    glPopMatrix();
}

void Leg::DrawFullLeg() {
    DrawUpperLeg();
    DrawLowerLeg();
}

void Leg::DrawUpperLeg() {
    glPushMatrix();

    // Move leg up to the torso.
    glTranslatef(0, 5, 0);

    if (m_is_left) {
        // Move towards the edge of the torso.
        glTranslatef(-UPPER_LEG_OFFSET, 0, 0);
        glRotatef(-LEG_BEND_ANGLE, 0, 0, 1);
    } else {
        // Move towards the edge of the torso.
        glTranslatef(UPPER_LEG_OFFSET, 0, 0);
        glRotatef(LEG_BEND_ANGLE, 0, 0, 1);
    }

    glScalef(LEG_WIDTH_HEIGHT, 20, LEG_WIDTH_HEIGHT);
    glutSolidCube(m_leg_girth);

    glPopMatrix();
}

void Leg::DrawLowerLeg() {
    glPushMatrix();

    if (m_is_left) {
        glTranslatef(-8.5, -7, 0);
    } else {
        glTranslatef(8.5, -7, 0);
    }

    // Ensure that forearm is longer than it is wide.
    glScalef(LEG_WIDTH_HEIGHT, 17, LEG_WIDTH_HEIGHT);

    // Draw the cube representing forearm of specified size.
    glutSolidCube(m_leg_girth);


    glPopMatrix();
}
