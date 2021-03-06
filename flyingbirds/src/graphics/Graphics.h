#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <uC++.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "eda/Bird.h"
#include "misc/Math.h"
#include "getOptions/getOptions.h"

#define WIN_WIDTH  640
#define WIN_HEIGHT  640
#define PADDING_X  30
#define PADDING_Y  30

#define MAX_X WIN_WIDTH - PADDING_X
#define MAX_Y WIN_HEIGHT - PADDING_Y
#define MIN_X PADDING_X
#define MIN_Y PADDING_Y

#define RADIO_CREACION 10.0

/*#include <iostream>
using namespace std;*/

class Graphics {
	public:
		//Constructor
		Graphics(int numBirdsInput);
		~Graphics(){};

		//Methods
		static void draw();
		static void dibujarLineasRojas();
		void setup();
		static void display();
		void initGraphics(getOptions weights);
};

#endif

