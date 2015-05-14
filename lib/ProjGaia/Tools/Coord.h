#ifndef COORD_H
#define COORD_H
#include <iostream>

namespace pg {
	class Coord
	{
		public:
			/** Default constructor */
			double x = 0, y = 0;
			Coord() = default;
			Coord ( double x, double y );
			/** Default destructor */
			virtual ~Coord();
			void move ( double angle, double speed );
			double distance ( Coord );
			void operator+= ( Coord );
			void operator-= ( Coord );

			Coord operator+ ( Coord );
			Coord operator- ( Coord );
			Coord operator* ( Coord );
			Coord operator/ ( Coord );

			void operator*= ( double k );
			Coord operator* ( double k );
			Coord operator/ ( double k );

			friend std::ostream& operator<< ( std::ostream&, const Coord& );

			bool operator== ( Coord );
			bool operator!= ( Coord );
			double modulo();
		protected:
		private:
	};
}
#endif // COORD_H
