#include <Interface/DisplayableObject.h>

//
// Created by ghost on 08/03/19.
//
class Forearm :
        public DisplayableObject
{
public:
    Forearm(double forearm_width);
    ~Forearm(){}

    void Display();

private:
    void DrawForearm();

    double m_forearm_width;
};