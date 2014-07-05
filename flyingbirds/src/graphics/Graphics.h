#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <vector>
#include "eda/Bird.h"
#include "random/Math.h"

#include <iostream>
using namespace std;

class Graphics {
	//vector<Bird*> birds;
	Math math;

	public:
		//Constructor
		Graphics();
		~Graphics(){};

		//Methods
		static void draw();
		static void dibujarLineasRojas();
		void setup();
		static void display();
		void initGraphics();
};

#endif

