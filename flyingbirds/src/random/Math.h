#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include "Random.h"
#include "eda/StatisticsIn.h"

class Math{

    private:
        static Random random;

    public:
        Math();
        Random getRandom();
        void setRandom(Random random);
        double uniform(double a, double b);
        double normal(double mu, double desv);
        double exponential(double lambda);
        double determineDistribution(string interarrive, double interarriveInter1, double interarriveInter2);
        double roundZero(double number);

};

#endif // MATH_H_INCLUDED

