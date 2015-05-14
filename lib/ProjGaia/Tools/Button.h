#ifndef BUTTON_H
#define BUTTON_H

#include "Observer.h"
#include "Coord.h"
#include "Polygon.h"
//TODO :Button implement states
namespace pg{
class Button: public Observer<int>
{
	public:
		enum ButtonState {
			HALF_CLICKED, OFF, ON
		};

		/** Default constructor */
		Button () = default;
		virtual void activate ( int n ); //avisa observadores
		virtual ~Button();
		ButtonState state;

	protected:

	private:
};
}

#endif // BUTTON_H
