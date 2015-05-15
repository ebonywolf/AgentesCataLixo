#include "State.h"

State::State()
{
    //ctor
}

State::~State()
{
    //dtor
}
Var State::operator-(State& that){
    Var mod;
    for(auto x: variables){
           auto key=x.first;
           mod[key]=this->variables[key]- that.variables[key];
    }

    return mod;
}
double State::getDifference(State&){
    //TODO: idk really
}
bool State::operator==(State& that){

    bool igual=true;
    for(auto x: variables){
           auto key=x.first;
          if(this->variables[key] !=that.variables[key]){
              return false;
          }
    }

    return true;
}
