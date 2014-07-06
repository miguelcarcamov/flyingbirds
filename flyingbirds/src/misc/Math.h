#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#define V_MAX 2.0
#define F_MAX 0.03

#include <cstdlib>
#include <cmath>
#include "misc/Random.h"

#define PI 3.1415926535897932384626433832795

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
        double *calculateVelocity(double scalar, double angle);
        double calculateDirection();
        double euclideanDistance(double *p, double *q);
        double *maxV(double *vector, double scalar);
        double *minV(double *vector, double scalar);
        double *normalizeSteps(double *vector, double *actualVelocity);

};

#endif // MATH_H_INCLUDED

