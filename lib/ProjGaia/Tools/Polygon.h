#ifndef POLYGON_H
#define POLYGON_H
#include <list>


#include "LineSeg.h"
#include "HitBox.h"


namespace pg {

	class Polygon: public pg::HitBox	{
		public:
			/** Default constructor */
			Polygon() = default;
			Polygon ( std::list<pg::LineSeg> axis );
			Polygon ( std::list<pg::Coord> vertexs );
			virtual ~Polygon();

			virtual bool pointBelongsTo ( pg::Coord coord );
			std::list<pg::LineSeg> getLines();
		protected:
			std::list<pg::LineSeg> axis;
		private:

	};

}
#endif // POLYGON_H
