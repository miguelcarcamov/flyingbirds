#include <uC++.h>
#include "graphics/Graphics.h"
#include "getOptions/getOptions.h"


using namespace std;

void uMain::main() {

	getOptions weights = getOptions();
	weights.GetOpt(argc, argv);
    Graphics graphics = Graphics(weights.getNumberBirds());
    graphics.initGraphics(weights);
    
}
