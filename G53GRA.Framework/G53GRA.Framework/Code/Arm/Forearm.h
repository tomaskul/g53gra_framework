#include <Interface/DisplayableObject.h>

//
// Created by ghost on 08/03/19.
//
class Forearm :
        public DisplayableObject
{
public:
    /**
     * Constructs a basic, rectangular forearm.
     * @param forearm_girth - Girth of the forearm cube.
     * @param forearm_length_scale - Scale representing forearm length to girth ratio. 3 by default.
     */
    Forearm(double forearm_girth, double forearm_length_scale);
    ~Forearm(){}

    void Display();

private:
    void DrawForearm();

    double m_forearm_girth;
    double m_forearm_length_scale;
};