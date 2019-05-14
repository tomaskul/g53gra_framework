//
// Created by Tomas on 14/05/19.
//

#include "CometTail.h"

CometTail::CometTail(float alpha, float size) : Alpha(alpha), Size(size) {
}

void CometTail::Display() {
    glPushMatrix();

    glColor4f(0.701960784f, 0.701960784f, 0.701960784f, Alpha);
    glutSolidSphere(Size, Size, Size);

    glPopMatrix();
}
