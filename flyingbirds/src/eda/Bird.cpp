#include "Bird.h"
#include "misc/Math.h"

#include <iostream>

using namespace std;

Math math = Math();
int numBirdsTotal;

Bird::Bird(int radio, int numBirdsTotalInput, double Ws, double Wc, double Wa, Bird **flock)
{
	double *P = math.calculatePositionInit(radio);
	this->Px = P[0];
	this->Py = P[1];

	this->Dir = math.calculateDirection();

	double *V = math.calculateVelocity(VInit, Dir);
	this->Vx = V[0];
	this->Vy = V[1];

	this->Ws = Ws;
	this->Wc = Wc;
	this->Wa = Wa;

	this->S[0] = 0;
	this->S[1] = 0;

	this->C[0] = 0;
	this->C[1] = 0;

	this->A[0] = 0;
	this->A[1] = 0;

	numBirdsTotal = numBirdsTotalInput;
	this->flock = flock;
}

void Bird::main()
{
	uCondition flockComplete;
	while(true){
		Move();
		unsigned miliseconds = 10*numBirdsTotal/25;
		usleep(miliseconds * 1000000);


		updatePosition();
	}
}

void Bird::Move()
{
	//Update position
	double Xn = 0;	//Axis X next
	double Yn = 0;	//Axis Y next

	double Xp = 0;	//Axis X present
	double Yp = 0;	//Axis Y present

	double Vx = 0;	//Velocity X
	double Vy = 0;	//Velocity Y

	Vx = this->Vx;
	Vy = this->Vy;

	Xp = this->Px;
	Yp = this->Py;

	//d_i+1 = d_i + v_i
	Xn = Xp + Vx;		
	Yn = Yp + Vy;		

	//Axis X
	if(Xn > MAX_X){
		Xp = 0;
		Xn = MIN_X + math.euclideanDistance(Xn, 0, MAX_X, 0);

	} 
	else if(Xn < MIN_X){
		Xp = 360;
		Xn = MAX_X - math.euclideanDistance(Xn, 0, MIN_X, 0);

	}

	this->Px = Xn;

	//Axis X
	if(Yn > MAX_Y){
		Yp = 0;
		Yn = MIN_Y + math.euclideanDistance(0, Yn, 0, MAX_Y);

	} 
	else if(Yn < MIN_Y){
		Yp = 360;
		Yn = MAX_Y - math.euclideanDistance(0, Yn, 0, MIN_Y);
	}

	this->Py = Yn;



	//Update direction
	double Dx = Xn - Xp;
	double Dy = Yn - Yp;
	double DirN = atan2(Dy, Dx)*180/PI;

	this->Dir = DirN;
}


void Bird::Separation()
{
	int m=0;
	double S[2]={0,0};
	double r[2]={0,0};
	for(unsigned i=0 ; i<numBirdsTotal ; i++){
		double D = math.euclideanDistance(this->Px, this->Py, this->flock[i]->Px, this->flock[i]->Py);

		if((D <= Dmax) && (D != 0)){

			r[0] = (this->Px - this->flock[i]->Px) / D;
			r[1] = (this->Py - this->flock[i]->Py) / D;

			S[0] += r[0];
 			S[1] += r[1];
 			m++;
 		} 		
	}

	if(m!=0){
		S[0] /= m;
		S[1] /= m;
		double V[2];
		V[0] = this->Vx;
		V[1] = this->Vy;

		double *Snorm = math.normalizeSteps(S, V);

		
		this->S[0] = Snorm[0];
		this->S[1] = Snorm[1];
		
	}else{
		this->S[0] = 0;
		this->S[1] = 0;
	}
}

void Bird::Cohesion()
{
	int m=0;
	double C[2]={0,0};
	for(unsigned i=0 ; i<numBirdsTotal ; i++){
		double D = math.euclideanDistance(this->Px, this->Py, this->flock[i]->Px, this->flock[i]->Py);

		if((D <= Cmax) && (D != 0)){

			C[0] += this->flock[i]->Px;
 			C[1] += this->flock[i]->Py; 			
			m++;
 		} 		
	}

	if(m!=0){

		C[0] /= m;
		C[1] /= m;
		double V[2];
		V[0] = this->Vx;
		V[1] = this->Vy;
		
		double *Cnorm = math.normalizeSteps(C, V);

		this->C[0] = Cnorm[0];
		this->C[1] = Cnorm[1];

	}else{
		C[0]=0;
		C[1]=0;
	}
}

void Bird::Alignment()
{
	int m=0;
	double A[2]={0,0};
	for(unsigned i=0 ; i<numBirdsTotal ; i++){
		double D = math.euclideanDistance(this->Px, this->Py, this->flock[i]->Px, this->flock[i]->Py);

		if((D <= Dmax) && (D != 0)){

			A[0] += this->flock[i]->Vx;
 			A[1] += this->flock[i]->Vy; 			
			m++;
 		} 		
	}

	if(m!=0){
		A[0] /= m;
		A[1] /= m;
		double V[2];
		A[0] = this->Vx;
		A[1] = this->Vy;	
		double *Anorm = math.normalizeSteps(A, V);

		this->A[0] = Anorm[0];
		this->A[1] = Anorm[1];
	}else{
		this->A[0]=0;
		this->A[1]=0;
	}
	
}

void Bird::updatePosition()
{
	Separation();
	Cohesion();
	Alignment();

	S[0] = Ws*S[0];
	S[1] = Ws*S[1];

	C[0] = Wc*C[0];
	C[1] = Wc*C[1];

	A[0] = Wa*A[0];
	A[1] = Wa*A[1];



	double F[2] = {0,0};				//ai = Fi

	F[0] = S[0] + C[0] + A[0];
	F[1] = S[1] + C[1] + C[1];


	
	this->Vx = F[0] + this->Vx;
	this->Vy = F[1] + this->Vy;

	double *Vn = math.min(this->Vx, this->Vy, Vmax);

	this->Vx = Vn[0];
	this->Vy = Vn[1];


}
