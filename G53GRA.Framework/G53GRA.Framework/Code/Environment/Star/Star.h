//
// Created by Tomas on 14/05/19.
//

#ifndef G53GRA_FRAMEWORK_STAR_H
#define G53GRA_FRAMEWORK_STAR_H


#include <Interface/DisplayableObject.h>

class Star :
        public DisplayableObject
{
public:
    Star(float xTranslate, float yTranslate, float zTranslate);
    ~Star(){};

    void Display();

private:
    float m_xTranslate;
    float m_yTranslate;
    float m_zTranslate;
};


#endif //G53GRA_FRAMEWORK_STAR_H
