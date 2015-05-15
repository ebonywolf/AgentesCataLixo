#ifndef CONTROL_H
#define CONTROL_H
#include <ProjGaia/Tools/KeyBoardEvent.h>
#include <ProjGaia/Tools/Listener.h>
#include "Robot.h"

class Control:public Robot, public pg::Listener<pg::KeyBoardEvent>
{
    public:

        Control();
        void notify(pg::KeyBoardEvent);

        virtual ~Control();
    protected:
    private:
};

#endif // CONTROL_H
