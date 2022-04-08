#ifndef _OBJECT_H
#define _OBJECT_H

#include "Vect.h"
#include "Color.h"
#include "Ray.h"

class Object {

    public:

    Object();

    //methods
    Color getObjectColor() {return Color(0.0,0.0,0.0,0);}

    double findIntersection(Ray ray) {
        return 0;
    }

};

Object::Object () {

}

#endif