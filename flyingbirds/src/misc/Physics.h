#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
#define PI 3.1415926535897932384626433832795
#define Dmax 25
#define Vmax 2.0

#include "eda/Bird.h"
#include "misc/Math.h"
#include "misc/Random.h"

#include <cstdlib>
#include <cmath>

class Physics{
    public:
    	//Attributes
    	double Ws;
    	double Wc;
    	double Wa;
        
        //Constructor
        Physics(){};
        Physics(int numBirdsInput, double Ws, double Wc, double Wa);
        ~Physics(){};
        
        //Methods
        double *Separation(Bird **flock, Bird *bird);
        double *Cohesion(Bird **flock, Bird *bird);
        double *Alignment(Bird **flock, Bird *bird);
        double *updatePosition(Bird **flock, Bird *bird);
};

#endif // PHYSICS_H_INCLUDED

