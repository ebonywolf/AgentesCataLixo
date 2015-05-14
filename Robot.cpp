#include "Robot.h"
#include "World.h"


Robot::~Robot()
{

}
void Robot::begin ( World* world )
{
	this->_world = world;
//TODO : robot begin
}

void Robot::update()
{
	//TODO: Commit turn actions.
	switch ( action ) {
		case MOVE_UP: {
				if ( _pos.y < _world->size.y-1 ) {
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
				if ( _pos.x < _world->size.x-1 ) {
					_pos.x++;
				}
				break;
			}
		case INTERACT: {

				break;
			}
		default:
			break;
	}

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

Trash * Robot::scan()
{
	//TODO: Verifica se há lixo no espaço atual.
}

int Robot::getMapWidth()
{
	//TODO: perguntar a largura do mapa ao mundo.
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
	//TODO: Interagir com o lixo carregado como tal:
	action = INTERACT;
	/* interacts with the thrash around you.
	* will pick up any trash in your spot if you are holding nothing;
	* will drop any thrash in the ground if the spot is empty and you are holding something
	* will swap your current thrash with the one on the ground if there is something in the ground
	* will do nothing otherwise
	*/
}

