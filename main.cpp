#include <uC++.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "ave.cpp"

#include <iostream>
using namespace std;

#define RADIO_CREACION 100

vector<Ave*> Aves;

void setup();
void display();
void createCoordinate();
void draw();

// drawing box square
void draw(){
	//glBegin(GL_TRIANGLES);//start drawing triangles
		//glVertex3f( POSICION_X , POSICION_Y , POSICION_Z); // Dibuja un vertice
    //glEnd();//end drawing of triangles

	int x;
	int y;
	int direccion;
  	for (int i = 0; i < Aves.size(); i++)
  	{
  		x 		  = Aves.at(i)->x;
  		y 		  = Aves.at(i)->y;
  		direccion = Aves.at(i)->direccion;
  		//cout << "Dibuje" << endl;
  		//Aves.at(i)->Draw();

    	glColor3f(1, 1, 1); // blanco
    	//glColor3f(0, 0, 1); // azul
  		

  		// Se supone que en este punto, opengl dibujara cualquier cosa respecto a 0, 0, 0
  		// Por lo tanto, le decimos que rote en "direccion" grados los dibujos y los traslate a la posicion x, y, 0
  		// ** Nota: OpenGl al parecer procesa los eventos alrevez, por lo que se ejecutaria la rotacion
  		// ** y luego la traslacion
  		glTranslatef(x, y, 0.0f);
		glRotatef(direccion, 0, 0, 1);
  		

  		/*
  			Se mantienen estas proporciones:
	  			Base: 1
  				Altura: 1.9364916731
  				Lado (isosceles): 2
  		*/
  		glBegin(GL_TRIANGLES); // Inicio del dibujo
			glVertex3f(-2.5, -4.841225, 0); // Primer vertice
	      	glVertex3f( 2.5, -4.841225, 0); // Segundo vertice
	      	glVertex3f( 0,  4.841225, 0); // Tercer vertice
	    glEnd(); // Fin del dibujo

	    // Deshago las operaciones de rotacion y translacion
	    glRotatef(-direccion, 0, 0, 1);
		glTranslatef(-x, -y, 0.0f);
		
		// Le indico una direccion de destino ficticia (en este caso,
		// la esquina superior derecha de la pantalla)
		Aves.at(i)->destino_x = 640;
		Aves.at(i)->destino_y = 640;

		// Aves.at(i)->Rotar(1); // No funciona al llamar un metodo de la clase, el programa no muestra nada
  	}
    

}

void dibujarCuadrados(){
	// Tabla de valores posibles para glBegin en
	// http://en.wikibooks.org/wiki/OpenGL_Programming/GLStart/Tut3
	// (Tutorial 3: Drawing Primitives)
	
	// Ejemplo de cuadrado
	glColor3f(1, 0, 0); // blanco
    glBegin(GL_QUADS);
        glVertex2f(0,   0);
        glVertex2f(10,  0);
        glVertex2f(10, 10);
        glVertex2f(0,  10);
    glEnd();

    glColor3f(0, 1, 0); // verde
    glBegin(GL_QUADS);
        glVertex2f(20,   0);
        glVertex2f(30,  0);
        glVertex2f(30, 10);
        glVertex2f(20,  10);
    glEnd();
}

void dibujarLineasRojas(){
	glColor3f(1, 0, 0); // verde
    glBegin(GL_LINES);
        // Lineas Verticales
	    	// Inferior
	        glVertex2f(PADDING_X, PADDING_Y);
	        glVertex2f(WIN_WIDTH - PADDING_X, PADDING_Y);

	        // Superior
	        glVertex2f(PADDING_X, WIN_HEIGHT - PADDING_Y);
	        glVertex2f(WIN_WIDTH - PADDING_X, WIN_HEIGHT - PADDING_Y);

	    // Lineas Horizontales
	        // Izquierda
	        glVertex2f(PADDING_X, WIN_HEIGHT - PADDING_Y);
	        glVertex2f(PADDING_X, PADDING_Y);

	        // Derecha
	        glVertex2f(WIN_WIDTH - PADDING_X, WIN_HEIGHT - PADDING_Y);
	        glVertex2f(WIN_WIDTH - PADDING_X, PADDING_Y);

    glEnd();
}

void setup(){
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo (negro)
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT);
}

void display(){
    while(1){
	    glClear(GL_COLOR_BUFFER_BIT);
	    glColor3f(1.0, 0.0, 0.0);

	    dibujarCuadrados();
	    dibujarLineasRojas();
    	draw();

	    
	    glFlush();
	    //sleepcp(1000);
	    //sleep(1);
    }
}

void handleKeypress(int key, int x, int y) {
	printf("Se presiono la tecla %c (%d)\n", key, key);
    switch (key) {
            case 27: //Escape key                                                                                                                                       
              exit(0); //Exit the program
    }
	glutPostRedisplay();
}

void uMain::main() {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 0); // Posicion de la ventana en pixeles
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT); // Tamano de la ventana en pixeles
    glutCreateWindow("Aves"); // Titulo de la ventana
    glutDisplayFunc(display); // display es la funcion que

    int numero_de_aves = 10;
	
	//srand (time(NULL));
	srand (10);

	// Limite inferior y superior para crear las aves horizontalmente respecto al centro
	// Ej: Si la ventana es de 640 x 640, el centro sera (320, 320),
	// el radio de creacion es 100,
	// entonces solo se podran crear pajaros en los rangos:
	// x: (220, 420)
	// y: (220, 420)
	int max_x = WIN_HEIGHT / 2 + RADIO_CREACION;
	int min_x = WIN_HEIGHT / 2 - RADIO_CREACION;
	
	int max_y = WIN_WIDTH / 2 + RADIO_CREACION;
	int min_y = WIN_WIDTH / 2 - RADIO_CREACION;
    
    for (int i = 0; i < numero_de_aves; ++i)
    {
    	int x = rand()%(max_x - min_x) + min_x;
    	int y = rand()%(max_y - min_y) + min_y;
    	//printf("%d %d\n", x, y); // Imprime las coordenadas obtenidas
		Aves.push_back(new Ave(x, y, 0));
    }
    
    setup();

	//glutKeyboardFunc(handleKeypress); // Intento de manejar los eventos de presionar una tacla con la funcion handleKeypress

    glutMainLoop();
}