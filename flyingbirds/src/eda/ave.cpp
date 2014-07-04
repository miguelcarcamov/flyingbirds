#include <uC++.h>

#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

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
_Task Ave
{
	protected:
		void main(){
			int avance_x = 1;
			int avance_y = 1;


			while(1){
				//avance_x = rand() % MAXIMO_DESPLAZAMIENTO - MAXIMO_DESPLAZAMIENTO / 2;
				//avance_y = rand() % MAXIMO_DESPLAZAMIENTO - MAXIMO_DESPLAZAMIENTO / 2;
				avance_x = 1;
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
				this->y += avance_y;

				direccion = -atan2(destino_x - x, destino_y - y) * 180 / PI;
				
				//printf("(%d, %d) %f\n", x, y, direccion);
				unsigned miliseconds = 5;
				usleep(miliseconds * 1000000);
			}
		}
	public:
		int x;
		int y;
		
		int destino_x;
		int destino_y;

		double direccion;

	Ave(int x, int y, double direccion){
		this->x = x;
		this->y = y;
		this->direccion = direccion;
	}

	void Mover(double sumar_x, double sumar_y){
		this->x += sumar_x;
		this->y += sumar_y;
	}

	void Rotar(float angulo){
		this->direccion = angulo;
	}

	void Draw(){
		double rotate_x = 1.0f;
		double rotate_y = 1.0f;


		glTranslatef(x, y, 0.0f);
		glRotatef(direccion, 0, 0, 1);
	    glBegin(GL_TRIANGLES);
			glVertex3f(-0.5, -15, 0);//triangle one first vertex
	      	glVertex3f( 0.5, -15, 0);//triangle one second vertex
	      	glVertex3f( 0,  -13.1, 0);//triangle one third vertex    
	    glEnd();
		glRotatef(-direccion, 0, 0, 1);
		glTranslatef(-x, -y, 0.0f);
	}
};
