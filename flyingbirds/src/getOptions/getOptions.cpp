#include "getOptions.h"

getOptions::getOptions() {
  this->numberBirds = 0;
  this->separation = 0.0;
  this->cohesion = 0.0;
  this->alignment = 0.0;
}

//GETTERS
int getOptions::getNumberBirds(){
  return this->numberBirds;
}

double getOptions::getSeparation(){
  return this->separation;
}

double getOptions::getCohesion(){
  return this->cohesion;
}

double  getOptions::getAlignment(){
  return this->alignment;
}


//SETTERS

void getOptions::setNumberBirds(int numberBirds){
  this->numberBirds=numberBirds;
}

void getOptions::setSeparation(double separation){
  this->separation=separation;
}

void getOptions::setCohesion(double cohesion){
  this->cohesion=cohesion;
}

void getOptions::setAlignment(double alignment){
  this->alignment=alignment;
}

void getOptions::help_printing ()
{
    cout << "Example: executable_name options [ arguments ...]\n" << endl;
    cout << "    -h  --help                  Shows this help\n" << endl;
    cout << "    -N  --Number        	Reads the number of birds\n" << endl;
    cout << "    -s  --separation           Reads the separation of the birds\n" << endl;
    cout << "    -c  --cohesion              Reads the cohesion of the birds\n" << endl;
    cout << "    -a  --alignment              Reads the alignment of the birds\n" << endl;
}

void getOptions::GetOpt(int argc, char **argv){
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
  				this->numberBirds = atoi(optarg);
  				break;
  			case 's':
  				this->separation = atof(optarg);
  				break;
  			case 'c':
  				this->cohesion = atof(optarg);
  				break;
  			case 'a':
  				this->alignment = atof(optarg);
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
