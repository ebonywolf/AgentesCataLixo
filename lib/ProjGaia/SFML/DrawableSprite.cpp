#include "DrawableSprite.h"

#include <SFML/Graphics/Drawable.hpp>
namespace pg{
DrawableSprite::DrawableSprite() : Sprite(Coord(),Coord(1,1),0,1)
{
	//ctor
}
DrawableSprite::DrawableSprite(HitBox* hb):Sprite(hb){

}
DrawableSprite::DrawableSprite ( pg::Coord position, pg::Coord scale, float rotation, float height ) :
	pg::Sprite ( position, scale, rotation, height )
{

}

DrawableSprite::~DrawableSprite()
{
	//dtor
}

void DrawableSprite::draw ( sf::RenderTarget& rt, sf::RenderStates rs ) const {



}
}
