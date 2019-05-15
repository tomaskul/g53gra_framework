//
// Created by Tomas on 20/04/19.
//

#include <iostream>
#include "Spaceship.h"

/// Modelled after Canadian Pacific 1989 EMD SD60M
Spaceship::Spaceship(){
};

void Spaceship::Display() {
    glColor3f(1, 0.26f, 0.26f);

    glPushMatrix();

    glScalef(0.1f, 0.1f, 0.1f);

    // Rotate spaceship around track origin.
    glRotatef(m_rotationAngle, .0f, 10.0f, .0f);

    // Translate spaceship from track centre.
    glTranslatef(.0f, -10.0f, -500.0f);

    this->DrawMainBody();
    this->DrawCabin();
    this->DrawNose();

    glPopMatrix();
}

void Spaceship::DrawMainBody() {
    glPushMatrix();

    glTranslatef(TOTAL_LENGTH + (CABIN_LENGTH*1.21f) + NOSE_LENGTH, 0, 0);
    glScalef(CABIN_LENGTH / 2, 1, 1);
    glutSolidCube(CONTROL_CENTRE_BODY_LENGTH);

    glPopMatrix();
}

void Spaceship::DrawCabin() {
    glPushMatrix();

    glColor3f(1, 0.26f, 0.26f); // red
    glRotatef(-90, 0, 1, 0);
    this->DrawShipOctagon(CABIN_LENGTH);

    glPopMatrix();
}

void Spaceship::DrawNose() {
    glPushMatrix();

    glTranslatef(-(CABIN_LENGTH + NOSE_LENGTH), -(NOSE_HEIGHT*.65f), 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(TOTAL_WIDTH * .8f, TOTAL_HEIGHT * .35f, 1);
    this->DrawShipOctagon(NOSE_LENGTH);

    glPopMatrix();
}

void Spaceship::DrawShipOctagon(const GLfloat sideLength, GLfloat division) {
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    // Top face (y = 1.0f)
    glPushMatrix();
    glTranslatef(0, sideLength / division, 0);
    glBegin(GL_QUADS);
    glVertex3f(sideLength / division, sideLength / division, -sideLength);
    glVertex3f(-sideLength / division, sideLength / division, -sideLength);
    glVertex3f(-sideLength / division, sideLength / division, sideLength);
    glVertex3f(sideLength / division, sideLength / division, sideLength);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    // Bottom face (y = -1.0f)
    glVertex3f(sideLength, -sideLength, sideLength);
    glVertex3f(-sideLength, -sideLength, sideLength);
    glVertex3f(-sideLength, -sideLength, -sideLength);
    glVertex3f(sideLength, -sideLength, -sideLength);

    // Front face  (z = 1.0f)
    glVertex3f(sideLength, sideLength / division, sideLength); // top right
    glVertex3f(-sideLength, sideLength / division, sideLength); // top left
    glVertex3f(-sideLength, -sideLength, sideLength); // bottom left
    glVertex3f(sideLength, -sideLength, sideLength); // bottom right
    glEnd();
    glPopMatrix();

    // Front face - upper bit
    glPushMatrix();
    glTranslatef(0, sideLength / division, 0);
    glBegin(GL_QUADS);
    glVertex3f(sideLength / division, sideLength / division, sideLength); // top right
    glVertex3f(-sideLength / division, sideLength / division, sideLength); // top left
    glVertex3f(-sideLength, 0, sideLength); // bottom left
    glVertex3f(sideLength, 0, sideLength); // bottom right
    glEnd();
    glPopMatrix();

    // Back face (z = -1.0f)
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(sideLength, -sideLength, -sideLength); // bottom left
    glVertex3f(-sideLength, -sideLength, -sideLength); // bottom right
    glVertex3f(-sideLength, sideLength / division, -sideLength); // top right
    glVertex3f(sideLength, sideLength / division, -sideLength); // top left
    glEnd();
    glPopMatrix();

    // Back face - upper bit
    glPushMatrix();
    glTranslatef(0, sideLength / division, 0);
    glBegin(GL_QUADS);
    glVertex3f(sideLength, 0, -sideLength); // bottom left
    glVertex3f(-sideLength, 0, -sideLength); // bottom right
    glVertex3f(-sideLength / division, sideLength / division, -sideLength); // top right
    glVertex3f(sideLength / division, sideLength / division, -sideLength); // top left
    glEnd();
    glPopMatrix();

    // Left face (x = -1.0f)
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-sideLength, sideLength / division, sideLength); // top right
    glVertex3f(-sideLength, sideLength / division, -sideLength); // top left
    glVertex3f(-sideLength, -sideLength, -sideLength); // bottom left
    glVertex3f(-sideLength, -sideLength, sideLength); // bottom right
    glEnd();
    glPopMatrix();

    // Left corner face
    glPushMatrix();
    glTranslatef(0, sideLength / division, 0);
    glBegin(GL_QUADS);
    glVertex3f(-(sideLength / division), sideLength / division, sideLength); // top right
    glVertex3f(-(sideLength / division), sideLength / division, -sideLength); // top left
    glVertex3f(-sideLength, 0, -sideLength); // bottom left
    glVertex3f(-sideLength, 0, sideLength); // bottom right
    glEnd();
    glPopMatrix();

    // Right face (x = 1.0f)
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(sideLength, sideLength / division, -sideLength); // top right
    glVertex3f(sideLength, sideLength / division, sideLength); // top left
    glVertex3f(sideLength, -sideLength, sideLength); // bottom left
    glVertex3f(sideLength, -sideLength, -sideLength); // bottom right
    glEnd();
    glPopMatrix();

    // Right corner face
    glPushMatrix();
    glTranslatef(0, sideLength / division, 0);
    glBegin(GL_QUADS);
    glVertex3f(sideLength / division, sideLength / division, -sideLength); // top right
    glVertex3f(sideLength / division, sideLength / division, sideLength); // top left
    glVertex3f(sideLength, 0, sideLength); // bottom left
    glVertex3f(sideLength, 0, -sideLength); // bottom right
    glEnd();
    glPopMatrix();
}

void Spaceship::Update(const double &deltaTime) {
    auto trackSpeed = 20.f;
    m_rotationAngle += trackSpeed * static_cast<float>(deltaTime);
    if (m_rotationAngle >= 360.0f){
        m_rotationAngle = m_rotationAngle - 360.0f;
    }
}
