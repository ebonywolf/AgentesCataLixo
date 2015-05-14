#include "ColoredShape.h"
#include <list>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <ProjGaia/Tools/Polygon.h>
namespace pg{
ColoredShape::ColoredShape ( std::list<pg::Coord> coords, sf::Color color ) :
	color ( color )
{
	pg::Polygon poly ( coords );
	createShape ( poly );
}
ColoredShape::ColoredShape ( sf::Shape* shape ) :
	shape ( shape )
{
	this->hitbox->position.x = shape->getPosition().x;
	this->hitbox->position.y = shape->getPosition().y;

}

ColoredShape::ColoredShape() {
}

ColoredShape::ColoredShape ( pg::Polygon polygon, sf::Color color ) :
	color ( color )
{
	createShape ( polygon );

}
ColoredShape::ColoredShape ( pg::Polygon polygon, pg::Coord position, pg::Coord scale, float rotation, float height, sf::Color color )
	: DrawableSprite ( position, scale, rotation, height ), color ( color )
{
	createShape ( polygon );
}

ColoredShape::~ColoredShape()
{
	delete ( shape );
}
void ColoredShape::createShape ( pg::Polygon polygon ) {
	std::list<pg::LineSeg> lines = polygon.getLines();
	int points = lines.size();
	sf::ConvexShape* shape2 = new sf::ConvexShape ( points );
	int i = 0;
for ( auto line: lines ) {
		sf::Vector2<float> vector = sf::Vector2<float> ( line.getStart().x, line.getStart().y );
		shape2->setPoint ( i, vector );
		i++;
	}
	shape2->setFillColor ( color );
	shape = shape2;

}
void ColoredShape::update(void*) {
	shape->setPosition ( hitbox->position.x, hitbox->position.y );


}
void ColoredShape::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const {
	rt.draw ( *shape, rs );
}
ColoredShape ColoredShape::createSquare(pg::Coord dimension, pg::Coord position, sf::Color color){
    std::list<Coord> lista;
    lista.push_back(position);
    lista.push_back(Coord(position.x+dimension.x,position.y));
    lista.push_back(dimension+position);
    lista.push_back(Coord(position.x,position.y+dimension.y));
    return ColoredShape(lista,color);



}


}
