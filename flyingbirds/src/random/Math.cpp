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

double *Math::calculatePosition(double radio)
{
  double p[2];
  double angle = uniform(0,2*PI);
  double radius = sqrt(uniform(0,1))*radio;

  p[0] = 320 + radius*cos(angle);
  p[1] = 320 + radius*sin(angle);
  
  //cout<<"Datos: X:"<< p[0] << ":: Y:" << p[1] << ":: Angle: "<< angle << endl;

  return p;
}

double Math::euclideanDistance(double *p, double *q){
  double x = q[0]-p[0];
  double y = q[1]-p[1];
  double distance = sqrt(pow(x,2)+pow(y,2));


  return distance;
}