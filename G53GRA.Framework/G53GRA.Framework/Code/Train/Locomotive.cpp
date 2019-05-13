//
// Created by ghost on 20/04/19.
//

#include <iostream>
#include "Locomotive.h"

/// Modelled after Canadian Pacific 1989 EMD SD60M
Locomotive::Locomotive(){
};

void Locomotive::Display() {
   // glColor3f(1, 0.26f, 0.26f);
    glColor3f(1, 1, 1);

    glPushMatrix();

    glScalef(0.1f, 0.1f, 0.1f);

    // Rotate locomotive around track origin.
    glRotatef(m_rotationAngle, .0f, 10.0f, .0f);

    // Translate locomotive from track centre.
    glTranslatef(0.0, -10.0, -m_distanceFromOrigin);
    //glTranslatef(m_xTranslation, 0.0, m_zTranslation);

    this->DrawMainBody();
    this->DrawCabin();
    this->DrawNose();

    glPopMatrix();
}

void Locomotive::DrawMainBody() {
    glPushMatrix();

    glTranslatef(TOTAL_LENGTH + (CABIN_LENGTH*1.21f) + NOSE_LENGTH, 0, 0);
    glScalef(CABIN_LENGTH / 2, 1, 1);
    glutSolidCube(LOCOMOTIVE_BODY_LENGTH);

    glPopMatrix();
}

void Locomotive::DrawCabin() {
    glPushMatrix();

    glColor3f(1, 0.26f, 0.26f); // red
    glRotatef(-90, 0, 1, 0);
    this->DrawLocomotiveOctagon(CABIN_LENGTH);

    glPopMatrix();
}

void Locomotive::DrawNose() {
    glPushMatrix();

    glTranslatef(-(CABIN_LENGTH + NOSE_LENGTH), -(NOSE_HEIGHT*.65f), 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(TOTAL_WIDTH * .8f, TOTAL_HEIGHT * .35f, 1);
    this->DrawLocomotiveOctagon(NOSE_LENGTH);

    glPopMatrix();
}

void Locomotive::DrawLocomotiveOctagon(const GLfloat sideLength, GLfloat division) {
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

void Locomotive::Update(const double &deltaTime) {
    auto trackSpeed = 5.f;
    m_rotationAngle += trackSpeed * static_cast<float>(deltaTime);
    if (m_rotationAngle >= 360.0f){
        m_rotationAngle = m_rotationAngle - 360.0f;
    }


    m_trackRotation += trackSpeed * static_cast<float>(deltaTime);
    auto distance = trackSpeed * static_cast<float>(deltaTime);

    // Reset rotation if gone around the track.
    if (m_trackRotation >= 360.0f){
        m_trackRotation = m_trackRotation - 360.0f;
    }


    // TODO: fix the rotation angles.
    if (m_trackRotation >= 30.f && m_trackRotation <= 60.f) {
        // First rotation.
        m_rotationAngle = (m_trackRotation * 1.125f);

    }else if (m_trackRotation > 60.f && m_trackRotation < 120.f){

        m_rotationAngle = 90; // going down

    } else if (m_trackRotation >= 120.f && m_trackRotation <= 150.f) {
        // Second rotation.
        m_rotationAngle = (m_trackRotation * 1.125f);

    } else if (m_trackRotation > 150 && m_trackRotation < 210.f){

        m_rotationAngle = 180; // going right.

    } else if (m_trackRotation >= 210.f && m_trackRotation <= 240.f) {
        // Third rotation.
        m_rotationAngle = (m_trackRotation * 1.125f);

    } else if (m_trackRotation > 240.f && m_trackRotation < 300.f){

        m_rotationAngle = 270; // going up.

    } else if (m_trackRotation >= 300.f && m_trackRotation <= 330.f){
        // Fourth rotation.
        m_rotationAngle = (m_trackRotation * 1.125f);

    } else {
        m_rotationAngle = 360; // going left.
    }


    // Heading left, top part of the track.
    if (m_trackRotation <= 45.f || m_trackRotation >= 315.f){
        m_xTranslation -= distance;
        return;
    }

    // Heading down, left part of the track.
    if (m_trackRotation <= 135.f){
        m_zTranslation += distance;
        return;
    }

    // Heading right, bottom of the track.
    if (m_trackRotation <= 225.f){
        m_xTranslation += distance;
        return;
    }

    // Heading up, right of the track.
    if (m_trackRotation <= 315.f){
        m_zTranslation -= distance;
        return;
    }
}
