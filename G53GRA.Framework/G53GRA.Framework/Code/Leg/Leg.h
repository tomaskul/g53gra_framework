//
// Created by ghost on 22/03/19.
//

#include <Interface/DisplayableObject.h>

class Leg :
        public DisplayableObject{
public:
    Leg(double legGirth, bool isLeft);
    ~Leg(){};

    void Display();

private:
    void DrawFullLeg();

    void DrawLowerLeg();
    void DrawUpperLeg();

    const double UPPER_LEG_OFFSET = 5;
    const double LEG_BEND_ANGLE = 30;
    const double LEG_WIDTH_HEIGHT = 5;

    double m_leg_girth;
    bool m_is_left;
};