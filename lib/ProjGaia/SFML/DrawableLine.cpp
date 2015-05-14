#include "DrawableLine.h"
#include <ProjGaia/Tools/Angle.h>
using namespace sf;
namespace pg{
DrawableLine::DrawableLine ( pg::LineSeg* line, Color color ) :
	line ( line ) {
	this->color = color;
	shape = new RectangleShape ( Vector2f ( line->getSpeed(), 2 ) );
	shape->setFillColor ( color );
	shape->setPosition ( line->getStart().x, line->getStart().y );
	float ang = pg::Angle::radianToDegree ( ( line->getAngle() ) );
	shape->setRotation ( ang );


}
DrawableLine::~DrawableLine()
{

}

void DrawableLine::update() {

}
}
