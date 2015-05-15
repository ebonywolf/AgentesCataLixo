#ifndef FACTORY_H
#define FACTORY_H
#include "Trash.h"
#include <list>
#include "Robot.h"
class Factory
{
	public:

		static std::list<Trash> createThrash ( int mapWidth, int mapHeight );
		static std::list<Robot*> createRobots();
	protected:
	private:
};

#endif // FACTORY_H
