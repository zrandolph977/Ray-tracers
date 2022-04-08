#ifndef _PLANE_H
#define _PLANE_H

#include "Vect.h"
#include "Color.h"
#include "math.h"
#include "Object.h"

class Plane : public Object{
    Vect normal;
    double distance;
    Color color;

    public:

    Plane();

    Plane (Vect, double, Color);

    //methods
    Vect getPlaneNormal() { return normal;}
    double getPlaneDistance() {return distance;}
    Color getPlaneColor() {return color;}

};

Plane::Plane () {
    normal = Vect(1,0,0);
    distance = 0.0;
    color = Color(0.5,0.5,0.5,0);
}

Plane::Plane (Vect n, double d,Color c) {
    normal = n;
    distance = d;
    color = c;
}

#endif