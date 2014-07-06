#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
#define PI 3.1415926535897932384626433832795
#define Dmax 25
#define Vmax 2.0

#include <uC++.h>

#include "eda/Bird.h"
#include "misc/Math.h"
#include "misc/Random.h"

#include <cstdlib>
#include <cmath>

class Physics{
    public:
    	//Attributes
        //Weights
    	double Ws;
    	double Wc;
    	double Wa;
        //Force
        double S[2];
        double C[2];
        double A[2];

        //Constructor
        Physics(){};
        Physics(int numBirdsInput, double Ws, double Wc, double Wa);
        ~Physics(){};
        
        //Methods
        void Separation(Bird **flock, Bird *bird);
        void Cohesion(Bird **flock, Bird *bird);
        void Alignment(Bird **flock, Bird *bird);
        void updatePosition(Bird **flock, Bird *bird);
};

#endif // PHYSICS_H_INCLUDED

