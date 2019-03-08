//
// Created by ghost on 08/03/19.
//

#include "Forearm.h"

Forearm::Forearm(double forearm_girth, double forearm_length_scale = 3.0)
    : m_forearm_girth(forearm_girth),
    m_forearm_length_scale(forearm_length_scale)
{
}

void Forearm::Display() {
    glPushMatrix();

    DrawForearm();

    glPopMatrix();
}

void Forearm::DrawForearm() {
    // Ensure that forearm is longer than it is wide.
    glScalef(1, m_forearm_length_scale, 1);

    // Draw the cube representing forearm of specified size.
    glutSolidCube(m_forearm_girth);
}
