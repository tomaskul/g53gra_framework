//
// Created by ghost on 22/03/19.
//

#include "Robot.h"

Robot::Robot() {

}

void Robot::Display() {
    m_torso->Display();
    m_leftArm->Display();
    m_rightArm->Display();
    m_leftLeg->Display();
    m_rightLeg->Display();
}
