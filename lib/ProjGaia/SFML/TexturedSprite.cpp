#include "TexturedSprite.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
using namespace pg;
TexturedSprite::TexturedSprite ( sf::Texture* texture, pg::Coord pos )
{

	hitbox->position = pos;
	sprite = new sf::Sprite ( *texture );

}

TexturedSprite::~TexturedSprite()
{
	//dtor
}

void TexturedSprite::update ( void* )
{

	sprite->setPosition ( hitbox->position.x, hitbox->position.y );
	sprite->setScale ( hitbox->scale.x, hitbox->scale.y );
}
void TexturedSprite::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const
{
	rt.draw ( *sprite, rs );
}
