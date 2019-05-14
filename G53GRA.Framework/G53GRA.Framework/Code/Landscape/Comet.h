//
// Created by Tomas on 14/05/19.
//

#ifndef G53GRA_FRAMEWORK_COMET_H
#define G53GRA_FRAMEWORK_COMET_H


#include <Interface/DisplayableObject.h>
#include <Interface/Animation.h>
#include "CometTail.h"

class Comet :
        public DisplayableObject,
        public Animation
{
public:
    Comet(float size, float speed, float tailLength);
    ~Comet(){};

    void Display();
    void Update(const double &deltaTime);

private:
    float m_xTranslate = 0.0f;
    float m_yTranslate = 0.0f;

    float m_cometSize;
    float m_cometSpeed;
    float m_tailLength;

    std::vector<CometTail*> m_tail;
};


#endif //G53GRA_FRAMEWORK_COMET_H
