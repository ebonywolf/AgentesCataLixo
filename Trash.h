#ifndef TRASH_H
#define TRASH_H
#include <iostream>
#include "TrashTypes.h"
#include <ProjGaia/Tools/Coord.h>
class World;
class Robot;
class Trash
{
    public:
        friend World;
        Trash();
        Trash(TrashTypes type,pg::Coord pos);
        pg::Coord getPosition();
        virtual ~Trash();
        const TrashTypes type;
    protected:

        bool carried=0;
        Robot* carrier=0;
        pg::Coord _pos;
    private:
};

#endif // THRASH_H
