//
// Created by ghost on 08/03/19.
//

#include <Interface/DisplayableObject.h>

class FullArm :
        public DisplayableObject
{
public:
    FullArm(double forearm_girth, double arm_girth, double forearm_length_scale = 3.0, double arm_length_scale = 2.0);
    ~FullArm(){};

    void Display();

private:
    void DrawFullArm();

    void DrawForearm();
    void DrawUpperarm();

    double m_forearm_girth;
    double m_forearm_length_scale;
    double m_arm_girth;
    double m_arm_length_scale;
};