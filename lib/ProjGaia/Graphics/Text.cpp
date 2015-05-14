#include "Text.h"
namespace pg{
Text::Text ( String text, float size, String font, pg::Coord pos ) :
	text ( text ), size ( size ), font ( font ), pos ( pos )
{
	//ctor
}

Text::~Text()
{
	//dtor
}
}
