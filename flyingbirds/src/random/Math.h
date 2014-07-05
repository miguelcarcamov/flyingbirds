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
        double *calculatePosition(double radius);
        double calculateDirection();
        double euclideanDistance(double *p, double *q);

};

#endif // MATH_H_INCLUDED

