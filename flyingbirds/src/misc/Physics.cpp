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
	int m=0;
	double S[2];
	double r[2];
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		if((D <= Dmax) && (D != 0)){
			//cout << "PAJARO X: "<<bird->Px <<"PAJARO Y: "<<bird->Py<<endl;
			//cout << "PAJAROS X: "<<flock[i]->Px<<"PAJAROS Y: "<<flock[i]->Py<<endl;
			r[0] = (bird->Px - flock[i]->Px) / D;
			r[1] = (bird->Py - flock[i]->Py) / D;

			S[0] += r[0];
 			S[1] += r[1];
 			m++;
 		} 		
	}

	if(m!=0){
		S[0] /= m;
		S[1] /= m;
		double V[2];
		V[0] = bird->Vx;
		V[1] = bird->Vy;
		//cout << "S X: "<< S[0]<<" S  Y: "<<S[1] << endl;
		double *Snorm = maths.normalizeSteps(S, V);
		return Snorm;
	}else{
		S[0]=0;
		S[1]=0;
		return S;
	}

	
}

double *Physics::Cohesion(Bird **flock, Bird *bird){
	int m=0;
	double C[2];
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		//Cmax = Dmax
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		if((D <= Dmax) && (D != 0)){
			//cout << "PAJARO X: "<<bird->Px <<"PAJARO Y: "<<bird->Py<<endl;
			//cout << "PAJAROS X: "<<flock[i]->Px<<"PAJAROS Y: "<<flock[i]->Py<<endl;
			C[0] += flock[i]->Px;
 			C[1] += flock[i]->Py; 			
			m++;
 		} 		
	}

	if(m!=0){
		//cout << " Antes C X: "<< C[0]<<" Antes C  Y: "<<C[1] << endl;
		//cout << "M: "<<m<<endl;
		C[0] /= m;
		C[1] /= m;
		double V[2];
		V[0] = bird->Vx;
		V[1] = bird->Vy;
		//cout << "Despues C X: "<< C[0]<<" Despues C  Y: "<<C[1] << endl;
		double *Cnorm = maths.normalizeSteps(C, V);
		return Cnorm;
	}else{
		C[0]=0;
		C[1]=0;
		return C;
	}

	

	
}

double *Physics::Alignment(Bird **flock, Bird *bird){
	int m=0;
	double A[2];
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		//Cmax = Dmax
		if((D <= Dmax) && (D != 0)){
			//cout << "PAJARO X: "<<bird->Px <<"PAJARO Y: "<<bird->Py<<endl;
			//cout << "PAJAROS X: "<<flock[i]->Px<<"PAJAROS Y: "<<flock[i]->Py<<endl;
			A[0] += flock[i]->Vx;
 			A[1] += flock[i]->Vy; 			
			m++;
 		} 		
	}

	if(m!=0){
		A[0] /= m;
		A[1] /= m;
		double V[2];
		A[0] = bird->Vx;
		A[1] = bird->Vy;
		//cout << "A X: "<< A[0]<<" A  Y: "<<A[1] << endl;
		double *Anorm = maths.normalizeSteps(A, V);

		return Anorm;
	}else{

		A[0]=0;
		A[1]=0;
		return A;
	}

	
}

double *Physics::updatePosition(Bird **flock, Bird *bird){
	double *S = Separation(flock, bird);
	double *C = Cohesion(flock, bird);
	double *A = Alignment(flock, bird);

	S[0] = Ws*S[0];
	S[1] = Ws*S[1];

	C[0] = Wc*C[0];
	C[1] = Wc*C[1];

	A[0] = Wa*A[0];
	A[1] = Wa*A[1];

	double F[2]={0,0};				//ai = Fi

	F[0] = S[0] + C[0] + A[0];
	F[1] = S[1] + C[1] + C[1];

	double Vf[2] = {0,0};
	cout <<"Velocidad pájaro X: "<< bird->Vx <<"Velocidad pajaro Y: "<< bird->Vy <<endl;
	Vf[0] = F[0] + bird->Vx;
	Vf[1] = F[1] + bird->Vy;

	double *Vfn = maths.maxV(Vf, Vmax);


	return Vfn;
}
