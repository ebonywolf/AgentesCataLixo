#ifndef STATE_H
#define STATE_H

#include "ThoughtConstants.h"
class State
{
    public:

        State();
        State(Var var):variables(var){}
        virtual ~State();

        Var operator-(State&);
        double getDifference(State&);
        bool operator==(State&);

        Var variables;
    protected:


    private:
};

#endif // STATE_H
