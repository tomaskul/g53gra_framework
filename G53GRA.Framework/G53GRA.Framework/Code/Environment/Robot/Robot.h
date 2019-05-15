//
// Created by Tomas on 14/05/19.
//

#ifndef G53GRA_FRAMEWORK_ASTRONAUT_H
#define G53GRA_FRAMEWORK_ASTRONAUT_H


#include <Interface/DisplayableObject.h>
#include <Interface/Animation.h>

class Robot :
        public DisplayableObject,
        public Animation
{
public:
    Robot(float spaceshipSpeed);
    ~Robot(){};

    void Display();
    void Update(const double &deltaTime);

private:
    bool m_drawAstraunaut = false;
    int m_stage = 0;

    float m_spaceshipSpeed = 0.0f;
    float m_totalRotationAngle = 0.0f;
    float m_spaceshipRotationAngle = 0.0f;

    float m_xTranslate = 0.0f;
    float m_yTranslate = 0.0f;
    float m_zTranslate = -500.0f;
};


#endif //G53GRA_FRAMEWORK_ASTRONAUT_H
