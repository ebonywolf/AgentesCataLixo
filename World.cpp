#include "World.h"
#include <stdlib.h>
using namespace pg;
static Coord randomCoord(Coord limit){
    return Coord(rand()%(int)limit.x, rand()%(int)limit.y);
}

World::World( std::list<Robot*> robots,pg::Coord size, int trashNum):
    size(size),trashAmount(trashNum),robots(robots)
{
    //TODO :World constructor


}

World::~World()
{

}
void World::updateAgents(){

    for(auto x: robots){
            x->turn();
            x->update();
    }

}
void World::ini(){
    createTrashCans();
    generateTrash();
    for(auto x: robots){
            x->_pos=randomCoord(size);
            x->begin(this);
    }

}
void World::begin(){
    //TODO : world begin
    ini();

    while(!checkVictoryCondition()){
        turn();
    }

}
bool  World::checkVictoryCondition(){
    //TODO :world Checkvictory
    return false;

}
void World::generateTrash(){
    //TODO :Generate trash
   // randomCoord()

}
void World::turn(){
    updateAgents();

}
void World::createTrashCans(){
    //TODO :generate cans;
    TrashCan* vidro = new TrashCan(TrashTypes::VIDRO,randomCoord(size));
    TrashCan* papel = new TrashCan(TrashTypes::PAPEL,randomCoord(size));
    TrashCan* plastico = new TrashCan(TrashTypes::PLASTICO,randomCoord(size));
    TrashCan* organico = new TrashCan(TrashTypes::ORGANICO,randomCoord(size));
    TrashCan* toxico = new TrashCan(TrashTypes::TOXICO,randomCoord(size));

    trashCans = {vidro,papel,plastico,organico,toxico};


}

TrashCan * World::canByType(TrashTypes t){
    for(auto cesto: trashCans){
        if (cesto->type == t)
            return cesto;
        break;
    }
    return 0;
}
