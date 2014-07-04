#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <vector>
#include "eda/Bird.h"

class Graphics {
	//vector<Bird*> birds;

	public:
		//Constructor
		Graphics(){};
		~Graphics(){};

		//Methods
		static void draw();
		//void dibujarCuadrados();
		static void dibujarLineasRojas();
		void setup();
		static void display();
		void initGraphics(int *argc, char **argv);
		//void handleKeypress(int key, int x, int y);
};

#endif

