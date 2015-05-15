#include "Graph.h"
#include "Node.h"
Graph::Graph(std::map<std::string,double(*)()> stateVars,  std::map<std::string,void(*)()> actionVars ):
    stateVars(stateVars),actionVars(actionVars)
{

}

Graph::~Graph()
{

}

void Graph::begin(){
//TODO : begin
    ///creating starting node

    Node* node=new Node(createState());
    position=node;
}

void Graph::turn(){
    //TODO : turn


}
State Graph::createState(){
    Var novo;
    for(auto x: stateVars){
        std::string key=x.first;
        novo[key] = stateVars[key]();
    }
    return State(novo);

}
