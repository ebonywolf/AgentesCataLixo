#include "MultiSprite.h"
#include <SFML/Graphics/RenderTarget.hpp>

using namespace pg;
MultiSprite::MultiSprite()
{
	sprites = std::list<pg::DrawableSprite*>();
}
MultiSprite::MultiSprite ( std::list<pg::DrawableSprite*> lista )
{
	sprites = lista;

}
MultiSprite::~MultiSprite()
{

}

void MultiSprite::add ( pg::DrawableSprite* p )
{
	sprites.push_back ( p );
}
void MultiSprite::remove ( pg::DrawableSprite* p )
{
	sprites.remove ( p );
}

void MultiSprite::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const
{
	for ( auto x : sprites ) {
		rt.draw ( *x, rs );
	}
}
void MultiSprite::update ( void* arg )
{
	for ( auto x : sprites ) {
		x->update ( arg );

	}
}
