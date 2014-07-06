#include "misc/Physics.h"

#include <iostream>
using namespace std;

Math maths = Math();
int numBirdsPhysics;

Physics::Physics(int numBirdsInput, double Ws, double Wc, double Wa)
{
	this->Ws = Ws;
	this->Wc = Wc;
	this->Wa = Wa;

	numBirdsPhysics = numBirdsInput;
}

double *Physics::Separation(Bird **flock, Bird *bird){
	int m;
	double S[2];
	double r[2];
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		if((D <= Dmax) && (D != 0)){
			r[0] = (bird->Px - flock[i]->Px) / D;
			r[1] = (bird->Py - flock[i]->Py) / D;

			S[0] += r[0];
 			S[1] += r[1];
 			m++;
 		} 		
	}

	S[0] /= m;
	S[1] /= m;

	double V[2];
	V[0] = bird->Vx;
	V[1] = bird->Vy;

	double *Snorm = maths.normalizeSteps(S, V);

	return Snorm;
}

double *Physics::Cohesion(Bird **flock, Bird *bird){
	int m;
	double C[2];
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		//Cmax = Dmax
		if((D <= Dmax) && (D != 0)){
			C[0] += flock[i]->Px;
 			C[1] += flock[i]->Py; 			
			m++;
 		} 		
	}

	C[0] /= m;
	C[1] /= m;

	double V[2];
	V[0] = bird->Vx;
	V[1] = bird->Vy;

	double *Cnorm = maths.normalizeSteps(C, V);

	return Cnorm;
}

double *Physics::Alignment(Bird **flock, Bird *bird){
	int m;
	double A[2];
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		//Cmax = Dmax
		if((D <= Dmax) && (D != 0)){
			A[0] += flock[i]->Vx;
 			A[1] += flock[i]->Vy; 			
			m++;
 		} 		
	}

	A[0] /= m;
	A[1] /= m;

	double V[2];
	A[0] = bird->Vx;
	A[1] = bird->Vy;

	double *Anorm = maths.normalizeSteps(A, V);

	return Anorm;
}

double *Physics::updatePosition(Bird **flock, Bird *bird){
	/*double *S = Separation(flock, bird);
	double *C = Cohesion(flock, bird);
	double *A = Alignment(flock, bird);

	S[0] = Ws*S[0];
	S[1] = Ws*S[1];

	C[0] = Wc*C[0];
	C[1] = Wc*C[1];

	A[0] = Wa*A[0];
	A[1] = Wa*A[1];

	double F[2];				//ai = Fi

	F[0] = S[0] + C[0] + A[0];
	F[1] = S[1] + C[1] + C[1];

	double Vf[2];

	Vf[0] = F[0] + bird->Vx;
	Vf[1] = F[1] + bird->Vy;

	double *Vfn = maths.maxV(Vf, Vmax);*/

	double *Vfn = NULL;

	return Vfn;
}
