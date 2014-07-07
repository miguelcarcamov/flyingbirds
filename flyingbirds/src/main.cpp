#include <uC++.h>
#include "graphics/Graphics.h"
#include "getOptions/getOptions.h"


using namespace std;

void uMain::main() {

	getOptions weights = getOptions();
	weights.GetOpt(argc, argv);
    Graphics graphics = Graphics(weights.getNumberBirds());
    double Ws = weights.getSeparation();
    double Wc = weights.getCohesion();
    double Wa = weights.getAlignment();
    double suma = Ws+Wa+Wc;
    if(suma==1.0){
    	graphics.initGraphics(weights);
    }else{
    	cout<<"Error de parámetros, Wc, Ws y Wa deben sumar 1"<<endl;
    	exit(EXIT_SUCCESS);
    }
    
    
}
