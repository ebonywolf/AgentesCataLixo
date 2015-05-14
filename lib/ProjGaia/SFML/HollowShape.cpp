#include "HollowShape.h"
#include <ProjGaia/Tools/Angle.h>

#include <SFML/Graphics/RenderTarget.hpp>
using namespace sf;
using namespace pg;

HollowShape::HollowShape ( pg::Polygon poly, sf::Color color, int width ) :
    DrawableSprite(new Polygon((const Polygon)poly )),
	color ( color ), width ( width )
{
   _ini(poly);
}

HollowShape::~HollowShape()
{
	//dtor
}
void HollowShape::_ini(pg::Polygon poly){
    shapes = std::list<sf::Shape*>();
	originalPos = std::vector<pg::Coord>();
	std::list<LineSeg> lines = poly.getLines();
	for ( auto x : lines ) {
		Shape* line = createLine ( x );
		shapes.push_back ( line );
		originalPos.push_back ( Coord ( line->getPosition().x, line->getPosition().y ) );

		Shape* circle = createCircle ( x.getStart() ) ;
		shapes.push_back ( circle );
		originalPos.push_back ( Coord ( circle->getPosition().x, circle->getPosition().y ) );

	}
}
Shape* HollowShape::createCircle ( Coord c )
{
	sf::Shape *novo = new CircleShape ( width / 2 );
	novo->setFillColor ( color );
	novo->setOrigin ( width / 2, width / 2 );
	novo->setPosition ( c.x, c.y );
	return novo;
}
Shape* HollowShape::createLine ( LineSeg line )
{

	Shape* shape = new RectangleShape ( Vector2f ( line.getSpeed(), width / 2 ) );
	shape->setFillColor ( color );
	shape->setPosition ( line.getStart().x, line.getStart().y );
	float ang = pg::Angle::radianToDegree ( ( line.getAngle() ) );
	shape->setRotation ( ang );
	return shape;



}

void HollowShape::update ( void* )
{
	int i = 0;
	for ( auto x : shapes ) {

		x->setPosition ( hitbox->position.x + originalPos[i].x , hitbox->position.y + originalPos[i].y );
		i++;
	}
//    sf::Shape::set



}
void HollowShape::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const
{
	for ( auto x : shapes ) {
		rt.draw ( *x, rs );
	}

}
