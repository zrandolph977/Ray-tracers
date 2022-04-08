#ifndef _SPHERE_H
#define _SPHERE_H

#include "Vect.h"
#include "Color.h"
#include "math.h"
#include "Object.h"

class Sphere : public Object{
    Vect center;
    double radius;
    Color color;

    public:

    Sphere();

    Sphere (Vect, double, Color);

    //methods
    Vect getSphereCenter() { return center;}
    double getSphereRadius() {return radius;}
    Color getSphereColor() {return color;}

};

Sphere::Sphere () {
    center = Vect(0,0,0);
    radius = 1.0;
    color = Color(0.5,0.5,0.5,0);
}

Sphere::Sphere (Vect p, double r,Color c) {
    center = p;
    radius = r;
    color = c;
}

#endif