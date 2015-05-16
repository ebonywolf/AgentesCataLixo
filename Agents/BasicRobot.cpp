#include "BasicRobot.h"

#include "Trash.h"


#include <cmath>

using namespace std;
using namespace pg;
 std::vector<std::vector<bool>> BasicRobot::explored=std::vector<std::vector<bool>>();
BasicRobot::BasicRobot ( pg::Coord c ) : objective ( c )
{
	//ctor
}

BasicRobot::~BasicRobot()
{
	//dtor
}

Coord BasicRobot::getUnexplored()
{



	auto getT = [] ( int n, std::vector<std::vector<bool>> mapa, Coord center )
	->std::vector<Coord> {
		std::vector<Coord> lista=std::vector<Coord>();
		for ( int i = 0; i < mapa.size(); i++ )
		{
			for ( int j = 0; j < mapa[i].size(); j++ ) {
				if ( abs ( center.x - i ) + abs ( center.y - j ) == n && mapa[i][j] ==0) {
					lista.push_back ( Coord ( i, j ) );
				}
			}
		}
		return lista;
	};
	int max = getMapHeight() + getMapWidth();

	int i = 1;
	while ( i <= max ) {

 		std::vector<Coord> vetor = getT ( i,explored,getPosition() );
		if ( vetor.size() == 0 ) {
			i++;
		} else {
			return vetor[0];
		}
	}




}
Coord BasicRobot::getClosestLeftOver(){
    std::list<Coord> toDelete =  std::list<Coord>();
    for(auto l: leftOvers){
            if(explored[l.x][l.y]==1)
                toDelete.push_back(l);
    }
    for(auto x: toDelete){
            leftOvers.remove(x);
    }



    auto dist= [](Coord a, Coord b){
        return (abs ( a.x - b.x ) + abs ( a.x - b.x ));
    };
    Coord closest = leftOvers.front();
    Coord pos=getPosition();
    for(auto x: leftOvers){
            if( dist(closest,pos)> dist(x,pos)  )
            closest=x;
    }
    return closest;

}
void BasicRobot::init()
{

	explored = std::vector<std::vector<bool>>();
	explored.resize ( getMapWidth() );

	leftOvers= std::list<Coord> ();


	for ( int i = 0; i < getMapWidth(); i++ ) {
		explored[i] = std::vector<bool>();
		explored[i].resize ( getMapHeight() );
	}

	state = EXPLORING;

}
void BasicRobot::turn()
{
	///since we cant drop trash and move at the same turn, this guarantees that
	/// it wont try to move incase we try to drop trash
	doingSomething = false;

	Coord pos = getPosition();
	if ( scan() == 0 ) { ///no trash on this ground, so it marks as explored
		explored[pos.x][pos.y] = 1;
	}
	if(getCarryingTrash() != 0 ){///to make it more failproof
        state = COLLECTING;
        objective = this->getTrashCan ( getCarryingTrash()->type );
	}
	if ( state == COLLECTING ) {
		if ( getPosition() == getTrashCan ( getCarryingTrash()->type ) ) {
			///carrying trash and reached its designated trashbin
			interactThrash();
			doingSomething = true;
			state = EXPLORING;
		}
	}
	if ( state == EXPLORING ) { ///se estiver explorando, procure proximo lugar não explorado

        /*
		if(leftOvers.size()>0){
                ///trash it finds while carrying other trash

                objective=getClosestLeftOver();
		}else{

		}
		*/
		 objective = getUnexplored();



	}

	if ( scan() != 0 && getCarryingTrash() == 0 ) { ///not carrying trash and found trash on ground
		pickTrash();
	}
	if ( scan() != 0 && getCarryingTrash() != 0 ) { ///carrying trash and found trash on ground
		if ( priorityTrash ( scan() ) ) { ///if scanned trash has higher priority
			pickTrash();
		}else{
          //  leftOvers.push_back(scan()->getPosition());
		}
	}


	moveToxy ( objective );
}
bool BasicRobot::priorityTrash ( Trash * trash )
{
	if ( trash->type <= 3 ) { return false; } ///lixo reciclavel não prioriza outro reciclavel

	if ( getCarryingTrash()->type < trash->type ) { return true; }
	return false;

}
void BasicRobot::pickTrash()
{
	interactThrash();
	doingSomething = true;
	state = COLLECTING;
	objective = this->getTrashCan ( scan()->type );

}


void  BasicRobot::moveToxy ( pg::Coord desti )
{
	if ( doingSomething ) { return; }
	Coord c = desti - getPosition();
	if ( abs ( c.x ) > abs ( c.y ) ) {
		if ( c.x < 0 ) {
			moveLeft();
		}
		if ( c.x > 0 ) {
			moveRight();
		}
	} else {
		if ( c.y < 0 ) {
			moveDown();
		}
		if ( c.y > 0 ) {
			moveUp();
		}
	}
}



