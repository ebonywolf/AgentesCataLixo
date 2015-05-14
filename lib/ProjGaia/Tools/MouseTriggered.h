#ifndef MOUSETRIGGERED_H
#define MOUSETRIGGERED_H
#include "HasCollison.h"
#include "Listener.h"
#include "Coord.h"

namespace pg{
class MouseTriggered:public HasCollison,Listener<void*>
{
    public:

        /** Default destructor */
        virtual ~MouseTriggered();
        void notify(void*)=0;
        virtual HitBox* getHitBox()=0;

    protected:

    private:
};
}
#endif // MOUSETRIGGERED_H
