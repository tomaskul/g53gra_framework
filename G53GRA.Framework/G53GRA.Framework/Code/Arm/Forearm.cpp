//
// Created by ghost on 08/03/19.
//

#include "Forearm.h"

Forearm::Forearm(double forearm_width) : m_forearm_width(forearm_width) {

}

void Forearm::Display() {
    glPushMatrix();

    DrawForearm();

    glPopMatrix();
}

void Forearm::DrawForearm() {
    // Let's presume that forearm is 3 times the width.
    glScalef(1, 3, 1);
    glutSolidCube(m_forearm_width);
}
