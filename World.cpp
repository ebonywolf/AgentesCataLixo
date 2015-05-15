#include "World.h"
#include <stdlib.h>

using namespace pg;
static Coord randomCoord ( Coord limit )
{
	return Coord ( rand() % ( int ) limit.x, rand() % ( int ) limit.y );
}
static TrashTypes randomType()
{
	int a = rand() % 5;
	TrashTypes type;
	switch ( a ) {
		case 0: {
				type = TrashTypes::ORGANICO;
				break;
			}
		case 1: {
				type = TrashTypes::VIDRO;
				break;
			}
		case 2: {
				type = TrashTypes::PAPEL;
				break;
			}
		case 3: {
				type = TrashTypes::PLASTICO;
				break;
			}
		case 4: {
				type = TrashTypes::TOXICO;
				break;
			}

		default:
			break;
	}
	return type;


}

World::World ( std::list<Robot*> robots, pg::Coord size, int trashNum ) :
	size ( size ), trashAmount ( trashNum ), robots ( robots )
{

}

World::~World()
{

}
void World::begin()
{
	ini();
	while ( !checkVictoryCondition() ) {
		turn();
	}

}

void World::ini()
{
    turnCont=0;
	createTrashCans();
	generateTrash();
	for ( auto x : robots ) {
		x->_pos = randomCoord ( size );
		x->begin ( this );
	}

}

void World::turn()
{
    turnCont++;
    updateAgents();

///Update carried trash location to the carrier location
	for ( Trash* t : trash ) {
		if ( t->carrier != 0 ) {
			t->_pos = t->carrier->_pos;
		}
	}
	updateCans();

}
bool  World::checkVictoryCondition()
{
	if ( trashAmount > 0 ) { return false; }
	return true;


}
void World::updateCans()
{
    ///update every trashcan
    ///if one of them sees a trash of their type in their position,
    /// the trash will be destroyed
	for ( auto x : trashCans ) {
		Trash* t = getTrash ( x->getPosition() );
		if ( t != 0 ) {
			if ( t->type == x->type ) {
				destroyTrash ( t );
			}
		}
	}
}
void World::generateTrash()
{
    ///generate trash in random positions
	for ( int i = 0; i < trashAmount; i++ ) {
		Coord c = randomCoord ( size );
		TrashTypes type = randomType();
		trash.push_back ( new Trash ( type, c ) );
	}
}
Trash* World::getTrash ( pg::Coord pos )
{
///get the first trash it finds in a determined position
	for ( auto x : trash ) {
		if ( x->getPosition() == pos && x->carrier == 0 ) {
			return x;
		}
	}
	return 0;

}
void World::pickTrash ( Robot* r, Trash* t )
{
	t->carrier = r;
}
void World::dropTrash ( Trash* t )
{
	t->carrier = 0;
}
void World::destroyTrash ( Trash* t )
{
	trash.remove ( t );
	delete ( t );
	trashAmount--;

}

void World::updateAgents()
{
	for ( auto x : robots ) {
		x->turn();
		x->update();
	}

}
void World::createTrashCans()
{

	TrashCan* vidro = new TrashCan ( TrashTypes::VIDRO, randomCoord ( size ) );
	TrashCan* papel = new TrashCan ( TrashTypes::PAPEL, randomCoord ( size ) );
	TrashCan* plastico = new TrashCan ( TrashTypes::PLASTICO, randomCoord ( size ) );
	TrashCan* organico = new TrashCan ( TrashTypes::ORGANICO, randomCoord ( size ) );
	TrashCan* toxico = new TrashCan ( TrashTypes::TOXICO, randomCoord ( size ) );

	trashCans = {vidro, papel, plastico, organico, toxico};

}

TrashCan * World::canByType ( TrashTypes t )
{
    ///returns the position of the first trashcan of type T
	for ( auto cesto : trashCans ) {
		if ( cesto->type == t ) {
			return cesto;
		}
		break;
	}
	return 0;
}
