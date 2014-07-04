#include <uC++.h>
#include "graphics/Graphics.h"
#include "getOptions/getOptions.h"


using namespace std;

void uMain::main() {

	getOptions input = getOptions();
	input.FunctionGetOptions(argc, argv);
    Graphics graphics = Graphics();
    graphics.initGraphics();
    
}
