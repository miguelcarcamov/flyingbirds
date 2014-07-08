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

		//uBarrier barrier(numBirdsTotal);
		//flockComplete.wait();
		updatePosition();
		//flockComplete.signal();
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
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		if((D <= Dmax) && (D != 0)){
			//cout << "Bird Px: "<<this->Px <<"Bird Py: "<<this->Py<<endl;
			//cout << "Flock "<< i <<" Px: "<<this->flock[i]->Px<<" :: Flock "<< i <<" Py: "<<this->flock[i]->Py<<endl;
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
		//cout << "Bird "<< "Sx: "<< S[0]<<" Sy: "<<S[1] << endl;
		double *Snorm = math.normalizeSteps(S, V);
		//cout << "Bird "<< "Snorm X: "<< Snorm[0]<<" Snorm Y: "<< Snorm[1] << endl;
		
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
		//Cmax = Dmax
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		if((D <= Dmax) && (D != 0)){
			//cout << "PAJARO X: "<<this->Px <<"PAJARO Y: "<<this->Py<<endl;
			//cout << "PAJAROS X: "<<this->flock[i]->Px<<"PAJAROS Y: "<<this->flock[i]->Py<<endl;
			C[0] += this->flock[i]->Px;
 			C[1] += this->flock[i]->Py; 			
			m++;
 		} 		
	}

	if(m!=0){
		//cout << " Antes C X: "<< C[0]<<" Antes C  Y: "<<C[1] << endl;
		//cout << "M: "<<m<<endl;
		C[0] /= m;
		C[1] /= m;
		double V[2];
		V[0] = this->Vx;
		V[1] = this->Vy;
		
		double *Cnorm = math.normalizeSteps(C, V);

		this->C[0] = Cnorm[0];
		this->C[1] = Cnorm[1];
		//cout << "Despues C X: "<< C[0]<<" Despues C  Y: "<<C[1] << endl;
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
		//cout << "Distancia entre pajaro y sus pares: "<< D <<endl;
		//Cmax = Dmax
		if((D <= Dmax) && (D != 0)){
			//cout << "PAJARO X: "<<this->Px <<"PAJARO Y: "<<this->Py<<endl;
			//cout << "PAJAROS X: "<<this->flock[i]->Px<<"PAJAROS Y: "<<this->flock[i]->Py<<endl;
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
		//cout << "Ax: "<< A[0]<<" Ay: "<< A[1] << endl;	
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

	//cout << "Sx " << S[0] << " Sy " << S[1] << endl;
	//cout << "Cx " << C[0] << " Cy " << C[1] << endl;
	//cout << "Ax " << A[0] << " Ay " << A[1] << endl;

	double F[2] = {0,0};				//ai = Fi

	F[0] = S[0] + C[0] + A[0];
	F[1] = S[1] + C[1] + C[1];

	//cout << "Fx " << F[0] << " Fy " << F[1] << endl;
	
	this->Vx = F[0] + this->Vx;
	this->Vy = F[1] + this->Vy;
	//usleep(100000);
	//FIX pleaseeee !!!
	math.minV(this->Vx, this->Vy, Vmax);					//Fix name

	//cout << "Vfx: " << Vfn[0] << "Vfy" << Vfn[1] << endl;
}
