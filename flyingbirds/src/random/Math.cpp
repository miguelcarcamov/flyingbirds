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
 		double u  = this->random.calcRandom();
		double result = a+((b-a)*u);
		return result;
	}

}

double Math::normal(double mu, double desv)
{
  const double p0 = 0.322232431088;     const double q0 = 0.099348462606;
  const double p1 = 1.0;                const double q1 = 0.588581570495;
  const double p2 = 0.342242088547;     const double q2 = 0.531103462366;
  const double p3 = 0.204231210245e-1;  const double q3 = 0.103537752850;
  const double p4 = 0.453642210148e-4;  const double q4 = 0.385607006340e-2;
  double u, t, p, q, z;

  u  = this->random.calcRandom();

  if (u < 0.5)
    t = sqrt(-2.0 * log(u));
  else
    t = sqrt(-2.0 * log(1.0 - u));
  p   = p0 + t * (p1 + t * (p2 + t * (p3 + t * p4)));
  q   = q0 + t * (q1 + t * (q2 + t * (q3 + t * q4)));
  if (u < 0.5)
    z = (p / q) - t;
  else
    z = t - (p / q);


  return (mu + desv * z);
}


double Math::exponential(double lambda)
{
 	double u  = this->random.calcRandom();
	double result = -lambda*log(1.0-u);

	return result;
}


double Math::determineDistribution(string interarrive, double interarriveInter1, double interarriveInter2)
{
  double arrivalTime=0.0;
  if(interarrive=="exponential"){
    arrivalTime = exponential(interarriveInter1);
  }else if(interarrive=="uniform"){
    arrivalTime = uniform(interarriveInter1,interarriveInter2);
  }else if(interarrive=="normal"){
    arrivalTime = normal(interarriveInter1,interarriveInter2);
  }else if(interarrive=="constant"){
    arrivalTime = interarriveInter1;
  }

  return arrivalTime;
}

double Math::roundZero(double number)
{
    double tolerance = 1e-7;

    if(abs(number)<tolerance)
        return 0;
    else
        return number;
}

