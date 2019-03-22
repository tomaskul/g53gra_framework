//
// Created by ghost on 22/03/19.
//
#ifndef G53GRA_FRAMEWORK_ROBOT_H
#define G53GRA_FRAMEWORK_ROBOT_H

#include <Interface/DisplayableObject.h>
#include <Arm/FullArm.h>
#include <Leg/Leg.h>
#include "torso.h"

class Robot
        : public DisplayableObject{
public:
    Robot();
    ~Robot(){};

    void Display();

private:
    FullArm *m_leftArm = new FullArm(0.75, true);
    FullArm *m_rightArm = new FullArm(0.75, false);
    torso *m_torso = new torso();
    Leg *m_leftLeg = new Leg(0.75, true);
    Leg *m_rightLeg = new Leg(0.75, false);
};

#endif