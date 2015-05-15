#include "StateClass.h"

StateClass::StateClass()
{
    //ctor
}

StateClass::~StateClass()
{
    //dtor
}
bool StateClass::belongsToClass(Node* ){
    //TODO :check similiarity

    return false;


}
void StateClass::addNode(Node* n){
    nodeList.push_back(n);
}
void StateClass::createAction(std::string key, Var value){
    actionList[key]=value;
}
bool StateClass::existsAction(std::string key){
    return exists[key];

}
