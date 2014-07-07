#include "Bird.h"
#include "misc/Math.h"

#include <iostream>
using namespace std;

Math math = Math();

Bird::Bird(int radio, int numBirds){
	double *P = math.calculatePositionInit(radio);
	this->Px = P[0];
	this->Py = P[1];

	this->Dir = math.calculateDirection();

	double *V = math.calculateVelocity(VInit, Dir);
	this->Vx = V[0];
	this->Vy = V[1];

	this->numBirds = numBirds;
}

void Bird::main(){
	while(true){
		Move();
		unsigned miliseconds = 10*numBirds/25;
		usleep(miliseconds * 1000000);
	}
}

void Bird::Move(){
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
}
