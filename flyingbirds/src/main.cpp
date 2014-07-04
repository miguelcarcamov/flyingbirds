#include <uC++.h>
#include "graphics/Graphics.h"
#include "getOptions/getOptions.h"


using namespace std;

void uMain::main() {

	getOptions getoptions = getOptions();
	getoptions.getOptions(argc, argv);
    Graphics graphics = Graphics();
    graphics.initGraphics();
    
}
