#include "Randy.h"
#include <stdlib.h>
Randy::Randy()
{
	//ctor
}

Randy::~Randy()
{
	//dtor
}
void Randy::turn()
{
	int a = rand() % 5;
	switch ( a ) {
		case 0: {
				moveDown();
				break;
			}
		case 1: {
				moveUp();
				break;
			}
		case 2: {
				moveLeft();
				break;
			}
		case 3: {
				moveRight();
				break;
			}

		default:
			break;
	}


}
