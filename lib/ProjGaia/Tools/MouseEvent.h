#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "Coord.h"

namespace pg{
class MouseEvent
{
	public:
		enum Click {
			LEFT_DOWN,
			LEFT_UP,
			RIGHT_DOWN,
			RIGHT_UP,
			MIDDLE_DOWN,
			MIDDLE_UP,
			WHEEL_DOWN,
			WHEEL_UP,
			MOVE
		};

		MouseEvent ( Click, pg::Coord , pg::Coord screenCoord );
		virtual ~MouseEvent();

		const Click click;
		const pg::Coord coord;
		const pg::Coord screenCoord;
	protected:

	private:
};
}
#endif // MOUSEEVENT_H
