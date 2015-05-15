#ifndef COLOREDSHAPE_H
#define COLOREDSHAPE_H

#include <SFML/Graphics/ConvexShape.hpp>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/Tools/Polygon.h>
#include <ProjGaia/Tools/LineSeg.h>
#include "DrawableSprite.h"

namespace pg
{
	class ColoredShape: public DrawableSprite
	{
		public:
			/** Default constructor */
			ColoredShape();
			ColoredShape ( std::list<pg::Coord> coords, sf::Color );
			ColoredShape ( pg::Polygon, sf::Color );
			ColoredShape ( sf::Shape* );
			ColoredShape ( pg::Polygon , pg::Coord position, pg::Coord scale, float rotation, float height, sf::Color );
			/** Default destructor */
			void update ( void* );
			virtual ~ColoredShape();

			static ColoredShape createSquare ( pg::Coord dimension, pg::Coord position, sf::Color );



		protected:
			sf::Color color;
			sf::Shape* shape;
			void update();


			void draw ( sf::RenderTarget&, sf::RenderStates ) const  ;

		private:
			void createShape ( pg::Polygon );
	};
}
#endif // COLOREDSHAPE_H
