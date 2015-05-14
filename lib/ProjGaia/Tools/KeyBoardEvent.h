#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

namespace pg{

class KeyBoardEvent
{
	public:
		enum Click {
			UP,
			DOWN
		};

		KeyBoardEvent ( int key, Click type ) : key ( key ), type ( type ) {}
		Click type;
		int key;
		virtual ~KeyBoardEvent() {}
	protected:
	private:
};

}
#endif // KEYBOARDEVENT_H
