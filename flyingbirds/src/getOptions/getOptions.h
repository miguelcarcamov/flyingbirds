#ifndef GETOPTIONS_H_INCLUDED
#define GETOPTIONS_H_INCLUDED

#include <uC++.h>
#include <iostream>
#include <getopt.h>

using namespace std;

class getOptions
{
private:
	int numberBirds;
  	double separation;
  	double cohesion;
  	double alignment;
public:
	getOptions();
	//GETTERS
	int getNumberBirds();
	double getSeparation();
	double getCohesion();
	double getAlignment();

//SETTERS
	void setNumberBirds(int numberBirds);
	void setSeparation(double separation);
	void setCohesion(double cohesion);
	void setAlignment(double alignment);
	//Methods
	void help_printing();
	void FunctionGetOptions(int argc, char **argv);

};

#endif // GETOPTIONS_H_INCLUDED