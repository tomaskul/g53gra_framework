//
// Created by ghost on 20/04/19.
//

#ifndef G53GRA_FRAMEWORK_LOCOMOTIVE_H
#define G53GRA_FRAMEWORK_LOCOMOTIVE_H


#include <Interface/DisplayableObject.h>

class Locomotive
        : public DisplayableObject {

public:
    Locomotive();
    ~Locomotive(){};

    void Display();

private:
    void DrawMainBody();
    void DrawCabin();
    void DrawNose();

    void DrawLocomotiveOctagon(const GLfloat sideLength, GLfloat division = 2);

    // Locomotive dimensions in meters.
    float TOTAL_HEIGHT = 4.76;
    float TOTAL_WIDTH = 3.12;
    float TOTAL_LENGTH = 21.69;

    // 5th of total length.
    float CABIN_LENGTH = 3.472;
    float NOSE_LENGTH = 0.868;

    float LOCOMOTIVE_BODY_LENGTH = 17.35;
};


#endif //G53GRA_FRAMEWORK_LOCOMOTIVE_H
