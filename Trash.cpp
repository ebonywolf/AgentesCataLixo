#include "Trash.h"
using namespace std;
Trash::Trash():type(zero){
}

Trash::Trash ( TrashTypes type,pg::Coord pos ):type(type),_pos(pos){

}
Trash::~Trash()
{
	//dtor
}
pg::Coord Trash::getPosition(){
    return _pos;
}
