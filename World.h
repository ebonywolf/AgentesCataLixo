#ifndef WORLD_H
#define WORLD_H
#include "Trash.h"
#include "Robot.h"
#include "TrashCan.h"
#include <list>
#include <ProjGaia/Tools/Coord.h>

class World
{
	public:
		World() = default;
		World ( std::list<Robot*> robots, pg::Coord size, int trashNum = 20 );
		virtual ~World();
		void begin();


		pg::Coord size;
		TrashCan * canByType ( TrashTypes t );
		Trash* getTrash ( pg::Coord );
		virtual void pickTrash ( Robot*, Trash* );
		virtual void dropTrash ( Trash* );



	protected:
		virtual   void ini();
		virtual   bool checkVictoryCondition();
		virtual   void generateTrash();
		virtual   void createTrashCans();
		virtual   void updateAgents();
		virtual   void updateCans();
		virtual   void destroyTrash ( Trash* );
		virtual   void turn();

		std::list<Robot*> robots;
		std::list<Trash*> trash;
		std::list<TrashCan*> trashCans;

		int trashAmount;
		long int turnCont = 0 ;



	private:
};

#endif // WORLD_H
