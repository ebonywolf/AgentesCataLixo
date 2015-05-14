#ifndef RANDY_H
#define RANDY_H
#include "Robot.h"

class Randy:public Robot
{
    public:
        /** Default constructor */
        Randy();
        void turn();
        /** Default destructor */
        virtual ~Randy();
    protected:
    private:
};

#endif // RANDY_H
