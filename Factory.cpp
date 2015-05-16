#include "Factory.h"
#include "Agents/Randy.h"
#include "Agents/RobotAI.h"
#include "Agents/BasicRobot.h"

std::list<Robot*> Factory::createRobots()
{
//TODO :createRobots
	std::list<Robot*> lista = std::list<Robot*>();
	//lista.push_back ( new RobotAI() );
	lista.push_back(new BasicRobot(pg::Coord(5,5)));
	lista.push_back(new BasicRobot());
	return lista;
}
