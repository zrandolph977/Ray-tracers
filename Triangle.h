#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Vect.h"
#include "Color.h"
#include "math.h"
#include "Object.h"
#include "Ray.h"

class Triangle : public Object{
    Vect A,B,C;
    Vect normal;
    double distance;
    Color color;

    public:

    Triangle();

    Triangle (Vect, Vect, Vect, Color);

    //methods
    Vect getTriangleNormal() { 
        Vect CA (C.getVectX() - A.getVectX(), C.getVectY() - A.getVectY(), C.getVectZ() - A.getVectZ());
        Vect BA (B.getVectX() - A.getVectX(), B.getVectY() - A.getVectY(), B.getVectZ() - A.getVectZ());
        normal = CA.crossProduct(BA).normalize();
        return normal;
    }
    double getTriangleDistance() {
        normal = getTriangleNormal();
        distance = normal.dotProduct(A);
        return distance;
        }
    virtual Color getColor() {
        normal = getTriangleNormal();
        return color;
        }

    virtual Vect getNormalAt (Vect point) {
        return normal;
    }

    virtual double findIntersection(Ray ray) {
        Vect ray_direction = ray.getRayDirection();
        Vect ray_origin = ray.getRayOrigin();
        normal = getTriangleNormal();
        distance = getTriangleDistance();

        double a = ray_direction.dotProduct(normal);
        if(a == 0){
            //Parallel Ray
            return -1;
        } else {
            double b = normal.dotProduct(ray.getRayOrigin().vectAdd(normal.vectMult(distance).negative()));
            double distanceToPlane = -1*b/a;
            double Qx = ray_direction.vectMult(distanceToPlane).getVectX() + ray_origin.getVectX();      
            double Qy = ray_direction.vectMult(distanceToPlane).getVectY() + ray_origin.getVectY();
            double Qz = ray_direction.vectMult(distanceToPlane).getVectZ() + ray_origin.getVectZ();  
            Vect Q (Qx, Qy, Qz);     
            Vect CA (C.getVectX() - A.getVectX(), C.getVectY() - A.getVectY(), C.getVectZ() - A.getVectZ());
            Vect QA (Q.getVectX() - A.getVectX(), Q.getVectY() - A.getVectY(), Q.getVectZ() - A.getVectZ());
            double test1 = (CA.crossProduct(QA)).dotProduct(normal);
            Vect BC (B.getVectX() - C.getVectX(), B.getVectY() - C.getVectY(), B.getVectZ() - C.getVectZ());
            Vect QC (Q.getVectX() - C.getVectX(), Q.getVectY() - C.getVectY(), Q.getVectZ() - C.getVectZ());
            double test2 = (BC.crossProduct(QC)).dotProduct(normal);
            Vect AB (A.getVectX() - B.getVectX(), A.getVectY() - B.getVectY(), A.getVectZ() - B.getVectZ());
            Vect QB (Q.getVectX() - B.getVectX(), Q.getVectY() - B.getVectY(), Q.getVectZ() - B.getVectZ());
            double test3 = (AB.crossProduct(QB)).dotProduct(normal);
            if((test1 >= 0) && (test2 >= 0) && (test3 >= 0)) {
                return -1*b/a;
            } else {
                return -1;
            }
            
        }
    }

};

Triangle::Triangle () {
    A = Vect(1,0,0);
    B = Vect(0,1,0);
    C = Vect(0,0,1);
    color = Color(0.5,0.5,0.5,0);
}

Triangle::Triangle (Vect pointA, Vect pointB, Vect pointC, Color c) {
    A = pointA;
    B = pointB;
    C = pointC;
    color = c;
}

#endif