#ifndef TEXTUREDSPRITE_H
#define TEXTUREDSPRITE_H

#include "DrawableSprite.h"
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace pg
{
	class TexturedSprite: public DrawableSprite
	{
		public:
			/** Default constructor */
			TexturedSprite ( sf::Texture*, pg::Coord pos );
			void update();
			sf::Sprite* sprite;
			void update ( void* );
			void setImageSize ( pg::Coord );
			/** Default destructor */
			virtual ~TexturedSprite();
		protected:
			void draw ( sf::RenderTarget&, sf::RenderStates ) const  ;


		private:
	};
}

#endif // TEXTUREDSPRITE_H
