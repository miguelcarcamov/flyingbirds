#include "Graphics.h"
#include "random/Math.h"

#define STEP_ROTACION 10
#define MAXIMO_DESPLAZAMIENTO 10
#define PI 3.1416

#define WIN_WIDTH  640
#define WIN_HEIGHT  640
#define PADDING_X  30
#define PADDING_Y  30

#define MAX_X WIN_WIDTH - PADDING_X // limite derecho hasta donde un ave puede llegar horizontalmente
#define MAX_Y WIN_HEIGHT - PADDING_Y // limite superior hasta donde un ave puede llegar verticalmente
#define MIN_X PADDING_X
#define MIN_Y PADDING_Y

#define RADIO_CREACION 100

//Global Variable
Bird **birds;
int numBirds = 1;

Graphics::Graphics(){
	Math math = Math();
}

void Graphics::draw(){
	double AxisX;
	double AxisY;
	double Direction;

	for (int i = 0; i < numBirds; i++)
	{
		AxisX     = birds[i]->Px;
   		AxisY 	  = birds[i]->Py;
		Direction = birds[i]->Dir - 90;
		glPushMatrix();
  		glColor3d(1, 1, 1);

  	//Operacion para el triangulo
		glTranslated(AxisX, AxisY, 0.0);
	  	glRotated(Direction, 0.0, 0.0, 1.0);

		/*
			Se mantienen estas proporciones:
  			Base: 1
				Altura: 1.9364916731
				Lado (isosceles): 2
		*/

		glBegin(GL_TRIANGLES); // Inicio del dibujo
      	glVertex3d(-5, 0, 0); // Primer vertice
      	glVertex3d( 5, 0, 0); // Segundo vertice
      	glVertex3d( 0, 15, 0); // Tercer vertice
    	glEnd(); // Fin del dibujo

    	// Deshago las operaciones de rotacion y translacion
    	glRotated(-Direction, 0, 0, 1);
	  	glTranslated(-AxisX, -AxisY, 0.0);
	  	glPopMatrix();
	}
}

void Graphics::dibujarLineasRojas(){
	glColor3d(1, 0, 0); // verde
    glBegin(GL_LINES);
        // Lineas Verticales
	    	// Inferior
	        glVertex2d(PADDING_X, PADDING_Y);
	        glVertex2d(WIN_WIDTH - PADDING_X, PADDING_Y);

	        // Superior
	        glVertex2d(PADDING_X, WIN_HEIGHT - PADDING_Y);
	        glVertex2d(WIN_WIDTH - PADDING_X, WIN_HEIGHT - PADDING_Y);

	    // Lineas Horizontales
	        // Izquierda
	        glVertex2d(PADDING_X, WIN_HEIGHT - PADDING_Y);
	        glVertex2d(PADDING_X, PADDING_Y);

	        // Derecha
	        glVertex2d(WIN_WIDTH - PADDING_X, WIN_HEIGHT - PADDING_Y);
	        glVertex2d(WIN_WIDTH - PADDING_X, PADDING_Y);

    glEnd();
}

void Graphics::setup(){
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo (negro)
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT);
}

void Graphics::display(){
    while(true){
	    glClear(GL_COLOR_BUFFER_BIT);
	    glColor3d(1.0, 0.0, 0.0);

	    dibujarLineasRojas();
    	draw();
	    
	    glFlush();
    }
}

void Graphics::initGraphics(){
	int argc = 1;	
	char *argv[] = {"Graphics"};

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 0); // Posicion de la ventana en pixeles
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT); // Tamano de la ventana en pixeles
    glutCreateWindow("Flying Birds"); // Titulo de la ventana
    glutDisplayFunc(display); // display es la funcion que

	birds = new Bird * [numBirds];
    
    for (unsigned i = 0; i < numBirds; i++)
    {  	
		birds[i] = new Bird(RADIO_CREACION);
    }
    
    setup();

    glutMainLoop();
}
