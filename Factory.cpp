#include "Factory.h"
#include "Agents/Randy.h"

std::list<Robot*> Factory::createRobots()
{
//TODO :createRobots
	std::list<Robot*> lista = std::list<Robot*>();
	lista.push_back ( new Randy() );
	return lista;
}
