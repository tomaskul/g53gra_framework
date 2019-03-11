//
// Created by ghost on 08/03/19.
//

#include <Interface/DisplayableObject.h>

class FullArm :
        public DisplayableObject
{
public:
    FullArm(double forearm_girth, double arm_girth, bool isLeft, double forearm_length_scale = 3.0, double arm_length_scale = 2.0);
    ~FullArm(){};

    void Display();

private:
    void DrawFullArm();

    void DrawForearm();
    void DrawUpperarm();

    const double SHOULDER_OFFSET = 9;
    const double ARM_BEND_ANGLE = 45;

    double m_forearm_girth;
    double m_forearm_length_scale;
    bool m_is_left;
    double m_arm_girth;
    double m_arm_length_scale;
};