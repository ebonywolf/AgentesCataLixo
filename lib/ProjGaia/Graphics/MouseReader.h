#ifndef MOUSEREADER_H
#define MOUSEREADER_H

#include <list>
#include "../Tools/MouseEvent.h"
#include "../Tools/Observer.h"

class MouseListener;

namespace pg{
class MouseReader : public Observer<MouseEvent>
{
	public:


	protected:
		// std::list<Listener<MouseEvent>*>mouseListeners = std::list<Listener<MouseEvent>*>();
	private:


};
}
#endif // MOUSEREADER_H
