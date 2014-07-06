#include "misc/Math.h"

#include <iostream>
using namespace std;

Random Math::random = Random();

Math::Math(){}

Random Math::getRandom()
{
  	return this->random;
}

void Math::setRandom(Random random)
{
  	this->random = random;
}

double Math::uniform(double a, double b)
{
	if(a>=b){
		cout<<"ERROR. Uniform[a,b] with a>=b. Correct the input and run again."<<endl;
		exit(0);
	}
	else{
 		double u = this->random.calcRandom();
		double result = a+((b-a)*u);
		return result;
	}

}

double Math::roundZero(double number)
{
    double tolerance = 1e-7;

    if(abs(number)<tolerance)
        return 0;
    else
        return number;
}

double *Math::calculatePositionInit(double radio)
{
  double p[2];
  double angle = uniform(0,2*PI);
  double radius = sqrt(uniform(0,1))*radio;

  p[0] = 320 + radius*cos(angle);
  p[1] = 320 + radius*sin(angle);
  
  //cout<<"Datos: X:"<< p[0] << ":: Y:" << p[1] << ":: Angle: "<< angle << endl;

  return p;
}

double *Math::calculateVelocity(double scalar, double angle){
  double vector[2];

  vector[0] = scalar*cos((angle*PI)/180);
  vector[1] = scalar*sin((angle*PI)/180);
  
  return vector;
}

double Math::calculateDirection()
{
  double angle = uniform(0,360);

  return angle;
}

double Math::euclideanDistance(double Px, double Py, double Qx, double Qy)
{
  double distance = sqrt(pow(Qx-Px,2)+pow(Qy-Py,2));
  //cout << "Distancia: "<<distance << endl;

  return distance;
}

double *Math::maxV(double *vector, double scalar)
{
  int sizeofvector = sizeof(vector)/sizeof(vector[0]);
  //cout << "Tamaño Vector entrante EN MAX: "<< sizeofvector << endl;
  //cout << "Vector entrante EN MAX X: "<< vector[0] << "Vector entrante en MAX Y: " << vector[1]<< endl;
  for(int i=0; i<=sizeofvector ;i++){
    if(vector[i] <= scalar){
      vector[i]=scalar;
    }
  }
  //cout << "Vector saliente EN MAX X: "<< vector[0] << "Vector saliente en MAX Y: " << vector[1]<< endl;
  return vector;
}

double *Math::minV(double *vector, double scalar)
{
  int sizeofvector = sizeof(vector)/sizeof(vector[0]);
  //cout << "Tamaño Vector entrante EN MIN: "<< sizeofvector << endl;
  for(int i=0; i<=sizeofvector; i++){
    if(vector[i] >= scalar){
      vector[i]=scalar;
    }
  }
  return vector;

}

double *Math::normalizeSteps(double *vector, double *actualVelocity)
{
  double module = 1;
  double *oldVector = vector;
  //cout << "VECTOR entrante a normalizar X: "<< vector[0]<<" VECTOR entrante a normalizar Y: "<<vector[1] << endl;
  //cout << "oLDVECTOR X: "<< oldVector[0]<<" oLDVECTOR Y: "<<oldVector[1] << endl;

  double x = oldVector[0];
  double y = oldVector[1];

  //STEP 1
  module = sqrt(pow(x,2)+pow(y,2));
  oldVector[0]=x/module;
  oldVector[1]=y/module;

  //cout << "VectorNormalizado X: "<< oldVector[0]<<" VectorNormalizado Y: "<<oldVector[1] << endl;
  //STEP2

  oldVector[0]=oldVector[0]*V_MAX;
  oldVector[1]=oldVector[1]*V_MAX;

  //STEP 3

  oldVector[0]=oldVector[0]-actualVelocity[0];
  oldVector[1]=oldVector[1]-actualVelocity[1];

  //STEP 4

  double *vectorSi = minV(oldVector, F_MAX);

  //cout << "VectorTotal X: "<< vectorSi[0]<<" VectorTotal Y: "<<vectorSi[1] << endl;

  return vectorSi;
}

