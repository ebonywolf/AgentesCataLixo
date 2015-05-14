#include "TextBox.h"

#include <SFML/Graphics/RenderTarget.hpp>

using namespace pg;

TextBox:: TextBox ( pg::Coord dimension, pg::Coord pos,
                   sf::Color color, sf::Font* font, std::string phrase,
                   sf::Color textColor  )
{
	std::list<Coord> lista = std::list<Coord>();
	//making the square
	Coord bottomLeft = pos;
	Coord bottomRight = Coord ( pos.x + dimension.x, pos.y );
	Coord topLeft = Coord ( pos.x, pos.y + dimension.y );
	Coord topRight = dimension + pos;

	lista.push_back ( bottomLeft );
	lista.push_back ( bottomRight );
	lista.push_back ( topRight );
	lista.push_back ( topLeft );

	box =new ColoredShape ( lista, color );


    text = new sf::Text(phrase,*font);

	text->setPosition((pos.x+dimension.x*0.1) ,(pos.y+dimension.y/2)-18);
	text->setCharacterSize(24);
	text->setColor(textColor);


}
TextBox::~TextBox()
{
	delete(box);
	delete(text);
}

void TextBox::update(void*){
}

void TextBox::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const{
  rt.draw ( *box, rs );
    rt.draw ( *text, rs );


}


