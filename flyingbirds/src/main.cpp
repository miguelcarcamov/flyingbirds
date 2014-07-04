#include <uC++.h>
#include "graphics/Graphics.h"
#include <iostream>
#include <getopt.h>

using namespace std;

struct globalArgs_t {
	int numberBirds;
	double separation;
	double cohesion;
	double alignment;
}globalArgs;
// declaracion de funciones
void help_printing();
void getOptions(int argc, char **argv);
void initializeGlobalArgs();

void help_printing ()
{
    cout << "Example: executable_name options [ arguments ...]\n" << endl;
    cout << "    -h  --help                  Shows this help\n" << endl;
    cout << "    -N  --Number        	Reads the number of birds\n" << endl;
    cout << "    -s  --separation           Reads the separation of the birds\n" << endl;
    cout << "    -c  --cohesion              Reads the cohesion of the birds\n" << endl;
    cout << "    -a  --alignment              Reads the alignment of the birds\n" << endl;
}

void getOptions(int argc, char **argv){
	int next_opt;
	const char* const short_op = "hN:s:c:a:" ;
	const struct option long_op[] =
  	{
  	  { "help", 0, NULL, 'h'},
      { "number",         1,  NULL,   'N'},
      { "separation",      1,  NULL,   's'},
      { "cohesion",       1,  NULL,   'c'},
      {	"alignment", 	1, 	NULL, 	'a'},
      { NULL,           0,  NULL,   0  }
 	 };

  	if(argc==1){
  		cout <<"ERROR. THE PROGRAM HAS BEEN EXECUTED WITHOUT PARAMETERS OR OPTIONS"<<endl;
  		help_printing();
  		exit(EXIT_SUCCESS);
  	}

  	while(1){
  		next_opt = getopt_long(argc, argv, short_op, long_op, NULL);
  		if(next_opt==-1){
  			break;
  		}
  		switch(next_opt){
  			case 'h':
  				help_printing();
  				exit(EXIT_SUCCESS);
  			case 'N':
  				globalArgs.numberBirds = atoi(optarg);
  				cout << globalArgs.numberBirds<<endl;
  				break;
  			case 's':
  				globalArgs.separation = atof(optarg);
  				cout << globalArgs.separation<<endl;
  				break;
  			case 'c':
  				globalArgs.cohesion = atof(optarg);
  				cout << globalArgs.cohesion<<endl;
  				break;
  			case 'a':
  				globalArgs.alignment = atof(optarg);
  				cout << globalArgs.alignment<<endl;
  				break;
  			case '?':
  				help_printing();
  				exit(1);
  			case -1 :
  				break;
  			default:
  				abort();
  		}
  	}
}

void initializeGlobalArgs() {
	globalArgs.numberBirds = 0;
	globalArgs.separation = 0.0;
	globalArgs.cohesion= 0.0;
	globalArgs.alignment = 0.0;
}


void uMain::main() {
	initializeGlobalArgs();
	getOptions(argc, argv);
    Graphics graphics = Graphics();
    graphics.initGraphics();
    
}
