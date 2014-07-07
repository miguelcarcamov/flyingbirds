#ifndef BIRD_H
#define BIRD_H

#include <uC++.h>

#define WIN_WIDTH  640
#define WIN_HEIGHT  640
#define PADDING_X  30
#define PADDING_Y  30

#define MAX_X WIN_WIDTH - PADDING_X // limite derecho hasta donde un ave puede llegar horizontalmente
#define MAX_Y WIN_HEIGHT - PADDING_Y // limite superior hasta donde un ave puede llegar verticalmente
#define MIN_X PADDING_X
#define MIN_Y PADDING_Y

#define VInit 1.0

_Task Bird {
public:
	double Px;
	double Py;
	double Vx;
	double Vy;
	double Dir;

	int numBirds;

	protected:
		void main();

	public:
		//Constructor
		Bird(int radio, int numBirds);
		~Bird(){};

		//Methods
		void Move();
};

#endif