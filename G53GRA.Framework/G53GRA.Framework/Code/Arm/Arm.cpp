//
// Created by ghost on 08/03/19.
//

#include "Arm.h"

Arm::Arm(double arm_width, double arm_length_scale)
    : m_arm_width(arm_width), m_arm_length_scale(arm_length_scale)
{
}

void Arm::Display() {
    glPushMatrix();

    DrawArm();

    glPopMatrix();
}

void Arm::DrawArm() {
    // Move the arm into position.
    glTranslated(50, 125, 0);

    glRotatef(-45.0, 0, 0, 1);

    glScalef(1, m_arm_length_scale, 1);
    glutSolidCube(m_arm_width);
}
