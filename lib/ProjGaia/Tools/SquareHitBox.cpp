#include "SquareHitBox.h"

namespace pg{
SquareHitBox::SquareHitBox ( int width, int height, pg::Coord pos ) :
	width ( width ), height ( height ), HitBox ( pos )
{
	//ctor
}

SquareHitBox::~SquareHitBox()
{
	//dtor
}
bool SquareHitBox::pointBelongsTo ( pg::Coord coord ) {
	if ( coord.x < position.x || coord.y < position.y ) return false; //verifica se esta acima ou a direita da caixa
	if ( coord.x > position.x + width ) return false; //verifica se está alem do eixo x
	if ( coord.y > position.y + height ) return false;
	return true;


}
}
