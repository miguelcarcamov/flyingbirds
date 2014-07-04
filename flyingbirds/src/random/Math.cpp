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

double Math::getX(){
  return this->x;
}

double Math::getY(){
  return this->y;
}

void Math::setRandom(Random random)
{
  	this->random = random;
}

void Math::setX(double x)
{
    this-> x = x;
}

void Math::setY(double y)
{
    this->y = y;
}

double Math::uniform(double a, double b)
{
	if(a>=b){
		cout<<"ERROR. Uniform[a,b] with a>=b. Correct the input and run again."<<endl;
		exit(0);
	}
	else{
 		double u  = this->random.calcRandom();
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

void Math::calculatePosition(double radio)
{
  double angle = uniform(0,2*PI);
  double radius = sqrt(uniform(0,1)*radio);
  
  this->x = radius * cos(angle);

  this->y = radius * sin(angle);
}