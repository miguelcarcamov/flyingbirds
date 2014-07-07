#include "Graphics.h"

//Global variable
Bird **flock;
Physics physics;
int numBirds = 0;

Graphics::Graphics(int numBirdsInput){
	numBirds = numBirdsInput;
}

void Graphics::draw(){
	double P[2];
	double Direction;

	for (int i = 0; i < numBirds; i++)
	{
		P[0]      = flock[i]->Px;
   		P[1] 	  = flock[i]->Py;
		Direction = flock[i]->Dir - 90;


		glPushMatrix();
	  		glColor3d(1, 1, 1);
	  		//Operacion para el triangulo
			glTranslated(P[0], P[1], 0.0);
		  	glRotated(Direction, 0.0, 0.0, 1.0);

			/*
				Se mantienen estas proporciones:
	  			Base: 1
					Altura: 1.9364916731
					Lado (isosceles): 2
			*/
			glBegin(GL_TRIANGLES); // Inicio del dibujo
	      	glVertex3d(-1.5, 0, 0); // Primer vertice
	      	glVertex3d( 1.5, 0, 0); // Segundo vertice
	      	glVertex3d( 0, 7.9364916731, 0); // Tercer vertice
	    	glEnd(); // Fin del dibujo

	    	// Deshago las operaciones de rotacion y translacion
	    	glRotated(-Direction, 0, 0, 1);
		  	glTranslated(-P[0], -P[1], 0.0);
	  	glPopMatrix();

	  	//cout << "Velocidad pajaro "<< i <<" Graph x: "<<flock[i]->Vx << " Velocidad pajaro Graph Y:"<< flock[i]->Vy<<endl;
	  	//flock[i]->Py 

	  	physics.updatePosition(flock, flock[i]);

	  	//cout << "Velocidad update pajaro "<< i <<" Graph x: "<<flock[i]->Vx << " Velocidad pajaro Graph Y:"<< flock[i]->Vy<<endl;
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

void Graphics::initGraphics(getOptions weights){
	int argc = 1;	
	char *argv[] = {"Graphics"};

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 0); // Posicion de la ventana en pixeles
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT); // Tamano de la ventana en pixeles
    glutCreateWindow("Flying Birds"); // Titulo de la ventana
    glutDisplayFunc(display); // display es la funcion que

	flock = new Bird * [numBirds];
    
    for (unsigned i = 0; i < numBirds; i++)
    {  	
		flock[i] = new Bird(RADIO_CREACION, numBirds);
    }

    double Ws = weights.getSeparation();
    double Wc = weights.getCohesion();
    double Wa = weights.getAlignment();

	physics = Physics(numBirds, Ws, Wc, Wa);    
    
    setup();

    glutMainLoop();
}
