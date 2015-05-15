#ifndef HOLLOWSHAPE_H
#define HOLLOWSHAPE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/Tools/Polygon.h>
#include <ProjGaia/Tools/LineSeg.h>
#include <list>
#include <vector>
#include "DrawableSprite.h"
namespace pg
{
	class HollowShape: public DrawableSprite
	{
		public:
			/** Default constructor */
			HollowShape ( pg::Polygon poly, sf::Color color, int width );
			HollowShape ( pg::Polygon poly, sf::Color color, int width, pg::HitBox* );
			/** Default destructor */
			virtual ~HollowShape();
		protected:
			sf::Color color;
			std::list<sf::Shape*> shapes;
			std::vector<pg::Coord> originalPos;
			void update ( void* );
			int width;


			void draw ( sf::RenderTarget&, sf::RenderStates ) const  ;
		private:
			void _ini ( pg::Polygon poly );
			sf::Shape* createCircle ( pg::Coord c );
			sf::Shape* createLine ( pg::LineSeg );
	};
}
#endif // HOLLOWSHAPE_H
