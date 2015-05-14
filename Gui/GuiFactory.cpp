#include "GuiFactory.h"
#include <ProjGaia/SFML/TexturedSprite.h>
using namespace pg;

sf::Texture* GuiFactory::robot =0;
GuiFactory::GuiFactory()
{
    //ctor
}

GuiFactory::~GuiFactory()
{
    //dtor
}

DrawableSprite*  GuiFactory::createRobotSprite(){
    if(robot==0){
        robot=new sf::Texture();
        if(!robot->loadFromFile(ROBOT_PATH)){
                std::cout<<"unable to load" <<ROBOT_PATH;
        }
    }
    pg::TexturedSprite* novo = new  pg::TexturedSprite(robot,Coord());
    novo->getHitBox()->scale.x=0.4;
    novo->getHitBox()->scale.y=0.4;

    return novo;
}

pg::Polygon GuiFactory::createRect(pg::Coord dimension, pg::Coord position){

    std::list<Coord> lista=  std::list<Coord>();
    Coord bottomleft=Coord();
    Coord bottomright=Coord(dimension.x,0);
    Coord topright=dimension;
    Coord topleft=Coord(0,dimension.y);
    lista.push_back(bottomleft);
    lista.push_back(bottomright);
    lista.push_back(topright);
    lista.push_back(topleft);

    pg::Polygon novo=pg::Polygon(lista);
    novo.position=position;
    return novo;
}
