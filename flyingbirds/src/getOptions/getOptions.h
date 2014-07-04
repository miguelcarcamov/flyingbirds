#ifndef GETOPTIONS_H_INCLUDED
#define GETOPTIONS_H_INCLUDED

#include <iostream>
#include <getopt.h>

using namespace std;

class File
{
private:
	int numberBirds;
  	double separation;
  	double cohesion;
  	double alignment;
public:
	getOptions();
	//GETTERS
	int getOptions::getNumberBirds();
	double getOptions::getSeparation();
	double getOptions::getCohesion();
	double  getOptions::getAlignment();

//SETTERS
	void getOptions::setNumberBirds(int numberBirds);
	void getOptions::setSeparation(double separation);
	void getOptions::setCohesion(double cohesion);
	void getOptions::setAlignment(double alignment);
	//Methods
	void help_printing();
	void getOptions(int argc, char **argv);

};

#endif // GETOPTIONS_H_INCLUDED