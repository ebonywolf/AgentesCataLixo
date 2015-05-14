#ifndef KEYBOARDREADER_H
#define KEYBOARDREADER_H


#include <list>
#include "../Tools/KeyBoardEvent.h"
#include "../Tools/Observer.h"

namespace pg{
class KeyBoardReader: public Observer<KeyBoardEvent>
{
	public:


	protected:
		// std::list<Listener<KeyBoardEvent>*>keyBoardListeners = std::list<Listener<KeyBoardEvent>*>();
	private:
};
}
#endif // KEYBOARDREADER_H
