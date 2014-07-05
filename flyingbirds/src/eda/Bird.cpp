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


Bird::Bird(int radio){
	Math math = Math();
	
	double *P = math.calculatePositionInit(radio);
	this->Px = P[0];
	this->Py = P[1];

	this->Dir = math.calculateDirection();

	double *V = math.calculateVelocity(VInit, Dir);
	this->Vx = V[0];
	this->Vy = V[1];

	//cout << "Vx " << Vx << " :: Vy " << Vy << endl;

	this->S = 0;
	this->C = 0;
	this->A = 0;

	this->F = 0;
}

void Bird::main(){
	double avance_x = 0;
	double avance_y = 0;

	while(true){
/*		unsigned miliseconds = 5;
		usleep(miliseconds * 1000);*/
		//avance_x = rand() % MAXIMO_DESPLAZAMIENTO - MAXIMO_DESPLAZAMIENTO / 2;
		//avance_y = rand() % MAXIMO_DESPLAZAMIENTO - MAXIMO_DESPLAZAMIENTO / 2;
		avance_x = this->Vx;
		avance_y = this->Vy;

		//cout << "X " << avance_x << " :: Y " << avance_y << endl;

		int x_anterior = this->Px;
		int y_anterior = this->Py;

		//Axis X
		if(this->Px + avance_x >= MAX_X){
			this->Px = MIN_X;
		}

		this->Px += + avance_x;

		//Axis Y
		if(this->Py + avance_y >= MAX_Y){
			this->Py = MIN_Y;
		}

		this->Py += avance_y;

		//Direccion = -atan2(destino_x - x, destino_y - y) * 180 / PI;
		
		//printf("(%d, %d) %f\n", p[x], p[y], Dir);
		unsigned miliseconds = 1;
		usleep(miliseconds * 1000000);
	}
}

void Bird::Separation(Bird **birds){
/*	double r[2];
	for(unsigned i=0 ; i<numBirds ; i++){
		D = maths.distEuclideana(p, birds[i].p)
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
