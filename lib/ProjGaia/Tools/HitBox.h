#ifndef HITBOX_H
#define HITBOX_H
#include "Coord.h"
//TODO :Better collision detection
namespace pg{
class HitBox
{


	public:
		/** Default constructor */
		HitBox();
		HitBox ( pg::Coord pos ) : position ( pos ) {}

		/** Default destructor */
		virtual bool pointBelongsTo ( pg::Coord coord ) = 0;
		virtual ~HitBox();

		pg::Coord position;
        pg::Coord scale= pg::Coord();
        float rotation=0;
        int z=1;
	protected:

	private:

};
}
#endif // HITBOX_H
