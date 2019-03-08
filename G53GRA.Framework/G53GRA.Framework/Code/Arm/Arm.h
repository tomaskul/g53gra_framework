#include <Interface/DisplayableObject.h>

//
// Created by ghost on 08/03/19.
//
class Arm :
        public DisplayableObject
{
public:
    Arm(double arm_width);
    ~Arm(){}

    void Display();

private:
    void DrawArm();

    double m_arm_width;
};