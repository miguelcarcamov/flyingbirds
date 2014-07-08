#ifndef BIRD_H
#define BIRD_H

#include <uC++.h>
#include <uBarrier.h>

#include "eda/Bird.h"
#include "misc/Math.h"
#include "misc/Random.h"

#include <cstdlib>
#include <cmath>

#define WIN_WIDTH  640
#define WIN_HEIGHT  640
#define PADDING_X  30
#define PADDING_Y  30

#define MAX_X WIN_WIDTH - PADDING_X // limite derecho hasta donde un ave puede llegar horizontalmente
#define MAX_Y WIN_HEIGHT - PADDING_Y // limite superior hasta donde un ave puede llegar verticalmente
#define MIN_X PADDING_X
#define MIN_Y PADDING_Y

#define Dmax 25
#define Cmax 40
#define Vmax 2.0
#define VInit 1.0

_Task Bird {
public:
	//Position
	double Px;
	double Py;
	double Vx;
	double Vy;
	double Dir;

    //Force
    double S[2];
    double C[2];
    double A[2];

    //Weights
	double Ws;
	double Wc;
	double Wa;

	//int numBirds;
	Bird **flock;

	protected:
		void main();

	public:
		//Constructor
		Bird(int radio, int numBirdsInput, double Ws, double Wc, double Wa, Bird **flock);
		~Bird(){};

		//Methods
		void Move();
		void Separation();
        void Cohesion();
        void Alignment();
        void updatePosition();
};

#endif