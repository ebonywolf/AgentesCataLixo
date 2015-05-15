#ifndef NODE_H
#define NODE_H
#include "State.h"
#include "ThoughtConstants.h"
#include <map>
class Node
{
    public:
        Node();
        Node(State state):state(state){}

        virtual ~Node();
        State state;


    protected:
        std::map<std::string,Node*> action;

    private:
};

#endif // NODE_H
