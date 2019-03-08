//
// Created by ghost on 08/03/19.
//

#include "Arm.h"

Arm::Arm(double arm_width) : m_arm_width(arm_width) {

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

    // Let's presume that arm is 3.5 times it's width.
    glScalef(1, 3.5, 1);
    glutSolidCube(m_arm_width);
}
