#ifndef BIRD_H
#define BIRD_H

#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

_Task Bird {
public:
	int x;
	int y;

	int destino_x;
	int destino_y;

	double direccion;


	protected:
		void main();

	public:
		//Constructor
		Bird(int x, int y, double direccion);
		~Bird(){};

		//Methods
		void Mover(double sumar_x, double sumar_y);
		void Rotar(float angulo);
		void Draw();
};

#endif