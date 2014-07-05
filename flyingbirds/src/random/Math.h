#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED
#define PI 3.1415926535897932384626433832795 
#include "Random.h"

class Math{

    private:
        static Random random;

    public:
        Math();
        Random getRandom();
        void setRandom(Random random);
        double uniform(double a, double b);
        double roundZero(double number);
        double *calculatePositionInit(double radius);
        double *calculatePosition(double scalar, double angle);
        double calculateDirection();
        double euclideanDistance(double *p, double *q);
        double *maxV(double *vector, double scalar);
        double *minV(double *vector, double scalar);

};

#endif // MATH_H_INCLUDED

