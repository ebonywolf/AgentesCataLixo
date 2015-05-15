#include "BasicRobot.h"
#include <cmath>
#include "Trash.h"
using namespace std;
using namespace pg;
BasicRobot::BasicRobot ( pg::Coord c ) : objective ( c )
{
	//ctor
}

BasicRobot::~BasicRobot()
{
	//dtor
}
 Coord BasicRobot::getUnexplored(){
    int biggest =explored.size();

    if(explored[0].size()>biggest)biggest=explored[0].size();
    Coord pos= getPosition();

    for (int a=0;a<explored.size();a++){
        int i=pos.x+a;
        if(i>=getMapWidth())i=getMapWidth()-1;

        for (int j=pos.y;j<explored[i].size();j++){
                if(!explored[i][j])return Coord(i,j);
        }
        for (int j=0;pos.y-j-1>=0;j++){
                if(!explored[i][j])return Coord(i,j);
        }
        i= pos.x-a;
        if(i<0)i=0;

        for (int j=pos.y;j<explored[i].size();j++){
            if(!explored[i][j])return Coord(i,j);
        }
        for (int j=0;pos.y-j-1>=0;j++){
                if(!explored[i][j])return Coord(i,j);
        }

    }

}

void BasicRobot::init()
{

	explored = std::vector<std::vector<bool>>();
	explored.resize ( getMapWidth() );

	for ( int i = 0; i < getMapWidth(); i++ ) {
		explored[i] = std::vector<bool>();
		explored[i].resize ( getMapWidth() );
	}

	state=EXPLORING;

}
void BasicRobot::turn()
{
    doingSomething=false;
    Coord pos=getPosition();
    if(scan()==0){///no trash on this ground
        explored[pos.x][pos.y]=1;
    }
    if(state==COLLECTING  ){
            if(getPosition()== getTrashCan(getCarryingTrash()->type)){
                ///carrying trash and reached its designated trashbin
                interactThrash();
                doingSomething=true;
                state=EXPLORING;
            }
    }
    if(state==EXPLORING){///
        objective=getUnexplored();
    }

    if(scan()!=0 && getCarryingTrash()==0){///not carrying trash and found trash on ground
        pickTrash();
    }
    if(scan()!=0 && getCarryingTrash()!=0){///carrying trash and found trash on ground
            if(priorityTrash( scan() ) ){///if scanned trash has higher priority
                pickTrash();
            }
    }
    moveToxy(objective);
}
bool BasicRobot::priorityTrash(Trash* trash){
    if(getCarryingTrash()->type<trash->type)return true;
    return false;

}
void BasicRobot::pickTrash(){
    interactThrash();
    doingSomething=true;
    state=COLLECTING;
    objective= this->getTrashCan(scan()->type);

}


void  BasicRobot::moveToxy ( pg::Coord desti )
{
    if(doingSomething)return;
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



