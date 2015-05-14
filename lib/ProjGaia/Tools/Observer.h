
#ifndef OBSERVER_H
#define OBSERVER_H

#include "Listener.h"
#include <list>

namespace pg{
template<class Tipo>
class Observer
{
	public:

		virtual void addListener ( Listener<Tipo>* listener );
		virtual void removeListener ( Listener<Tipo>* listener );
		virtual void clearListener ( );
		virtual bool hasListener ( Listener<Tipo>* listener );
		virtual void notifyListeners ( Tipo t );

	protected:
		std::list<Listener<Tipo>*> listeners = std::list<Listener<Tipo>*>();

	private:
};

template <typename T>
void Observer<T>::addListener ( Listener<T>* listener ) {
	listeners.push_back ( listener );
}
template <typename T>
void Observer<T>::removeListener ( Listener<T>* listener ) {
	listeners.remove ( listener );
}
template <typename T>
void Observer<T>::clearListener ( ) {
	listeners.clear();
}
template <typename T>
bool Observer<T>::hasListener ( Listener<T>* listener ) {
for ( auto x: listeners ) {
		if ( x == listener ) return true;
	}
	return false;

}
template <typename T>
void Observer<T>::notifyListeners ( T t ) {
for ( auto x: listeners ) {
		x->notify ( t );
	}
}
}

#endif // OBSERVER_H
