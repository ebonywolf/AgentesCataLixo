#include "Robot.h"
#include "World.h"


Robot::~Robot()
{

}
void Robot::begin ( World* world )
{
	this->_world = world;
	init();

}

void Robot::update()
{

	switch ( action ) {
		case MOVE_UP: {
				if ( _pos.y < _world->size.y - 1 ) {
					_pos.y++;
				}
				break;
			}
		case MOVE_DOWN: {
				if ( _pos.y > 0 ) {
					_pos.y--;
				}
				break;
			}
		case MOVE_LEFT: {
				if ( _pos.x > 0 ) {
					_pos.x--;
				}
				break;
			}
		case MOVE_RIGHT: {
				if ( _pos.x < _world->size.x - 1 ) {
					_pos.x++;
				}
				break;
			}
		case INTERACT: {
				/* interacts with the thrash around you.
				* will pick up any trash in your spot if you are holding nothing;
				* will drop any thrash in the ground if the spot is empty and you are holding something
				* will swap your current thrash with the one on the ground if there is something in the ground
				* will do nothing otherwise
				*/
				Trash* scanned = scan();
				if ( _carrying == 0 && scanned != 0 ) {
					_world->pickTrash ( this, scanned );
					_carrying = scanned;
					break;
				}
				if ( _carrying != 0 && scanned == 0 ) {

					_world->dropTrash ( _carrying );
					_carrying = 0;
					break;
				}
				if ( _carrying != 0 && scanned != 0 ) {
					_world->dropTrash ( _carrying );
					_world->pickTrash ( this, scanned );
					_carrying = scanned;
					break;
				}

			}
		default:
			break;
	}
	action=NOTHING;

}

void Robot::moveUp()
{
	this->action = MOVE_UP;
}

void Robot::moveDown()
{
	this->action = MOVE_DOWN;
}

void Robot::moveLeft()
{
	this->action = MOVE_LEFT;
}

void Robot::moveRight()
{
	this->action = MOVE_RIGHT;
}

pg::Coord Robot::getTrashCan ( TrashTypes t )
{

	TrashCan* aux = _world->canByType ( t );
	return aux->getPosition();
}

Trash* Robot::scan()
{
Trash* t=0;
    t = _world->getTrash ( _pos );
	return t;

}

int Robot::getMapWidth()
{
	int width = _world->size.x;
	return width;
}

int Robot::getMapHeight()
{
	int height = _world->size.y;
	return height;
}

const Trash * Robot::getCarryingTrash()
{

	return this->_carrying;
}
pg::Coord Robot::getPosition()
{
	return _pos;
}
void Robot::interactThrash()
{

	action = INTERACT;
	/* interacts with the thrash around you.
	* will pick up any trash in your spot if you are holding nothing;
	* will drop any thrash in the ground if the spot is empty and you are holding something
	* will swap your current thrash with the one on the ground if there is something in the ground
	* will do nothing otherwise
	*/
}

