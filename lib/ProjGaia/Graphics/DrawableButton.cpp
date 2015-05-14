#include "DrawableButton.h"
using namespace pg;
DrawableButton::DrawableButton ( Sprite* main, Sprite* off, Sprite* half, Text* text ) :
	main ( main ), half ( half ), off ( off ), text ( text )
{


}

DrawableButton::~DrawableButton()
{
	//dtor
}
Sprite* DrawableButton::getSprite() {
	switch ( state ) {
		case ON:
			return main ;
			break;
		case OFF:
			return off;
			break;
		case HALF_CLICKED:
			return half;
			break;
		default:
			return 0;
			break;

	}
}
