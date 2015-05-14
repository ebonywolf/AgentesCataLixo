#include "CameraMouseControl.h"
#include <iostream>

namespace pg{
CameraMouseControl::CameraMouseControl ( Camera* c, WindowType* w, float speed )  :
	camera ( c ), speed ( speed ), window ( w )
{
	//ctor
}

CameraMouseControl::~CameraMouseControl()
{
	//dtor
}
void CameraMouseControl::notify ( MouseEvent e ) {
	int totalWidth = window->getWidth();
	int totalHeight = window->getHeight();

	//Gather the size of the square where the mouse doesnt move the camera
	int width = totalWidth * BORDER;
	int height = totalHeight * BORDER;

	//calculate the square border locations
	int leftBorder = ( totalWidth - width ) / 2;
	int rightBorder = totalWidth - leftBorder;

	int upperBorder = ( totalHeight - height ) / 2;
	int lowerBorder = totalHeight - upperBorder;


	if ( e.screenCoord.x < leftBorder ) {
	    //move at max speed when mouse is at 0 x, and minimum when left border
	    //increasing at linear rate
		move.x = -speed;
		if ( acceleration ) {
		    float p= ( 1 - e.screenCoord.x / leftBorder );
			move.x *=p;

		}

	} else if ( e.screenCoord.x > rightBorder ) {
		move.x = speed;
		if ( acceleration ) {
			float p= ( e.screenCoord.x / ( totalWidth - rightBorder ) )-(rightBorder/( totalWidth - rightBorder ));
			move.x*=p;
        }
	}else{
        move.x=0;
	}
	if ( e.screenCoord.y < upperBorder ) {
	    //move at max speed when mouse is at 0 x, and minimum when left border
	    //increasing at linear rate
		move.y = -speed;
		if ( acceleration ) {
		    float p= ( 1 - e.screenCoord.y / upperBorder );
			move.y *=p;

		}

	} else if ( e.screenCoord.y > lowerBorder ) {
		move.y = speed;
		if ( acceleration ) {
			float p= ( e.screenCoord.y / ( totalHeight - lowerBorder ) )-(lowerBorder/( totalHeight - lowerBorder ));
			move.y*=p;
        }
	}else{
        move.y=0;
	}


}
void CameraMouseControl::update(void* arg){
    camera->pos+= move;

}
}
