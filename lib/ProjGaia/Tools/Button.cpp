#include "Button.h"
using namespace pg;

namespace pg{
Button::~Button()
{
	//dtor
}
void Button::activate ( int n ) {
	if ( state != OFF ) notifyListeners ( n );
}

}
