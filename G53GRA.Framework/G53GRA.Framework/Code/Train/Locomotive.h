//
// Created by ghost on 20/04/19.
//

#ifndef G53GRA_FRAMEWORK_LOCOMOTIVE_H
#define G53GRA_FRAMEWORK_LOCOMOTIVE_H


#include <Interface/DisplayableObject.h>
#include <Interface/Animation.h>

class Locomotive :
        public DisplayableObject,
        public Animation
{
public:
    Locomotive();
    ~Locomotive(){};

    void Display();
    void Update(const double& deltaTime);

private:
    void DrawMainBody();
    void DrawCabin();
    void DrawNose();

    void DrawLocomotiveOctagon(const GLfloat sideLength, GLfloat division = 2);

    // Locomotive dimensions in meters.
    float TOTAL_HEIGHT = 4.76;
    float TOTAL_WIDTH = 3.12;
    float TOTAL_LENGTH = 21.69;

    float LOCOMOTIVE_BODY_LENGTH = 14.46; // 2/3 of total length.

    float CABIN_LENGTH = 7.23; // 3rd of total length.

    float NOSE_HEIGHT = 3.808; // 4/5th of total height.
    float NOSE_LENGTH = 2.892; // 2/5 of cabin length.

    GLfloat m_rotationAngle = 1.0f;
    float m_distanceFromOrigin = 300.0f;
};


#endif //G53GRA_FRAMEWORK_LOCOMOTIVE_H
