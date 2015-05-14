#ifndef CLICKABLEMANAGER_H
#define CLICKABLEMANAGER_H
#include "Listener.h"
#include "MouseEvent.h"
#include <list>
#include "Observer.h"
#include "MouseTriggered.h"

namespace pg{
class ClickableManager:public Observer<MouseTriggered*>,public Listener<MouseEvent>
{
    public:
        /** Default constructor */
        ClickableManager();

        void notify(MouseEvent e);
        /** Default destructor */
        virtual ~ClickableManager();
    protected:
     pg::Coord _downClick;
    private:
};
}
#endif // CLICKABLEMANAGER_H
