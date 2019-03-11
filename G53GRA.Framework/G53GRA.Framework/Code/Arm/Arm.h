#include <Interface/DisplayableObject.h>

//
// Created by ghost on 08/03/19.
//
class Arm :
        public DisplayableObject
{
public:
    /**
     * Constructs a basic, rectangular (upper) arm.
     * @param arm_width - Girth of the arm cube.
     * @param arm_length_scale - Scale representing arm length to girth ratio. 3.5 by default.
     */
    Arm(double arm_width, double arm_length_scale = 3.5);
    ~Arm(){}

    void Display();

private:
    void DrawArm();

    double m_arm_width;
    double m_arm_length_scale;
};