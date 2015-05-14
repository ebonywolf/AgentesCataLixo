#ifndef PAINTERTYPE_H
#define PAINTERTYPE_H
#include <list>
class DrawableType;
class NeedsUpdate;

namespace pg{
class PainterType {
	public:

		virtual ~PainterType()=default;
		virtual void begin()=0;
		virtual void removeDrawable ( DrawableType* ) = 0;
		virtual void addDrawable ( DrawableType* ) = 0;
		void notifySyncs();
        void syncronize ( NeedsUpdate* n){lista.push_back(n);};
        void unSyncronize(NeedsUpdate*n ){lista.remove(n);};
	protected:
        std::list<NeedsUpdate*> lista;
	private:
};
}
#endif // PAINTERTYPE_H
