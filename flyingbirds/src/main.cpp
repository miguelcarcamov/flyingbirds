#include <uC++.h>
#include "graphics/Graphics.h"


using namespace std;

void uMain::main() {

	getOptions(argc, argv);
    Graphics graphics = Graphics();
    graphics.initGraphics();
    
}
