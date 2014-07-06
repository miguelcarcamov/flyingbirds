#include "misc/Physics.h"

#include <iostream>
using namespace std;

Physics::Physics(){}

void Physics::Separation(Bird **birds){
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

void Physics::Cohesion(Bird **birds){
/*	for(unsigned i=0 ; i<numBirds ; i++){
		D = maths.distEuclideana(p, birds[i].p)
		if(D <= Cmax){
			C[X] = C[X] + p[X];
 			C[Y] = C[Y] + p[Y];
 		}	
	}

	C = maths.normalization(S);*/
}

void Physics::Alignment(Bird **birds){
/*	for(unsigned i=0 ; i<numBirds ; i++){
		D = maths.distEuclideana(v, birds[i].v)
		if(D <= Amax){
			C[X] = C[X] + v[X];
 			C[Y] = C[Y] + v[Y];
 		}
	}

	A = maths.normalization(S);*/
}

void Physics::updatePosition(Bird **birds){
/*	F = Ws*S + Wc*C = Wa*A;*/
}