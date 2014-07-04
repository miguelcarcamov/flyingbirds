#include "Bird.h"

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

#define X 0
#define Y 0

Bird::Bird(double x, double y, double direccion){
	this->p[X] = x;
	this->p[Y] = y;

	this->v[X] = x;
	this->v[Y] = y;

	this->dir = direccion;

	this->S = 0;
	this->C = 0;
	this->A = 0;

	this->F = 0;
}

void Bird::main(){
/*	int avance_x = 1;
	int avance_y = 1;*/

	while(true){
		//avance_x = rand() % MAXIMO_DESPLAZAMIENTO - MAXIMO_DESPLAZAMIENTO / 2;
		//avance_y = rand() % MAXIMO_DESPLAZAMIENTO - MAXIMO_DESPLAZAMIENTO / 2;
		/*avance_x = 1;
		avance_y = 1;

		int x_anterior = x;
		int y_anterior = y;

		if(this->x + avance_x >= MAX_X){
			this->x = MIN_X;
		}
		this->x += avance_x;

		if(this->y + avance_y >= MAX_Y){
			this->y = MIN_Y;
		}
		this->y += avance_y;*/

		dir = -atan2((int) (destino_x - p[X]), (int) (destino_y - p[Y])) * 180 / PI;
		
		//printf("(%d, %d) %f\n", x, y, direccion);
		unsigned miliseconds = 5;
		usleep(miliseconds * 1000000);
	}
}

void Bird::Mover(double sumar_x, double sumar_y){
	this->p[X] += sumar_x;
	this->p[Y] += sumar_y;
}

void Bird::Rotar(float angulo){
	this->dir = angulo;
}

void Bird::Draw(){
	double rotate_x = 1.0f;
	double rotate_y = 1.0f;

	glTranslatef(p[X], p[Y], 0.0f);
	glRotatef(dir, 0, 0, 1);
    glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -15, 0);//triangle one first vertex
      	glVertex3f( 0.5, -15, 0);//triangle one second vertex
      	glVertex3f( 0,  -13.1, 0);//triangle one third vertex    
    glEnd();
	glRotatef(-dir, 0, 0, 1);
	glTranslatef(-p[X], -p[Y], 0.0f);
}

void Bird::Separation(){

}

void Bird::Cohesion(){

}

void Bird::Alignmet(){

}

void Bird::updatePosition(){

}