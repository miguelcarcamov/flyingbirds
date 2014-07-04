#ifndef BIRD_H
#define BIRD_H

#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

_Task Bird {
public:
	double p[2];
	double v[2];
	double dir;

	double S;
	double C;
	double A;

	double F;

	double destino_x;
	double destino_y;


	protected:
		void main();

	public:
		//Constructor
		Bird(double x, double y, double direccion);
		~Bird(){};

		//Methods
		void Mover(double sumar_x, double sumar_y);
		void Rotar(float angulo);
		void Draw();
		//Force
		void Separation();
		void Cohesion();
		void Alignmet();
		void updatePosition();
};

#endif