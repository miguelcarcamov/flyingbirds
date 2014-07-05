#include "Bird.h"
#include "random/Math.h"

#include <iostream>
using namespace std;

#define STEP_ROTACION 10
#define MAXIMO_DESPLAZAMIENTO 10

#define VInit 1
#define WIN_WIDTH  640
#define WIN_HEIGHT  640
#define PADDING_X  30
#define PADDING_Y  30

#define MAX_X WIN_WIDTH - PADDING_X // limite derecho hasta donde un ave puede llegar horizontalmente
#define MAX_Y WIN_HEIGHT - PADDING_Y // limite superior hasta donde un ave puede llegar verticalmente
#define MIN_X PADDING_X
#define MIN_Y PADDING_Y

Math math = Math();

Bird::Bird(int radio, double Ws, double Wc, double Wa, int numBirds){
	double *P = math.calculatePositionInit(radio);
	this->Px = P[0];
	this->Py = P[1];

	this->Dir = math.calculateDirection();

	double *V = math.calculateVelocity(VInit, Dir);
	this->Vx = V[0];
	this->Vy = V[1];

	this->S = 0;
	this->C = 0;
	this->A = 0;

	this->Ws = Ws;
	this->Wc = Wc;
	this->Wa = Wa;

	this->F = 0;

	this->numBirds = numBirds;
}

void Bird::main(){

	double Xn = 0;	//Axis X next
	double Yn = 0;	//Axis Y next

	double Xp = 0;	//Axis X present
	double Yp = 0;	//Axis Y present

	double Vx = 0;	//Velocity X
	double Vy = 0;	//Velocity Y

	while(true){
		Vx = this->Vx;
		Vy = this->Vy;

		Xp = this->Px;
		Yp = this->Py;

		//d_i+1 = d_i + v_i
		Xn = Xp + Vx;		
		Yn = Yp + Vy;		

		//Axis X
		if(Xn > MAX_X){
			Xn = MIN_X + (Xn - MAX_X);
		} 
		else if(Xn < MIN_X){
			Xn = MAX_X - (Xn - MIN_X);
		}

		this->Px = Xn;

		//Axis X
		if(Yn > MAX_Y){
			Yn = MIN_Y + (Yn - MAX_Y);
		} 
		else if(Yn < MIN_Y){
			Yn = MAX_Y - (Yn - MIN_Y);
		}

		this->Py = Yn;

		unsigned miliseconds = numBirds/16;
		usleep(miliseconds * 1000000);
	}
}

void Bird::Separation(Bird **birds){
/*	double r[2];
	for(unsigned i=0 ; i<numBirds ; i++){
		D = maths.euclideanDistance(p, birds[i].p)
		if(D > Dmax){
			r[X] = 0;
			r[Y] = 0;
		} else {
			r[X] = (p[X] - numBirds[i].p[X]) / D;
			r[Y] = (p[Y] - numBirds[i].p[Y]) / D;
 		}

 		S[X] = S[X] + r[X];
 		S[Y] = S[Y] + r[X];
	}

	S = maths.normalization(S);*/
}

void Bird::Cohesion(Bird **birds){
/*	for(unsigned i=0 ; i<numBirds ; i++){
		D = maths.distEuclideana(p, birds[i].p)
		if(D <= Cmax){
			C[X] = C[X] + p[X];
 			C[Y] = C[Y] + p[Y];
 		}	
	}

	C = maths.normalization(S);*/
}

void Bird::Alignment(Bird **birds){
/*	for(unsigned i=0 ; i<numBirds ; i++){
		D = maths.distEuclideana(v, birds[i].v)
		if(D <= Amax){
			C[X] = C[X] + v[X];
 			C[Y] = C[Y] + v[Y];
 		}
	}

	A = maths.normalization(S);*/
}

void Bird::updatePosition(){

}
