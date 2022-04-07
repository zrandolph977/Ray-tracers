#ifndef _VECT_H
#define _VECT_H

#include "math.h"

class Vect {
    double x,y,z;

    public:

    Vect();

    Vect (double, double, double);

    //methods
    double getVectX() {return x;}
    double getVectY() {return y;}
    double getVectz() {return z;}


};

Vect::Vect () {
    x = 0;
    y = 0;
    z = 0;
}

Vect::Vect (double i, double j, double k) {
    x = i;
    y = j;
    z = k;
}

#endif