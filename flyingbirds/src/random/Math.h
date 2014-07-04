#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED
#define PI 3.1415926535897932384626433832795 
#include "Random.h"

class Math{

    private:
        static Random random;
        double x;
        double y;

    public:
        Math();
        Random getRandom();
        double getX();
        double getY();
        void setRandom(Random random);
        void setX(double x);
        void setY(double y);
        double uniform(double a, double b);
        double roundZero(double number);
        void calculatePosition(double radius);

};

#endif // MATH_H_INCLUDED

