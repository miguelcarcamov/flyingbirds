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


	this->S[0] = 0;
	this->S[1] = 0;

	this->C[0] = 0;
	this->C[1] = 0;

	this->A[0] = 0;
	this->A[1] = 0;

	numBirdsPhysics = numBirdsInput;
}

void Physics::Separation(Bird **flock, Bird *bird){
	int m=0;
	double S[2]={0,0};
	double r[2]={0,0};
	for(unsigned i=0 ; i<numBirdsPhysics ; i++){
		double D = maths.euclideanDistance(bird->Px, bird->Py, flock[i]->Px, flock[i]->Py);
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		if((D <= Dmax) && (D != 0)){
			//cout << "Bird Px: "<<bird->Px <<"Bird Py: "<<bird->Py<<endl;
			//cout << "Flock "<< i <<" Px: "<<flock[i]->Px<<" :: Flock "<< i <<" Py: "<<flock[i]->Py<<endl;
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
		//cout << "Bird "<< "Sx: "<< S[0]<<" Sy: "<<S[1] << endl;
		double *Snorm = maths.normalizeSteps(S, V);
		//cout << "Bird "<< "Snorm X: "<< Snorm[0]<<" Snorm Y: "<< Snorm[1] << endl;
		
		this->S[0] = Snorm[0];
		this->S[1] = Snorm[1];
		
	}else{
		this->S[0] = 0;
		this->S[1] = 0;
	}
}

void Physics::Cohesion(Bird **flock, Bird *bird){
	int m=0;
	double C[2]={0,0};
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
		
		double *Cnorm = maths.normalizeSteps(C, V);

		this->C[0] = Cnorm[0];
		this->C[1] = Cnorm[1];
		//cout << "Despues C X: "<< C[0]<<" Despues C  Y: "<<C[1] << endl;
	}else{
		C[0]=0;
		C[1]=0;
	}
}

void Physics::Alignment(Bird **flock, Bird *bird){
	int m=0;
	double A[2]={0,0};
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
		//cout << "Ax: "<< A[0]<<" Ay: "<< A[1] << endl;	
		double *Anorm = maths.normalizeSteps(A, V);

		this->A[0] = Anorm[0];
		this->A[1] = Anorm[1];
	}else{
		this->A[0]=0;
		this->A[1]=0;
	}

	
}

void Physics::updatePosition(Bird **flock, Bird *bird){
	Separation(flock, bird);
	Cohesion(flock, bird);
	Alignment(flock, bird);

	S[0] = Ws*S[0];
	S[1] = Ws*S[1];

	C[0] = Wc*C[0];
	C[1] = Wc*C[1];

	A[0] = Wa*A[0];
	A[1] = Wa*A[1];

	//cout << "Sx " << S[0] << " Sy " << S[1] << endl;
	//cout << "Cx " << C[0] << " Cy " << C[1] << endl;
	//cout << "Ax " << A[0] << " Ay " << A[1] << endl;

	double F[2] = {0,0};				//ai = Fi

	F[0] = S[0] + C[0] + A[0];
	F[1] = S[1] + C[1] + C[1];

	//cout << "Fx " << F[0] << " Fy " << F[1] << endl;

	
	bird->Vx = F[0] + bird->Vx;
	bird->Vy = F[1] + bird->Vy;
	usleep(100000);
	maths.maxV(bird, Vmax);

	//cout << "Vfx: " << Vfn[0] << "Vfy" << Vfn[1] << endl;

}
