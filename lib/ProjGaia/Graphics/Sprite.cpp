#include "Sprite.h"
#include "../Tools/SquareHitBox.h"

using namespace pg;

Sprite::Sprite(HitBox* h):hitbox(h){

}

Sprite::Sprite ( Coord position = Coord(), Coord scale = Coord ( 1, 1 ), float rotation = 0, float height = 1 ) :
   hitbox( new SquareHitBox(0,0,position))
{
	hitbox->scale=scale;
	hitbox->rotation=rotation;
	hitbox->z=height;
}

Sprite::~Sprite()
{
	//dtor
}
