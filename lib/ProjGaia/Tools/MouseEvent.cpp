#include "MouseEvent.h"


namespace pg{
MouseEvent::MouseEvent ( Click click, pg::Coord coord, pg::Coord screenCoord ) :
	click ( click ), coord ( coord ), screenCoord ( screenCoord )
{
	//ctor
}

MouseEvent::~MouseEvent()
{
	//dtor
}
}
