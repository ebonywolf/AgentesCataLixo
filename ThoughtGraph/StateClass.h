#ifndef STATECLASS_H
#define STATECLASS_H

#include "Node.h"
#include "State.h"
#include <list>
#include "ThoughtConstants.h"
#include <map>
class StateClass
{
    public:

        StateClass();
       std::list<Node*> nodeList;


       std::map<std::string,Var> actionList;



       bool belongsToClass(Node* );
       void addNode(Node*);
       void createAction(std::string, Var);
       bool existsAction(std::string);




        virtual ~StateClass();
    protected:
        enum varState{
            CONSTANT,ANY
        };
        std::map<std::string,bool> exists;
        std::map<std::string,varState> variableStates;
        Var variableValues;



    private:
};

#endif // STATECLASS_H
