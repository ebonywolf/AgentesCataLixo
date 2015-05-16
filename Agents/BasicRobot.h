#ifndef BASICROBOT_H
#define BASICROBOT_H
#include "Robot.h"
#include <vector>
#include <list>
#include <ProjGaia/Tools/Coord.h>
class BasicRobot: public Robot
{
		enum State {
			EXPLORING,
			COLLECTING,
		};
	public:


		BasicRobot ( pg::Coord c = pg::Coord() );
		void init();
		void turn();
		bool priorityTrash ( Trash* );
		void pickTrash();
		virtual ~BasicRobot();
	protected:
	    pg::Coord getClosestLeftOver();

		pg::Coord getUnexplored();

		std::list<pg::Coord> leftOvers;
		void  moveToxy ( pg::Coord );
		pg::Coord objective;
		State state;
		bool doingSomething = false;

		static std::vector<std::vector<bool>> explored;


	private:
};

#endif // BASICROBOT_H
