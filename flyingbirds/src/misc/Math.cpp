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
  double distanceToroid = 610 - distance;

  if(distance < distanceToroid){
    return distance;
  } else {
    return distanceToroid;
  }
}

double *Math::min(double x, double y, double scalar)
{
  double vector[2];

  double module = sqrt(pow(x,2)+pow(y,2));

  if (module > Vmax){
    vector[0] = (x/module) * Vmax;
    vector[1] = (y/module) * Vmax;
  }
  else
  {
    vector[0] = x;
    vector[1] = y;
  }

  return vector;

}

/*FORMULA ORIGINAL
void Math::minV1(double Vx, double Vy, double scalar)
{
    if(abs(Vx) >= scalar){
      if(Vx < 0){
        Vx = -scalar;
      }else{
        Vx = scalar;
      }
    }

    if(abs(Vy) >= scalar){
      if(Vy < 0){
        Vy = -scalar;
      }else{
        Vy = scalar;
      }
    }

}

double *Math::minV2(double *vector, double scalar)
{
  int sizeofvector = sizeof(vector)/sizeof(vector[0]);
  //cout << "Tamaño Vector entrante EN MIN: "<< sizeofvector << endl;
  for(int i=0; i<=sizeofvector; i++){
    if(abs(vector[i]) >= scalar){
      if(vector[i] < 0)
        vector[i]=-scalar;
      else
        vector[i]=scalar;
    }
  }
  return vector;

}

}*/

double *Math::normalizeSteps(double *vector, double *actualVelocity)
{
  double module = 1;
  double *oldVector = vector;

  double x = oldVector[0];
  double y = oldVector[1];

  //STEP 1
  module = sqrt(pow(x,2)+pow(y,2));
  oldVector[0]=x/module;
  oldVector[1]=y/module;

  //STEP2
  oldVector[0]=oldVector[0]*V_MAX;
  oldVector[1]=oldVector[1]*V_MAX;
  
  //STEP 3
  oldVector[0]=oldVector[0]-actualVelocity[0];
  oldVector[1]=oldVector[1]-actualVelocity[1];

  //STEP 4

  double *vectorSi = min(oldVector[0], oldVector[1],F_MAX);


  return vectorSi;
}

