#include "TrashCan.h"

TrashCan::TrashCan(TrashTypes type,pg::Coord pos):type(type),_pos(pos)
{
    //ctor
}
TrashCan::~TrashCan()
{
    //dtor
}

pg::Coord TrashCan::getPosition(){
    return this->_pos;
}
