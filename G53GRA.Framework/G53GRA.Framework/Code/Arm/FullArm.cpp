//
// Created by ghost on 08/03/19.
//

#include "FullArm.h"

FullArm::FullArm(double forearm_girth, double arm_girth, bool isLeft, double forearm_length_scale, double arm_length_scale)
        : m_forearm_girth(forearm_girth),
          m_arm_girth(arm_girth),
          m_is_left(isLeft),
          m_forearm_length_scale(forearm_length_scale),
          m_arm_length_scale(arm_length_scale) {
}

void FullArm::Display() {
    glPushMatrix();

    DrawFullArm();

    glPopMatrix();
}

void FullArm::DrawFullArm() {
    DrawUpperarm();
    //DrawForearm();
}

void FullArm::DrawForearm() {
    glPushMatrix();



    glTranslatef(-15, 0, 0);

    // Ensure that forearm is longer than it is wide.
    glScalef(1, m_forearm_length_scale, 1);

    // Draw the cube representing forearm of specified size.
    glutSolidCube(m_forearm_girth);

    glPopMatrix();
}

void FullArm::DrawUpperarm() {
    glPushMatrix();

    // Move the arm into position.
    if (m_is_left){
        glTranslatef(-SHOULDER_OFFSET, 20, 0);
        glRotatef(-ARM_BEND_ANGLE, 0, 0, 1);
    }else{
        glTranslatef(SHOULDER_OFFSET, 20, 0);
        glRotatef(ARM_BEND_ANGLE, 0, 0, 1);
    }

    glScalef(5, 20, 5);

    glutSolidCube(m_forearm_girth);

    glPopMatrix();
}
