#ifndef TRASH_H
#define TRASH_H
#include <iostream>
#include "TrashTypes.h"
#include <ProjGaia/Tools/Coord.h>
class World;
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
        pg::Coord _pos;
    private:
};

#endif // THRASH_H
