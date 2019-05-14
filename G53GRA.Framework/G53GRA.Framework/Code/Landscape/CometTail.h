//
// Created by Tomas on 14/05/19.
//

#ifndef G53GRA_FRAMEWORK_COMETTAIL_H
#define G53GRA_FRAMEWORK_COMETTAIL_H


#include <Interface/DisplayableObject.h>

class CometTail : DisplayableObject{
public:
    CometTail(float alpha, float size);
    ~CometTail(){};

    void Display();

    float Alpha = 0.0f;
    float Size = 0.0f;
};


#endif //G53GRA_FRAMEWORK_COMETTAIL_H
