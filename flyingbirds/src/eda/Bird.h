#ifndef BIRD_H
#define BIRD_H

#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

_Task Bird {
public:
	double Px;
	double Py;
	double Vx;
	double Vy;
	double Dir;

	double S;
	double C;
	double A;

	double Ws;
	double Wc;
	double Wa;

	double F;

	int numBirds;

	protected:
		void main();

	public:
		//Constructor
		Bird(int radio, double Ws, double Wc, double Wa, int numBirds);
		~Bird(){};

		//Methods
		void Mover(double sumar_x, double sumar_y);
		void Rotar(float angulo);
		void Draw();
		//Force
		void Separation(Bird **birds);
		void Cohesion(Bird **birds);
		void Alignment(Bird **birds);
		void updatePosition();
};

#endif