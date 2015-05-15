#ifndef DRAWABLESPRITE_H
#define DRAWABLESPRITE_H
#include <ProjGaia/Graphics/Sprite.h>
#include <SFML/Graphics/Drawable.hpp>

namespace pg
{
	class DrawableSprite: public pg::Sprite, public sf::Drawable
	{
		public:
			/** Default constructor */
			DrawableSprite();
			DrawableSprite ( HitBox* );
			DrawableSprite ( pg::Coord position, pg::Coord scale, float rotation, float height );
			/** Default destructor */
			virtual ~DrawableSprite();
		protected:
			void draw ( sf::RenderTarget&, sf::RenderStates ) const = 0 ;

		private:
	};
}
#endif // DRAWABLESPRITE_H
