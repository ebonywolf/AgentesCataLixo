#include "DrawableTypeBox.h"
#include <SFML/Graphics/RenderTarget.hpp>

DrawableTypeBox::DrawableTypeBox ( sf::Font *font ,pg::Coord coord)
{

	text = sf::Text();
	text.setFont ( *font );
	text.setCharacterSize(18);
    text.setPosition(coord.x,coord.y);
}

DrawableTypeBox::~DrawableTypeBox()
{
	//dtor
}
void DrawableTypeBox::update ( void* )
{
	text.setString ( this->phrase );
}
void DrawableTypeBox::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const
{
	rt.draw ( text, rs );

}
