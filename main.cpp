#include <iostream>
#include "GuiWorld.h"
#include "GuiFactory.h"
#include <list>
#include "Factory.h"
#include "Control.h"

using namespace std;
using namespace pg;


int main()
{
	GuiFactory::setColorCodes();

	srand ( time ( 0 ) );
	Control* control=new Control();

	std::list<Robot*> robo = Factory::createRobots();
	robo.push_back(control);
	World* world = new GuiWorld ( robo, Coord ( 10, 10 ),50,control );
	world->begin();






	return 0;
}
