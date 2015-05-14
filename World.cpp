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

void World::ini()
{
	createTrashCans();
	generateTrash();
	for ( auto x : robots ) {
		x->_pos = randomCoord ( size );
		x->begin ( this );
	}

}
void World::begin()
{
	ini();
	while ( !checkVictoryCondition() ) {
		turn();
	}

}
void World::turn()
{
	for ( Trash* t : trash ) {
		if ( t->carrier != 0 ) {
			t->_pos = t->carrier->_pos;
		}
	}
	updateCans();
	updateAgents();
}
bool  World::checkVictoryCondition()
{
	if(trashAmount>0)return false;
	return true;


}
void World::updateCans(){
    for(auto x: trashCans){
            Trash* t= getTrash(x->getPosition());
            if(t!=0){
                if(t->type == x->type){
                    destroyTrash(t);
                }
            }
    }
}
void World::generateTrash()
{
	for ( int i = 0; i < trashAmount; i++ ) {
		Coord c = randomCoord ( size );
		TrashTypes type = randomType();
		trash.push_back ( new Trash ( type, c ) );
	}
}
Trash* World::getTrash ( pg::Coord pos ){

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
void World::destroyTrash(Trash* t){
    trash.remove(t);
    delete(t);
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
	for ( auto cesto : trashCans ) {
		if ( cesto->type == t ) {
			return cesto;
		}
		break;
	}
	return 0;
}
