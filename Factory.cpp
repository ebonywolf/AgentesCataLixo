#include "Factory.h"
#include "Agents/Randy.h"
#include "Agents/RobotAI.h"
#include "Agents/BasicRobot.h"

std::list<Robot*> Factory::createRobots(int roboquant)
{
//TODO :createRobots
	std::list<Robot*> lista = std::list<Robot*>();
	//lista.push_back ( new RobotAI() );
	for (int i=0;i<roboquant;i++){
        lista.push_back(new BasicRobot(pg::Coord(5,5)));
	}



	return lista;
}
