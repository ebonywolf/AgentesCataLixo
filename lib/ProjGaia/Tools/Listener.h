#ifndef LISTENER_H
#define LISTENER_H

namespace pg{
template<class Tipo>
class Listener
{
	public:
		virtual void notify ( Tipo ) = 0;
	protected:
	private:
};
}
#endif // LISTENER_H
