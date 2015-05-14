#include <iostream>
#include <ProjGaia/SFML/Renderer.h>
#include "GuiWorld.h"
#include <ProjGaia/SFML/ColoredShape.h>
#include <ProjGaia/SFML/HollowShape.h>
#include <ProjGaia/Tools/Polygon.h>
#include "GuiFactory.h"
#include <list>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/Tools/HitBox.h>
#include "Factory.h"
#include <time.h>
using namespace std;
using namespace pg;
struct A{

    A(){
    foo();
    }
    virtual void foo(){
    std::cout<< "A" <<std::endl;
    }
    void boo(){
        this->foo();
    }

};
struct B: public A{
    B(){

    }
    void foo(){
        std::cout<< "B" <<std::endl;
    }

};

int main()
{
    GuiFactory::setColorCodes();

    srand(time(0));

    std::list<Robot*> robo=Factory::createRobots();
   World* world = new GuiWorld(robo,Coord(10,10));
    world->begin();


/*
   Renderer rend= Renderer("test",new Camera(),Coord(600,600),Coord(600,600));
   DrawableSprite* t =GuiFactory::createCanSprite(TrashTypes::PAPEL);
   t->getHitBox()->position.x=200;
    t->getHitBox()->position.y=200;
    rend.addDrawable(t);
    rend.beginAssync();
    while(true);
    */




    return 0;
}
