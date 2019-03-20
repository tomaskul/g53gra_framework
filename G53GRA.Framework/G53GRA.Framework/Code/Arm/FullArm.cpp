//
// Created by ghost on 08/03/19.
//

#include "FullArm.h"

FullArm::FullArm(double arm_girth, bool isLeft)
	: m_arm_girth(arm_girth),
	m_is_left(isLeft) {
}

void FullArm::Display() {
	glPushMatrix();

	DrawFullArm();

	glPopMatrix();
}

void FullArm::DrawFullArm() {
	DrawUpperarm();
	DrawForearm();
}

void FullArm::DrawForearm() {
	glPushMatrix();

	if (m_is_left) {
		glTranslatef(15, 17, 0);
	}
	else {
		glTranslatef(-15, 17, 0);
	}

	// Ensure that forearm is longer than it is wide.
	glScalef(ARM_WIDTH_HEIGHT, 17, ARM_WIDTH_HEIGHT);

	// Draw the cube representing forearm of specified size.
	glutSolidCube(m_arm_girth);

	glPopMatrix();
}

void FullArm::DrawUpperarm() {
	glPushMatrix();

	// Move the arm into position.
	if (m_is_left) {
		glTranslatef(-SHOULDER_OFFSET, 25, 0);
		glRotatef(-ARM_BEND_ANGLE, 0, 0, 1);
	}
	else {
		glTranslatef(SHOULDER_OFFSET, 25, 0);
		glRotatef(ARM_BEND_ANGLE, 0, 0, 1);
	}

	glScalef(ARM_WIDTH_HEIGHT, 20, ARM_WIDTH_HEIGHT);

	glutSolidCube(m_arm_girth);

	glPopMatrix();
}
