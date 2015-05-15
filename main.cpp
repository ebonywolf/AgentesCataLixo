#include <iostream>
#include "GuiWorld.h"
#include "GuiFactory.h"
#include <list>
#include "Factory.h"
#include "Control.h"
#include <map>
using namespace std;
using namespace pg;


int main()

{
    map<string,int> test;
    cout<<test["hi"];

	GuiFactory::setColorCodes();

	srand ( time ( 0 ) );

	std::list<Robot*> robo =Factory::createRobots();

	World* world = new GuiWorld ( robo, Coord ( 10, 10 ),25,200 );
	world->begin();






	return 0;
}
