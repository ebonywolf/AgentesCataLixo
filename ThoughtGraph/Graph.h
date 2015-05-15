#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include "State.h"
#include "ThoughtConstants.h"
class Node;
class Graph
{
    public:
        Graph(std::map<std::string,double(*)()> stateVars,  std::map<std::string,void(*)()> actionVars );
        void begin();
        void turn();

        virtual ~Graph();
    protected:
        std::map<std::string,double(*)()> stateVars;
        std::map<std::string,void(*)()>  actionVars;

        State Objective;
        State SeconObjective;

        //std::list<Node*> future list
        State createState();
        Node* position;




    private:
};

#endif // GRAPH_H
