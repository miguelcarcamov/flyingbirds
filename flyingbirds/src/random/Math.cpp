#include <cstdlib>
#include <cmath>
#include "random/Math.h"
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

double Math::euclideanDistance(double *p, double *q){
  double x = q[0]-p[0];
  double y = q[1]-p[1];
  double distance = sqrt(pow(x,2)+pow(y,2));


  return distance;
}

double *Math::maxV(double *vector, double scalar){
  int sizeofvector = sizeof(vector)/sizeof(vector[0]);
  for(int i=0; i< sizeofvector ;i++){
    if(vector[i] <= scalar){
      vector[i]=scalar;
    }
  }
  return vector;
}

double *Math::minV(double *vector, double scalar){
  int sizeofvector = sizeof(vector)/sizeof(vector[0]);
  for(int i=0; i< sizeofvector; i++){
    if(vector[i] >= scalar){
      vector[i]=scalar;
    }
  }
  return vector;

}

double *Math::normalizeSteps(double *vector, double *actualVelocity){
  double module = 0;
  double *oldVector = vector;
  double x = oldVector[0];
  double y = oldVector[1];

  //STEP 1
  module = sqrt(pow(x,2)+pow(y,2));
  oldVector[0]=x/module;
  oldVector[1]=y/module;


  //STEP2

  oldVector[0]=oldVector[0]*2.0;
  oldVector[1]=oldVector[1]*2.0;

  //STEP 3

  oldVector[0]=oldVector[0]-actualVelocity[0];
  oldVector[1]=oldVector[1]-actualVelocity[1];

  //STEP 4

  double *vectorSi = minV(oldVector, 0.03);


  return vectorSi;
}

