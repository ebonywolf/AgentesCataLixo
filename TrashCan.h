#ifndef TRASHCAN_H
#define TRASHCAN_H
#include "TrashTypes.h"
#include <ProjGaia/Tools/Coord.h>
class World;
class TrashCan
{
    public:
        friend World;

        TrashCan(TrashTypes,pg::Coord);
        virtual ~TrashCan();
        const TrashTypes type;
        pg::Coord getPosition();
    protected:
        pg::Coord _pos;
    private:
};

#endif // TRASHCAN_H
