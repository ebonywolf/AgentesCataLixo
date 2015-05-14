#include "Trash.h"
using namespace std;
Trash::Trash():type(zero){
//TODO : Thrash Default ctor
}

Trash::Trash ( TrashTypes type,pg::Coord pos ):type(type),_pos(pos){
//TODO : thrash Constructor
}
Trash::~Trash()
{
	//dtor
}
pg::Coord Trash::getPosition(){
    return _pos;
}
