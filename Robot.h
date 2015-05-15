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
		friend World;

		Robot():_carrying(0),_world(0) {}
		virtual ~Robot();


        ///called once at the start
		virtual void init(){}

		///will get Called once every turn.
		virtual void turn() {}

		///returns your current position
		pg::Coord getPosition();

		///returns map boundary. not that you cant get out of these boundaries
		/// even if you try
		int getMapWidth();
		int getMapHeight();

		/**< Returns the thrash the robot is currently carrying */
		const Trash* getCarryingTrash();

		/**< returns the coordenate to the thrashcan of type */
		pg::Coord getTrashCan ( TrashTypes );


		///Returns a Trash if there is a Trash in your square, otherwise returns 0
		Trash* scan();

		/** interactThrash
		 * interacts with the thrash around you.
		 * will pick up anythrash in your spot if you are holding nothing;
		 * will drop any thrash in the ground if the spot is empty and you are holding something
		 * will swap your current thrash with the one on the ground if there is something in the ground
		 * will do nothing otherwise
		 */
		///only one of these actions below can be executed per turn. If more than one is called
		/// it will overwrite the last
		void interactThrash();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();


	protected:





	private:
		enum Actions {
			MOVE_RIGHT,
			MOVE_LEFT,
			MOVE_DOWN,
			MOVE_UP,
			INTERACT,
			NOTHING
		};


		void begin ( World* world );
		void update();

		World* _world;
		Trash* _carrying;
		pg::Coord _pos;
		Actions action;


};

#endif // ROBOT_H
