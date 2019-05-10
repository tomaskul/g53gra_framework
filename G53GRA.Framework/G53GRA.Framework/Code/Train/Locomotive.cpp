//
// Created by ghost on 20/04/19.
//

#include <iostream>
#include "Locomotive.h"

/// Modelled after Canadian Pacific 1989 EMD SD60M
Locomotive::Locomotive(){
};

void Locomotive::Display() {
    glColor3f(1, 0.26f, 0.26f); // rgb
    //this->DrawLocomotiveOctagon(100);
    this->DrawMainBody();
    this->DrawCabin();
    this->DrawNose();
}

void Locomotive::DrawMainBody() {
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(LOCOMOTIVE_BODY_LENGTH / TOTAL_WIDTH, TOTAL_HEIGHT / TOTAL_WIDTH, 1); // x, y, z
    glutSolidCube(LOCOMOTIVE_BODY_LENGTH);
    glPopMatrix();
}

void Locomotive::DrawCabin() {
    glPushMatrix();
    // Colour red.
    glColor3f(1, 0.26f, 0.26f); // rgb

    //glScalef(CABIN_LENGTH / TOTAL_WIDTH, TOTAL_HEIGHT / TOTAL_WIDTH, 1); // xyz
    glTranslatef(-((LOCOMOTIVE_BODY_LENGTH * TOTAL_WIDTH) - CABIN_LENGTH),0,0);

    glScalef(2, TOTAL_HEIGHT, CABIN_LENGTH);

    glRotatef(-90, 0, 1, 0);
    this->DrawLocomotiveOctagon(CABIN_LENGTH);

    glPopMatrix();
}


void Locomotive::DrawNose() {
    glPushMatrix();
    glColor3f(1, 1, 1);

    glTranslatef(-(TOTAL_LENGTH * 3), 0, 0);
    //glScalef(TOTAL_LENGTH / TOTAL_WIDTH, TOTAL_HEIGHT / CABIN_LENGTH, 1); // xyz
    //glutSolidCube(TOTAL_WIDTH);

    glScalef(2, TOTAL_HEIGHT / 2, CABIN_LENGTH / 2);

    glRotatef(-90, 0, 1, 0);
    this->DrawLocomotiveOctagon(TOTAL_WIDTH);

    glPopMatrix();
}

void Locomotive::DrawLocomotiveOctagon(const GLfloat sideLength, GLfloat division) {
    // Define vertices in counter-clockwise (CCW) order with normal pointing out

    // TODO: investigate whether bottom faces are being drawn correctly.

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
    //glColor3f(1, 0, 1);

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
