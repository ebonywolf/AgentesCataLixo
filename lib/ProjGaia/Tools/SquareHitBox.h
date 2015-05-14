#ifndef SQUAREHITBOX_H
#define SQUAREHITBOX_H

#include "Polygon.h"
#include "Coord.h"
#include "HitBox.h"

namespace pg{
class SquareHitBox: public HitBox {
	public:
		/** Default constructor */
		SquareHitBox ( int width, int height, pg::Coord pos );
		/** Default destructor */
		virtual ~SquareHitBox();
		virtual bool pointBelongsTo ( pg::Coord pos );
		int width, height;
	protected:

	private:
};
}
#endif // SQUAREHITBOX_H
