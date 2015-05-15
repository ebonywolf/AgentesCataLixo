#ifndef MULTISPRITE_H
#define MULTISPRITE_H
#include "DrawableSprite.h"
#include <list>
namespace pg
{
	class MultiSprite: public pg::DrawableSprite
	{
		public:

			MultiSprite();
			virtual ~MultiSprite();
			MultiSprite ( std::list<pg::DrawableSprite*> lista );
			void add ( pg::DrawableSprite* );
			void remove ( pg::DrawableSprite* );


			virtual void draw ( sf::RenderTarget&, sf::RenderStates ) const;
			virtual void update ( void* arg );
		protected:
			std::list<DrawableSprite*> sprites;
		private:
	};
}
#endif // MULTISPRITE_H
