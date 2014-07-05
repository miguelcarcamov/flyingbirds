#ifndef BIRD_H
#define BIRD_H

#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

_Task Bird {
public:
	double x;
	double y;

	int destino_x;
	int destino_y;

	double direccion;


	protected:
		void main();

	public:
		//Constructor
		Bird(int radio);
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