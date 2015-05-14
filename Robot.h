#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <ProjGaia/Tools/Coord.h>

#include "TrashTypes.h"
class World;
class Trash;
class TrashCan;
class Robot
{
	public:

	     Robot(){}

		virtual ~Robot();

        virtual void turn(){}
        void update();


		void begin ( World* world );


		pg::Coord getPosition();
		int getMapWidth();
		int getMapHeight();

		/**< Returns the thrash the robot is currently carrying */
		const Trash* getCarryingTrash();

		/**< returns the coordenate to the thrashcan of type */
		pg::Coord getTrashCan ( TrashTypes );

		/** interactThrash
		 * interacts with the thrash around you.
		 * will pick up anythrash in your spot if you are holding nothing;
		 * will drop any thrash in the ground if the spot is empty and you are holding something
		 * will swap your current thrash with the one on the ground if there is something in the ground
		 * will do nothing otherwise
		 */
		void interactThrash();
		Trash* scan();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

	protected:





	private:
	    enum Actions{
            MOVE_RIGHT,
            MOVE_LEFT,
            MOVE_DOWN,
            MOVE_UP,
            INTERACT,
            NOTHING
	    };
	    friend World;

	    World* _world;
	    Trash* _carrying;
	    pg::Coord _pos;
	    Actions action;


};

#endif // ROBOT_H
