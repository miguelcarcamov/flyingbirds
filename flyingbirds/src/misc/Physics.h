#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
#define PI 3.1415926535897932384626433832795

#include "eda/Bird.h"
#include "misc/Math.h"
#include "misc/Random.h"

#include <cstdlib>
#include <cmath>

class Physics{
    public:
        //Constructor
        Physics();
        //Methods
        void Separation(Bird **birds);
        void Cohesion(Bird **birds);
        void Alignment(Bird **birds);
        void updatePosition(Bird **birds);
};

#endif // PHYSICS_H_INCLUDED

